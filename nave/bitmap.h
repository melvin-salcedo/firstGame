#include <allegro.h>
class imagen{
public:
    void iniciar();
    void begining();
    BITMAP *pantalla = create_bitmap(1340,700);
    BITMAP *fondo_uno = load_bitmap("titulo1.bmp",NULL);
    BITMAP *fondo_dos = load_bitmap("titulo2.bmp",NULL);
    BITMAP *fondo_tres= load_bitmap("titulo3.bmp",NULL);
    BITMAP *cursor = load_bitmap("puntero.bmp",NULL);
    BITMAP *espacio= load_bitmap("pelea1.bmp",NULL);
    BITMAP *espacio1=load_bitmap("fondo meteoro.bmp",NULL);
    BITMAP *espacio2=load_bitmap("fondo meteoro1.bmp",NULL);

    BITMAP *nave000=load_bitmap("nave0.bmp",NULL);
    BITMAP *nave00=load_bitmap("nave00.bmp",NULL);
    BITMAP *nave01=load_bitmap("nave1.bmp",NULL);
    BITMAP *nave02=load_bitmap("nave2.bmp",NULL);
    BITMAP *nave03=load_bitmap("nave3.bmp",NULL);
    BITMAP *laser=load_bitmap("bala_bos0.bmp",NULL);
    BITMAP *rifle=load_bitmap("rifle.bmp",NULL);
    BITMAP *explo=load_bitmap("bos.bmp",NULL);
    BITMAP *esplo2=load_bitmap("explo2.bmp",NULL);
    BITMAP *roca1=load_bitmap("ares1.bmp",NULL);
    BITMAP *saludddd=load_bitmap("vida.bmp",NULL);
    BITMAP *texto=load_bitmap("texto.bmp",NULL);
    BITMAP *bos=load_bitmap("bos.bmp",NULL);


};
void imagen::iniciar(){
    destroy_bitmap(pantalla);
    destroy_bitmap(fondo_uno);
    destroy_bitmap(fondo_tres);
    destroy_bitmap(fondo_dos);
    destroy_bitmap(cursor);
    destroy_bitmap(espacio);
    destroy_bitmap(espacio1);
    destroy_bitmap(espacio2);
    destroy_bitmap(nave00);
    destroy_bitmap(nave01);
    destroy_bitmap(nave02);
    destroy_bitmap(nave03);
    destroy_bitmap(laser);
    destroy_bitmap(rifle);
    destroy_bitmap(explo);
    destroy_bitmap(roca1);
}

