#include <iostream>
#include <algorithm>
#include <fstream>
#include "professionnel.h"
#include "profile.h"
#include "cptGestion.h"

std::string input(std::string var){
    while(var==""){
        getline(std::cin,var);
    }
    return var;
}

HandleSkills::HandleSkills(){}

std::string HandleSkills::strip_string(std::string str){
    str.erase(std::remove(str.begin(), str.end(),'\t'), str.end());
    return str;
}
bool HandleSkills::create_professionnel(){
    Professionnel professionnel;
    std::string name, surname, competence;
    int nb;
    std::cout << "\nEntrer le nom du professionnel: ";
    name = input(name);
    std::cout << "\nEntrer le prenom du professionnel: ";
    surname = input(surname);
    professionnel.set_firstname(surname);
    professionnel.set_lastname(name);
    if(is_professionnel(professionnel,1)){
        std::cout << "Le professionnel "<< name << " " << surname << " existe deja!\n";
        return false;
    }
    std::cout << "\n\nEntrer le nombre de competences du professionnel " << name << " " << surname << ":";
    std::cin >> nb;
    professionnel.set_nb_competences(nb);
    for(int i=0; i<nb; i++){
        competence = "";
        if(i==0){
            std::cout << "Entrer la premiere competence: ";
            competence = input(competence);
            add_competences(competence);
        }
        else{
            std::cout << "Entrer la "<<i+1<<"eme competence: ";
            competence = input(competence);
            add_competences(competence);
        }
        professionnel.add_competences(competence);
    }
    add_professionnel(professionnel);
    std::cout << "Le professionnel "<< name << " " << surname << " a ete cree avec succes!\n";
    return true;

}

bool HandleSkills::create_profile(){
    std::string name, competence;
    int nb;
    Profile profile;
    std::cout << "\n\nEntrer le nom du profile: ";
    name = input(name);
    profile.set_profile_name(name);
    if(is_profile(profile,1)){
        std::cout << "Le profile "<< name << " existe deja!\n";
        return false;
    }
    std::cout << "\n\nEntrer le nombre de competences du profile " << name << ": ";
    std::cin >> nb;
    profile.set_nb_competences(nb);
    for(int i=0; i<nb; i++){
        competence = "";
        if(i==0){
            std::cout << "Entrer la premiere competence:";
            competence = input(competence);
            add_competences(competence);
        }
        else{
            std::cout << "Entrer la "<< i+1 <<"eme competence:";
            competence = input(competence);
            add_competences(competence);
        }
        profile.add_profile_compentence(competence);
    }
    add_profile(profile);
    std::cout << "Le profile "<< name << " a ete cree avec succes!\n";
    return true;


}
void HandleSkills::add_competences(std::string competence){
    competences.push_back(competence);
}
void HandleSkills::add_professionnel(Professionnel professionnel){
    professionnels.push_back(professionnel);
}

void HandleSkills::add_profile(Profile profile){
    profiles.push_back(profile);
}

bool HandleSkills::is_profile(Profile& profile,int is_create = 0){
    for(auto &pfl : profiles){
        if (pfl.get_profile_name() == profile.get_profile_name()){
            return true;
        }
    }
    if(is_create == 0){
        std::cout << "Le profile " << profile.get_profile_name() << " n'est pas dans la liste des profiles !" << std::endl;
    }
    return false;
}

bool HandleSkills::is_professionnel(Professionnel& professionnel,int is_create = 0){
    for (auto &pro : professionnels){
        if(pro.get_lastname() == professionnel.get_lastname()  && pro.get_firstname() == professionnel.get_firstname()){
            return true;
        }
    }
    if(is_create == 0)
        std::cout << "Le professionnel " << professionnel.get_lastname() << " " << professionnel.get_firstname() << " n'est pas dans la liste des professionel " << std::endl;
    return false;
}

bool HandleSkills::is_competence_in_professionnel(Professionnel& professionnel, std::string competence){
    for (auto &cpt : professionnel.get_competences()){
        if(cpt == competence){
            return true;
        }
    }
    return false;
}

bool HandleSkills::is_competence_in_profile(Profile& profile, std::string competence){
    for (auto &cpt : profile.get_profile_competences()){
        if (cpt == competence){
            return true;
        }
    }
    return false;
}

std::vector<std::string>& HandleSkills::get_competences(){
    return competences;
}
std::vector<Professionnel>& HandleSkills::get_professionnels(){
    return professionnels;
}
std::vector<Profile>& HandleSkills::get_profiles(){
    return profiles;
}


