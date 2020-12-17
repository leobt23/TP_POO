#ifndef IMPERIO_H
#define IMPERIO_H

#include <iostream>
#include <sstream>
#include <vector>
#include "Territorio.h"

using namespace std;


class Imperio {
    int armazem;
    int cofre;
    int tamArmazem;
    int tamCofre;
    int forcaMilitar;
    int forcaMilitarMax;

public:
    Imperio();

    void alteraCapArmazem(int a);
    void alteraCapCofre(int a);
    void alteraNumeroProdutos(int numProdutos);
    void alteraNumeroOuro(int numOuro);
//    void adicionaTerritorio(Territorio a);
//    void eliminaTerritorio(Territorio a);
    void compraForcaMilitar();


    //getters

    int getProdutosImperio()const;
    int getOuroImperio()const;
    int getTamArmazem()const;
    int getTamCofre()const;
    string getImperioAsString() const;
    int getForcaMilitar() const;
    int getForcaMilitarMax() const;

    ~Imperio();
};


#endif /* IMPERIO_H */

