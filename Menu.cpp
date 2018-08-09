//
//  @file Menu.cpp
//  FilmMenu
//
//  @author Zachary Duncan on 3/17/18.
//  Copyright © 2018 Zachary Duncan. All rights reserved.
//

#include "Menu.hpp"
#include "MenuUtilities.hpp"
#include <iostream>

using namespace std;


Menu::Menu(string t) {
    title = t;
    setKey(INIT_VAL);
}
Menu::Menu(string t, int a) {
    title = t;
    setKey(title[0]);
    action = a;
}

void Menu::addSub(Menu &m) {
    m.setKey(getUsedKeys()); //When subordinating to a new menu
    options.push_back(m);
    availableKeys.push_back(m.getKey());
}

string Menu::getKey() {
    return key;
}

void Menu::setKey(string usedKeys) {
    //Grabs the first char of the title or the EXIT_KEY
    string k = key == EXIT_KEY ? EXIT_KEY : string(1, title[0]);
    
    //Makes sure this menu option isn't a 'back/exit' option
    if (k != EXIT_KEY) {
        int j = 2; //Starts off the optional numeric add-on for the key
        
        //Looks through each stored key in the current menu to ensure
        //none has the same key. If there is an identical key the
        //optional numeric add-on is attached to distinguish it
        for (int i = 0; i < usedKeys.size(); i++) {
            if (usedKeys[i] == k[0]) {//if (options[i].getKey() == k) {
                //If the numerical add-on was previously applied and needs
                //to be reassigned it is first removed and then assigned
                k = k[0];
                k += to_string(j);
                j++;
            }
        }
    //If the key starts with an X it is a 'back/exit' option and should
    //have it's title amended
    } else {
        k = EXIT_KEY;
        title = "Exit";
    }
    
    //After much deliberation, the key is assigned to its ivar
    key = k;
}
void Menu::setKey(char k) {
    setKey(string(1, k));
}

string Menu::getTitle() {
    return title;
}

string Menu::getUsedKeys() {
    string keys;
    
    for (int i = 0; i < availableKeys.size(); i++) {
        keys += availableKeys[i][0];
    }
    
    return keys;
}

void Menu::subroutine(FilmDatabase &db) {
    switch (action) {
        case 1:
            db.displayByTitle();
            break;
            
        case 2:
            db.displayByRank();
            break;
            
        case 3:
            db.searchByTitle();
            break;
            
        case 4:
            db.searchByKeyword();
            break;
            
        case 5:
            db.searchByStudio();
            break;
            
        case 6:
            db.searchByMonth();
            break;
        case 7:
            db.displayDescription();
            break;
    }
}

void Menu::draw(FilmDatabase &db) {
    subroutine(db);
    
    if (action < 1 || action > 7) {
        cout << "┏------------------------------" << endl;
        cout << "| " << title << endl << "|" << endl;
        
        for (int i = 0; i < options.size(); i++) {
            cout  << "| " << options.at(i).getKey() << " - ";
            
            if (options.at(i).getKey() == EXIT_KEY) {
                cout << "..";
            }
            
            cout << options.at(i).getTitle();
            
             if (options.at(i).action == 0 && options.at(i).getKey() != EXIT_KEY) {
                cout << "...";
            }
            cout << endl;
        }
        
        cout << "┗------------------------------" << endl
        << endl << "Enter Selection: ";
    }
}

void Menu::run(FilmDatabase &db) {
    bool exit = false;
    
    do {
        //Turns availableKeys into an array so it can be passed
        //as a method argument
        string keys[availableKeys.size()];
        
        for (int i = 0; i < availableKeys.size(); i++) {
            keys[i] = availableKeys[i];
        }
        
        draw(db);
        
        string response = action > 0 && action < 8
                        ? EXIT_KEY
                        : util.presentSet(keys, availableKeys.size());
        
        if (response != EXIT_KEY) {
            for (int i = 0; i < options.size(); i++) {
                if (response == keys[i]) {
                    options[i].run(db);
                }
            }
        } else {
            exit = true;
            cout << endl;
        }
    } while (!exit);
}



