Pour compiler ce programme, il faut lancer le Makefile par la commande:
- make -f Makefile
Pour la creation de la table:
./createTable rainbowTable.txt
Pour le crackage:
./executeCrack rainbowTable.txt `echo kcyxz | md5sum`

Avancement du programme:
- Ce programme crée parfaitement la table arc en ciel
- Au niveau du crackage, il y avait un probleme de lentement car quand on augmente T, la boucle devient plus long.

