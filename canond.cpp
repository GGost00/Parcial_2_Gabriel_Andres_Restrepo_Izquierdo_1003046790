#include "canond.h"

canonD::canonD(int posx_,int posy_,int distancia_)
{
    posx=posx_;
    posy=posy_;
    distancia=distancia_;
    //disparos(posx,posy,10,20,distancia,radio);
}
//int disparos(int x_1,int y_1,int x_2,int y_2,int distancia,float radio){
//    float vx_bala,vy_bala,t=2,v=0,cont=0,pos_x,pos_y,angulo;


//    for (v=0;v<=100;v+=0.5){
//        for (angulo=0;angulo<=90;angulo+=1){
//        vx_bala=v*cos(angulo);
//        vy_bala=v*sin(angulo);
//        for (t=0;t<=100;t+=0.3){
//            pos_x=x_1+vx_bala*t;
//            pos_y=y_1 +vy_bala*t - (4.901*(t*t));
//            if (pos_y <0){
//                break;
//            }
//            if(sqrt(pow(x_2-pos_x,2)+pow(y_2-pos_y,2))<=(radio*distancia)){
//                cout<<"velocidad= "<<v<<", Angulo= "<<angulo*180/M_PI<<",tiempo= "<<t<<endl;
//                cont+=1;
//            }
//        if(cont==3){
//            break;
//        }

//        }
//    }
//    }
//    return 0;
//}
