//
//  Partie.cpp
//  GestionNew
//
//  Created by Kevin on 19/06/2018.
//  Copyright © 2018 Kevin. All rights reserved.
//

#include "Partie.hpp"

using namespace std;

Partie::Partie(DonneesSave data){
    
   this->name = data.nomPartie;
   this->num = data.idPartie;
   this->monPerso.setName(data.nomHeros);
   this->monPerso.setLevel(data.levelHeros);

}

Partie::Partie(string name, int num){
    this->name = name;
    this->num = num;
    string nom;
    
    cout << "Création du personnage veuillez choisir un nom -> " ;
    cin >> nom ;
    this->monPerso.setName(nom);
    
}

Partie::~Partie(){
        
    
}

int Partie::getNum(){
    
    return num;
}

string Partie::getName(){
    
    return name;
}

void Partie::setName(string nom){

    name = nom;

}

void Partie::setNum(int num){
    this->num = num;


}

void Partie::getPerso(){

    monPerso.getStats();
}

void Partie::up(){
    
    monPerso.augmenterLevel();
}

DonneesSave Partie::getDonnees(){
    
    save.nomPartie = getName();
    save.idPartie = getNum();
    save.nomHeros = monPerso.getName();
    save.levelHeros = monPerso.getLevel();
    
    return save;
}



