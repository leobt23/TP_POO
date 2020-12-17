#include "TerritorioInicial.h"
TerritorioInicial::TerritorioInicial() {
	this->setNome("Territorio Inicial");
	this->setCriaProdutos(1);
	this->setCriaOuro(1);
	this->setResistencia(9);
	this->setPontosVitoria(0);
	this->setConquistado(true);
}

Territorio* TerritorioInicial::duplica() const {
	return new TerritorioInicial(*this);
}

TerritorioInicial::~TerritorioInicial(){}
