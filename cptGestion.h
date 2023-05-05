#ifndef CPTGESTION_H_INCLUDED
#define CPTGESTION_H_INCLUDED
#include <vector>
#include "professionnel.h"

class HandleSkills{

private:
    std::vector<std::string> competences;
    std::vector<Professionnel> professionnels;
    std::vector<Profile> profiles;
    std::string strip_string(std::string strings);

public:
    HandleSkills();
    std::vector<std::string> get_profile_names(std::vector<Profile>);
    bool create_professionnel();
    bool create_profile();
    void add_competences(std::string competence);
    void add_professionnel(Professionnel professionnel);
    void add_profile(Profile profile);
    bool load_data_from_file(std::string file_name);
    bool is_profile(Profile& profile,int is_create);
    void set_profile_to_professionnel(Professionnel& pro);
    bool is_professionnel(Professionnel& professionnel,int is_create);
    bool is_competence_in_professionnel(Professionnel& professionnel, std::string competence);
    bool is_competence_in_profile(Profile& profile, std::string competence);
    bool add_competence_to_profile(Profile& profile, std::string competence);
    bool add_competence_to_professionnel(Professionnel& professionnel, std::string competence);
    bool remove_competence_from_professionnel(Professionnel professionnel, std::string competence);
    bool remove_competence_from_profile(Profile profile, std::string competence);
    void print_competences();
    void print_profiles();
    void print_professionels();
    void print_competences_of_professionnel(std::string name, std::string surname);
    void print_competences_of_profile(std::string name);
    void print_professionnel_of_profile(std::string name);
    std::vector<std::string>& get_competences();
    std::vector<Professionnel>& get_professionnels();
    std::vector<Profile>& get_profiles();
    int menu();
    void update_profile();
    void save_data(std::string file_name);

};

std::string input(std::string var);



#endif // CPTGESTION_H_INCLUDED
