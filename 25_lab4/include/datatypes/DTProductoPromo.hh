#ifndef DTPRODUCTO_PROMO
#define DTPRODUCTO_PROMO
#include <iostream>

class DTProductoPromo
{
private:
    int id;
    std::string nombre;
    int cantidadMinima;
    float porcentajeDescuento;

public:
    int getId();
    std::string getNombre();
    int getCantidadMinima();
    float getPorcentajeDescuento();
    DTProductoPromo(int, std::string, int, float);
    ~DTProductoPromo();
};

#endif