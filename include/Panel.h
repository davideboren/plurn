#ifndef PANEL_H
#define PANEL_H

#include <vector>
#include <ncurses.h>
#include <Entity.h>

class Panel {
    public:
        Panel(int h, int w, int y_off, int x_off);
        
        void update();
        void draw();

    private:
        WINDOW* win; 
        std::vector<Entity> ents;
};

#endif
