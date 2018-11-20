//
//  main.cpp
//  GestionNew
//
//  Created by Kevin on 19/06/2018.
//  Copyright © 2018 Kevin. All rights reserved.
//

#include <iostream>
#include "Jeu.hpp"

using namespace std;


void purge(){
    system("clear");
}



int main(int argc, const char * argv[]) {

 cout << "Gestion New 1.0 by MOKS\n";
    
    
    Jeu monJeu;
    
    monJeu.afficherPartie();
    monJeu.chargerPartie();
    system("clear");
    //monJeu.supprimerPartie();
    
   // monJeu.ajoutPartie();
    //monJeu.ajoutPartie();
    //monJeu.ajoutPartie();

    monJeu.afficherPartie();
    //monJeu.sauvegardePartie();
    //monJeu.supprimerPartie();
    //monJeu.afficherPartie();
     //monJeu.sauvegardePartie();
   // monJeu.chargerPartie();
    
    //monJeu.afficherPartie();
    
    cout <<endl;
    return 0;
}
