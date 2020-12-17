#ifndef MUNDO_H
#define MUNDO_H

#include"Territorio.h"
#include"Imperio.h"

class Mundo {
	string nome;
	vector<Territorio*> territorios;
	vector<Territorio*> territoriosDoImperio;
	Imperio imp;

public:
	Mundo(string n);
	Mundo(const Mundo& nv);

	void adicionaCastelo();
	void adicionaDuna();
	void adicionaFortaleza();
	void adicionaMina();
	void adicionaMontanha();
	void adicionaPescaria();
	void adicionaPlanicie();
	void adicionaRefugio();
	void adicionaTerritorioInicial();

	void listarTerritorios() const;
        void listarTerritorioEspecifico(string s) const;
	int getTam() const;
	string getNome() const;

	void atualizaProducaoRecursosImperio(int turno);
	int getRecursosImperio() const;
	int getOuroImperio() const;

	string conquista(string s);

        void listarImperio() const;
        
	//Fazer fun��o para percorrer o vetor do territ�rios do Imp�rio e ir somando ao Armaz�m e ao Cofre o valor dos recursos cada turno

	bool criaTerritorios(string nome, int quantidade);

	virtual ~Mundo();
	Mundo& operator=(const Mundo& terr);
};

#endif // !MUNDO_H


