#include <Engine.h>

#include <ncurses.h>
#include <vector>

#include <constants.h>
#include <Player.h>
#include <World.h>

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
        init_pair(SEEN_COLOR, COLOR_RED, COLOR_BLACK);
        init_pair(NPC_COLOR, COLOR_BLUE, COLOR_BLACK);
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

    int y_pad = (y - MAP_HEIGHT + 2) / 2;
    int x_pad = (x - MAP_WIDTH + 2) / 2;

    w_world = newwin(MAP_HEIGHT + 2, MAP_WIDTH + 2, y_pad, x_pad);

    world.initMap();
    world.initEntities();

}

void Engine::gameLoop(){
    int ch;

    while(ch = getch()){
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
}

void Engine::render(){
    werase(w_world);

    box(w_world, 0, 0);
    for(int y = 0; y < MAP_HEIGHT; y++){
        for(int x = 0; x < MAP_WIDTH; x++){
            mvwaddch(w_world, y + 1, x + 1, world.map.tiles[y][x].ch | world.map.tiles[y][x].color);
        }
    }
    mvwaddch(w_world, world.player.pos.y + 1, world.player.pos.x + 1, world.player.ch | world.player.color);

    wrefresh(w_world); 
}
