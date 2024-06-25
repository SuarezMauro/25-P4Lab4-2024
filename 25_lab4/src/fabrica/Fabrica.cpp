#include "../../include/fabrica/Fabrica.hh"

IControladorUsuario *Fabrica::getInterfazUsuario()
{
  return ControladorUsuario::getInstancia();
}
IControladorCompra *Fabrica::getInterfazCompra()
{
  return ControladorCompra::getInstancia();
}
IControladorProducto *Fabrica::getInterfazProducto()
{
  return ControladorProducto::getInstancia();
}
IControladorPromocion *Fabrica::getInterfazPromocion()
{
  return ControladorPromocion::getInstancia();
}
IControladorNotificacion *Fabrica::getInterfazNotificacion()
{
  return ControladorNotificacion::getInstancia();
}
