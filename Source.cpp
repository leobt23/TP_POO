#include "Territorio.h"
#include "TerritorioInicial.h"
#include "Mundo.h"
#include "Castelo.h"
#include "Duna.h"
#include "Fortaleza.h"
#include "Mina.h"
#include "Montanha.h"
#include "Pescaria.h"
#include "Planicie.h"
#include "Refugio.h"
#include <fstream>


string getDados(istream& in, string& a) {

    getline(in, a);
    

    if (in.fail()) {
        cout << "Erro ao ler ficheiro!" << endl;
        in.clear();
    }

    return a;
}


int main() {
    
	TerritorioInicial t;
    Castelo cas;
    Duna du;
    Fortaleza fort;
    Mina mi;
    Montanha mon;
    Pescaria pesc;
    Refugio refu;

    Mundo world("mundo 1");
    ifstream f;
    string out, obtido;

    cout << "----- TP POO -----" << endl;

    f.open("teste.txt");
    if (!f)
        cout << "ERRO!" << endl;

    while (obtido != "fim") {
        obtido = getDados(f, out);
        cout << obtido << endl;

        if (obtido == "Montanha")
            world.adicionaMontanha();
        if (obtido == "Planicie")
            world.adicionaPlanicie();
        if (obtido == "Mina")
            world.adicionaMina();
    }
    cout << "\n INFO. TERRITORIOS" << endl;
    world.listarTerritorios();

    string tipo;
    int quantidade;

    cout << "\n*****************************" << endl;
    cout << "Insira o tipo de Territorio:  ";
    cin >> tipo;
    cout << "Quantos territorios deste tipo deseja inserir?  ";
    cin >> quantidade;
    cout << endl;

    world.criaTerritorios(tipo, quantidade);

   cout << "\n INFO. TERRITORIOS" << endl;
   world.listarTerritorios();

   cout << "\n MOSTRAR PROD. EM CADA TURNO" << endl;

   cout << "Produtos total: " << world.getRecursosImperio() << "Ouro total: " << world.getOuroImperio() << endl;
   for (int i = 1; i <= 12; i++) {
       cout << "Turno = " << i << endl;
       world.atualizaProducaoRecursosImperio(i);
       world.conquista("Planicie1");
       world.conquista("Planicie2");
   }

   cout << "Produtos total: " << world.getRecursosImperio() << "Ouro total: " << world.getOuroImperio() << endl;


   cout << "lolol" << endl;
	//cout << t.getNome() << endl;


	return 0;
}