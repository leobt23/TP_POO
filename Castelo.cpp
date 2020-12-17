#include "Castelo.h"

int Castelo::id = 0;

Castelo::Castelo() {
	this->setNome("Castelo" + to_string(id++));
	this->setResistencia(7);
	this->setCriaProdutos(3);
	this->setCriaOuro(1);
	this->setConquistado(false);
	this->setPontosVitoria(1);
}

Territorio* Castelo::duplica() const {
	return new Castelo(*this);
}

Castelo::~Castelo() {}