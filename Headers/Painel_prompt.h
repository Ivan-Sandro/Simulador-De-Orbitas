#ifndef PAINEL_PROMPT_H_INCLUDED
#define PAINEL_PROMPT_H_INCLUDED

/*****************************************************************
*
*   Biblioteca respons�vel pelas fun��es que envolvem o painel do programa, o seu prompt
*   incluindo as decis�es como salvar a configura��o em um arquivo de texto.
*
******************************************************************/

#include <vector>
#include <cstring>
#include "..\Headers\Corpos.h"

std::vector <CORPO> _Get_Planetas_Salvos(std::string Nome_Do_Arquivo);

void _Push_Informasoes_EXTRAS_Nao_Salvos(CORPO &Planeta_Alocador);

std::vector <CORPO> _Push_Planetas_Nao_Salvos(void);

bool _Salvar_Planetas_em_Arquivo(std::vector <CORPO> Planetas, std::string Nome_Do_Arquivo);

#endif // PAINEL_PROMPT_H_INCLUDED
