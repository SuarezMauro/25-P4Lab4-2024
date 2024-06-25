#include "../include/InfoPromoProducto.hh"

int InfoPromoProducto::getCantidadMinima()
{
    return cantidadMinima;
}

void InfoPromoProducto::setCantidadMinima(int nuevaCantidadMinima)
{
    cantidadMinima = nuevaCantidadMinima;
}
int InfoPromoProducto::getId()
{
    return id;
}

void InfoPromoProducto::setId(int i)
{
    id = i;
}
InfoPromoProducto::InfoPromoProducto() {}

InfoPromoProducto::InfoPromoProducto(int id, int cant)
{
    this->id = id;
    this->cantidadMinima = cant;
}
InfoPromoProducto::~InfoPromoProducto() {}