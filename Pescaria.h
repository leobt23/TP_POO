#ifndef PESCARIA_H
#define PESCARIA_H

#include "Ilhas.h"

class Pescaria : public Ilhas
{
	static int id;
public:
	Pescaria();

	void atualizaProducaoRecursos(int turno) override {
		this->setCriaOuro(0);
		
		if (turno <= 6 && turno > 0) 
			this->setCriaProdutos(2);
		else if(turno > 6 && turno <= 12)
			this->setCriaProdutos(4);
	}

	Territorio* duplica() const override;

	~Pescaria();
};


#endif // !PESCARIA_H

