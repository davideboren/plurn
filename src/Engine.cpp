#include <Engine.h>

#include <ncurses.h>
#include <vector>

#include <constants.h>
#include <Player.h>
#include <World.h>

Engine::Engine(){
    
}

void Engine::initCurses(){
    initscr();
    noecho();
    curs_set(0);
}

void Engine::initPanels(){
    int y, x;
    getmaxyx(stdscr, y, x);

    int y_pad = (y - MAP_HEIGHT) / 2;
    int x_pad = (x - MAP_WIDTH) / 2;

    w_world = newwin(MAP_HEIGHT, MAP_WIDTH, y_pad, x_pad);

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

    for(int y = 0; y < MAP_HEIGHT; y++){
        for(int x = 0; x < MAP_WIDTH; x++){
            mvwaddch(w_world, y, x, world.tiles[y][x].ch);
        }
    }
    mvwaddch(w_world, world.player.pos.y, world.player.pos.x, '@');

    wrefresh(w_world); 
}
