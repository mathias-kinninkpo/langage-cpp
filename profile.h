#ifndef PROFILE_H_INCLUDED
#define PROFILE_H_INCLUDED
#include <iostream>
#include <vector>
class Profile{
private:
    std::string profile_name;
    int nb_competences = 0;
    std::vector <std::string> profile_competences;
public:
    Profile();
    Profile(const Profile& pfl);
    Profile (std::string profile_name);
    void set_profile_name(std::string profilename);
    void set_nb_competences(int nb);
    void add_profile_compentence(std::string profilecompetence);
    bool remove_competences(std::string competence);
    std::string get_profile_name();
    int get_nb_competences();
    std::vector <std::string>& get_profile_competences();
    bool operator==(const Profile& profile) const;
};


#endif // PROFILE_H_INCLUDED
