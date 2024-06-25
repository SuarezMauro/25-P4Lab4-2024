#ifndef FABRICA
#define FABRICA

#include "../controladores/ControladorUsuario.hh"
#include "../controladores/ControladorCompra.hh"
#include "../controladores/ControladorProducto.hh"
#include "../controladores/ControladorPromocion.hh"
#include "../controladores/ControladorNotificacion.hh"

class Fabrica
{
public:
  static IControladorUsuario *getInterfazUsuario();
  static IControladorCompra *getInterfazCompra();
  static IControladorProducto *getInterfazProducto();
  static IControladorPromocion *getInterfazPromocion();
  static IControladorNotificacion *getInterfazNotificacion();
};

#endif