#include "Mundo.h"
#include "TerritorioInicial.h"
#include "Castelo.h"
#include "Duna.h"
#include "Fortaleza.h"
#include "Mina.h"
#include "Montanha.h"
#include "Pescaria.h"
#include "Planicie.h"
#include "Refugio.h"

Mundo::Mundo(string n) {
    this->nome = n;
}

Mundo::Mundo(const Mundo& nv) {

    nome = nv.nome;

    for (unsigned int i = 0; i < nv.territorios.size(); i++) {
        Territorio* t = nv.territorios[i]->duplica();
        territorios.push_back(t);
        territorios[i]->colocaTerritorio(this);
    }
}

//---------------------------------------

void Mundo::adicionaTerritorioInicial() {
    TerritorioInicial* t = new TerritorioInicial();
    territorios.push_back(t);
    t->colocaTerritorio(this);
}

void Mundo::adicionaCastelo() {
    Castelo* t = new Castelo();
    territorios.push_back(t);
    t->colocaTerritorio(this);
}

void Mundo::adicionaDuna() {
    Duna* t = new Duna();
    territorios.push_back(t);
    t->colocaTerritorio(this);
}

void Mundo::adicionaFortaleza() {
    Fortaleza* t = new Fortaleza();
    territorios.push_back(t);
    t->colocaTerritorio(this);
}

void Mundo::adicionaMina() {
    Mina* t = new Mina();
    territorios.push_back(t);
    t->colocaTerritorio(this);
}

void Mundo::adicionaMontanha() {
    Montanha* t = new Montanha();
    territorios.push_back(t);
    t->colocaTerritorio(this);
}

void Mundo::adicionaPescaria() {
    Pescaria* t = new Pescaria();
    territorios.push_back(t);
    t->colocaTerritorio(this);
}

void Mundo::adicionaPlanicie() {
    Planicie* t = new Planicie();
    territorios.push_back(t);
    t->colocaTerritorio(this);
}

void Mundo::adicionaRefugio() {
    Refugio* t = new Refugio();
    territorios.push_back(t);
    t->colocaTerritorio(this);
}

//---------------------------------------

void Mundo::listarTerritorios() const {
    ostringstream os;

    for (unsigned int i = 0; i < territorios.size(); i++) {
        territorios[i]->getAsString(os);
        cout << os.str() << endl;
    }
}

void Mundo::listarTerritorioEspecifico(string s) const {
    ostringstream os;

    for (unsigned int i = 0; i < territorios.size(); i++) {
        if (territorios[i]->getNome() == s) {
            territorios[i]->getAsString(os);
            cout << os.str() << endl;
            return;
        }
    }
    cout << "Nao existe" << endl;
    return;
}

void Mundo::listarImperio() const {
    ostringstream os;

    for (unsigned int i = 0; i < territoriosDoImperio.size(); i++) {
        territoriosDoImperio[i]->getAsString(os);
        cout << os.str() << endl;
    }
}

int Mundo::getTam() const {
    return territorios.size();
}

string Mundo::getNome() const {
    return nome;
}

Mundo& Mundo::operator=(const Mundo& terr) {
    nome = terr.nome;

    for (unsigned int i = 0; i < territorios.size(); i++) {
        delete(territorios[i]);
    }

    for (unsigned int i = 0; i < terr.territorios.size(); i++) {
        Territorio* t = terr.territorios[i]->duplica();
        territorios.push_back(t);
        territorios[i]->colocaTerritorio(this);
    }

    return *this;
}

void Mundo::atualizaProducaoRecursosImperio(int turno) {
    for (int i = 0; i < territorios.size(); i++) {
        if (territorios[i]->getConquistado() == true)
            territorios[i]->atualizaProducaoRecursos(turno);
    }
}

int Mundo::getRecursosImperio() const {
    int recursosTotal = 0;
    for (int i = 0; i < territorios.size(); i++) {
        if (territorios[i]->getConquistado() == true)
            recursosTotal += territorios[i]->getCriaProdutos();
    }
    return recursosTotal;
}

int Mundo::getOuroImperio() const {
    int ouroTotal = 0;
    for (int i = 0; i < territorios.size(); i++) {
        if (territorios[i]->getConquistado() == true)
            ouroTotal += territorios[i]->getCriaOuro();
    }
    return ouroTotal;
}

string Mundo::conquista(string s) {
    int randomNumber = 1 + (rand() % 6);

    //cout << "TAMANHO DOS TERRITORIOS" <<  getTam() << endl; -> debugging

    for (int i = 0; i < territorios.size(); i++) {
        if (territorios[i]->getNome() == s && territorios[i]->getConquistado() != true) {
            if (territorios[i]->getResistencia() <= (imp.getForcaMilitar() + randomNumber)) {
                territoriosDoImperio.push_back(territorios[i]);
                territorios[i]->setConquistado(true);
                return territorios[i]->getNome();
                // cout << "Territorio " << territorios[i]->getNome() << " conquistado!" << endl << endl;
            }
        }
    }
    return "Erro";
}

bool Mundo::criaTerritorios(string nome, int quantidade) {
    if (nome == "TerritorioInicial") {
        for (int i = 0; i < quantidade; i++)
            this->adicionaTerritorioInicial();
        return true;
    }
    if (nome == "Castelo") {
        for (int i = 0; i < quantidade; i++)
            this->adicionaCastelo();
        return true;
    }

    if (nome == "Duna") {
        for (int i = 0; i < quantidade; i++)
            this->adicionaDuna();
        return true;
    }

    if (nome == "Fortaleza") {
        for (int i = 0; i < quantidade; i++)
            this->adicionaFortaleza();
        return true;
    }

    if (nome == "Mina") {
        for (int i = 0; i < quantidade; i++)
            this->adicionaMina();
        return true;
    }

    if (nome == "Montanha") {
        for (int i = 0; i < quantidade; i++)
            this->adicionaMontanha();
        return true;
    }

    if (nome == "Pescaria") {
        for (int i = 0; i < quantidade; i++)
            this->adicionaPescaria();
        return true;
    }

    if (nome == "Planicie") {
        for (int i = 0; i < quantidade; i++)
            this->adicionaPlanicie();
        return true;
    }

    if (nome == "Refugio") {
        for (int i = 0; i < quantidade; i++)
            this->adicionaRefugio();
        return true;
    }

    return false;
}

Mundo::~Mundo() {
    for (Territorio* p : territorios) {
        delete p;
    }
}

