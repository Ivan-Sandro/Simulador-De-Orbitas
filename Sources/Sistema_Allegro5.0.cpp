
#include "../Headers/Sistema_Allegro5.0.h"

ALLEGRO_EVENT_QUEUE*  DISPLAY::_Get_Event_Queue     (void){ return Fila_Eventos;    }
ALLEGRO_DISPLAY*      DISPLAY::_Get_Display         (void){ return Janela;          }

unsigned short int    DISPLAY::_Get_FPS             (void){ return FPS;             }

unsigned int          DISPLAY::_Get_Largura_Tela    (void){ return Largura_Tela;    }
unsigned int          DISPLAY::_Get_Altura_Tela     (void){ return Altura_Tela;     }

void _Erro_Box(const char* txt){
    al_show_native_message_box(NULL, "ERROR", "Ocorreu o seguinte erro:", txt, NULL, ALLEGRO_MESSAGEBOX_ERROR);
}

void    DISPLAY::_Push_FPS  (unsigned short int PFPS){ FPS = PFPS; }

void DISPLAY::_Atualizar_Tamanho_Display (unsigned int Largura, unsigned int Altura){
    Largura_Tela = Largura;
    Altura_Tela = Altura;
    al_resize_display(Janela, Largura, Altura);
}

bool DISPLAY::_Criar_Sistema_Allegro(void){

    Janela = al_create_display(Largura_Tela, Altura_Tela);
    if(!Janela){
        _Erro_Box("Falha ao crear a janela.");
        return false;
    }

    Fila_Eventos = al_create_event_queue();
    if(!Fila_Eventos){
        _Erro_Box("Falha ao instalar a fila de eventos.");
        return false;
    }

    Timer = al_create_timer( 1.0 / FPS );
    if(!Timer){
        _Erro_Box("Falha ao criar o Timer.");
        return false;
    }
    return true;
}
void DISPLAY::_Destuir_Sistema_Allegro(void){

    if(Janela)al_destroy_display(Janela);
    if(Fila_Eventos)al_destroy_event_queue(Fila_Eventos);
    if(Timer)al_destroy_timer(Timer);
}

void DISPLAY::_Registrar_Eventos(void){

    al_register_event_source(Fila_Eventos, al_get_display_event_source(Janela));
    al_register_event_source(Fila_Eventos, al_get_mouse_event_source());
    al_register_event_source(Fila_Eventos, al_get_timer_event_source(Timer));
}

bool _Iniciar_Sistema_Allegro(void){

    if(!al_init()){
        _Erro_Box("Falha ao iniciar o Allegro.");
        return false;
    }

    if(!al_init_primitives_addon()){
        _Erro_Box("Falha ao iniciar os efeitos primitivos.");
        return false;
    }

    if(!al_install_mouse()){
        _Erro_Box("Falha ao instalar o mouse.");
        return false;
    }
    return true;
}


