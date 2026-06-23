#include <Engine.h>

#include <ncurses.h>
#include <vector>
#include <string>
#include <fmt/core.h>

#include <constants.h>
#include <Logger.h>
#include <Player.h>
#include <World.h>
#include <Map.h>
#include <MapBuilder.h>

Engine::Engine(){
    
}

bool Engine::initCurses(){
    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, true);

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

    // Border
    if(y_pad >= 2 && x_pad >= 2){
        for(int y = y_pad; y < SCREEN_HEIGHT + y_pad; y++){
            mvaddch(y, x_pad - 1, '|');
            mvaddch(y, x_pad + SCREEN_WIDTH, '|');
        }
        for(int x = x_pad; x < SCREEN_WIDTH + x_pad; x++){
            mvaddch(y_pad - 1, x, '-');
            mvaddch(y_pad + SCREEN_HEIGHT, x, '-');
        }
        mvaddch(y_pad - 1, x_pad - 1, 'x');
        mvaddch(y_pad + SCREEN_HEIGHT, x_pad - 1, 'x');
        mvaddch(y_pad + SCREEN_HEIGHT, x_pad + SCREEN_WIDTH, 'x');
        mvaddch(y_pad - 1, x_pad + SCREEN_WIDTH, 'x');
    }


    w_stats = newwin(1, SCREEN_WIDTH, y_pad, x_pad);
    w_world = newwin(MAP_HEIGHT, MAP_WIDTH, y_pad + 1, x_pad);
    w_info = newwin(1, SCREEN_WIDTH, y_pad + 1 + MAP_HEIGHT, x_pad);

    //MapBuilder mb;
    //Map m = mb.buildMapFromJSONFile("data/map1.json");
    //world.map = m;
    //world.player.pos = {5, 68};
    //world.map.createRoomsBSP(MAP_HEIGHT - 2, MAP_WIDTH - 2, {1,1});
    //world.player.pos = world.map.createRoomsRandom();
    world.player.pos = world.map.createRoomsSimple();

    world.initEntities();
}

void Engine::gameLoop(){
    int ch;

    while((ch = getch())){
        if(ch == 'q'){
            world.clearEntities();
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
    werase(w_stats);
    werase(w_world);
    werase(w_info);

    // Render stats
    std::string stat_line = fmt::format("HP: [{}/{}]", world.player.destructible->hp, world.player.destructible->max_hp);
    mvwprintw(w_stats, 0, 0, stat_line.c_str());

    // Render map
    for(int y = 0; y < MAP_HEIGHT; y++){
        for(int x = 0; x < MAP_WIDTH; x++){
            if(world.map.tiles[y][x].visible || SEE_ALL){
                mvwaddch(w_world, y, x, world.map.tiles[y][x].ch | world.map.tiles[y][x].color);
            } else if(world.map.tiles[y][x].seen){
                mvwaddch(w_world, y, x, world.map.tiles[y][x].ch | COLOR_PAIR(SEEN_COLOR));
            } else{
                mvwaddch(w_world, y, x, ' ');
            }
            //Show DMap
            if(false){
                if(world.map.tiles[y][x].ch == '.' || world.map.tiles[y][x].ch == '#')
                {
                    mvwaddch(w_world, y, x, world.map.dmap[y][x] + '0');
                }
            }
        }
    }

    // Render actors
    for(Actor* actor : world.actors){
        if(actor->visible){
            mvwaddch(w_world, actor->pos.y, actor->pos.x, actor->ch | actor->color);
        }
    }

    // Render info
    std::string msg = world.feed.pop();
    mvwprintw(w_info, 0, 0, msg.c_str());

    wrefresh(w_stats);
    wrefresh(w_world); 
    wrefresh(w_info); 
}
