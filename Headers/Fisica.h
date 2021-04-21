#ifndef FISICA_H_INCLUDED
#define FISICA_H_INCLUDED

#include <vector>
#include "../Headers/Corpos.h"

float _Calcular_Distancia_Entre_Corpos(CORPO Planeta1, CORPO Planeta2);

bool _Colisao_Circulos(float Raio_Corpo_1, float Raio_Corpo_2, float Distancia_Corpos);

// Constante gravitacional = 6,67408
float _Calcular_Gravidade_Corpos(int Massa_Corpo_1, int Massa_Corpo_2, float Distancia_Corpos);

void _Calcular_Velocidade_XY_Corpos(float Frames_Por_Segundo, CORPO &Planeta_1, CORPO &Planeta_2, float Gravidade_Corpos);

void _Calcular_Impacto(CORPO &Planeta_1, CORPO &Planeta_2);

void _Ajustar_Velocidades_Iniciais_Ao_FPS(unsigned short int FPS, std::vector <CORPO> &Planetas);
#endif // FISICA_H_INCLUDED
