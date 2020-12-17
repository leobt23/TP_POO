#ifndef MINA_H
#define MINA_H

#include "Continente.h"

class Mina : public Continente
{
	static int id;
public:
	Mina();

	void atualizaProducaoRecursos(int turno) override {
		if (turno <= 3 && turno > 0 || turno <= 9 && turno > 6) {
			this->setCriaOuro(1);
		}
		else {
			this->setCriaOuro(2);
		}
	}

	Territorio* duplica() const override;

	~Mina();
};


#endif // !MINA_H

