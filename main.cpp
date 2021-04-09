#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <ctime>
#include <cmath>
#include <vector>
#include <cstring>
#include <locale>
#include <fstream>

using namespace std;

#include "Corpos.h"
#include "Fun��es painel prim�rio.cpp"

int main()
{
    setlocale(LC_ALL, "portuguese");

    vector <CORPO> Planetas;

    int Resposta_Usuario = 0;

    do
    {
        system("cls");
        cout << "<<<==== Selecione a op��o que voc� deseja prosseguir ====>>>" << endl;
        cout << "# 1 -> Ler configura��o salva." << endl;
        cout << "# 2 -> Criar configura��o nova." << endl << endl;
        cout << "# ";
        cin >> Resposta_Usuario;
        fflush(stdin);
    }while(Resposta_Usuario < 1 || Resposta_Usuario > 2);

    switch(Resposta_Usuario)
    {
        case 1:
        {
            string Nome_do_Arquivo_Salvo;
            std::cout << " -> Lendo configura��o salva. . ." << std::endl << std::endl;
            std::cout << ". . .| Por favor, digite o nome do arquivo de texto |. . ." << std::endl << std::endl;
            std::cout << "# ";
            getline(cin, Nome_do_Arquivo_Salvo);

            Planetas = _Get_Planetas_Salvos(Nome_do_Arquivo_Salvo);

        }
        break;


        case 2:
        {
            std::cout << " -> Criando uma configura��o. . ." << std::endl << std::endl;
            Planetas = _Push_Planetas_Nao_Salvos();
        }
        break;
    }



    do
    {
        system("cls");
        cout << "<<<==== Deseja salvar os planetas utilizados?[S/N] ====>>>" << endl;
        cout << "# 1 -> Sim." << endl;
        cout << "# 2 -> N�o." << endl << endl;
        cout << "# ";
        cin >> Resposta_Usuario;
        fflush(stdin);
    }while(Resposta_Usuario < 1 || Resposta_Usuario > 2);

    if(Resposta_Usuario == 1){
        string Nome_do_Arquivo_a_Ser_Criado;
        cout << endl << endl;
        cout << "-> Criando arquivo de texto na pasta do execut�vel." << std::endl << std::endl;
        std::cout << ". . .| Por favor, digite o nome do arquivo de texto |. . ." << std::endl << std::endl;
        std::cout << "# ";
        getline(cin, Nome_do_Arquivo_a_Ser_Criado);

        _Salvar_Planetas_em_Arquivo(Planetas, Nome_do_Arquivo_a_Ser_Criado);
    }

    return 0;
}
