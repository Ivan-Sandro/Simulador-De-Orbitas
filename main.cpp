#include <iostream>
#include <vector>

using namespace std;

#include "Headers/Corpos.h"
#include "Headers/Painel_prompt.h"
#include "Headers/Sistema_Allegro5.0.h"
#include "Headers/Fisica.h"
#include "Headers/Desenhos_Allegro5.0.h"

int main()
{
    setlocale(LC_ALL, "portuguese");

    vector <CORPO> Planetas;

    ALLEGRO_EVENT evento;
    DISPLAY Painel;
    Painel._Get_Configurasao_Sistema();

    _Ajustar_Velocidades_Iniciais_Ao_FPS(Painel._Get_FPS(), Planetas);

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

    for(size_t X = 0 ; X < Planetas.size() ; X++) Planetas[X]._Printar();


    _Iniciar_Sistema_Allegro();


    Painel._Criar_Sistema_Allegro();
    Painel._Registrar_Eventos();

    al_start_timer(Painel._Get_Timer());

    bool Sair_Programa = false;

    do
    {
        al_wait_for_event(Painel._Get_Event_Queue(), &evento);

        switch(evento.type)
        {
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                Sair_Programa = true;
            break;

            case ALLEGRO_EVENT_TIMER:

                for(size_t X = 0 ; X < Planetas.size() -1 ; X++){
                    for(size_t Y = 1 ; Y < Planetas.size(); Y++){
                        if(Y > X)
                        {
                            _Calcular_Velocidade_XY_Corpos(Painel._Get_FPS(),Planetas[X], Planetas[Y], _Calcular_Gravidade_Corpos(Planetas[X]._Get_Massa(), Planetas[Y]._Get_Massa(), _Calcular_Distancia_Entre_Corpos(Planetas[X], Planetas[Y])));
                            if(_Colisao_Circulos(Planetas[X]._Get_Raio(), Planetas[Y]._Get_Raio(), _Calcular_Distancia_Entre_Corpos(Planetas[X], Planetas[Y])) == true)
                            {
                                _Calcular_Impacto(Planetas[X], Planetas[Y]);
                            }
                        }
                    }
                }

                for(size_t X = 0 ; X < Planetas.size() ; X++){
                    Planetas[X]._Push_Pos_X(Planetas[X]._Get_Pos_X() + Planetas[X]._Get_Vel_X() / Painel._Get_FPS());
                    Planetas[X]._Push_Pos_Y(Planetas[X]._Get_Pos_Y() + Planetas[X]._Get_Vel_Y() / Painel._Get_FPS());
                }

                al_clear_to_color(al_map_rgb(0, 0, 0));
                    for(size_t X = 0 ; X < Planetas.size() ; X++)_Desenhar_Corpo(Planetas[X]);
                al_flip_display();
            break;
        }

    }while(Sair_Programa != true);

    Painel._Destuir_Sistema_Allegro();

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