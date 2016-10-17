#include "cracker.hpp"

using namespace std;

bool Cracker::cracker(char* y, ArcEnCiel& aec, Contexte& ctx, string& clair, int T){
    int nb_fausses_alertes = 0;
    uint p = 0, q = 0;
    clock_t begin = clock();
    for ( int t = T - 1 ; t > 0 ; --t ) {
         uint64_t idx = ctx.h2i(t, y);
         cout << t << " " << (double(clock() - begin) / CLOCKS_PER_SEC) << endl;
         // trouve le T-1 ème indice
         for (int k = t + 1 ; k <= T - 1 ; ++k ) {
             idx = ctx.i2i(idx, k);
         }
         // Recherche dans la table.
         if ( aec.recherche( idx, p, q ) ) {
             // On vérifie chacune des alertes
             for (uint m = p; m <= q; ++m ) {
                if (verifieAlerte(y, aec ,ctx, t, m, clair, T) )
                   return true;
                nb_fausses_alertes++;
             }
         }
    }

    cout << "Non trouve, fausses alertes = " << nb_fausses_alertes << endl;
    return false;
}

bool Cracker::verifieAlerte(char* y, ArcEnCiel& aec, Contexte& ctx, int t, uint m, string & c, int T){
    char digest[strlen(y)];
    vector<Chaine>* datas = aec.getX().at(aec.getNumero());
    uint64_t idx = datas->at(m).idx1;
    for ( int k = t + 1 ; k <= T - 1 ; ++k ) {
       idx = ctx.i2i(idx, k);
    }
    ctx.i2c(idx, c);
    ctx.h(c,(unsigned char*)digest);
    return y == digest;
}
