//
//  Jeu.hpp
//  GestionNew
//
//  Created by Kevin on 19/06/2018.
//  Copyright © 2018 Kevin. All rights reserved.
//

#ifndef Jeu_hpp
#define Jeu_hpp

#include <stdio.h>
#include "Partie.hpp"
#include <vector>
#include <memory>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <limits>
#include <unistd.h>

using namespace std;



class Jeu{
    
    public:
        Jeu();
        ~Jeu();
        void ajoutPartie();
        void ajoutPartie(DonneesSave data);
    
        void supprimerPartie();
        void afficherPartie();
    
        void sauvegardePartie();
        void chargerPartie();
    
        DonneesSave getSave(int i);
    
        void purge();
        bool getEtat();
        void Lancement();
        void Stop();
        void afficheMenu();
        void GameLoop();
    
    
    
    private:
        bool etatDuJeu;
        vector <shared_ptr<Partie>> lesParties;
        string const nomFichier="/Users/Kevin/Desktop/Programmation/C++/GestionNew/GestionNew/sauvegarde";
        
    
};

#endif /* Jeu_hpp */
