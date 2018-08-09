//
//  @file FilmDatabase.cpp
//  FilmMenu
//
//  @author Zachary Duncan on 4/2/18.
//  Copyright © 2018 Zachary Duncan. All rights reserved.
//

#include "FilmDatabase.hpp"
#include <iostream>
#include <fstream>


//Gloabl functions and variables
const int MAX_SEARCH_TERMS = 5;
int rankToFind = 1;
string searchTerm;
bool resultFound;


void displayFilm(Film &film) {
    cout << film << endl;
}

void displayRank(Film &film) {
    if (film.getRank() == rankToFind) {
        cout << film << endl;
    }
}

void displayTitle(Film &film) {
    if (!resultFound) {
        string titleTerms[10];
        string searchTerms[MAX_SEARCH_TERMS];
        int j = 0;
        
        for (int i = 0; i < searchTerm.length(); i++) {
            if (searchTerm[i] == ' ') {
                if (i != searchTerm.length() - 1) {
                    j++;
                    if (j > MAX_SEARCH_TERMS) {
                        break;
                    }
                }
            } else {
                if (isalpha(searchTerm[i])) {
                    searchTerms[j] += toupper(searchTerm[i]);
                }
            }
        }
        
        int searchWordCount = j + 1;
        j = 0;
        
        for (int i = 0; i < film.getTitle().length(); i++) {
            if (film.getTitle()[i] == ' ') {
                if (i != film.getTitle().length() - 1) {
                    j++;
                }
            } else {
                if (isalpha(film.getTitle()[i])) {
                    titleTerms[j] += toupper(film.getTitle()[i]);
                }
            }
        }
        
        int titleWordCount = j + 1;
        j = 0;
        
        for (int i = 0; i < titleWordCount; i++) {
            if (titleTerms[i] == searchTerms[j]) {
                j++;
            }
        }
        
        if (j == searchWordCount) {
            cout << film << endl;
            resultFound = true;
        }
    }
}

void displayKeyword(Film &film) {
    string titleTerms[10];
    string searchTerms[MAX_SEARCH_TERMS];
    int j = 0;
    
    for (int i = 0; i < searchTerm.length(); i++) {
        if (searchTerm[i] == ',') {
            if (i != searchTerm.length() - 1) {
                j++;
                if (j > MAX_SEARCH_TERMS) {
                    break;
                }
            }
        } else {
            if (isalpha(searchTerm[i])) {
                searchTerms[j] += toupper(searchTerm[i]);
            }
        }
    }
    
    int searchWordCount = j + 1;
    j = 0;
    
    for (int i = 0; i < film.getTitle().length(); i++) {
        if (film.getTitle()[i] == ' ') {
            if (i != film.getTitle().length() - 1) {
                j++;
            }
        } else {
            if (isalpha(film.getTitle()[i])) {
                titleTerms[j] += toupper(film.getTitle()[i]);
            }
        }
    }
    
    int titleWordCount = j + 1;
    
    for (int i = 0; i < titleWordCount; i++) {
        for (int k = 0; k < searchWordCount; k++) {
            if (titleTerms[i] == searchTerms[k]) {
                cout << film << endl;
                resultFound = true;
                return;
            }
        }
    }
}

void displayStudio(Film &film) {
    string newSearchTerm;
    string newStudio;
    
    for (int i = 0; i < searchTerm.length(); i++) {
        if (isalpha(searchTerm[i])) {
            newSearchTerm += toupper(searchTerm[i]);
        }
    }
    
    for (int i = 0; i < film.getStudio().length(); i++) {
        if (isalpha(film.getStudio()[i])) {
            newStudio += toupper(film.getStudio()[i]);
        }
    }
    
    if (newStudio == newSearchTerm) {
        cout << film << endl;
        resultFound = true;
    }
}

void displayMonth(Film &film) {
    string newDate;
    string newSearchTerm = searchTerm[0] == '0' ? string(1, searchTerm[1]) : searchTerm;
    
    for (int i = 0; i < film.getReleaseDate().length(); i++) {
        if (film.getReleaseDate()[i] == '/') {
            break;
        } else {
            newDate += film.getReleaseDate()[i];
        }
    }
    
    if (newDate == newSearchTerm) {
        cout << film << endl;
        resultFound = true;
    }
}




//Class constructors and methods
FilmDatabase::FilmDatabase() {
    createDatabase();
}

void FilmDatabase::createDatabase() {
    string line;
    int field = 0;
    string fields[8];
    ifstream filmsFile(FILE_NAME);
    
    if (filmsFile.is_open()) {
        while (getline(filmsFile, line)) {
            for (int i = 0; i < line.length(); i++) {
                if (line[i] == ',') {
                    field++;
                } else {
                    fields[field] += line[i];
                }
            }
            
            field = 0;
            
            Film film(stoi(fields[0]), fields[1], fields[2], stod(fields[3]),
                      stoi(fields[4]), stod(fields[5]), stoi(fields[6]), fields[7]);
            database.add(film);
            
            for (int i = 0; i < 8; i++) {
                fields[i] = "";
            }
        }
    } else {
        cout << "File was not found. Database not built." << endl;
    }
    
    filmsFile.close();
}

void FilmDatabase::displayByTitle() {
    cout << endl << endl  << "||==== Report: Films By Title ====||" << endl << endl;
    database.inorderTraverse(displayFilm);
}

void FilmDatabase::displayByRank() {
    cout << endl << endl  << "||==== Report: Films By Rank ====||" << endl << endl;
    
    for (int i = 1; i <= database.getNumberOfNodes(); i++) {
        rankToFind = i;
        database.inorderTraverse(displayRank);
    }
}

void FilmDatabase::search(string category, void (*visit)(Film &)) {
    searchTerm = "";
    resultFound = false;
    bool valid = false;
    
    
    cin.ignore(INT_MAX, '\n');
    while (!valid) {
        cout << "Search By " << category << ": ";
        getline(cin, searchTerm);
        cout << endl << searchTerm << " is " << searchTerm.length() << " long" << endl;
        
        if (searchTerm[0] == ' ') { cout << "Search cannot begin with a space." << endl; }
        else if (searchTerm == "") { cout << "No search term was given." << endl; }
        else { valid = true; }
    }
    
    cout << endl << endl  << "||======= Search By " << category << " =======||" << endl << endl;
    
    database.inorderTraverse(visit);
    
    if (!resultFound) { cout << "No result found!" << endl; }
}

void FilmDatabase::searchByTitle() {
    search("Title", displayTitle);
}

void FilmDatabase::searchByKeyword() {
    search("Keyword", displayKeyword);
}

void FilmDatabase::searchByStudio() {
    search("Studio", displayStudio);
}

void FilmDatabase::searchByMonth() {
    search("Release Month", displayMonth);
}

void FilmDatabase::displayDescription() {
    cout << endl << endl  << "||==== Description of Program ====||" << endl << endl
    << "This program demonstrates the manipulation"  << endl
    << "of a binary search tree and the use of a" << endl
    << "pseudo-visitor programming pattern to"<< endl
    << "display the contents of specific nodes" << endl
    << "in the tree as requested by the user." << endl;
}





