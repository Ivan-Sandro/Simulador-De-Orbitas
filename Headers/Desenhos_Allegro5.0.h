#ifndef DESENHOS_ALLEGRO5_0_H_INCLUDED
#define DESENHOS_ALLEGRO5_0_H_INCLUDED

/*****************************************
*
*   Biblioteca que irá desenhar os Corpos na tela de forma mais fácil.
*
******************************************/

#include "../Headers/Corpos.h"
#include <allegro5/allegro_primitives.h>

void _Desenhar_Corpo(CORPO &Planeta, long int &Pos_Camera_X, long int &Pos_Camera_Y);

#endif // DESENHOS_ALLEGRO5_0_H_INCLUDED
