#include <iostream>
using namespace std;

class mundo{
    int j;
    int especial;
public:
    mundo(int largo=1340,int especia=0):j(largo),especial(especia){}
    void mover_asteroides(BITMAP*,BITMAP*);
};

void mundo::mover_asteroides(BITMAP*espacio1,BITMAP*pantalla){
    masked_blit(espacio1,pantalla,j,0,0,0,1340,700);
        if(especial%30==0){
            j--;
        }
        if(j==-1340){
                j=1340;
        }
        especial++;
        if (especial==61){
            especial=0;
        }
}
