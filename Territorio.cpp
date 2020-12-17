#include "Territorio.h"
#include "Mundo.h"

Territorio::Territorio() { //será feita a devida inicialização em cada herdeiro da classe Território
	this->nome = "null";
	this->criaProdutos = -1;
	this->criaOuro = -1;
	this->pontosVitoria = -1;
	this->resistencia = -1;
	this->conquistado = false;
	this->m = nullptr;
}

string Territorio::getNome() const { return nome; }
int Territorio::getResistencia() const { return resistencia; }
int Territorio::getCriaProdutos() const { return criaProdutos; }
int Territorio::getCriaOuro() const { return criaOuro; }
int Territorio::getPontosVitoria() const { return pontosVitoria; }
bool Territorio::getConquistado() const { return conquistado; }

void Territorio::setNome(string nome) { this->nome = nome; }
void Territorio::setResistencia(int res) { this->resistencia = res; }
void Territorio::setCriaProdutos(int cp) { this->criaProdutos = cp; }
void Territorio::setCriaOuro(int co) { this->criaOuro = co; }
void Territorio::setPontosVitoria(int pv) { this->pontosVitoria = pv; }
void Territorio::setConquistado(bool conq) { this->conquistado = conq; }

void Territorio::getAsString(ostringstream& os) {
	os.str("");

	os << "Nome: " << nome << " | Resistencia: " << resistencia << " | Producao de Produtos: " << criaProdutos
		<< " | Producao de Ouro: " << criaOuro << " | Pontos de Vitoria: " << pontosVitoria << endl;
}

void Territorio::colocaTerritorio(Mundo* nm) {
	m = nm;
}


Territorio::~Territorio() {}