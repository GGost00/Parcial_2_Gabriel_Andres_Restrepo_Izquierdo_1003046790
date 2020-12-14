#ifndef CANONO_H
#define CANONO_H
#include<math.h>
#include<iostream>
using namespace std;

class canonO
{
private:
    float d ;
    float Ho ;
    float Xo ;
    float Yo = Ho;
    float d0 = 0.05*d;
public:
    canonO(float distancia,float alturaof,float posx);
    //int disparos(int x_1,int y_1,int x_2,int y_2,int distancia,float radio);
};

#endif // CANONO_H
