#include "constante.hpp"
#include <string.h>
#include <iostream>
#include "contexte.hpp"
#include "arcEnCiel.hpp"
#include "cracker.hpp"
using namespace std;


int main( int argc, char *argv[] ){
    
    const string alphanumerique = "abcdefghijklmnopqrstuvwxyz";
    int N   = pow(alphanumerique.size(),taille_);
    ArcEnCiel aec(0);
    Contexte ctx(N, alphanumerique);
    Cracker crack;
    string clair;

    aec.load(argv[1]);
    crack.cracker(argv[2], aec, ctx, clair, T_);

    cout <<"Clair find: "<< clair <<endl;
    return 0;
}
