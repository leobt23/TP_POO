#ifndef MONTANHA_H
#define MONTANHA_H

#include "Territorio.h"
#include "Continente.h"

class Montanha : public Continente
{
	int turnoConquistado;
	static int id;
public:
	Montanha();

	void setTurnoConquistado(int t) { turnoConquistado = t; }
	int getTurnoConquistado() { return turnoConquistado; }

	void atualizaProducaoRecursos(int turno) override {
		
		int nrTurnosNaoProduz = this->getTurnoConquistado() + 2;

		if (turno <= nrTurnosNaoProduz && this->getTurnoConquistado() != -1) {
			this->setCriaProdutos(0);
			this->setCriaOuro(0);
		}
		else {
			this->setCriaProdutos(1);
		}
	}

	Territorio* duplica() const override;

	~Montanha();
};


#endif // !MONTANHA_H



