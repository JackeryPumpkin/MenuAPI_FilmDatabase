//
//  @file FilmMenu.cpp
//  FilmMenu
//
//  @author Zachary Duncan on 4/3/18.
//  Copyright © 2018 Zachary Duncan. All rights reserved.
//

#include "FilmMenu.hpp"


void FilmMenu::begin() {
    Menu back("X");
    
    //Main Menu menu and submenus
    Menu mainMenu("Main Menu");
    Menu describe("Describe Program", 7);
    Menu reports("Reports");
    Menu search("Search Directory");
    
    //Reports submenus
    Menu reportFilm("Title ordered report", 1);
    Menu reportRank("Rank ordered report", 2);
    
    //Search submenus
    Menu searchTitle("Title search", 3);
    Menu searchWord("Key-word search", 4);
    Menu searchStudio("Studio search", 5);
    Menu searchMonth("Release month search", 6);
    
    reports.addSub(reportFilm);
    reports.addSub(reportRank);
    reports.addSub(back);
    
    search.addSub(searchTitle);
    search.addSub(searchWord);
    search.addSub(searchStudio);
    search.addSub(searchMonth);
    search.addSub(back);
    
    mainMenu.addSub(describe);
    mainMenu.addSub(reports);
    mainMenu.addSub(search);
    mainMenu.addSub(back);
    
    mainMenu.run(database);
}
