#include "canond.h"

float canonD::getXd() const
{
    return Xd;
}

float canonD::getYd() const
{
    return Yd;
}

canonD::canonD(float distancia,float alturadf,float posx)
{
    d=distancia;
    Hd=alturadf;
    Xd = d+posx;
    Yd = Hd;
    d0 = 0.025*d;

}
