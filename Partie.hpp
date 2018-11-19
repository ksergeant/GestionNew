//  Partie.hpp
//  GestionNew
//
//  Created by Kevin on 19/06/2018.
//  Copyright © 2018 Kevin. All rights reserved.
//

#ifndef Partie_hpp
#define Partie_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include "Personnage.hpp"

using namespace std;

struct DonneesSave {
    string nomPartie;
    int idPartie;
    string nomHeros;
    int levelHeros;
    
};


class Partie{
    
public:
    Partie(DonneesSave data);
    Partie(string name,int num);
    ~Partie();
    int getNum();
    void setNum(int num);
    string getName();
    void setName(string nom);
    void getPerso();
    void up();
    DonneesSave getDonnees();
    
private:
    int num;
    string name;
    Personnage monPerso;
    DonneesSave save;
    
   
};


#endif /* Partie_hpp */
