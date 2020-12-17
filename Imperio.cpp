#include "Imperio.h"
#include "Mundo.h"

Imperio::Imperio() : armazem(0), cofre(0), tamArmazem(3), tamCofre(3), // Construtor da classe imp�rio
forcaMilitar(1), forcaMilitarMax(3) {
}

void Imperio::alteraCapArmazem(int a) { //Aumenta ou diminui o tamnaho de Armazem
    if (tamArmazem + a >= 0)
        tamArmazem += a;
}

void Imperio::alteraCapCofre(int a) { //Aumenta ou diminui o tamnaho de cofre
    if ((tamCofre + a) >= 0)
        tamCofre += a;
}

void Imperio::alteraNumeroProdutos(int numProdutos) { //Aumenta ou diminui o numero de produtos existentes no armazem
    if ((numProdutos + armazem) >= 0)
        armazem += numProdutos;
}

void Imperio::alteraNumeroOuro(int numOuro) { //Aumenta ou diminui o numero de ouro existente no cofre
    if ((numOuro + cofre) >= 0)
        cofre += numOuro;
}





//PODERA TER QUE SER ALTERADO O AGUMENTO RECEBIDO

//void Imperio::adicionaTerritorio(Territorio a) { //Adiciona um territ�rio ao imp�rio
//    //Verifica��o se posso adicionar
//    vetor_territorios.push_back(&a);
//}
//
////PRECISA DE ALTERACAO POSTERIORMENTE NO QUE RECEBE E NO IF
//
//void Imperio::eliminaTerritorio(Territorio a) { // Elimina um territ�rio do imp�rio
//    auto it = vetor_territorios.begin();
//
//    //    while (it < vetor_territorios.end())
//    //        if (it->getQualquercoisa() < Limite qualquer) 
//    //            it = vetor_territorios.erase(it);
//    //        else
//    //            it++;
//}

void Imperio::compraForcaMilitar() {
    if (armazem > 0 && cofre > 0)
        if (forcaMilitar <= forcaMilitarMax) {
            forcaMilitar++;
            armazem--;
            cofre--;
        }
}

int Imperio::getProdutosImperio() const { // Mostra a quantidade de produtos que ha no armazem do imperio
    return armazem;
}

int Imperio::getOuroImperio() const { // Mostra a quantidade de ouro que h� no cofre do imperio;
    return cofre;
}

int Imperio::getTamArmazem() const { // Mostra o tamanho atual do armazem
    return tamArmazem;
}

int Imperio::getTamCofre() const { // Mostra o tamanho atual do cofre
    return tamCofre;
}

int Imperio::getForcaMilitar() const {
    return forcaMilitar;
}

int Imperio::getForcaMilitarMax() const {
    return forcaMilitarMax;
}

string Imperio::getImperioAsString() const { // Mostra as caracteristica de um objeto imp�rio 
    ostringstream os;
    os << "Produtos: " << getProdutosImperio() << "  Ouro: " << getOuroImperio()
        << "   TamArmazem:" << getTamArmazem() << "  TamCofre: " << getTamCofre()
        << "    Forca Militar: " << getForcaMilitar() << "  Forca Militar Max: "
        << getForcaMilitarMax() << endl;
    return os.str();
}

Imperio::~Imperio() { // Destrutor da Classe imp�rio

}