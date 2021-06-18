
#include "../Headers/Mouse.h"

void _Mover_Camera(unsigned char Segurando_clique, long int &Camera_Pos_X, long int &Camera_Pos_Y, ALLEGRO_EVENT &evento){
    if(Segurando_clique == 1)
    {
        Camera_Pos_X += evento.mouse.dx;
        Camera_Pos_Y += evento.mouse.dy;
    }
}
