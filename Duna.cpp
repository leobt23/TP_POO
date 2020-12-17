#include "Duna.h"

int Duna::id = 0;

Duna::Duna() {
	this->setNome("Duna" + to_string(id++));
	this->setResistencia(4);
	this->setCriaProdutos(1);
	this->setCriaOuro(0);
	this->setConquistado(false);
	this->setPontosVitoria(1);
}

Territorio* Duna::duplica() const {
	return new Duna(*this);
}

Duna::~Duna() {}