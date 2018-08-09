//
//  @file Menu.hpp
//  FilmMenu
//
//  @author Zachary Duncan on 3/17/18.
//  Copyright © 2018 Zachary Duncan. All rights reserved.
//

#ifndef Menu_hpp
#define Menu_hpp

#include "MenuUtilities.hpp"
#include "FilmDatabase.hpp"
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Menu {
private:
    const string EXIT_KEY = "X";
    const string INIT_VAL = "";
    
    string title;
    string key;
    vector<Menu> options;
    vector<string> availableKeys;
    MenuUtilities util;
    int action = 0;
    /* -- action value breakdown --
     - 0: Clears the screen for the next menu
     - 1: Orders and displays films by title
     - 2: Orders and displays films by rank
     - 3: Search by title and display results
     - 4: Search by key word and display results
     - 5: Search by studio and display results
     - 6: Search by month of release and display results
     - 7: Describe the program
     */
    
    void setKey(string);
    void setKey(char);
    string getTitle();
    string getKey();
    string getUsedKeys();
    void subroutine(FilmDatabase &db);
    void draw(FilmDatabase &db);

public:
    /* @param Initializes a Menu with a given name and an action defaulted to 0 */
    Menu(string title);
    
    /* @param Initializes a Menu with a given name and action */
    Menu(string title, int action);
    
    
    /* @param Adds a new Menu to the list of options for the caller Menu */
    void addSub(Menu&);
    
    /* Handles the drawing and available keys for currect Menu */
    void run(FilmDatabase &db);
};

#endif /* Menu_hpp */
