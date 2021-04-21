
#include "../Headers/Fisica.h"

float _Calcular_Distancia_Entre_Corpos(CORPO Planeta_1, CORPO Planeta_2){

    float Distancia_X = Planeta_1._Get_Pos_X() - Planeta_2._Get_Pos_X();
    float Distancia_Y = Planeta_1._Get_Pos_Y() - Planeta_2._Get_Pos_Y();

    float Distancia_Planetas = sqrt((Distancia_X * Distancia_X) + (Distancia_Y * Distancia_Y));

    if(Distancia_Planetas < Planeta_1._Get_Raio() + Planeta_2._Get_Raio())
        return Planeta_1._Get_Raio() + Planeta_2._Get_Raio();
    else
        return Distancia_Planetas;
}

bool _Colisao_Circulos(float Raio_Corpo_1, float Raio_Corpo_2, float Distancia_Corpos){
    if(Raio_Corpo_1 + Raio_Corpo_2 >= Distancia_Corpos){
        return true;
    }
    return false;
}

float _Calcular_Gravidade_Corpos(int Massa_Corpo_1, int Massa_Corpo_2, float Distancia_Corpos){
    return ( 6.67408 * Massa_Corpo_1 * Massa_Corpo_2) / (Distancia_Corpos * Distancia_Corpos);
}

void _Calcular_Velocidade_XY_Corpos(float Frames_Por_Segundo, CORPO &Planeta_1, CORPO &Planeta_2, float Gravidade_Corpos){

    float Atrair_Corpo_1 = Gravidade_Corpos / Planeta_1._Get_Massa();
    float Atrair_Corpo_2 = Gravidade_Corpos / Planeta_2._Get_Massa();

    Atrair_Corpo_1 /= Frames_Por_Segundo;
    Atrair_Corpo_2 /= Frames_Por_Segundo;

    if(Planeta_1._Get_Pos_X() >= Planeta_2._Get_Pos_X()){
        Planeta_1._Push_Vel_X(Planeta_1._Get_Vel_X() - Atrair_Corpo_1);
        Planeta_2._Push_Vel_X(Planeta_2._Get_Vel_X() + Atrair_Corpo_2);
    }else{
        Planeta_1._Push_Vel_X(Planeta_1._Get_Vel_X() + Atrair_Corpo_1);
        Planeta_2._Push_Vel_X(Planeta_2._Get_Vel_X() - Atrair_Corpo_2);
    }

    if(Planeta_1._Get_Pos_Y() >= Planeta_2._Get_Pos_Y()){
        Planeta_1._Push_Vel_Y(Planeta_1._Get_Vel_Y() - Atrair_Corpo_1);
        Planeta_2._Push_Vel_Y(Planeta_2._Get_Vel_Y() + Atrair_Corpo_2);
    }else{
        Planeta_1._Push_Vel_Y(Planeta_1._Get_Vel_Y() + Atrair_Corpo_1);
        Planeta_2._Push_Vel_Y(Planeta_2._Get_Vel_Y() - Atrair_Corpo_2);
    }
}

void _Calcular_Impacto(CORPO &Planeta_1, CORPO &Planeta_2){

    Planeta_1._Push_Vel_X(-Planeta_1._Get_Vel_X() * Planeta_1._Get_Elasticidade());
    Planeta_1._Push_Vel_Y(-Planeta_1._Get_Vel_Y() * Planeta_1._Get_Elasticidade());

    Planeta_2._Push_Vel_X(-Planeta_2._Get_Vel_X() * Planeta_2._Get_Elasticidade());
    Planeta_2._Push_Vel_Y(-Planeta_2._Get_Vel_Y() * Planeta_2._Get_Elasticidade());
}

void _Ajustar_Velocidades_Iniciais_Ao_FPS(unsigned short int FPS, std::vector <CORPO> &Planetas){

    for(size_t X = 0 ; X < Planetas.size() ; X++)
    {
        Planetas[X]._Push_Vel_X(Planetas[X]._Get_Vel_X() / FPS);
        Planetas[X]._Push_Vel_Y(Planetas[X]._Get_Vel_Y() / FPS);
    }
}
