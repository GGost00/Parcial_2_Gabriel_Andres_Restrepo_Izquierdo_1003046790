#ifndef BALAD_H
#define BALAD_H


class balaD
{
private:
    float angulo;
    float velocidad;
    float tiempo;
public:
    balaD();
    float getAngulo() const;
    void setAngulo(float value);
    float getVelocidad() const;
    void setVelocidad(float value);
    float getTiempo() const;
    void setTiempo(float value);
};

#endif // BALAD_H
