#ifndef PLANICIE_H
#define PLANICIE_H

#include "Continente.h"

class Planicie : public Continente
{
	static int id;

public:
	Planicie();

	void atualizaProducaoRecursos(int turno) override{
		if (turno <= 6 && turno > 0) {
			this->setCriaProdutos(1);
			this->setCriaOuro(1);
		}
		else {
			this->setCriaProdutos(2);
		}
	}

	Territorio* duplica() const override;

	~Planicie();
};


#endif // !PLANICIE_H
