#ifndef CORPOS_H_INCLUDED
#define CORPOS_H_INCLUDED

/**************************************
*
*   Biblioteca da classe e funções importantes dos Planetas que nós teremos durante a simulação ( Corpos )
*
***************************************/

#include <cmath>
#include <iostream>
#include <fstream>

#include <allegro5/allegro.h>

class CORPO{
    private:
        int     X         = 0, Y      = 0;
        float   Vel_X     = 0, Vel_Y  = 0;
        float   Massa     = 0;
        float   Raio      = 0;
        float   Volume    = 0;
        float   Densidade = 0;
    
        ALLEGRO_COLOR Cor = al_map_rgb( 0, 0, 0);

    public:
        float   _Get_X          (void);
        float   _Get_Y          (void);
        float   _Get_Massa      (void);
        float   _Get_Raio       (void);
        float   _Get_Vel_X      (void);
        float   _Get_Vel_Y      (void);
        float   _Get_Volume     (void);
        float   _Get_Densidade  (void);
    
        ALLEGRO_COLOR _Get_Cor  (void);

        void _Push_Pos_X            (float PX);
        void _Push_Pos_Y            (float PY);

        void _Push_Vel_X            (float PVel_X);
        void _Push_Vel_Y            (float PVel_Y);

        void _Push_Massa            (float PMassa);
        void _Push_Raio             (float PRaio);
        void _Push_Volume           (float PVolume);
        void _Push_Densidade        (float PDensidade);

        void _Push_Raio_com_Volume  (float PVolume);

        void _Salvar_em_Arquivo(std::ofstream &Arquivo);
        void _Printar(void);
        void _Zerar(void);
};

#endif // CORPOS_H_INCLUDED
