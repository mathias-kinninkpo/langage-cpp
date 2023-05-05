#ifndef PROFESSIONNEL_H_INCLUDED
#define PROFESSIONNEL_H_INCLUDED
#include <vector>
#include <iostream>
#include "profile.h"

class Professionnel{
private:
    std::string lastname, firstname;
    int nb_competences = 0, nb_profile = 0;
    std::vector <std::string> competences;
    std::vector <Profile> profiles_pro;

public:
    // the constructors
    Professionnel();
    Professionnel(const Professionnel& professionnel);
    Professionnel(const Professionnel* professionnel);
    Professionnel(std::string lastname, std::string firstname);
    // the setters
    void set_lastname(std::string last_name);
    void set_firstname(std::string first_name);
    void set_nb_competences(int nb);
    void set_nb_profile(int nb);
    void add_competences(std::string competence);
    bool remove_competences(std::string competence);
    void set_profile(Profile pfl);
    // the getters
    std::string get_lastname();
    std::string get_firstname();
    int get_nb_competences();
    int get_nb_profile();
    std::vector <std::string>& get_competences();
    std::vector <Profile>& get_profile_pro();

};



#endif // PROFESSIONNEL_H_INCLUDED
