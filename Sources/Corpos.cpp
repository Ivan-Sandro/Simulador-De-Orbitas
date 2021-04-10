
#include "..\Headers\Corpos.h"

int     CORPO::_Get_X          (void)  {return X;          }
int     CORPO::_Get_Y          (void)  {return Y;          }
float   CORPO::_Get_Massa      (void)  {return Massa;      }
float   CORPO::_Get_Raio       (void)  {return Raio;       }
float   CORPO::_Get_Vel_X      (void)  {return Vel_X;      }
float   CORPO::_Get_Vel_Y      (void)  {return Vel_Y;      }
float   CORPO::_Get_Volume     (void)  {return Volume;     }
float   CORPO::_Get_Densidade  (void)  {return Densidade;  }

void    CORPO::_Push_Pos_X        (int PX)            {X = PX;}
void    CORPO::_Push_Pos_Y        (int PY)            {Y = PY;}
void    CORPO::_Push_Vel_X        (float PVel_X)      {Vel_X = PVel_X;}
void    CORPO::_Push_Vel_Y        (float PVel_Y)      {Vel_Y = PVel_Y;}
void    CORPO::_Push_Massa        (float PMassa)      {Massa = PMassa;}
void    CORPO::_Push_Raio         (float PRaio)       {Raio = PRaio;}
void    CORPO::_Push_Volume       (float PVolume)     {Volume = PVolume;}
void    CORPO::_Push_Densidade    (float PDensidade)  {Densidade = PDensidade;}


void CORPO::_Push_Raio_com_Volume(float PVolume){
    Raio = pow((PVolume/3.14)*0.75, 1.0/3.0);
}

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
