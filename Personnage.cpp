//
//  Personnage.cpp
//  GestionNew
//
//  Created by Kevin on 22/06/2018.
//  Copyright © 2018 Kevin. All rights reserved.
//

#include "Personnage.hpp"

using namespace std;

Personnage::Personnage(){
    
    level = 1;
  
}

Personnage::~Personnage(){
    
    
}

string Personnage::getName(){
    
    return name;
}

void Personnage::setName(string nom){
    name = nom;

}

void Personnage::augmenterLevel(){
    
    level = level +1;

}

void Personnage::getStats(){
    cout << name << " Lvl " << level <<endl;

}

int Personnage::getLevel(){

    return level;
}

void Personnage::setLevel(int lvl){
    
    level = lvl;

}

