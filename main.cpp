#include <iostream>
#include <math.h>
#include <vector>
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
    //DisparoOfensivo(disparoO, disparoD, 1,3);
    //DisparoDefensivo(disparoO, disparoD, 1,3);

    return 0;
}
void ImprimirResultados1(int angle,int V0o,float x,float y,int t)
{
    cout << "Impacto con un angulo de " << angle << " grados" << endl;
    cout << "Impacto con velocidad incial " << V0o << endl;
    cout << "Impacto con posicion x: " << x << endl;
    cout << "Impacto con posicion y: " << y << endl;
    cout << "Con tiempo: " << t << endl;
    cout << endl;

}
void DisparoOfensivo(canonO disparoO,canonD disparoD, int Voo,int cantidad){
    vector<int> disparo;
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
    vector<int> disparo;
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

