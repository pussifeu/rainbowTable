#include "contexte.hpp"
#include <sstream>
using namespace std;

// fonction de hachage
// In: Clair c ----> Out: Empreinte
void Contexte::h( string c, unsigned char* y ){
    MD5((unsigned char*)c.c_str(),c.size(),y);
}

// In: position t, empreinte d ---> Retourne index
uint64_t Contexte::h2i( uint64_t t, const char* y){
    uint64_t result = 0;
    memcpy(&result, y, sizeof(uint64_t));// prend les 8 premiers octets de l'empreinte
    return (result + t + 1) % _N;
}

// permet de reconstruire le texte à partir d'une empreinte
// In: index idx ----> Out: Clair c
void Contexte::i2c( uint64_t idx, string & c ){// sur 64 bits on stocke environ 14 * 36 symboles possibles
    c.clear();
    do {
        c   += _alphanumerique[ idx % _alphanumerique.size() ];
        idx /= _alphanumerique.size();
    } while ( idx );
}

// In: index idx ----> retourne index (la composée des précédentes)
uint64_t Contexte::i2i( uint64_t idx, int T){
    string clair;
    char digest[MD5_DIGEST_LENGTH];// 16 octets

    for (int i = 0; i < T ; ++i){
        i2c(idx, clair);
        h(clair, (unsigned char*)digest);
        idx = h2i(i, (const char*)digest);
    }
    return idx;
}

// Retourne un indice aléatoire valide.
uint64_t Contexte::createRandomIndex(){
    int n1 = rand();
    int n2 = rand();
    return ( ( (uint64_t) n2 ) + ( ( (uint64_t) n1 ) << 32 ) ) % _N;
}
