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
// Avoir pensé à tester est un plus.
// Dans l'idée, on essaye de tester des cas extrèmes, typiquement tester
// des cas qui son sensés ne pas marcher.

// Le fait d'avoir dans get:
// static Password temp_password("otot", true); 
// static User user(id, temp_password);

// puis de tester:
// Password password("toto", false);
// User user(1, password);
// User &retrieved_user = User::get(1);
// assert(retrieved_user.login("toto") == 1); 

// Aurait pu vous alerter sur le comportement de static,
// dans le sens où l'User que retourne la fonction get
// est sensé avoir comme mot de passe "otot" et non "toto"
// étant donné que c'est codé en dur dans la fonction get.

// Essayer de get plusieurs utilisateurs aurait mis cela en lumière.

// Une approche "TDD" peut être intéressante, c'est à dire
// écrire les tests avant d'écrire le code. Cela permet de
// se concentrer sur ce que l'on veut obtenir, typiquemet
// on écrit un test qui échoue, puis on écrit le code pour
// que le test passe. Un peu comme un cahier des charges.
// Par exemple un test qui vérifie que
// User &retrieved_user = User::get(9001); a bien l'id 9001
// On aurait vu que le test échoue et on corrige la fonction get.
