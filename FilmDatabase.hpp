//
//  @file FilmDatabase.hpp
//  FilmMenu
//
//  @author Zachary Duncan on 4/2/18.
//  Copyright © 2018 Zachary Duncan. All rights reserved.
//

#ifndef FilmDatabase_hpp
#define FilmDatabase_hpp

#include <stdio.h>
#include "BinarySearchTree.h"
#include "Film.hpp"

class FilmDatabase {
private:
    const string FILE_NAME = "Films2015.csv";
    const int MAX_SEARCH_TERMS = 5;
    
    BinarySearchTree<Film> database;
    
    /* @param This serves as a reusable template for all search methods */
    void search(string byTerm, void (*visit)(Film &));
    
public:
    /* @param Initializes FilmDatabase object and calls createDatabase() */
    FilmDatabase();
    
    /* @param Creates a database using a Binary Search Tree that stores films
              read from a .csv file*/
    void createDatabase();
    
    /* @param Finds and displays all films in the database in order by title */
    void displayByTitle();
    
    /* @param Finds and displays all films in the database in order by rank */
    void displayByRank();
    
    /* @param Finds and displays the film (if one is found) that matches the given title */
    void searchByTitle();
    
    /* @param Finds and displays the films (if any are found) that match the given keyword(s) */
    void searchByKeyword();
    
    /* @param Finds and displays the films (if any are found) that match the given studio */
    void searchByStudio();
    
    /* @param Finds and displays the films (if any are found) that match the given release month */
    void searchByMonth();
    
    /* @param Displays an explanation of the over-all purpose and useage of the program */
    void displayDescription();
};

#endif /* FilmDatabase_hpp */
