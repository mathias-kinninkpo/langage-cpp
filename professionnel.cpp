#include "professionnel.h"
#include <algorithm>

Professionnel::Professionnel(){}
Professionnel::Professionnel(const Professionnel& professionnel){
    this->competences = professionnel.competences;
    this->firstname = professionnel.firstname;
    this->lastname = professionnel.lastname;
    this->nb_competences = professionnel.nb_competences;
    this->nb_profile = professionnel.nb_profile;
}
Professionnel::Professionnel(const Professionnel* professionnel){
    this->competences = professionnel->competences;
    this->firstname = professionnel->firstname;
    this->lastname = professionnel->lastname;
    this->nb_competences = professionnel->nb_competences;
    this->nb_profile = professionnel->nb_profile;
}
Professionnel::Professionnel(std::string lastname, std::string firstname):lastname(lastname), firstname(firstname)
{

}
// the setters
void Professionnel::set_lastname(std::string last_name){
    lastname = last_name;
}
void Professionnel::set_firstname(std::string first_name){
    firstname = first_name;
}
void Professionnel::set_nb_competences(int nb){
    nb_competences = nb;

}
void Professionnel::set_nb_profile(int nb){
    nb_profile = nb;
}
// the function add a competence (string) to the list of competences (vector) ; the list is empty by default
void Professionnel::add_competences(std::string competence){
    competences.push_back(competence);
}

//the function below remove an element from the list. if element exist it return true and delete it false else
bool Professionnel::remove_competences(std::string competence){
    std::vector <std::string>::iterator iter = std::find(competences.begin(),competences.end(),competence);
    if(iter != competences.end()){
        competences.erase(std::remove(competences.begin(),competences.end(),competence),competences.end());
        return true;
    }
    std::cout << "Le professionnel " << this->lastname << " "  << this->firstname << " n'a pas la competence " << competence <<std::endl;
    return false;

}
void Professionnel::set_profile(Profile pfl){
// set the profile of an professional
    this->profiles_pro.push_back(pfl);

}

// the getters
std::string Professionnel::get_lastname(){
    return lastname;
}
std::string Professionnel::get_firstname(){
    return firstname;
}
int Professionnel::get_nb_competences(){
    return nb_competences;
}
int Professionnel::get_nb_profile(){
    return nb_profile;
}
std::vector <std::string>& Professionnel::get_competences(){
    return competences;
}
std::vector <Profile>& Professionnel::get_profile_pro(){
    return profiles_pro;
}
