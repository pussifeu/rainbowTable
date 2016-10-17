#include "arcEnCiel.hpp"

using namespace std;

void ArcEnCiel::creer(Contexte ctx, int M, int T){
    int nextStep = 0;
    const clock_t begin_time = clock();
    uint64_t idx1;
    uint64_t idxT;
    vector<Chaine>* datas = new vector<Chaine>;

    for (int i = 0; i < M; ++i)
    {
        // Chaque sommet du graphe est l'indice d'un texte clair
        idx1 = ctx.createRandomIndex();
        idxT  = ctx.i2i(idx1, T);

        datas->push_back(Chaine(idx1, idxT));

        if( i > nextStep ){// affiche la progression
            progression( (float)i / M );
            nextStep += (1 * M) / 100;// tous les 5 % on rafraichit.
        }
    }

    sort(datas->begin(), datas->end(), greater<Chaine>());

    _X.push_back(datas);

    _numero = _X.size() -1;// table actuelle
    cout << M << " entrées (taille de chaine: " << T << ") créées en " << float(clock()-begin_time) / CLOCKS_PER_SEC << " secondes" << endl;
}

// Sauvegarde la table sur disque.
void ArcEnCiel::save( string name, int numero){
    ofstream myfile;
    vector<Chaine>* datas = _X.at(numero >= 0 ? numero : _numero);

    myfile.open (name);

    sort(datas->begin(), datas->end(), greater<Chaine>());

    for ( auto indexes : *datas ){
        myfile << indexes.idx1 << '-' << indexes.idxT <<endl;
    }

    myfile.close();
}

// Charge en mémoire la table à partir du disque.
void ArcEnCiel::load( string name ){
    ifstream fichier(name, ios::in);  // on ouvre le fichier en lecture
    string contenu;
    vector<Chaine>* datas = new vector<Chaine>;

    if( fichier ) {
        while( getline(fichier, contenu) ){
            vector<string> ids;
            Utils::split(contenu, '-', ids);
            datas->push_back(Chaine(
                (uint64_t)stoull(ids.at(0), NULL, 0),
                (uint64_t)stoull(ids.at(1), NULL, 0)
            ));
        }

        fichier.close();

        _X.push_back(datas);

        _numero = _X.size() - 1;
    }
    else
        cerr << "Impossible d'ouvrir le fichier !" << endl;
}

// Recherche dichotomique dans la table
// ( p et q sont le premier/dernier trouvé )

bool ArcEnCiel::recherche( uint64_t idx, uint & p, uint & q ){
    vector<Chaine>* datas = _X.at(_numero);
    if(p == 0) p = 0;
    if(q == 0) q = (uint)datas->size();
    bool trouve = false;
    uint iMilieu = (uint)((q+p) / 2);
    /* boucle de recherche */
    while(!trouve && (q-p) > 0){
        iMilieu = (uint)((q+p) / 2);
        if (datas->at(iMilieu).idxT == idx)
            trouve = true;
        else{
            if(datas->at(iMilieu).idxT > idx)
                q = iMilieu-1;
            else
                p = iMilieu+1;
        }

    }

    return trouve;
}

// affiche l'avancement
void ArcEnCiel::progression(float progress){
    cout << "[";
    int pos = _progression * progress;
    for (int k = 0; k < _progression; ++k) {
        if ( k < pos ) cout << ".";
        else if (k == pos) cout << ">";
        else cout << " ";
    }
    cout << "] " << int(progress * 100.0) << " %\r";
    cout.flush();
}

//Accesseur getter
uint ArcEnCiel::getNumero(){
 return _numero;
}

vector< vector<Chaine>* > ArcEnCiel::getX(){
 return _X;
}