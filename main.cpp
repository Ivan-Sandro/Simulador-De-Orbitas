#include <iostream>
#include <vector>

using namespace std;

#include "Headers/Corpos.h"
#include "Headers/Painel_prompt.h"

int main()
{
    setlocale(LC_ALL, "portuguese");

    vector <CORPO> Planetas;

    int Resposta_Usuario = 0;

    do
    {
        system("cls");
        cout << "<<<==== Selecione a opção que você deseja prosseguir ====>>>" << endl;
        cout << "# 1 -> Ler configuração salva." << endl;
        cout << "# 2 -> Criar configuração nova." << endl << endl;
        cout << "# ";
        cin >> Resposta_Usuario;
        fflush(stdin);
    }while(Resposta_Usuario < 1 || Resposta_Usuario > 2);

    switch(Resposta_Usuario)
    {
        case 1:
        {
            string Nome_do_Arquivo_Salvo;
            std::cout << " -> Lendo configuração salva. . ." << std::endl << std::endl;
            std::cout << ". . .| Por favor, digite o nome do arquivo de texto |. . ." << std::endl << std::endl;
            std::cout << "# ";
            getline(cin, Nome_do_Arquivo_Salvo);

            Planetas = _Get_Planetas_Salvos(Nome_do_Arquivo_Salvo);

        }
        break;


        case 2:
        {
            std::cout << " -> Criando uma configuração. . ." << std::endl << std::endl;
            Planetas = _Push_Planetas_Nao_Salvos();
        }
        break;
    }

    // TEMPORARIO, apenas para mostrar a configuração enquanto continuo o código

    for(size_t X = 0 ; X < Planetas.size() ; X++)
        Planetas[X]._Printar();

    cout << endl << endl;
    system("pause");

    //===========================================================

    do
    {
        system("cls");
        cout << "<<<==== Deseja salvar os planetas utilizados?[S/N] ====>>>" << endl;
        cout << "# 1 -> Sim." << endl;
        cout << "# 2 -> Não." << endl << endl;
        cout << "# ";
        cin >> Resposta_Usuario;
        fflush(stdin);
    }while(Resposta_Usuario < 1 || Resposta_Usuario > 2);

    if(Resposta_Usuario == 1){
        string Nome_do_Arquivo_a_Ser_Criado;
        cout << endl << endl;
        cout << "-> Criando arquivo de texto na pasta do executável." << std::endl << std::endl;
        std::cout << ". . .| Por favor, digite o nome do arquivo de texto |. . ." << std::endl << std::endl;
        std::cout << "# ";
        getline(cin, Nome_do_Arquivo_a_Ser_Criado);

        _Salvar_Planetas_em_Arquivo(Planetas, Nome_do_Arquivo_a_Ser_Criado);
    }

    return 0;
}
