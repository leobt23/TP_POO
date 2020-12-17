#ifndef TERRITORIO_H
#define TERRITORIO_H

#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include <cstdlib>

using namespace std;

class Mundo;

class Territorio {
	string nome;
	int resistencia, criaProdutos, criaOuro, pontosVitoria;
	bool conquistado;
	Mundo* m;
	
public:
	Territorio();

	string getNome() const;
	int getResistencia() const;
	int getCriaProdutos() const;
	int getCriaOuro() const;
	int getPontosVitoria() const;
	bool getConquistado() const;

	void setNome(string nome);
	void setResistencia(int res);
	void setCriaProdutos(int cp);
	void setCriaOuro(int co);
	void setPontosVitoria(int pv);
	void setConquistado(bool conq);

	void getAsString(ostringstream& os);
	void colocaTerritorio(Mundo* nm);

	virtual void atualizaProducaoRecursos(int turno) {
		this->setCriaProdutos(1);
		this->setCriaOuro(1);
	}

	virtual Territorio* duplica() const = 0;

	~Territorio();
};

#endif /* TERRITORIO_H */