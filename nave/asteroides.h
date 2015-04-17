#include <list>
#include <allegro.h>
class Meteoro:public Bala,public NAVE{
    int x;
    int y;
    int etiqueta;
    int numero=1;
    int yy=0,xx=0, velocidad=0;
    int personal,comparacion=1;
    int puntaje=0,cuerpos=0;
    int vida=110;
    int fin;

public:
    int contador_=0;
    Meteoro(int _x=0,int _y=0,int n=1,int e=10,int p=0,int f=0):x(_x),y(_y),numero(n),etiqueta(e),personal(p),fin(f){}
    int get_fin(){return fin;}
    int get_x(){return x;}
    int get_y(){return y;}
    int get_personal(){return personal;}
    int get_yy(){return yy;}
    int get_etiqueta(){return etiqueta;}
    int get_numero(){return numero;}
    void set_etiqueta(int e){etiqueta=e;}
    void set_x(float);
    void set_personal(int v){personal=v;}
    void set_y(float);
    void set_fin(int finn){fin=finn;}
    void set_numero(int valor){numero=valor;}
    void mover_meteoro(BITMAP*,BITMAP*,NAVE,Bala,BITMAP*,BITMAP*,BITMAP*,BITMAP*);
    void detectar_colision(Bala,BITMAP*,BITMAP*);
    void contador_de_puntos(BITMAP*);
    void crear_vida(BITMAP*,BITMAP*,BITMAP*);
    void destroy_nave(NAVE,BITMAP*,BITMAP*);

    list<Meteoro*>rocas;
    list<Meteoro*>::iterator actual;
};
void Meteoro::set_x(float valor){
    x+=valor;
}
void Meteoro::destroy_nave(NAVE enlace,BITMAP*pantalla,BITMAP*explo2){
    for(actual = rocas.begin() ; actual != rocas.end() ; actual++){
        if(enlace.get_x()-119==(*actual)->get_x()-10){

                draw_sprite(pantalla,explo2,222,222);

            delete (*actual);
            actual=rocas.erase(actual);
        }
    }

}
void Meteoro::crear_vida(BITMAP*pantalla,BITMAP*vid,BITMAP*saludd){
    draw_sprite(pantalla,vid,10,10);
    for(int vi=0;vi<=vida;vi+=22){
        draw_sprite(pantalla,saludd,75+vi,10);
    }
}
void Meteoro::contador_de_puntos(BITMAP*pantalla){

    textprintf(pantalla,font ,300,29,pallete_color[100],"CUERPOS DESTRUIDOS ----- %d",cuerpos);
    textprintf(pantalla,font ,300,10,pallete_color[100],"PUNTAJE TOTAL      ----- %d",puntaje);

}
void Meteoro::detectar_colision(Bala rifle,BITMAP*explo,BITMAP*pantalla){
    for(actual = rocas.begin() ; actual != rocas.end() ; actual++){
        for(rifle.B = rifle.rayo.begin() ; rifle.B != rifle.rayo.end() ; rifle.B++){
            if((*actual)->get_y()<(*rifle.B)->get_y()&&(*actual)->get_y()+70>(*rifle.B)->get_y()+10){
               if((*actual)->get_x()+80<(*rifle.B)->get_x()&&(*actual)->get_x()+160>(*rifle.B)->get_x()+10){
                    if(comparacion==1){
                        velocidad=1;
                        delete (*actual);
                        actual=rocas.erase(actual);
                        (*actual)->set_personal(1);
                        (*rifle.B)->set_eliminar(1);
                        puntaje+=50;
                        cuerpos+=1;
                    }
                    comparacion=0;
               }
            }
        }
        comparacion=1;
    }
}


void Meteoro::mover_meteoro(BITMAP*pantalla,BITMAP*roca1,NAVE enlace,Bala ayuda,BITMAP*explo,BITMAP*vid,BITMAP*saludd,BITMAP*explo2){
    draw_sprite(pantalla,explo,444,444);
    contador_de_puntos(pantalla);
    crear_vida(pantalla,vid,saludd);
    if(yy==800){
        rocas.push_back(new Meteoro(-200,rand()%600,get_numero(),get_etiqueta(),get_personal(),get_fin()));
        yy=0;
    }
    yy++;
    detectar_colision(ayuda,explo,pantalla);
    destroy_nave(enlace,pantalla,explo2);

    for(actual = rocas.begin() ; actual != rocas.end() ; actual++){
        draw_sprite(pantalla,roca1,(*actual)->get_x(),(*actual)->get_y());
        if((*actual)->get_numero()==1){
            (*actual)->set_x(1);
            (*actual)->set_numero(0);
        }
        if((*actual)->get_x()>1300){
                delete (*actual);
                actual=rocas.erase(actual);
                velocidad=0;
        }
        if((*actual)->get_etiqueta()==0){
            delete (*actual);
            actual=rocas.erase(actual);
        }
    }
    if(xx==7){
        for(actual = rocas.begin() ; actual != rocas.end() ; actual++){
            (*actual)->set_numero(1);
        }
        xx=0;
    }
    xx++;
}
