#include "Continente.h"
Continente::Continente() {
	this->setNome("Continente");
	this->setCriaProdutos(0);
	this->setCriaOuro(0);
	this->setResistencia(0);
	this->setPontosVitoria(0);
	this->setConquistado(true);
}

Continente::~Continente() {}