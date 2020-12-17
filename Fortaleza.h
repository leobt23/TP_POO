#ifndef FORTALEZA_H
#define FORTALEZA_H

#include "Continente.h"

class Fortaleza : public Continente
{
	static int id;
public:
	Fortaleza();

	void atualizaProducaoRecursos(int turno) override {	
		this->setCriaProdutos(0);
		this->setCriaOuro(0);
	}

	Territorio* duplica() const override;

	~Fortaleza();
};


#endif // !FORTALEZA_H