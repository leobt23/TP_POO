#include "Refugio.h"

int Refugio::id = 0;

Refugio::Refugio() {
	this->setNome("RefugioDosPiratas" + to_string(id++));
	this->setResistencia(9);
	this->setCriaProdutos(0);
	this->setCriaOuro(1);
	this->setConquistado(false);
	this->setPontosVitoria(2);
}

Territorio* Refugio::duplica() const {
	return new Refugio(*this);
}

Refugio::~Refugio() {}