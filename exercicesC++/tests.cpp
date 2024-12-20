// Ce fichier contient les tests unitaires pour les classes Password et User. Les tests couvrent la vérification de
// l'encryptage des mots de passe, la sauvegarde des utilisateurs, la récupération et la connexion.
// @author:@thocle03

#include "password.hpp"
#include "user.hpp"
#include <cassert>
#include <iostream>

void test_password() {
    Password password("toto", false);
    assert(password.str() == "otot");

    assert(password == "otot");
    Password encrypted_password("otot", true);
    assert(password == encrypted_password);

    std::cout << "Tests Password réussis." << std::endl;
}

void test_user() {
    Password password("toto", false);
    User user(1, password);
    user.save();

    User &retrieved_user = User::get(1);

    assert(retrieved_user.login("toto") == 1); 
    assert(retrieved_user.login("wrong") == 0); 

    std::cout << "Tests User réussis." << std::endl;
}

int main() {
    test_password();
    test_user();

    std::cout << "Tous les tests ont été passés avec succès !" << std::endl;
    return 0;
}
