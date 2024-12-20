// Ce fichier implémente la classe Password, qui permet de gérer un mot de passe. La classe gère l'encryptage, la comparaison de mots
// de passe et fournit des opérateurs pour les comparer ou les afficher.
// @author:@thocle03

#include "password.hpp"

Password::Password(const std::string &password, bool is_encrypted):
	_raw_value(password) {
    if (is_encrypted) {
        _encrypted_value = password;
    } else {
        encrypt(password);
    }
}

void Password::encrypt(const std::string &password) {
    _encrypted_value = std::string(password.rbegin(), password.rend());
}

std::string Password::str() const {
	return _encrypted_value;
}

bool Password::operator==(const std::string &str) const {
    return str == _encrypted_value;
}

bool Password::operator==(const Password &other) const {
    return _encrypted_value == other._encrypted_value;
}

std::ostream &operator<<(std::ostream &os, const Password &p) {
    os << p._encrypted_value;
    return os;
}
