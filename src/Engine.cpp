#include <Engine.h>

#include <ncurses.h>
#include <vector>
#include <string>
#include <fstream>

#include <constants.h>
#include <Logger.h>
#include <Player.h>
#include <World.h>
#include <MapBuilder.h>

Engine::Engine(){
    
}

bool Engine::initCurses(){
    initscr();
    noecho();
    curs_set(0);

    // Color
    if(has_colors()){
        start_color();

        init_pair(PLAYER_COLOR, COLOR_YELLOW, COLOR_BLACK);
        init_pair(VISIBLE_COLOR, COLOR_WHITE, COLOR_BLACK);
        init_pair(SEEN_COLOR, COLOR_BLUE, COLOR_BLACK);
        init_pair(MONSTER_COLOR, COLOR_RED, COLOR_BLACK);
    } else {
        mvprintw(0, 0, "No color support, dying.");
        getch();
        return false;
    }


    return true;
}

void Engine::initPanels(){
    int y, x;
    getmaxyx(stdscr, y, x);

    int y_pad = (y - SCREEN_HEIGHT) / 2;
    int x_pad = (x - SCREEN_WIDTH) / 2;

    w_world = newwin(MAP_HEIGHT, MAP_WIDTH, y_pad, x_pad);
    w_info = newwin(1, SCREEN_WIDTH, y_pad + MAP_HEIGHT, x_pad);

    MapBuilder mb;
    Map m = mb.buildMapFromJSONFile("data/map1.json");
    world.map = m;

    world.initEntities();
}

void Engine::gameLoop(){
    int ch;

    while((ch = getch())){
        if(ch == 'q'){
            break;
        }
        handleInput(ch);
        update();
        render();
    }
}

int Engine::handleInput(int input){
    world.handleInput(input);
    return 0;
}

void Engine::update(){
    world.update();
}

void Engine::render(){
    werase(w_world);
    werase(w_info);

    // Render map
    for(int y = 0; y < MAP_HEIGHT; y++){
        for(int x = 0; x < MAP_WIDTH; x++){
            if(world.map.tiles[y][x].visible){
                mvwaddch(w_world, y, x, world.map.tiles[y][x].ch | world.map.tiles[y][x].color);
            } else if(world.map.tiles[y][x].seen){
                mvwaddch(w_world, y, x, world.map.tiles[y][x].ch | COLOR_PAIR(SEEN_COLOR));
            } else{
                mvwaddch(w_world, y, x, ' ');
            }
        }
    }

    // Render entities
    for(Entity* ent : world.ents){
        mvwaddch(w_world, ent->pos.y, ent->pos.x, ent->ch | ent->color);
    }

    // Render info
    std::string msg = world.log.pop();
    mvwprintw(w_info, 0, 0, msg.c_str());

    wrefresh(w_world); 
    wrefresh(w_info); 
}
