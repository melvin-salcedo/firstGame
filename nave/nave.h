#include <iostream>
using namespace std;
class NAVE{
    int x,y;
    int posicion;

    int ndisparos;
public:
    NAVE(int _x=610,int _Y=280,int posi=0,int ndi=0):x(_x),y(_Y),posicion(posi),ndisparos(ndi){}
    void set_tiempos(int);
    int get_ndisparos(){return ndisparos;}
    void set_ndisparos(int);
    int get_x(){return x;}
    int get_y(){return y;}
    int get_posicion(){return posicion;}
    void set_x(int);
    void set_y(int);
    void set_posicion();

    void pintar_pantalla(BITMAP*,BITMAP*,BITMAP*,BITMAP*,bool&,bool&);
    void salir(bool&);
    void pintar_nave(BITMAP*,BITMAP*,BITMAP*,BITMAP*,BITMAP*,BITMAP*(&));
    void salir_menu_principal(bool &);
    void limite_de_salida(int &,int &);

    void pintar_laser(BITMAP*,BITMAP*);
};

void NAVE::set_ndisparos(int y){
    ndisparos=ndisparos+y;
}
void NAVE::pintar_laser(BITMAP*pantalla,BITMAP *laser){
    draw_sprite(pantalla,laser,get_x(),get_y());
}
void NAVE::limite_de_salida(int &z,int&h){
    if(get_y()<-100){
        z=get_x();
        h=700;
    }
    else if(get_y()>750){
        x=get_x();
        y=-100;
    }
    else if(get_x()>1340){
        x=-100;
        y=get_y();
    }
    else if(get_x()<-100){
        x=1340;
        y=get_y();
    }

}

void NAVE::set_posicion(){
    posicion+=2;
}

void NAVE::set_x(int numero_0){
    x+=numero_0;
}
void NAVE::set_y(int numero_1){
    y+=numero_1;
}
void NAVE::pintar_nave(BITMAP*pantalla,BITMAP*nave00,BITMAP*nave01,BITMAP*nave02,BITMAP*nave03,BITMAP*(&nave000)){
    draw_sprite(pantalla,nave000,x,y);
    if(key[KEY_UP]){
        if(posicion%3==0){
            set_y(-2);
            draw_sprite(pantalla,nave00,x,y);
            nave000=nave00;
        }
        limite_de_salida(x,y);
        set_posicion();

    }
    else if(key[KEY_DOWN]){
        if(posicion%3==0){
            set_y(2);
            draw_sprite(pantalla,nave02,x,y);
            nave000=nave02;

        }
        limite_de_salida(x,y);
        set_posicion();
    }
    else if(key[KEY_LEFT]){
        if(posicion%3==0){
            set_x(-2);
            draw_sprite(pantalla,nave03,x,y);
            nave000=nave03;
        }
        limite_de_salida(x,y);
        set_posicion();
    }
    else if(key[KEY_RIGHT]){
        if(posicion%3==0){
            set_x(2);
            draw_sprite(pantalla,nave01,x,y);
            nave000=nave01;
        }
        limite_de_salida(x,y);
        set_posicion();
    }
}
void NAVE::salir(bool &entrar){
    if(key[KEY_ESC]){
        entrar=false;
    }
}

void NAVE::pintar_pantalla(BITMAP*pantalla,BITMAP*fondo_uno,BITMAP*fondo_dos,BITMAP*fondo_tres,bool &salida,bool &entrar){
        if(mouse_x>531&&mouse_x<789&&mouse_y>384&&mouse_y<418){
            blit(fondo_dos,pantalla,0,0,0,0,1340,700);
            if(mouse_b &1){
                entrar=true;
            }
        }
        else if(mouse_x>590&&mouse_x<730&&mouse_y>458&&mouse_y<491){
            blit(fondo_tres,pantalla,0,0,0,0,1340,700);
            if(mouse_b &1){
                salida=true;
            }
        }
        else {
            blit(fondo_uno,pantalla,0,0,0,0,1340,700);
        }
}

