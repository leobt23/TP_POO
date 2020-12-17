#include "Mina.h"

int Mina::id = 0;

Mina::Mina() {
	this->setNome("Mina" + to_string(id++));
	this->setResistencia(5);
	this->setCriaProdutos(0);
	this->setCriaOuro(1);
	this->setConquistado(false);
	this->setPontosVitoria(1);
}

Territorio* Mina::duplica() const {
	return new Mina(*this);
}

Mina::~Mina() {}