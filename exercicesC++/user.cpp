// Ce fichier implémente la classe User, qui représente un utilisateur avec un ID unique et un mot de passe. La classe gère
// la sauvegarde des données, la récupération à partir du stockage persistant et la vérification des identifiants pour le login.
// @author:@thocle03

#include "user.hpp"
#include "password.hpp"
#include <iostream>

User::User(int id, Password &password):
    id(id), password(std::make_unique<Password>(password)) {
        is_logged_in = false;
    }

void User::save() {
    std::cout << "Sauvegarde de l'utilisateur: ID = " << id << ", Password = " << *password << std::endl;
}

int User::login(const char *raw_password) {
    Password temp_password(raw_password, false);
    if (*password == temp_password) {
        is_logged_in = true;
        std::cout << "Login réussi pour l'utilisateur ID: " << id << std::endl;
        return 1;
    }
    std::cout << "Login échoué pour l'utilisateur ID: " << id << std::endl;
    return 0;
}

User& User::get(int id) {
    static Password temp_password("otot", true); 
    static User user(id, temp_password);
    std::cout << "Récupération de l'utilisateur ID: " << id << std::endl;
    return user;
}
