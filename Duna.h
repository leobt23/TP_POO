#ifndef DUNA_H
#define DUNA_H

#include "Continente.h"

class Duna : public Continente
{
	static int id;
public:
	Duna();

	void atualizaProducaoRecursos(int turno) override {
		this->setCriaProdutos(1);
	}

	Territorio* duplica() const override;

	~Duna();
};


#endif // !DUNA_h

