#include <allegro.h>
#include "inicia.h"
#include "nave.h"
#include "fondos.h"
#include "balas.h"
#include "asteroides.h"
#include "bitmap.h"
#include "vida.h"
int main(){
    inicia_allegro(1340,700);
    inicia_audio(70,70);
    install_mouse();
    imagen bit;
    NAVE uno;
    mundo m;
    Bala l;
    Meteoro unico;

    bool salida=false;
    bool entrar=false;
    while(salida!=true){
        uno.pintar_pantalla(bit.pantalla,bit.fondo_uno,bit.fondo_dos,bit.fondo_tres,salida,entrar);
        while(entrar==true){
            uno.salir(entrar);
            m.mover_asteroides(bit.espacio1,bit.pantalla);
            l.fijar_bala(bit.pantalla,bit.rifle,uno,bit.laser,bit.explo);
            unico.mover_meteoro(bit.pantalla,bit.roca1,uno,l,bit.explo,bit.texto,bit.saludddd,bit.esplo2);
            uno.pintar_nave(bit.pantalla,bit.nave00,bit.nave01,bit.nave02,bit.nave03,bit.nave000);

            blit(bit.pantalla,screen,0,0,0,0,1340,700);
            blit(bit.espacio,bit.pantalla,0,0,0,0,1340,700);
        }
        draw_sprite(bit.pantalla,bit.cursor,mouse_x,mouse_y);
        blit(bit.pantalla,screen,0,0,0,0,1340,700);
        blit(bit.fondo_uno,bit.pantalla,0,0,0,0,1340,700);
    }
    bit.iniciar();
    return 0;
}
END_OF_MAIN();
