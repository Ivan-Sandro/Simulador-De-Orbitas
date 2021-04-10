#ifndef CORPOS_H_INCLUDED
#define CORPOS_H_INCLUDED

#include <cmath>
#include <iostream>
#include <fstream>

class CORPO{
    private:
        int     X         = 0, Y      = 0;
        float   Vel_X     = 0, Vel_Y  = 0;
        float   Massa     = 0;
        float   Raio      = 0;
        float   Volume    = 0;
        float   Densidade = 0;

    public:
        int     _Get_X          (void);
        int     _Get_Y          (void);
        float   _Get_Massa      (void);
        float   _Get_Raio       (void);
        float   _Get_Vel_X      (void);
        float   _Get_Vel_Y      (void);
        float   _Get_Volume     (void);
        float   _Get_Densidade  (void);

        void _Push_Pos_X            (int PX);
        void _Push_Pos_Y            (int PY);

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
