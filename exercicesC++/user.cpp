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
    // Ce qui me dérange c'est surtout que le comentaire de présentation du
    // fichier disant "récupération à partir du stockage persistant" est faux.
    std::cout << "Sauvegarde de l'utilisateur: ID = " << id << ", Password = " << *password << std::endl;
    // En soit ce n'est pas bien grave de faire une fonction save qui ne fait rien.
    // C'est même compréhensible si l'on considère que c'est un exemple (et c'est le cas).
    // Par contre mieux vaux ne pas commenter que de mettre des commentaires faux.
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
// L'utilisation de static ne convient pas ici.
// Static signifie que la variable ne sera initialisée qu'une seule fois,
// et que sa valeur sera conservée entre les appels de la fonction.
// Cf dans main on peut get(1), ou get(9001) et on aura toujours
// le même utilisateur avec le même id et le même mot de passe.
