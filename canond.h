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
    float Xd;
    float Yd;
    float d0;
public:
    canonD(float distancia,float alturaof,float posx);
    float getXd() const;
    float getYd() const;
};

#endif // CANOND_H
