
#include "../Headers/Painel_prompt.h"

using namespace std;

vector <CORPO> _Get_Planetas_Salvos(string Nome_Do_Arquivo){

    vector <CORPO> Planetas;
    ifstream Arquivo;
    string Frase_Arquivo;
    float Numero_Convertido;
    unsigned short int Posisao_Lida_Arquivo = 0;
    CORPO Planeta_alocador;

    Arquivo.open(Nome_Do_Arquivo + ".txt");

    if(!Arquivo.is_open()){
        system("cls");
        cout << "### ERROR AO ABRIR O ARQUIVO. ###" << endl;
        getch();
        exit(1);
    }
    system("cls");

    while(!Arquivo.eof())
    {
        getline(Arquivo, Frase_Arquivo);

        if(isdigit(Frase_Arquivo[16]) || isdigit(Frase_Arquivo[17])){

            Numero_Convertido = stof(Frase_Arquivo.substr(15, Frase_Arquivo.size()));

            switch(Posisao_Lida_Arquivo)
            {
                case 0:
                    Planeta_alocador._Push_Pos_X(Numero_Convertido);
                break;

                case 1:
                    Planeta_alocador._Push_Pos_Y(Numero_Convertido);
                break;

                case 2:
                    Planeta_alocador._Push_Vel_X(Numero_Convertido);
                break;

                case 3:
                    Planeta_alocador._Push_Vel_Y(Numero_Convertido);
                break;

                case 4:
                    Planeta_alocador._Push_Massa(Numero_Convertido);
                break;

                case 5:
                    Planeta_alocador._Push_Volume(Numero_Convertido);
                    Planeta_alocador._Push_Raio_com_Volume(Numero_Convertido);
                break;

                case 6:
                    Planeta_alocador._Push_Densidade(Numero_Convertido);
                break;

                case 7:
                    Planeta_alocador._Push_Cor_R(Numero_Convertido);
                break;

                case 8:
                    Planeta_alocador._Push_Cor_G(Numero_Convertido);
                break;

                case 9:
                    Planeta_alocador._Push_Cor_B(Numero_Convertido);
                break;

                case 10:
                    Planeta_alocador._Push_Elasticidade(Numero_Convertido);
                break;

            }

            Posisao_Lida_Arquivo++;
        }else{
            Planetas.push_back(Planeta_alocador);
            Posisao_Lida_Arquivo = 0;
        }

    }
    Arquivo.close();

    return Planetas;
}

void _Push_Informasoes_EXTRAS_Nao_Salvos(CORPO &Planeta_Alocador){

    int Imput;
    char Char_Escolhas;

    do
    {
        fflush(stdin);
        cout << endl << endl;
        cout << "##Deseja dar informações extras para melhor precisão geral do programa?[V/D/N]##";
        cout << endl;

        cout << "# V -> Informar o VOLUME" << endl;
        cout << "# D -> Informar a DENSIDADE" << endl;
        cout << "# N -> Não fornecer informações extras" << endl;
        cout << endl << "# ";

        cin >> Char_Escolhas;
        fflush(stdin);

    }while(Char_Escolhas != 'd' && Char_Escolhas != 'v' && Char_Escolhas != 'n'
        && Char_Escolhas != 'D' && Char_Escolhas != 'V' && Char_Escolhas != 'N');


    if(Char_Escolhas == 'n' || Char_Escolhas == 'N')
    {
        Planeta_Alocador._Push_Densidade(1.0);
        Planeta_Alocador._Push_Volume(Planeta_Alocador._Get_Massa());
        Planeta_Alocador._Push_Raio_com_Volume(Planeta_Alocador._Get_Volume());

        cout << endl << endl;
        cout << "--->>> Densidade considerada e salva como 1.0; Volume = Massa.";
        cout << endl << endl;

    }
    else if(Char_Escolhas == 'v' || Char_Escolhas == 'V')
    {
        cout << endl;
        cout << "VOLUME........: ";
        cin >> Imput;
        fflush(stdin);

        Planeta_Alocador._Push_Volume(Imput);

        Planeta_Alocador._Push_Raio_com_Volume(Planeta_Alocador._Get_Volume());
        Planeta_Alocador._Push_Densidade(Planeta_Alocador._Get_Massa()/Planeta_Alocador._Get_Volume());
    }
    else
    {
        cout << endl;
        cout << "DENSIDADE......: ";
        cin >> Imput;
        fflush(stdin);

        Planeta_Alocador._Push_Densidade(Imput);

        Planeta_Alocador._Push_Volume(Planeta_Alocador._Get_Massa()/Planeta_Alocador._Get_Densidade());
        Planeta_Alocador._Push_Raio_com_Volume(Planeta_Alocador._Get_Volume());
    }
}

