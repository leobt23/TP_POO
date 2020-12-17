#include "Pescaria.h"

int Pescaria::id = 0;

Pescaria::Pescaria() {
	this->setNome("Pescaria" + to_string(id++));
	this->setResistencia(9);
	this->setCriaProdutos(2);
	this->setCriaOuro(0);
	this->setConquistado(false);
	this->setPontosVitoria(2);
}

Territorio* Pescaria::duplica() const {
	return new Pescaria(*this);
}

Pescaria::~Pescaria() {}