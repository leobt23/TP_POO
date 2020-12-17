#ifndef TERRITORIOINICIAL_H
#define TERRITORIOINICIAL_H

#include"Territorio.h"

class TerritorioInicial : public Territorio
{
public:
	TerritorioInicial();

	//void atualizaProducaoRecursos(int turno);

	Territorio* duplica() const override;

	~TerritorioInicial();
};

#endif //TERRITORIOINICIAL_H
