//
//  @file FilmMenu.hpp
//  FilmMenu
//
//  @author Zachary Duncan on 4/3/18.
//  Copyright © 2018 Zachary Duncan. All rights reserved.
//

#ifndef FilmMenu_hpp
#define FilmMenu_hpp

#include "FilmDatabase.hpp"
#include "Menu.hpp"
#include <stdio.h>

class FilmMenu {
private:
    FilmDatabase database;
public:
    /* @param Assembles the Menu components to make
              the full Menu system for Film Menu and
              calls the FilmDatabase run() command
              on the main menu */
    void begin();
};

#endif /* FilmMenu_hpp */
