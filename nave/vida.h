#include <iostream>

class vida:public NAVE,public Meteoro,public Bala{
    int a,b;
    int j=0;
    int expositor=1;
    int contador=0;
    int yyy,orejota=1;
public:
    int get_x(){return a;}
    int get_y(){return b;}
    int get_yyy(){return yyy;}
    void set_yyy(int y){yyy=y;}
    vida(int _a=0,int _b=0,int y=1):a(_a),b(_b),yyy(y){}
    void pintar_vida(BITMAP*,BITMAP*,BITMAP*,Meteoro,NAVE,Bala,bool&);
    void borrar_vida(bool&);
    list<vida*>salud;
    list<vida*>::iterator vida_actual;
};

void vida::borrar_vida(bool &cambio){
    for(vida_actual = salud.begin() ; vida_actual!= salud.end() ; vida_actual++){
        if(expositor==1){
            (*vida_actual)->set_yyy(0);
            expositor=0;
        }
    }
    for(vida_actual = salud.begin() ; vida_actual!= salud.end() ; vida_actual++){
        if((*vida_actual)->get_yyy()==0){
            delete (*vida_actual);
            vida_actual=salud.erase(vida_actual);
        }
        if(vida_actual==salud.end()){
                cambio=false;
        }
    }
}
void vida::pintar_vida(BITMAP *pantalla,BITMAP*corazon,BITMAP*texto,Meteoro piedra,NAVE avion,Bala n,bool &cambio){
    if(piedra.get_yy()==800){
        expositor=1;
    }
    draw_sprite(pantalla,texto,10,10);
    if(j==0){
        for(int x=0;x<5;x++){
            salud.push_back(new vida(100+x*22,10,get_yyy()));
        }
    }
    j++;
    if(j==10){j=1;}
    for(vida_actual = salud.begin() ; vida_actual!= salud.end() ; vida_actual++){
            draw_sprite(pantalla,corazon,(*vida_actual)->get_x(),(*vida_actual)->get_y());
    }
    yyy=0;
    if(n.get_controlador()==1){
        for(piedra.actual = piedra.rocas.begin() ; piedra.actual != piedra.rocas.end() ; piedra.actual++){
            for(int c=avion.get_x()+100;c<avion.get_x()+109;c++){
                for(int cc=((*piedra.actual)->get_x()+200);cc<=(*piedra.actual)->get_x()+209;cc++){
                    if(cc==c){
                        for(int b=avion.get_y();b<(avion.get_y()+119);b++){
                            for(int bb=(*piedra.actual)->get_y();bb<=(*piedra.actual)->get_y()+94;bb++){
                                if(bb==b){
                                    if(orejota==1){
                                        borrar_vida(cambio);
                                        (*piedra.actual)->set_etiqueta(0);
                                        orejota=0;
                                    }
                                }
                            }
                        }
                    }
                }
                orejota=1;
            }
        }
    }
    if(n.get_controlador()==2){
        for(piedra.actual = piedra.rocas.begin() ; piedra.actual != piedra.rocas.end() ; piedra.actual++){
            for(int c=avion.get_x()+70;c<avion.get_x()+75;c++){
                for(int cc=((*piedra.actual)->get_x()+200);cc<=(*piedra.actual)->get_x()+209;cc++){
                    if(cc==c){
                        for(int b=avion.get_y();b<(avion.get_y()+90);b++){
                            for(int bb=(*piedra.actual)->get_y();bb<=(*piedra.actual)->get_y()+94;bb++){
                                if(bb==b){
                                    if(orejota==1){
                                        borrar_vida(cambio);
                                        (*piedra.actual)->set_etiqueta(0);
                                        orejota=0;
                                    }
                                }
                            }
                        }
                    }
                }
            orejota=1;
            }
        }
    }
    if(n.get_controlador()==3){
        for(piedra.actual = piedra.rocas.begin() ; piedra.actual != piedra.rocas.end() ; piedra.actual++){
            for(int c=avion.get_x()+85;c<avion.get_x()+90;c++){
                for(int cc=((*piedra.actual)->get_x()+200);cc<=(*piedra.actual)->get_x()+209;cc++){
                    if(cc==c){
                        for(int b=avion.get_y();b<(avion.get_y()+119);b++){
                            for(int bb=(*piedra.actual)->get_y();bb<=(*piedra.actual)->get_y()+94;bb++){
                                if(bb==b){
                                    if(orejota==1){
                                        borrar_vida(cambio);
                                        (*piedra.actual)->set_etiqueta(0);
                                        orejota=0;
                                    }
                                }
                            }
                        }
                    }
                }
                orejota=1;
            }
        }
    }

    if(n.get_controlador()==4){
        for(piedra.actual = piedra.rocas.begin() ; piedra.actual != piedra.rocas.end() ; piedra.actual++){
            for(int c=avion.get_x()+85;c<avion.get_x()+90;c++){
                for(int cc=((*piedra.actual)->get_x()+200);cc<=(*piedra.actual)->get_x()+209;cc++){
                    if(cc==c){
                        for(int b=avion.get_y();b<(avion.get_y()+119);b++){
                            for(int bb=(*piedra.actual)->get_y();bb<=(*piedra.actual)->get_y()+94;bb++){
                                if(bb==b){
                                    if(orejota==1){
                                        borrar_vida(cambio);
                                        (*piedra.actual)->set_etiqueta(0);
                                        orejota=0;
                                    }
                                }
                            }
                        }
                    }
                }
                orejota=1;
            }
        }
    }
}
