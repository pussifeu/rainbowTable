#ifndef CRACKER_H
#define CRACKER_H

#include <ctime>
#include <string.h>
#include <iostream>
#include "contexte.hpp"
#include "arcEnCiel.hpp"

class Cracker {
public:
    bool cracker(char* y, ArcEnCiel& aec, Contexte& ctx, std::string& clair, int T);
    bool verifieAlerte(char* y, ArcEnCiel& aec, Contexte& ctx,  int t, uint m,  std::string& clair, int T);
};
#endif /* ifndef CRACKER_H */