std::vector<std::string> HandleSkills::get_profile_names(std::vector<Profile> pfls){
    std::vector<std::string> profile_names;
    for (auto pfl : pfls){
        profile_names.push_back(pfl.get_profile_name());
    }
    return profile_names;
}

void HandleSkills::set_profile_to_professionnel(Professionnel& pro){
        for(auto &pfl : profiles){
            bool is_profile = true;
            for (auto &cpt_pfl : pfl.get_profile_competences()){
                bool is_in = false;
                for(auto &cpt_pro : pro.get_competences()){
                    if (cpt_pro == cpt_pfl){
                        is_in = true;
                        break;
                    }
                }
                if(is_in == false){
                    is_profile = false;
                    break;
                }
            }
            if (is_profile == true){
                // set the profile of an professional
                pro.set_profile(pfl);
            }
        }
}

bool HandleSkills::add_competence_to_professionnel(Professionnel& professionnel, std::string competence){
    if(is_professionnel(professionnel)){
        for(auto &pro : professionnels){
            if (pro.get_lastname() == professionnel.get_lastname() && pro.get_firstname() == professionnel.get_firstname()){
                if(is_competence_in_professionnel(pro,competence)){
                    std::cout << "Le professionnel " << professionnel.get_lastname() << " " << professionnel.get_firstname() << "a deja la competence " << competence << std::endl;
                    return false;
                }
                pro.add_competences(competence);
                add_competences(competence);
                 return true;
            }
        }

    }
    return false;
}

bool HandleSkills::add_competence_to_profile(Profile& profile, std::string competence){
    if(is_profile(profile)){
        for(auto &pfl : profiles){
            if (pfl.get_profile_name() == profile.get_profile_name()){
                if(is_competence_in_profile(pfl,competence)){
                    std::cout << "Le profile " << profile.get_profile_name() << "a deja la competence " << competence << std::endl;
                    return false;
                }
                 pfl.add_profile_compentence(competence);
                 add_competences(competence);
                 return true;
            }
        }

    }
    return false;
}

 bool HandleSkills::remove_competence_from_profile(Profile profile, std::string competence){
    if(is_profile(profile)){
        for(auto &pfl : profiles){
            if(pfl.get_profile_name() == profile.get_profile_name()){
                if(pfl.remove_competences(competence)){
                    //competences.erase(std::remove(competences.begin(),competences.end(),competence),competences.end());
                    return true;
                }
                return false;
            }
        }
    }
    std::cout << "Le profile " <<profile.get_profile_name() << " n'existe pas dans la liste de profiles ! !\n";
    return false;
}
 bool HandleSkills::remove_competence_from_professionnel(Professionnel professionnel, std::string competence){
    if(is_professionnel(professionnel)){
        for(auto &pro : professionnels){
            if(pro.get_lastname() == professionnel.get_lastname() && pro.get_firstname() == pro.get_firstname()){
                if(pro.remove_competences(competence)){
                    //competences.erase(std::remove(competences.begin(),competences.end(),competence),competences.end());
                    return true;
                }
                return false;


            }
        }
    }
    std::cout << "Le nom " << professionnel.get_lastname() << " "  << professionnel.get_firstname() << " n'est pas dans la liste des professionnels ! !\n";
    return false;
 }

bool HandleSkills::load_data_from_file(std::string file_name){
    std::fstream myfile;
    std::string chaine, name, surname,cpt;
    int nb;
    myfile.open(file_name,std::ios::in);
    if(myfile.is_open()){
        while(getline(myfile,chaine)){
                if(chaine == "PRO:"){
                    Professionnel professionnel;
                    getline(myfile,name);
                    getline(myfile,surname);
                    professionnel.set_firstname(strip_string(surname));
                    professionnel.set_lastname(strip_string(name));
                    myfile >> nb;
                    myfile.ignore();
                    professionnel.set_nb_competences(nb);
                    for(int i=0; i<nb; i++){
                        getline(myfile,cpt);
                        professionnel.add_competences(strip_string(cpt));
                         add_competences(strip_string(cpt));
                    }
                    // set the professionnels
                    add_professionnel(professionnel);
                }
                if(chaine == "CPT:"){
                    myfile >> nb;
                    myfile.ignore();
                    for(int i=0; i< nb; i++){
                        getline(myfile,cpt);
                        // set the competences
                        add_competences(strip_string(cpt));
                    }
                }
                if(chaine == "PFL:"){
                    Profile profile;
                    getline(myfile,name);
                    profile.set_profile_name(strip_string(name));
                    myfile >> nb;
                    myfile.ignore();
                    profile.set_nb_competences(nb);
                    for(int i=0; i< nb; i++){
                        getline(myfile,cpt);
                        profile.add_profile_compentence(strip_string(cpt));
                        add_competences(strip_string(cpt));
                    }
                    // set the profiles
                    add_profile(profile);
                }
        }
        update_profile();
       // profiles.erase(std::unique(profiles.begin(),profiles.end()),profiles.end());
        /*for(auto &pro : professionnels){
            pro.get_competences().erase(std::unique(pro.get_competences().begin(),pro.get_competences().end()),pro.get_competences().end());
        }*/
        myfile.close();
        return true;
    }
    return false;
}



