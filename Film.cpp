//
//  @file Film.cpp
//  FilmMenu
//
//  Created by Zachary Duncan on 3/26/18.
//  @author Zachary Duncan. All rights reserved.
//

#include "Film.hpp"
#include <iostream>
#include <iomanip>


Film::Film(): title("title"), rank(0), studio("studio"), totalGross(0.0), totalTheaters(0), releaseDate("releaseDate"), openingTheaters(0), openingGross(0.0)  {
    
}

Film::Film(int rank, string title, string studio, double totalGross, int totalTheaters, double openingGross, int openingTheaters, string releaseDate):
            title(title), rank(rank), studio(studio), totalGross(totalGross), totalTheaters(totalTheaters), releaseDate(releaseDate), openingGross(openingGross), openingTheaters(openingTheaters) {
    
}

int Film::getRank() const {
    return rank;
}
string Film::getTitle() const {
    return title;
}
string Film::getStudio() const {
    return studio;
}
double Film::getTotalGross() const {
    return totalGross;
}
int Film::getTotalTheaters() const {
    return totalTheaters;
}
double Film::getOpeningGross() const {
    return openingGross;
}
int Film::getOpeningTheaters() const {
    return openingTheaters;
}
string Film::getReleaseDate() const {
    return releaseDate;
}

//Operator Overloading
bool Film::operator>(const Film &r) const {
    char left = this->getTitle()[0];
    char right = r.getTitle()[0];
    bool isGreater = false;
    bool done = false;
    int i = 0;

    while (!done) {
        done = true;

        if (left > right) {
            isGreater = true;
        } else if (left == right) {
            i++;

            if (i == this->getTitle().length() || i == r.getTitle().length()) {
                isGreater = this->getTitle().length() > r.getTitle().length();
            } else {
                left = this->getTitle()[i];
                right = r.getTitle()[i];
                done = false;
            }
        } else {
            isGreater = false;
        }
    }

    return isGreater;
}

bool Film::operator<(const Film &r) const {
    char left = this->getTitle()[0];
    char right = r.getTitle()[0];
    bool isLesser = false;
    bool done = false;
    int i = 0;
    
    while (!done) {
        done = true;
        
        if (left < right) {
            isLesser = true;
        } else if (left == right) {
            i++;
            
            if (i == this->getTitle().length() || i == r.getTitle().length()) {
                isLesser = this->getTitle().length() < r.getTitle().length();
            } else {
                left = this->getTitle()[i];
                right = r.getTitle()[i];
                done = false;
            }
        } else {
            isLesser = false;
        }
    }
    
    return isLesser;
}

bool Film::operator==(const Film &r) const {
    return this->getTitle() == r.getTitle();
}

bool Film::operator!=(const Film &r) const {
    return this->getTitle() != r.getTitle();
}

ostream& operator<<(ostream &out, const Film f) {
    out << fixed << f.getRank() << " - " << f.getTitle() << " - " << f.getStudio() << " - "
     << std::setprecision(2)<< f.getTotalGross() << " - " << f.getTotalTheaters() << " - "
     << std::setprecision(2)<< f.getOpeningGross() << " - " << f.getOpeningTheaters() << " - "
    << f.getReleaseDate();
    
    return out;
}
