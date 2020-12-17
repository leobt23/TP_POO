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
#include <time.h>

string getDados(istream& in, string& a) {

    getline(in, a);


    if (in.fail()) {
        cout << "Erro ao ler ficheiro!" << endl;
        in.clear();
    }

    return a;
}

int main() {

    int resp;
    TerritorioInicial t;
    Castelo cas;
    Duna du;
    Fortaleza fort;
    Mina mi;
    Montanha mon;
    Pescaria pesc;
    Refugio refu;

    srand((unsigned) time(0));

    Mundo world("mundo 1");
    ifstream f;
    string out, obtido, tipo, terrConq;
    int quantidade;

    printf("\t-----------------POO 20/21-----------------");

    string val, val2;
    int val3;

    do {
        string stringvalues;

        printf("\n\n");
        printf("1 - carrega <nomeFicheiro>\n");
        printf("2 - cria <tipo> <n>\n");
        printf("3 - conquista <nome>\n");
        printf("4 - lista <nome>\n");
        printf("5 - sair\n\n");

        cout << "Adiciona Comando: ";
        getline(cin, stringvalues);
        stringstream ss(stringvalues);

        ss >> val;

        if (val == "carrega") { //"teste.txt"
            int fileflag = 1;
            ss >> val2;
            if (val2.size() == 0)
                cout << "Deve inserir o nome do ficheiro!" << endl;
            else {

                f.open(val2);
                if (!f){
                    cout << "ERRO!" << endl;
                    fileflag = 0;
                    }

                while (obtido != "fim") {
                    obtido = getDados(f, out);
                    //cout << obtido << endl; ---> Isto serve apenas para DEBUG

                    if (obtido == "TerritorioInicial")
                        world.adicionaTerritorioInicial();
                    if (obtido == "Montanha")
                        world.adicionaMontanha();
                    if (obtido == "Planicie")
                        world.adicionaPlanicie();
                    if (obtido == "Mina")
                        world.adicionaMina();
                    if (obtido == "Castelo")
                        world.adicionaCastelo();
                    if (obtido == "Duna")
                        world.adicionaDuna();
                    if (obtido == "Fortaleza")
                        world.adicionaFortaleza();
                    if (obtido == "Pescaria")
                        world.adicionaPescaria();
                    if (obtido == "Refugio")
                        world.adicionaRefugio();

                }
                if(fileflag != 0)
                cout << "Ficheiro carregado com sucesso!" << endl;
            }
        }

        if (val == "cria") {
            ss >> val2 >> val3;
            cout << "-----------------Adiciona Territótio-----------------" << endl;
            world.criaTerritorios(val2, val3);
        }

        if (val == "conquista") {
            ss >> val2;
            string terconquistado;
            cout << "-----------------Conquista Territótio-----------------" << endl;
            terconquistado = world.conquista(val2);
            if (terconquistado != "Erro") {
                cout << "Territorio " << terconquistado << " conquistado!" << endl << endl;
            } else
                cout << "Nao foi conquitado!" << endl << endl;
            cout << "Terristorios conquistados: " << endl;
            world.listarImperio();
        }

        if (val == "lista") {
            cout << "-----------------Lista-----------------" << endl;
            val2 = "nada";
            ss >> val2;
            if (val2 != "nada") {
                world.listarTerritorioEspecifico(val2);
            } else
                world.listarTerritorios();

        }
    } while (val != "sair");

    return 0;
}

/*
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
}*/