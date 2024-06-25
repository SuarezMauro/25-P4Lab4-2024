#ifndef INFO_PROMO_PRODUCTO
#define INFO_PROMO_PRODUCTO

#include <iostream>

class InfoPromoProducto
{
private:
    int id;
    int cantidadMinima;

public:
    int getCantidadMinima();
    void setCantidadMinima(int);
    int getId();
    void setId(int i);

    InfoPromoProducto();
    InfoPromoProducto(int id, int cant);
    ~InfoPromoProducto();
};

#endif