void HandleSkills::print_competences(){
    std::sort(competences.begin(),competences.end());
    auto cpts = std::unique(competences.begin(), competences.end());
    competences.erase(cpts,competences.end());
    if(competences.size()){
            std::cout << "\nLes competences dans l'ordre alphabetique:" << std::endl;
        for(auto cpt : competences){
            std::cout << cpt << std::endl;
        }
    }else{
        std::cout << "\nLa listed des competences est vide\n";
    }
}
void HandleSkills::print_profiles(){
    std::vector<std::string> profile_names;
    for(auto pfl : profiles){
        profile_names.push_back(pfl.get_profile_name());
    }
    std::sort(profile_names.begin(),profile_names.end());
    auto pfl = std::unique(profile_names.begin(),profile_names.end());
    profile_names.erase(pfl,profile_names.end());
    if(profiles.size() > 0){
        std::cout << "\nLes profils dans l'ordre alphabetique:" << std::endl;
        for(auto pfl : profile_names){
            std::cout << pfl << std::endl;
        }
    }else{
        std::cout << "\nLa liste des profiles est vide\n";
    }
}

void HandleSkills::print_professionels(){
    std::vector<std::string> pro_fullname;
    std::string fullname = "";
    for (auto &pro : professionnels){
        fullname += pro.get_lastname() + " " + pro.get_firstname();
        pro_fullname.push_back(fullname);
        fullname = "";
    }
    std::sort(pro_fullname.begin(),pro_fullname.end());
    // delete the duplicate
    auto last = std::unique(pro_fullname.begin(),pro_fullname.end());
    pro_fullname.erase(last,pro_fullname.end());
    if(professionnels.size()>0){
        std::cout << "\nLes noms et prenoms des professionnels dans l'ordre alphabetique:" << std::endl;
        for (auto pro_name : pro_fullname){
            std::cout << pro_name << std::endl;
        }
    }else{
        std::cout << "\nLa liste des professionnels est vide\n";
    }
}

 void HandleSkills::print_competences_of_professionnel(std::string name, std::string surname){
    bool is_pro = false;
    for (auto &pro : professionnels){
        if(pro.get_lastname() == name && pro.get_firstname() == surname){
            is_pro = true;
            //std::sort(pro.get_competences().begin(),pro.get_competences().end());
            std::cout << "Les competences de " << name << " " << surname << ":" << std::endl;
            auto tab = pro.get_competences();
            std::sort(tab.begin(),tab.end());
            tab.erase(std::unique(tab.begin(),tab.end()),tab.end());
            for(auto cpt : tab){
                std::cout << cpt << std::endl;
            }
        }
    }
    if(is_pro == false){
        std::cout << "Le nom " << name << " "  << surname << " n'est pas dans la liste des professionnels ! !\n";
    }
 }


 void HandleSkills::print_competences_of_profile(std::string name){
     bool is_pfl = false;
    for (auto pfl : profiles){
        if(pfl.get_profile_name() == name){
            is_pfl = true;
            std::cout << "Les competences du profil " << name << ":" << std::endl;
            auto tab = pfl.get_profile_competences();
            std::sort(tab.begin(),tab.end());
            tab.erase(std::unique(tab.begin(),tab.end()),tab.end());
            for(auto cpt : tab){
                std::cout << cpt << std::endl;
            }

        }
    }
    if(is_pfl == false){
        std::cout << "Le nom " << name << " n'est pas dans la liste des profiles ! !\n";
    }
 }


 void HandleSkills::print_professionnel_of_profile(std::string name){
    std::vector<std::string> pro_of_a_profile;
    std::string fullname = "";
    bool is_pfl = false;
    for(auto pfl : get_profile_names(profiles)){
        if(pfl == name){
            is_pfl = true;
            break;
        }
    }
    if(is_pfl ==  true){
        for(auto &pro : professionnels){
            for(auto prl_name : get_profile_names(pro.get_profile_pro())){
                if (prl_name == name){
                    fullname += pro.get_lastname() + " " + pro.get_firstname();
                    pro_of_a_profile.push_back(fullname);
                    fullname = "";
                }
            }
        }
        if(pro_of_a_profile.size() > 0){
            std::cout << "\nLes professionnels correspondants au profile " << name << ":" << std::endl;
            pro_of_a_profile.erase(std::unique(pro_of_a_profile.begin(),pro_of_a_profile.end()),pro_of_a_profile.end());
            std::sort(pro_of_a_profile.begin(),pro_of_a_profile.end());
            for (auto &pro : pro_of_a_profile){
                std::cout << pro << std::endl;
            }
        }
        else{
            std::cout << "Aucun professionnel dans la liste n'a le profile " << name ;
        }
    }
    else{
        std::cout << "Aucun professionnel dans la liste n'a le profile  " << name <<"\nEt d'ailleur ce profile n'existe pas dans la liste des profile\nChoisir l'option 2 pour voir la liste des profile!!\n";
    }


}
int HandleSkills::menu(){

    std::cout << "\n*  1. Lister les competences du fichier" << std::endl;
    std::cout << "*  2. Lister les profiles du fichier" << std::endl;
    std::cout << "*  3. Lister les professionnels du fichier" << std::endl;
    std::cout << "*  4. Lister les competences d'un profile specifique" << std::endl;
    std::cout << "*  5. Lister les competences d'un professionnel specifique" << std::endl;
    std::cout << "*  6. Lister les professionnels d'un profile specifique" << std::endl;
    std::cout << "*  7. Ajouter de competence a un professionnel specifique" << std::endl;
    std::cout << "*  8. Ajouter de competence a un profile specifique" << std::endl;
    std::cout << "*  9. Retirer une competence de la liste des competences d'un professionnel" << std::endl;
    std::cout << "*  10. Retirer une competence de la liste des competences d'un profile" << std::endl;
    std::cout << "*  11. Creer un professionnel" << std::endl;
    std::cout << "*  12. Creer un profile" << std::endl;
    std::cout << "*  13. Sauvegarder et quiter" << std::endl;
    std::cout << "*  14. Quiter sans sauvegarder" << std::endl;
    std::cout << "Entrer le chiffre, numero de l'operatioin:";
    int a;
    std::cin >> a;
    return a;
}

