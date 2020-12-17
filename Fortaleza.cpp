#include "Fortaleza.h"

int Fortaleza::id = 0;

Fortaleza::Fortaleza() {
	this->setNome("Fortaleze" + to_string(id++));
	this->setResistencia(8);
	this->setCriaProdutos(0);
	this->setCriaOuro(0);
	this->setConquistado(false);
	this->setPontosVitoria(1);
}

Territorio* Fortaleza::duplica() const {
	return new Fortaleza(*this);
}

Fortaleza::~Fortaleza() {}