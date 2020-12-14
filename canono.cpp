#include "canono.h"

float canonO::getYo() const
{
    return Yo;
}

float canonO::getD0() const
{
    return d0;
}

canonO::canonO(float distancia,float alturaof,float posx)
{
    d=distancia;
    Xo=posx;
    Ho=alturaof;
    Yo = Ho;
    d0 = 0.05*d;

}


