#include <string.h>
#include <iostream>
#include "contexte.hpp"
#include "arcEnCiel.hpp"
#include "constante.hpp"
using namespace std;


int main( int argc, char *argv[] ){
    // trucs pas important
    srand(time(0));

    const string alphanumerique = "abcdefghijklmnopqrstuvwxyz";
    int N   = pow(alphanumerique.size(),taille_);
    ArcEnCiel a(0);
    Contexte ctx(N, alphanumerique);

    a.creer(ctx, M_, T_);
    a.save(argv[1]);

    cout << "Table créee et sauvée dans: " << argv[1] << endl;

    return 0;
}