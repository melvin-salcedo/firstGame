#include <list>
class Bala:public NAVE{
    private:
        int x;int y;
        int controlador;
        int tiempo=0;
        int eliminar;

    public:
        Bala(int _x=200,int _y=200,int c=1,int e=0):x(_x),y(_y),controlador(c),eliminar(e){}
        int get_controlador(){return controlador;}
        int get_x(){return x;}
        int get_y(){return y;}
        int get_eliminar(){return eliminar;}
        void set_x(int);
        void set_y(int);
        void set_controlador(int);
        void set_eliminar(int valor){eliminar=valor;}
        void fijar_bala(BITMAP*,BITMAP*,NAVE,BITMAP*,BITMAP*);
        void borrar_balas();
        list<Bala*>rayo;
        list<Bala*>::iterator B;
};
void Bala::set_controlador(int g){
    controlador=g;
}
void Bala::set_x(int h){
    x+=h;
}
void Bala::set_y(int h){
    y+=h;
}

void Bala::borrar_balas(){
    if(key[KEY_UP]){set_controlador(1);}
    else if(key[KEY_RIGHT]){set_controlador(2);}
    else if(key[KEY_DOWN]){set_controlador(3);}
    else if(key[KEY_LEFT]){set_controlador(4);}

}

void Bala::fijar_bala(BITMAP*pantalla,BITMAP*laser,NAVE  enlace,BITMAP*rol,BITMAP *explo){
    borrar_balas();
    if(tiempo==90){
        if(key[KEY_SPACE]){
            if(get_controlador()==1){
                rayo.push_back(new Bala(enlace.get_x()+24,enlace.get_y()+36,get_controlador(),get_eliminar()));
                rayo.push_back(new Bala(enlace.get_x()+63,enlace.get_y()+36,get_controlador(),get_eliminar()));
            }
            else if(get_controlador()==2){
                rayo.push_back(new Bala(enlace.get_x()+44,enlace.get_y()+25,get_controlador(),get_eliminar()));
                rayo.push_back(new Bala(enlace.get_x()+44,enlace.get_y()+62,get_controlador(),get_eliminar()));
            }
            else if(get_controlador()==3){
                rayo.push_back(new Bala(enlace.get_x()+24,enlace.get_y()+55,get_controlador(),get_eliminar()));
                rayo.push_back(new Bala(enlace.get_x()+63,enlace.get_y()+55,get_controlador(),get_eliminar()));
            }
            else if(get_controlador()==4){
                rayo.push_back(new Bala(enlace.get_x()+35,enlace.get_y()+24,get_controlador(),get_eliminar()));
                rayo.push_back(new Bala(enlace.get_x()+35,enlace.get_y()+62,get_controlador(),get_eliminar()));
            }
        }
        tiempo=0;
    }
    tiempo++;

    for(B=rayo.begin();B!=rayo.end();B++){
        if((*B)->get_controlador()==1){
            draw_sprite(pantalla,laser,(*B)->get_x(),(*B)->get_y());
            (*B)->set_y(-1);
            if((*B)->get_y()<-10||(*B)->get_eliminar()==1){

                delete (*B);
                B=rayo.erase(B);
            }
        }
        else if((*B)->get_controlador()==2){
            draw_sprite(pantalla,rol,(*B)->get_x(),(*B)->get_y());
            (*B)->set_x(1);
            if((*B)->get_x()>1366||(*B)->get_eliminar()==1){
                delete (*B);
                B=rayo.erase(B);
            }
        }
        else if((*B)->get_controlador()==3){
            draw_sprite(pantalla,laser,(*B)->get_x(),(*B)->get_y());
            (*B)->set_y(1);
            if((*B)->get_y()>766||(*B)->get_eliminar()==1){
                delete (*B);
                B=rayo.erase(B);
            }
        }
        else if((*B)->get_controlador()==4){
            draw_sprite(pantalla,rol,(*B)->get_x(),(*B)->get_y());
            (*B)->set_x(-1);
            if((*B)->get_y()<-10||(*B)->get_eliminar()==1){
                delete (*B);
                B=rayo.erase(B);
            }
        }
    }
}





























