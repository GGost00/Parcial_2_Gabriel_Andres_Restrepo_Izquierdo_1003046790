#ifndef CANOND_H
#define CANOND_H
#include<math.h>
#include<iostream>
using namespace std;

class canonD
{
private:
    float d ;
    float Hd;
    float Xd = d;
    float Yd = Hd;
    float d0 = 0.025*d;
public:
    canonD(float distancia,float alturaof);

    //int disparos(int x_1,int y_1,int x_2,int y_2,int distancia,float radio);
};

#endif // CANOND_H
