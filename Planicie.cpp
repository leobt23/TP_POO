#include "Planicie.h"

int Planicie::id = 0;

Planicie::Planicie() {
	this->setNome("Planicie" + to_string(id++));
	this->setResistencia(5);
	this->setCriaProdutos(1);
	this->setCriaOuro(1);
	this->setConquistado(false);
	this->setPontosVitoria(1);
}

Territorio* Planicie::duplica() const {
	return new Planicie(*this);
}

Planicie::~Planicie() {}