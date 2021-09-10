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

class CORPO{
    private:
        float   X       , Y     ;
        float   Vel_X   , Vel_Y ;

        float   Massa           ;
        float   Raio            ;
        float   Volume          ;
        float   Densidade       ;
        float   Elasticidade    ;

        unsigned char Cor_R;
        unsigned char Cor_G;
        unsigned char Cor_B;


    public:
        float   _Get_Pos_X          (void);
        float   _Get_Pos_Y          (void);
        float   _Get_Massa          (void);
        float   _Get_Raio           (void);
        float   _Get_Vel_X          (void);
        float   _Get_Vel_Y          (void);
        float   _Get_Volume         (void);
        float   _Get_Densidade      (void);
        float   _Get_Elasticidade   (void);

        unsigned char _Get_Cor_R  (void);
        unsigned char _Get_Cor_G  (void);
        unsigned char _Get_Cor_B  (void);

        void _Push_Pos_X            (float PX);
        void _Push_Pos_Y            (float PY);

        void _Push_Vel_X            (float PVel_X);
        void _Push_Vel_Y            (float PVel_Y);

        void _Push_Massa            (float PMassa           );
        void _Push_Raio             (float PRaio            );
        void _Push_Volume           (float PVolume          );
        void _Push_Densidade        (float PDensidade       );
        void _Push_Elasticidade     (float PElasticidade    );

        void _Push_Cor_R            (unsigned char Pigmento);
        void _Push_Cor_G            (unsigned char Pigmento);
        void _Push_Cor_B            (unsigned char Pigmento);

        void _Push_Cores            (unsigned char R, unsigned char G, unsigned char B);

        void _Push_Raio_com_Volume  (float PVolume);

        void _Salvar_em_Arquivo(std::ofstream &Arquivo);
        void _Printar(void);
        void _Zerar(void);
};

#endif // CORPOS_H_INCLUDED
