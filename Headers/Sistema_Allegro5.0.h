#ifndef SISTEMA_ALLEGRO5_0_H_INCLUDED
#define SISTEMA_ALLEGRO5_0_H_INCLUDED

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>

class DISPLAY{
    private:
        ALLEGRO_DISPLAY *Janela = NULL;
        ALLEGRO_TIMER *Timer = NULL;
        ALLEGRO_EVENT_QUEUE *Fila_Eventos = NULL;

        unsigned short int FPS = 60.0;

        unsigned int Largura_Tela = 720;
        unsigned int Altura_Tela  = 720;

    public:
        ALLEGRO_EVENT_QUEUE*    _Get_Event_Queue    (void);
        ALLEGRO_DISPLAY*        _Get_Display        (void);
        unsigned short int      _Get_FPS            (void);
        unsigned int            _Get_Largura_Tela   (void);
        unsigned int            _Get_Altura_Tela    (void);

        void _Push_FPS  (unsigned short int PFPS);

        void _Atualizar_Tamanho_Display (unsigned int Largura, unsigned int Altura);
        void _Registrar_Eventos         (void);

        bool _Criar_Sistema_Allegro     (void);
        void _Destuir_Sistema_Allegro   (void);

};


void _Erro_Box(const char *txt);

bool _Iniciar_Sistema_Allegro(void);

#endif // SISTEMA_ALLEGRO5_0_H_INCLUDED
