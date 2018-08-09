//
//  @file Film.hpp
//  FilmMenu
//
//  @author Zachary Duncan on 3/26/18.
//  Copyright © 2018 Zachary Duncan. All rights reserved.
//

#ifndef Film_hpp
#define Film_hpp

#include <iostream>

using namespace std;


//@class Film
class Film {
private:
    int rank;
    string title;
    string studio;
    double totalGross;
    int totalTheaters;
    double openingGross;
    int openingTheaters;
    string releaseDate;
    
public:
    /* @param Creates an empty default film */
    Film();
    /* @param Creates a film from the given parameters */
    Film(int rank, string title, string studio, double totalGross, int totalTheaters, double openingGross, int openingTheaters, string releaseDate);
    
    //Accessers
    /* @param Accesses the private rank member varuable
     @return returns the rank value */
    int getRank() const;
    
    /* @param Accesses the private title member varuable
     @return returns the title value */
    string getTitle() const;
    
    /* @param Accesses the private studio member varuable
     @return returns the studio value */
    string getStudio() const;
    
    /* @param Accesses the private totalGross member varuable
     @return returns the totalGross value */
    double getTotalGross() const;
    
    /* @param Accesses the private totalTheaters member varuable
     @return returns the totalTheaters value */
    int getTotalTheaters() const;
    
    /* @param Accesses the private openingGross member varuable
     @return returns the openingGross value */
    double getOpeningGross() const;
    
    /* @param Accesses the private openingTheaters member varuable
     @return returns the openingTheaters value */
    int getOpeningTheaters() const;
    
    /* @param Accesses the private releaseDate member varuable
     @return returns the releaseDate value */
    string getReleaseDate() const;
    
    //Operator Overloading
    /* @param Compares one Film with another
     @return returns the truth of the calling object's title being greater. */
    bool operator>(const Film &right) const ;
    
    /* @param Compares one Film with another
     @return returns the truth of the calling object's title being lesser. */
    bool operator<(const Film &right) const ;
    
    /* @param Compares one Film with another
     @return returns the truth of the calling object's title being equal to the right. */
    bool operator==(const Film &right) const ;
    
    /* @param Compares one Film with another
     @return returns the truth of the calling object's title being unequal to the right. */
    bool operator!=(const Film &right) const ;
    
    /* @param Creates a non-membe friendship to ostream so that a Film's information
              can be easily printed to the console
     @return returns the resulting ostream containing the Film's info */
    friend ostream& operator<<(ostream &out, Film f);
};

#endif /* Film_hpp */