void HandleSkills::update_profile(){
    for(auto &pro : professionnels){
            pro.get_profile_pro().clear();
            set_profile_to_professionnel(pro);
            pro.get_profile_pro().erase(std::unique(pro.get_profile_pro().begin(),pro.get_profile_pro().end()),pro.get_profile_pro().end());
        }
}

void HandleSkills::save_data(std::string file_name){
     std::fstream myfile;
     myfile.open(file_name,std::ios::out);
     if(myfile.is_open()){
        for(auto &pro : professionnels){
            myfile << "PRO:\n";
            myfile << "\t" << pro.get_lastname() << "\n\t" << pro.get_firstname() << "\n";
            pro.get_competences().erase(std::remove(pro.get_competences().begin(),pro.get_competences().end(),""),pro.get_competences().end());
            std::sort(pro.get_competences().begin(),pro.get_competences().end());
            pro.get_competences().erase(std::unique(pro.get_competences().begin(),pro.get_competences().end()),pro.get_competences().end());
            myfile << "\t" << pro.get_competences().size() << std::endl;
            for(auto &cpt_pro : pro.get_competences()){
                myfile << "\t" << cpt_pro << std::endl;
            }
        }
        for(auto &pfl : profiles){
            pfl.get_profile_competences().erase(std::remove(pfl.get_profile_competences().begin(),pfl.get_profile_competences().end(),""),pfl.get_profile_competences().end());
            std::sort(pfl.get_profile_competences().begin(),pfl.get_profile_competences().end());
            pfl.get_profile_competences().erase(std::unique(pfl.get_profile_competences().begin(),pfl.get_profile_competences().end()),pfl.get_profile_competences().end());
            myfile << "PFL:\n\t" << pfl.get_profile_name() << "\n\t" << pfl.get_profile_competences().size()<< std::endl;
            for(auto &cpt_pfl : pfl.get_profile_competences()){
                myfile << "\t" << cpt_pfl << std::endl;
            }
        }
        competences.erase(std::remove(competences.begin(),competences.end(),""),competences.end());
        std::sort(competences.begin(),competences.end());
        competences.erase(std::unique(competences.begin(),competences.end()),competences.end());
        myfile << "CPT:\n\t" << competences.size() << std::endl;
        for(auto &cpt : competences){
            myfile << "\t" << cpt  << std::endl;
        }
     }
}





