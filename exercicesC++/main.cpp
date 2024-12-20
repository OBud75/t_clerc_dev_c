// Ce fichier est le point d’entrée de l’application. Il permet de créer un utilisateur avec un mot de passe, de tester l'encryptage
// du mot de passe, de vérifier les fonctionnalités, de sauvegarder l’utilisateur, de le récupérer et de tester la fonctionnalité de connexion.
// @author:@thocle03

#include "password.hpp"
#include "user.hpp"

int main() {
    Password password("toto", false); 
    User user(1, password);

    user.save();

    User &retrieved_user = User::get(1);

    retrieved_user.login("toto");

    return 0;
}
