#ifndef FUNSOES_PAINEL_PRIMARIO_H_INCLUDED
#define FUNSOES_PAINEL_PRIMARIO_H_INCLUDED

#include <vector>
#include "..\Headers\Corpos.h"

std::vector <CORPO> _Get_Planetas_Salvos(std::string Nome_Do_Arquivo);

void _Push_Informasoes_EXTRAS_Nao_Salvos(CORPO &Planeta_Alocador);

std::vector <CORPO> _Push_Planetas_Nao_Salvos(void);

bool _Salvar_Planetas_em_Arquivo(std::vector <CORPO> Planetas, std::string Nome_Do_Arquivo);

#endif // FUNSOES_PAINEL_PRIMARIO_H_INCLUDED
