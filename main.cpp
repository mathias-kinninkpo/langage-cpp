#include <iostream>
#include <vector>
#include <fstream>
#include "cptGestion.h"



using namespace std;


int main()
{
    HandleSkills gestion;

    string ch, file_name;

    cout << "Entrer le chemin du fichier a utiliser pour les donnees:  ";

    //getline(cin , file_name);
    file_name = input(file_name);

    if(gestion.load_data_from_file(file_name)){
        //gestion.create_professionnel();
        auto a = 1;

        std::fstream file;
        file.open("Texte.txt.txt",ios::in);
        if(file.is_open()){
            while(getline(file,ch)){
                cout << ch << endl;
            }
        }else{
            std::cout << "Bienvenue sur notre application de gestion des competences!\n" << std::endl;
        }
        while (a==1){
            string name, surname,competence;
            auto opperation = gestion.menu();
            switch(opperation){
            case 1:
               {
                    system("cls");
                    gestion.print_competences();
                    break;
               }
            case 2:
               {
                    system("cls");
                    gestion.print_profiles();
                    break;
               }
            case 3:
               {
                    system("cls");
                    gestion.print_professionels();
                    break;
               }
            case 4:
                {
                    string name;
                    system("cls");
                    cout << "Entrer le nom du profile: ";
                    name = input(name);
                    gestion.print_competences_of_profile(name);
                    break;
                }
            case 5:
                {
                    system("cls");
                    cout << "Entrer le nom du professionnel: ";
                    name = input(name);
                    cout << "Entrer le prenom du professionnel :";
                    surname = input(surname);
                    gestion.print_competences_of_professionnel(name,surname);
                    break;
                }
            case 6:
                {
                    system("cls");
                    cout << "Entrer le nom du profile: ";
                    name = input(name);
                    gestion.print_professionnel_of_profile(name);
                    break;
                }
            case 7:
                {
                    system("cls");
                    cout << "Entrer le nom du professionnel a qui vous voulez ajouter de competence: ";
                    name = input(name);
                    cout << "Entrer son prenom:";
                    surname = input(surname);
                    Professionnel pro(name,surname);
                    if(!gestion.is_professionnel(pro,0)){
                        break;
                    }
                    cout <<"Entrer la competence dont vous voulez ajouter a " << name << " " << surname << ": ";
                    getline(cin , competence);
                    if(gestion.add_competence_to_professionnel(pro,competence)){
                        cout << "L'ajout a ete effectue avec succes" << endl;
                        gestion.update_profile();
                    }
                    else
                        cout << "Une erreur est survenue lors de l'ajout" << endl;
                    break;
                }
            case 8:
                {
                    system("cls");
                    cout << "Entrer le nom du profile auquel vous voulez ajouter de competence: ";
                    name = input(name);
                    Profile pfl(name);
                    if(!gestion.is_profile(pfl,0)){
                        break;
                    }
                    cout <<"Entrer la competence dont vous voulez ajouter au profile " << name << ": ";
                     competence = input(competence);
                    if(gestion.add_competence_to_profile(pfl,competence)){
                        cout << "L'ajout a ete effectue avec succes" << endl;
                        gestion.update_profile();
                    }

                    else
                        cout << "Une erreur est survenue lors de l'ajout" << endl;
                    break;
                }
            case 9:
               {
                   system("cls");
                    cout << "Entrer le nom du professionnel a qui vous voulez retirer de competence: ";
                    name = input(name);
                    cout << "Entrer le son prenom  :";
                    surname = input(surname);
                    Professionnel pro(name,surname);
                    cout <<"Entrer la competence dont vous voulez retirer de la liste des competence de " << name << " " << surname << ": ";
                    competence = input(competence);
                    if(gestion.remove_competence_from_professionnel(pro,competence)){
                        cout << "la suppression a ete effectue avec succes" << endl;
                        gestion.update_profile();
                    }

                    else
                        cout << "Une erreur est survenue lors de la suppression!" << endl;
                    break;
               }
            case 10:
                {
                    system("cls");
                    cout << "Entrer le nom du profile duquel vous voulez retirer de competence: ";
                    name = input(name);
                    Profile pfl(name);
                    cout <<"Entrer la competence dont vous voulez retierer de la liste des competences du profile " << name << ": ";
                    competence = input(competence);
                    if(gestion.remove_competence_from_profile(pfl,competence)){
                        cout <<" la suppression a ete effectue avec succes" << endl;
                        gestion.update_profile();
                    }

                    else
                        cout <<"Une erreur est survenue lors de la suppression!"<< endl;
                    break;
                }
            case 11:
                {
                    system("cls");
                    if(gestion.create_professionnel()){
                        gestion.update_profile();
                    }
                }
                break;
            case 12:
                {
                    system("cls");
                    if(gestion.create_profile()){
                        gestion.update_profile();
                    }
                    break;
                }
            case 13:
                {
                    system("cls");
                    int choice;
                    cout << "\n\nLe contenue du " << file_name << " sera modifie\n1. Sauvegarder\n2. Annuler\nEntrer le chiffre:";
                    cin >> choice;
                    while(choice < 1 || choice > 2){
                        cout << "Vous devez choisir 1 ou 2\nMerci de reesayer:";
                        cin >> choice;
                    }
                    if(choice == 1){
                        gestion.save_data(file_name);
                        cout << "Sauvegarde effectuee avec succes!!\nMerci d'avoir utilise notre service!\n\n";
                        return 0;
                    }
                    break;
                }
            case 14:
                {
                    system("cls");
                    int choice;
                    cout << "\nLes modification ne seront pas enregistrees \n1. Quitter quand meme\n2. Annuler\nEntrer le chiffre:";
                    cin >> choice;
                    while(choice < 1 || choice > 2){
                        cout << "Vous devez choisir 1 ou 2\nMerci de reesayer:";
                        cin >> choice;
                    }
                    if(choice == 1){
                        cout << "Merci d'avoir utilise notre service!\n\n";
                        return 0;
                    }
                    cout << "Vous pouvez choisir l'option 11 pour sauvegarder avant de quitter!\n";

                }
            default:
                system("cls");
                cout << "Vous devez choisir entre 1 et 14\nMerci de reesayer :";


            }

        }

    }
    else{
        cout << "\n\nUne erreur est survenue lors de l'ouverture du fichier\nVeuillez revoir le nom du fichier entre\n\n";
    }
    return 0;

}
