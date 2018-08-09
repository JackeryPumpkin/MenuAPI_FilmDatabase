//
//  @file MenuUtilities.cpp
//  MenuUtilities
//
//  @author Zachary Duncan on 3/1/18.
//  Copyright © 2018 Zachary Duncan. All rights reserved.
//

#include "MenuUtilities.hpp"

char MenuUtilities::presentYesNo(string prompt) {
    char response;
    
    cout << prompt << endl;
    cin >> response;
    
    while (toupper(response) != 'Y' && toupper(response) != 'N') {
        cin >> response;
    }
    
    return response;
}

string MenuUtilities::presentSet(string set[], unsigned long setSize) {
    string response;
    bool isValid = false;
    
    cin >> response;
    
    while (!isValid) {
        for (int i = 0; i < response.length(); i++) {
            response[i] = toupper(response[i]);
        }
        
        for (int i = 0; i < setSize; i++) {
            if (response == set[i]) {
                isValid = true;
            }
        }
        
        if (!isValid) {
            cout << "Invalid Selection, Try Again: ";
            cin >> response;
        }
    }
    
    return response;
}

string MenuUtilities::presentSet(string set[], unsigned long setSize, string prompt) {
    cout << prompt;
    return presentSet(set, setSize);
}