vector <CORPO> _Push_Planetas_Nao_Salvos(void){
    vector <CORPO> Planetas;
    char Char_Escolhas;
    float Imput;

    const char *Valores_Name[9] = {"LUGAR X.......: ",
                                   "LUGAR Y.......: ",
                                   "VELOCIDADE X..: ",
                                   "VELOCIDADE Y..: ",
                                   "MASSA.........: ",
                                   "COR VERMELHO..: ",
                                   "COR VERDE.....: ",
                                   "COR AZUL......: ",
                                   "ELASTICIDADE..: "};

    CORPO Planeta_Alocador;

    cout << endl << endl;
    cout << "<<<==== Defina as informações dos planetas ====>>>" << endl << endl;

    do
    {
        for(unsigned short int Fileira = 0 ; Fileira < 9 ; Fileira++)
        {
            cout << Valores_Name[Fileira];
            cin >> Imput;
            cin.clear();
            fflush(stdin);

            switch(Fileira)
            {
                case 0:
                    Planeta_Alocador._Push_Pos_X(Imput);
                break;

                case 1:
                    Planeta_Alocador._Push_Pos_Y(Imput);
                break;

                case 2:
                    Planeta_Alocador._Push_Vel_X(Imput);
                break;

                case 3:
                    Planeta_Alocador._Push_Vel_Y(Imput);
                break;

                case 4:
                    Planeta_Alocador._Push_Massa(Imput);
                break;

                case 5:
                    Planeta_Alocador._Push_Cor_R(Imput);
                break;

                case 6:
                    Planeta_Alocador._Push_Cor_G(Imput);
                break;

                case 7:
                    Planeta_Alocador._Push_Cor_B(Imput);
                break;

                case 8:
                    Planeta_Alocador._Push_Elasticidade(Imput);
                break;
            }
        }

        _Push_Informasoes_EXTRAS_Nao_Salvos(Planeta_Alocador);

        Planetas.push_back(Planeta_Alocador);
        Planeta_Alocador._Zerar();

        do
        {
            cout << endl << endl << "Acrescentar mais algum corpo?[S/N]" << endl << endl << "# ";
            cin >> Char_Escolhas;
            fflush(stdin);
        }while(Char_Escolhas != 's' && Char_Escolhas != 'S' && Char_Escolhas != 'n' && Char_Escolhas != 'N');

    }while(Char_Escolhas == 'S' || Char_Escolhas == 's');

   return Planetas;
}

bool _Salvar_Planetas_em_Arquivo(vector <CORPO> Planetas, string Nome_Do_Arquivo){

    ofstream Arquivo;
    Arquivo.open(Nome_Do_Arquivo + ".txt");

    if(!Arquivo.is_open()){
        system("cls");
        cout << "### ERROR AO ABRIR O ARQUIVO. ###" << endl;
        return false;
    }

    for(size_t X = 0 ; X < Planetas.size() ; X++)
        Planetas[X]._Salvar_em_Arquivo(Arquivo);

    Arquivo.close();

    return true;
}
