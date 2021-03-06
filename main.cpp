#include <iostream>
#include <math.h>

#include "canond.h"
#include "canono.h"
#include "balad.h"
#include "balao.h"
#define G 9.81
#define pi 3.141617

using namespace std;

balaD disparoO1 = balaD();
balaO disparoD1 = balaO();
void DisparoOfensivo(canonO disparoO,canonD disparoD, int Voo,int cantidad);
void DisparoDefensivo(canonO disparoO,canonD disparoD, int Voo,int cantidad);
void DefensaDefensivo1(canonO disparoO,canonD disparoD,int cantidad);
void ContraAtaqueOf(canonO disparoO,canonD disparoD,int cantidad);
void Menu_(canonO disparoO,canonD disparoD);

int main()
{

    float distancia,Hod,Hoo;
    cout<<"ingrese la distancia entre los dos canones-> ";
    cin>>distancia;
    cout<<"ingrese la altura del canon ofensivo-> ";
    cin>>Hoo;
    cout<<"ingrese la altura del canon defencivo-> ";
    cin>>Hod;

    canonO disparoO = canonO(distancia,Hoo);
    canonD disparoD = canonD(distancia,Hod);
    cout<<endl;

    system("CLS");
    Menu_(disparoO,disparoD);



    return 0;
}
void ImprimirResultados1(int angle,int V0o,float x,float y,float t)
{
    cout << "Impacto con un angulo de " << angle << " grados" << endl;
    cout << "Impacto con velocidad incial " << V0o << endl;
    cout << "Impacto con posicion x: " << x << endl;
    cout << "Impacto con posicion y: " << y << endl;
    cout << "Con tiempo: " << t << endl;
    cout << endl;

}
void DisparoOfensivo(canonO disparoO,canonD disparoD, int Voo,int cantidad){

    int flag = 0;
    float x,y;
    float Vxo,Vy0;
    int V0o = 0;
    int t = 0;
    int angle = 0;
    for(V0o = Voo; ; V0o += 5){
        for(angle = 0; angle < 90; angle++){
            Vxo = V0o*cos(angle*pi/180);
            Vy0 = V0o*sin(angle*pi/180);
            x = 0.0;
            y = 0.0;
            for(t = 0; ; t++){
                x = Vxo*t;
                y = disparoO.getYo() + Vy0*t -(0.5*G*t*t);
                if(sqrt(pow((disparoD.getXd() - x),2)+pow((disparoD.getYd() - y),2)) < disparoO.getD0()){
                    if(y<0) y = 0;
                    if(cantidad==1){
                        if (t>2){
                            cout<<"disparo ofensivo--------------"<<endl;
                            ImprimirResultados1(angle, V0o, x, y, t);
                            disparoO1.setAngulo(angle);
                            disparoO1.setVelocidad(V0o);
                            disparoO1.setTiempo(t);
                            flag += 1;
                            break;
                        }

                    }else{
                    ImprimirResultados1(angle, V0o, x, y, t);
                    flag += 1;
                    V0o += 50;
                    break;
                    }
                }
                if(y < 0){
                    break;
                }
            }
            if(flag == cantidad) break;

        }
        if(flag == cantidad) break;
    }
    if(flag != cantidad){
        cout << "No impacto en los disparos esperados"<< endl;
    }
}
void DisparoDefensivo(canonO disparoO,canonD disparoD, int Voo,int cantidad){

    int flag = 0;
    float x,y;
    float Vxo,Vy0;
    int V0o = 0;
    int t = 0;
    int angle = 0;
    for(V0o = Voo; ; V0o += 5){
        for(angle = 0; angle < 90; angle++){
            Vxo = V0o*cos((angle+90)*pi/180);
            Vy0 = V0o*sin((angle+90)*pi/180);
            x = 0.0;
            y = 0.0;
            for(t = 0; ; t++){
                x = Vxo*t;
                y = disparoD.getYd() + Vy0*t -(0.5*G*t*t);
                if(sqrt(pow((disparoO.getXo() - x),2)+pow((disparoO.getYo() - y),2)) < disparoD.getD0()){
                    if(y<0) y = 0;
                    if(cantidad==1){
                        if (t>2){
                            disparoD1.setAngulo(angle);
                            disparoD1.setVelocidad(V0o);
                            disparoD1.setTiempo(t);
                            flag += 1;
                            break;
                        }
                    }else{
                    ImprimirResultados1(angle, V0o, x, y, t);
                    flag += 1;
                    V0o += 50;
                    break;
                    }
                }
                if(y < 0){
                    break;
                }
            }
            if(flag == cantidad) break;

        }
        if(flag == cantidad) break;
    }
    if(flag != cantidad){
        cout << "No impacto en los disparos esperados"<< endl;
    }
}
void DefensaDefensivo1(canonO disparoO,canonD disparoD,int cantidad){
    DisparoOfensivo(disparoO, disparoD, 1,1);
    float tiempoRes =disparoO1.getTiempo()-2;
    float xb,yb;
    int flag = 0;
    float x,y;
    float Vxo,Vy0,vxoo,vyoo;
    int vbd = 0;
    float t = tiempoRes/2;
    int anglbd = 0;
    vxoo=disparoO1.getVelocidad()*cos((disparoO1.getAngulo())*pi/180);
    vyoo=disparoO1.getVelocidad()*sin((disparoO1.getAngulo())*pi/180);
    xb=vxoo*(t +2);
    yb=disparoO.getYo()+vyoo*(t +2)-((1/2)*G*(pow(t,2)));




    for(vbd = 1; ; vbd += 1){
        for(anglbd = 0; anglbd < 90; anglbd++){
            Vxo = abs(vbd*cos((anglbd+90)*pi/180));
            Vy0 = abs(vbd*sin((anglbd+90)*pi/180));
            x = 0.0;
            y = 0.0;

            x = Vxo*(t +2);
            y = disparoD.getYd() + Vy0*(t+2) -(0.5*G*(pow(t,2)));
            if(sqrt(pow((xb - x),2)+pow((yb - y),2)) < disparoO.getD0()){
                if(y<0) y = 0;
                if(cantidad==1){
                    if (t>3){
                        cout<<"disparo defensivo--------------"<<endl;
                        ImprimirResultados1(anglbd+90, vbd, x, y, t);
                        disparoD1.setAngulo(anglbd);
                        disparoD1.setVelocidad(vbd);
                        disparoD1.setTiempo(t);
                        flag += 1;
                        break;
                    }
                }else{
                    ImprimirResultados1(anglbd+90, vbd, x, y, t);
                    tiempoRes=tiempoRes/2;
                    t+=tiempoRes/2;
                    flag += 1;
                    vbd =0;
                    break;
                }
            }
            if(y < 0){
                break;
            }


        }
        if(flag == cantidad) break;
    }
    if(flag != cantidad){
        cout << "No impacto en los disparos esperados"<< endl;
    }
}
void ContraAtaqueOf(canonO disparoO,canonD disparoD,int cantidad){
    DefensaDefensivo1(disparoO, disparoD, 1);


    float tiempoRes =disparoD1.getTiempo()-1;
    float xb,yb;
    int flag = 0;
    float x,y;
    float Vxo,Vy0,vxoo,vyoo;
    int vbd = 0;
    float t = tiempoRes/2;
    int anglbd = 0;
    vxoo=disparoD1.getVelocidad()*cos((disparoD1.getAngulo()+90)*pi/180);
    vyoo=disparoD1.getVelocidad()*sin((disparoD1.getAngulo()+90)*pi/180);
    xb=disparoD.getD()+ vxoo*(t +1);
    yb=disparoO.getYo()+vyoo*(t +1)-((1/2)*G*(pow(t,2)));




    for(vbd = 1; ; vbd += 1){
        for(anglbd = 0; anglbd < 90; anglbd++){
            Vxo = abs(vbd*cos((anglbd)*pi/180));
            Vy0 = abs(vbd*sin((anglbd)*pi/180));
            x = 0.0;
            y = 0.0;

            x = Vxo*(t +1);
            y = disparoO.getYo() + Vy0*(t+1) -(0.5*G*(pow(t,2)));
            if(sqrt(pow((xb - x),2)+pow((yb - y),2)) < disparoD.getD()*0.005){
                if(y<0) y = 0;
                if(cantidad==1){
                    if (t>3){
                        disparoD1.setAngulo(anglbd);
                        disparoD1.setVelocidad(vbd);
                        disparoD1.setTiempo(t);
                        flag += 1;
                        break;
                    }
                }else{
                    ImprimirResultados1(anglbd, vbd, x, y, t);
                    tiempoRes=tiempoRes/2;
                    t+=tiempoRes/2;
                    flag += 1;
                    vbd =0;
                    break;
                }
            }
            if(y < 0){
                break;
            }


        }
        if(flag == cantidad) break;
    }
    if(flag != cantidad){
        cout << "No impacto en los disparos esperados"<< endl;
    }
}
void Menu_(canonO disparoO,canonD disparoD){
    int opcion;
    cout<<"********************************************"<<endl;
    cout<<"*             QUE QUIERE HECER             *"<<endl;
    cout<<"********************************************"<<endl;
    cout<<"*                                          *"<<endl;
    cout<<"*   1.VER CASO 1                           *"<<endl;
    cout<<"*   2.VER CASO 2                           *"<<endl;
    cout<<"*   3.VER CASO 3                           *"<<endl;
    cout<<"*   4.VER CASO 4                           *"<<endl;
    cout<<"*   5.VER CASO 5                           *"<<endl;
    cout<<"*   6.SALIR                                *"<<endl;
    cout<<"*                                          *"<<endl;
    cout<<"********************************************"<<endl;
    cin>>opcion;
    switch (opcion) {
    case 1:
        system("CLS");
        DisparoOfensivo(disparoO, disparoD, 1,3);
       break;
    case 2:
        system("CLS");
        DisparoDefensivo(disparoO, disparoD, 1,3);
        break;
    case 3:
        system("CLS");
        DefensaDefensivo1(disparoO, disparoD,3);
        break;
    case 4:
        system("CLS");
        DefensaDefensivo1(disparoO, disparoD,3);
        break;
    case 5:
        system("CLS");
        ContraAtaqueOf(disparoO, disparoD,3);
        break;
    case 6:
        cout<<"********************************************"<<endl;
        cout<<"*           QUE TENGA BUEN DIA             *"<<endl;
        cout<<"********************************************"<<endl;
        break;
    default:
        cout<<"********************************************"<<endl;
        cout<<"*             !NO ESCOGIO NADA¡            *"<<endl;
        cout<<"********************************************"<<endl;
        break;
    }
}


