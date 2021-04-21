

#include "..\Headers\Corpos.h"

float   CORPO::_Get_Pos_X       (void)  {return X;              }
float   CORPO::_Get_Pos_Y       (void)  {return Y;              }
float   CORPO::_Get_Massa       (void)  {return Massa;          }
float   CORPO::_Get_Raio        (void)  {return Raio;           }
float   CORPO::_Get_Vel_X       (void)  {return Vel_X;          }
float   CORPO::_Get_Vel_Y       (void)  {return Vel_Y;          }
float   CORPO::_Get_Volume      (void)  {return Volume;         }
float   CORPO::_Get_Densidade   (void)  {return Densidade;      }
float   CORPO::_Get_Elasticidade(void)  {return Elasticidade;   }

unsigned char CORPO::_Get_Cor_R(void)  {return Cor_R;      }
unsigned char CORPO::_Get_Cor_G(void)  {return Cor_G;      }
unsigned char CORPO::_Get_Cor_B(void)  {return Cor_B;      }

void    CORPO::_Push_Pos_X        (float PX)            {X = PX;                        }
void    CORPO::_Push_Pos_Y        (float PY)            {Y = PY;                        }
void    CORPO::_Push_Vel_X        (float PVel_X)        {Vel_X = PVel_X;                }
void    CORPO::_Push_Vel_Y        (float PVel_Y)        {Vel_Y = PVel_Y;                }
void    CORPO::_Push_Massa        (float PMassa)        {Massa = PMassa;                }
void    CORPO::_Push_Raio         (float PRaio)         {Raio = PRaio;                  }
void    CORPO::_Push_Volume       (float PVolume)       {Volume = PVolume;              }
void    CORPO::_Push_Densidade    (float PDensidade)    {Densidade = PDensidade;        }
void    CORPO::_Push_Elasticidade (float PElasticidade) {Elasticidade = PElasticidade;  }

void    CORPO::_Push_Cor_R        (unsigned char Pigmento){Cor_R = Pigmento;    }
void    CORPO::_Push_Cor_G        (unsigned char Pigmento){Cor_G = Pigmento;    }
void    CORPO::_Push_Cor_B        (unsigned char Pigmento){Cor_B = Pigmento;    }

void    CORPO::_Push_Cores        (unsigned char R, unsigned char G, unsigned char B){Cor_R = R ; Cor_G = G ; Cor_B = B ;}


void CORPO::_Push_Raio_com_Volume(float PVolume){
    Raio = pow((PVolume/3.14159265359)*0.75, 1.0/3.0);
}

void CORPO::_Printar(void){
    unsigned short int Int_Cor_R = Cor_R;
    unsigned short int Int_Cor_G = Cor_G;
    unsigned short int Int_Cor_B = Cor_B;

    std::cout << "POS X        : " << X            << std::endl;
    std::cout << "POS Y        : " << Y            << std::endl;
    std::cout << "VEL X        : " << Vel_X        << std::endl;
    std::cout << "VEL Y        : " << Vel_Y        << std::endl;
    std::cout << "MASSA        : " << Massa        << std::endl;
    std::cout << "RAIO         : " << Raio         << std::endl;
    std::cout << "VOLUME       : " << Volume       << std::endl;
    std::cout << "DENSIDADE    : " << Densidade    << std::endl;
    std::cout << "COR VERMELHO : " << Int_Cor_R    << std::endl;
    std::cout << "COR VERDE    : " << Int_Cor_G    << std::endl;
    std::cout << "COR AZUL     : " << Int_Cor_B    << std::endl;
    std::cout << "ELASTICIDADE : " << Elasticidade << std::endl;
    std::cout << "=========================>>>"    << std::endl;
}
void CORPO::_Salvar_em_Arquivo(std::ofstream &Arquivo){
    unsigned short int Int_Cor_R = Cor_R;
    unsigned short int Int_Cor_G = Cor_G;
    unsigned short int Int_Cor_B = Cor_B;

    Arquivo << "LUGAR X.......: " << X              << std::endl;
    Arquivo << "LUGAR Y.......: " << Y              << std::endl;
    Arquivo << "VELOCIDADE X..: " << Vel_X          << std::endl;
    Arquivo << "VELOCIDADE Y..: " << Vel_Y          << std::endl;
    Arquivo << "MASSA.........: " << Massa          << std::endl;
    Arquivo << "VOLUME........: " << Volume         << std::endl;
    Arquivo << "DENSIDADE.....: " << Densidade      << std::endl;
    Arquivo << "COR VERMELHO..: " << Int_Cor_R      << std::endl;
    Arquivo << "COR VERDE.....: " << Int_Cor_G      << std::endl;
    Arquivo << "COR AZUL......: " << Int_Cor_B      << std::endl;
    Arquivo << "ELASTICIDADE..: " << Elasticidade   << std::endl;
    Arquivo << "==============================>>>"  << std::endl;
}

void CORPO::_Zerar(void){
    X               = 0, Y      = 0;
    Vel_X           = 0, Vel_Y  = 0;
    Massa           = 0;
    Raio            = 0;
    Volume          = 0;
    Densidade       = 0;
    Raio            = 0;
    Cor_R           = 0; Cor_G  = 0; Cor_B  = 0;
    Elasticidade    = 0;
}
