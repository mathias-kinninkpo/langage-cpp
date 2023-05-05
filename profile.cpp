#include <algorithm>
#include "profile.h"

Profile::Profile(){}
Profile::Profile(const Profile& pfl){
    this->nb_competences = pfl.nb_competences;
    this->profile_name = pfl.profile_name;
    this->profile_competences = pfl.profile_competences;
}
Profile::Profile(std::string profile_name):profile_name(profile_name){}
void Profile::set_profile_name(std::string profilename){
    profile_name = profilename;
}
void Profile::set_nb_competences(int nb){
    nb_competences = nb;
}
void Profile::add_profile_compentence(std::string profilecompetence){
    profile_competences.push_back(profilecompetence);
}
// the function below remove an element from the list. if element exist it return true and delete it false else

bool Profile::remove_competences(std::string competence){
    std::vector <std::string>::iterator iter = std::find(profile_competences.begin(),profile_competences.end(),competence);
    if(iter != profile_competences.end()){
        profile_competences.erase(std::remove(profile_competences.begin(),profile_competences.end(),competence),profile_competences.end());
        return true;
    }
    std::cout << "La competence " << competence << " n'est pas dans la liste des competences requises pour le profile " << this->profile_name <<std::endl;
    return false;
    // after
}
std::string Profile::get_profile_name(){
    return profile_name;
}
int Profile::get_nb_competences(){
    return nb_competences;
}
// the function below return the list of the competences in a profile
std::vector <std::string>& Profile::get_profile_competences(){
    return profile_competences;
}

bool Profile::operator== (const Profile& profile)const{
    return this->nb_competences == profile.nb_competences;
}
