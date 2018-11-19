//
//  Personnage.hpp
//  GestionNew
//
//  Created by Kevin on 22/06/2018.
//  Copyright © 2018 Kevin. All rights reserved.
//

#ifndef Personnage_hpp
#define Personnage_hpp

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;
class Personnage{
    
public:
    Personnage();
    ~Personnage();
    string getName();
    int getLevel();
    void setLevel(int lvl);
    void setName(string nom);
    void getStats();
    void augmenterLevel();
    
    
private:
    string name;
    int level;
    
    
};

#endif /* Personnage_hpp */
