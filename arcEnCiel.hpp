#ifndef ARC_EN_CIEL_H
#define ARC_EN_CIEL_H

#include <cstdint>
#include <string>
#include <vector>
#include <iostream>
#include <openssl/md5.h>
#include <algorithm>
#include <fstream>
#include "utils.hpp"
#include "contexte.hpp"

typedef uint64_t uint64;

struct Chaine
{
    uint64_t idx1;
    uint64_t idxT;

    Chaine(uint64_t first, uint64_t last) : idx1(first), idxT(last) {}

    bool operator > (const Chaine& str) const
    {
        return (str.idxT > idxT);
    }
};

class ArcEnCiel {

public:
    ArcEnCiel(int numero):_numero(numero),_progression(70){};

    // Creer les M chaînes de taille T, dans le contexte ctxt
    void creer(Contexte ctx, int M, int T);

    // Tri _X suivant idxT.
    void trier();

    // Sauvegarde la table sur disque.
    void save( std::string name, int numero = -1);

    // Charge en mémoire la table à partir du disque. (et retourne son index)
    void load( std::string name );

    // Recherche dichotomique dans la table
    // ( p et q sont le premier/dernier trouvé )
    bool recherche( uint64_t idx, uint & p, uint & q );
    
    //Accesseur
    uint getNumero();
    std::vector< std::vector<Chaine>* > getX();

    void progression(float progress);
private:
    uint _numero;   // numero de la table (ici 0, mais voir "Moult tables")
    uint _M;        // nombre de chaines dans la table
    uint _T;        // taille de chaque chaine
    std::vector< std::vector<Chaine>* > _X;// la / les pointeur(s) sur (la / les) table(s) créées
    int _progression;
    Contexte _ctx;

};

#endif /* ifndef ARC_EN_CIEL_H */
