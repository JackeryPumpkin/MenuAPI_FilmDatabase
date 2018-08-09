//
//  @file MenuUtilities.hpp
//  MenuUtilities
//
//  @author Zachary Duncan on 3/1/18.
//  Copyright © 2018 Zachary Duncan. All rights reserved.
//

#ifndef MenuUtilities_hpp
#define MenuUtilities_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

class MenuUtilities {
private:
    
public:
    /* @param Presents user with yes/no key and custom prompt */
    char presentYesNo(string prompt);
    
    /* @param Presents user with an indefinite key-set prompt */
    string presentSet(string set[], unsigned long setSize);
    
    /* @param Presents user with an indefinite key-set with custom prompt */
    string presentSet(string set[], unsigned long setSize, string prompt);
    
};

#endif /* MenuUtilities_hpp */
