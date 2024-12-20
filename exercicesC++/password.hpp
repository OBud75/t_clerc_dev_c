// Ce fichier déclare la classe Password, qui encapsule la gestion d'un mot de passe, son encryptage et les opérateurs
// nécessaires pour comparer ou afficher un mot de passe.
// @author:@thocle03

#ifndef PASSWORD_HPP
#define PASSWORD_HPP

#include <string>
#include <iostream>

class Password {
    private:
        std::string _raw_value;
        std::string _encrypted_value;
        void encrypt(const std::string &password);

    public:
        Password(const std::string &password, bool is_encrypted = false);
        std::string str() const;
        bool operator==(const std::string &str) const;
        bool operator==(const Password &other) const;
        friend std::ostream &operator<<(std::ostream &os, const Password &p);
};

#endif 
