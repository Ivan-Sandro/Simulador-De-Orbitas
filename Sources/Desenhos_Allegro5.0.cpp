
#include "../Headers/Desenhos_Allegro5.0.h"

void _Desenhar_Corpo(CORPO &Planeta){
    al_draw_filled_circle(Planeta._Get_Pos_X(), Planeta._Get_Pos_Y(), Planeta._Get_Raio(),
                          al_map_rgb(Planeta._Get_Cor_R(), Planeta._Get_Cor_G(), Planeta._Get_Cor_B()));
}
