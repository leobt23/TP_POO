#ifndef CASTELO_H
#define CASTELO_h

#include "Continente.h"

class Castelo : public Continente
{
	static int id;

public:
	Castelo();

	void atualizaProducaoRecursos(int turno) override {
		this->setCriaOuro(1);

		if (turno < 3 && turno > 0 || turno < 9 && turno > 6)
			this->setCriaProdutos(3);
		else {
			this->setCriaProdutos(0);
		}
			
	}

	Territorio* duplica() const override;

	~Castelo();
};


#endif // !CASTELO_h

