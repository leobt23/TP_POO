#include "Montanha.h"

int Montanha::id = 0;

Montanha::Montanha() {
	this->setNome("Montanha" + to_string(id++));
	this->setResistencia(6);
	this->setCriaProdutos(0);
	this->setCriaOuro(0);
	this->setConquistado(0);
	this->setPontosVitoria(1);
	this->setTurnoConquistado(-1);  //Se estiver a -1 quer dizer que ainda não foi conquistado
}									

Territorio* Montanha::duplica() const {
	return new Montanha(*this);
}

Montanha::~Montanha(){}