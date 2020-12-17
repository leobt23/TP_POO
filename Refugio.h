#ifndef REFUGIO_H
#define REFUGIO_H

#include "Ilhas.h"

class Refugio : public Ilhas
{
	static int id;
public:
	Refugio();

	void atualizaProducaoRecursos(int turno) override {
		this->setCriaProdutos(0);
		this->setCriaOuro(1);
	}

	Territorio* duplica() const override;

	~Refugio();
};


#endif // !REFUGIO_H

