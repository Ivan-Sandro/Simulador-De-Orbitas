/**********************************************
*
*   Header responsável pela declaração da classe CORPO e suas funções
*   a classe corpo é a classe que guarda as variaveis de cada planeta
*   e suas funções de salvar, alocar, printar, etc.
*
************************************************/


#ifndef CORPOS_H_INCLUDED
#define CORPOS_H_INCLUDED

class CORPO{
    private:
        int     X           = 0, Y      = 0;
        float   Vel_X       = 0, Vel_Y  = 0;
        float   Massa       = 0;
        float   Raio        = 0;
        float   Volume      = 0;
        float   Densidade   = 0;

    public:
        int     _Get_X          (void)  {return X;          }
        int     _Get_Y          (void)  {return Y;          }
        float   _Get_Massa      (void)  {return Massa;      }
        float   _Get_Raio       (void)  {return Raio;       }
        float   _Get_Vel_X      (void)  {return Vel_X;      }
        float   _Get_Vel_Y      (void)  {return Vel_Y;      }
        float   _Get_Volume     (void)  {return Volume;     }
        float   _Get_Densidade  (void)  {return Densidade;  }

        void _Push_Pos_X    (int PX)            {X = PX;}
        void _Push_Pos_Y    (int PY)            {Y = PY;}

        void _Push_Vel_X    (float PVel_X)      {Vel_X = PVel_X;}
        void _Push_Vel_Y    (float PVel_Y)      {Vel_Y = PVel_Y;}

        void _Push_Massa    (float PMassa)      {Massa = PMassa;}

        void _Push_Raio     (float PRaio)       {Raio = PRaio;}

        void _Push_Volume   (float PVolume)     {Volume = PVolume;}

        void _Push_Densidade(float PDensidade)  {Densidade = PDensidade;}

        // Volume = Massa/Densidade.
        void _Push_Raio_com_Volume(float PVolume){
            Raio = pow((PVolume/3.14)*0.75, 1.0/3.0);   // Fórmula criada pela relação de Volume e raio de uma esfera.
        }

        void _Salvar_em_Arquivo(ofstream &Arquivo);
        void _Printar(void);
        void _Zerar(void);
};

void CORPO::_Printar(void){
    std::cout << "POS X     : " << X            << std::endl;
    std::cout << "POS Y     : " << Y            << std::endl;
    std::cout << "VEL X     : " << Vel_X        << std::endl;
    std::cout << "VEL Y     : " << Vel_Y        << std::endl;
    std::cout << "MASSA     : " << Massa        << std::endl;
    std::cout << "RAIO      : " << Raio         << std::endl;
    std::cout << "VOLUME    : " << Volume       << std::endl;
    std::cout << "DENSIDADE : " << Densidade    << std::endl;
    std::cout << "=========================>>>" << std::endl;
}
void CORPO::_Salvar_em_Arquivo(ofstream &Arquivo){
    Arquivo << "LUGAR X.......: " << X              << std::endl;
    Arquivo << "LUGAR Y.......: " << Y              << std::endl;
    Arquivo << "VELOCIDADE X..: " << Vel_X          << std::endl;
    Arquivo << "VELOCIDADE Y..: " << Vel_Y          << std::endl;
    Arquivo << "MASSA.........: " << Massa          << std::endl;
    Arquivo << "VOLUME........: " << Volume         << std::endl;
    Arquivo << "DENSIDADE.....: " << Densidade      << std::endl;
    Arquivo << "==============================>>>"  << std::endl;
}

void CORPO::_Zerar(void){
    X           = 0, Y      = 0;
    Vel_X       = 0, Vel_Y  = 0;
    Massa       = 0;
    Raio        = 0;
    Volume      = 0;
    Densidade   = 0;
}

#endif // CORPOS_H_INCLUDED
