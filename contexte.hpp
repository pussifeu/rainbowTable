#ifndef CONTEXTE_H
#define CONTEXTE_H

#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdint>
#include <string.h>
#include <string>
#include <openssl/md5.h>

class Contexte {

public:
    Contexte(){};
    Contexte(uint64_t N, const std::string & alphanumerique) : _N(N), _alphanumerique(alphanumerique){};
    // fonction de hachage
    // In: Clair c ----> Out: Empreinte
    void h( std::string c, unsigned char* y );
    // In: position t, empreinte d ---> Retourne index
    uint64_t h2i( uint64_t t, const char* y);
    // In: index idx ----> Out: Clair c
    void i2c(uint64_t idx, std::string & c);
    // In: index idx ----> retourne index (la composée des précédentes)
    uint64_t i2i( uint64_t idx, int M);// normalement ( uint64_t idx ) uniquement
    // Retourne un indice aléatoire valide.
    uint64_t createRandomIndex();

private:

    uint64_t _N;           // nombre de mots
    int _mot_taille_min;   // nombre de lettres min d'un mot
    int _mot_taille_max;   // nombre de lettres max d'un mot
    const std::string _alphanumerique; // tableau des symboles utilisés (courament : "abcdef...1234...")
    uint64_t _N_taille[];  // tableau, nombre de mots d'une taille donnée

};
#endif /* ifndef CONTEXTE_H */
