//
//  Jeu.cpp
//  GestionNew
//
//  Created by Kevin on 19/06/2018.
//  Copyright © 2018 Kevin. All rights reserved.
//

#include "Jeu.hpp"

Jeu::Jeu(){
    
    cout << "\n### Création du jeu ###"<<endl;
    this->etatDuJeu = false;
}

Jeu::~Jeu(){
    
}

void Jeu::Lancement(){
    etatDuJeu = true;
    
}

void Jeu::Stop(){
    
    etatDuJeu = false;
}

void Jeu::ajoutPartie(){
    cout << "\n->Ajout de partie ";
    string name;
    cout << "Nom de la partie ? ";
    cin >> name;
    // shared_ptr pointeur intelligent et make_shared remplace le new
  
    shared_ptr<Partie> ptr(make_shared<Partie>(name,lesParties.size()+1));
    
    lesParties.push_back(ptr);
    
    
}

void Jeu::ajoutPartie(DonneesSave data){
    
    shared_ptr<Partie> ptr(make_shared<Partie>(data));
    
    lesParties.push_back(ptr);
}

void Jeu::supprimerPartie(){
    int num,num2 = 0;
    bool find = false;
    cout << "\nSuppression de la partie ? id : ";
    cin >> num;
    for (int i = 0; i<lesParties.size();i++){
        
        if(num == lesParties[i]->getNum()){
            lesParties.erase(lesParties.begin()+i);
            num2 = i; //position dans le vector donc num -1
            find = true;
        }
        
    }
    
    // si la suppression fonctionne on met à jour les id dans le vector
    if (find==true && lesParties.size()>0){
        for(int k = num2; k<lesParties.size();k++){
            
            lesParties[k]->setNum(k+1);
        }
    
    }
    
   
}

void Jeu::afficherPartie(){
    cout << "\n### Affichage des parties ###"<<endl;
    if(lesParties.size()==0){
        cout << "->Aucune Partie";
    }
    else{
        for(int i = 0; i<lesParties.size();i++){
            cout << "Partie nom : " << lesParties[i]->getName()<<" id : " << lesParties[i]->getNum()<<endl;
            cout << "Héros " ;
            lesParties[i]->getPerso() ;
        }
    }
    
}

DonneesSave Jeu::getSave( int i){
    
    DonneesSave saveAll;
    
          saveAll =  lesParties[i]->getDonnees();
            
    return saveAll;
}



void Jeu::sauvegardePartie(){
    cout << "-> Sauvegarde des données" << endl << endl;
    
    ofstream monFlux(nomFichier.c_str(),ios::out | ios::trunc ); // écriture
    
    DonneesSave data;
    
    if(monFlux){
        
        for(int i = 0; i<lesParties.size();i++){
            
            data = Jeu::getSave(i);
            if(i==lesParties.size()-1){
                monFlux << data.nomPartie <<" "<< data.idPartie <<" "<< data.nomHeros <<" "<< data.levelHeros;
            }
            else{
                monFlux << data.nomPartie <<" "<< data.idPartie <<" "<< data.nomHeros <<" "<< data.levelHeros <<endl;
            }
        }
        
        monFlux.close();
    }
    
    else{
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    }
    
    
}



void Jeu::chargerPartie(){
    cout << "\n-> Chargement des données" << endl << endl;
    
    ifstream monFlux(nomFichier.c_str(), ios::in); // Lecture
        
        DonneesSave data;
        
        if(monFlux){
            
            int nbLignes = 0;
            
            do{
                monFlux >> data.nomPartie >> data.idPartie >> data.nomHeros >> data.levelHeros;
                if (data.nomPartie == ""){
                    cout <<"Aucune partie a charger" <<endl;
                }
                else{
                Jeu::ajoutPartie(data);
                    nbLignes++;
                }
                
                    
            }while(monFlux.ignore(numeric_limits<int>::max(), '\n'));
                
            
            cout << "Le fichier contient " << nbLignes << "lignes";
            /*
            for(int i = 0; i<lesParties.size();i++){
                
               
             
                
            }
            */
            monFlux.close();
        }

    
    else{
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    }


}

void Jeu::purge(){
    system("clear");
}

bool Jeu::getEtat(){
    
    return etatDuJeu;
}
