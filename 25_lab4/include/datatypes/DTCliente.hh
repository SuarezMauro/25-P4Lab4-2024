#ifndef DTCLIENTE
#define DTCLIENTE

#include "./DTUsuario.hh"
#include "./DTVendedor.hh"
#include "./DTNotificacion.hh"
#include "./DTDireccion.hh"
#include "./DTCompra.hh"

#include <iostream>
#include <set>

class DTCompra;
class DTVendedor;
class DTNotificacion;

class DTCliente : public DTUsuario
{
private:
  DTDireccion *direccion;
  std::string ciudadDeResidencia;
  std::set<DTVendedor *> suscripciones;
  std::set<DTNotificacion *> notificaciones;
  std::set<DTCompra *> comprasPasadas;

public:
  DTDireccion *getDireccion();
  std::set<DTCompra *> getComprasPasadas();
  std::string getCiudadDeResidencia();
  std::set<DTVendedor *> getSuscripciones();
  std::set<DTNotificacion *> getNotificaciones();
  DTCliente(std::string, DTFecha *, DTDireccion *, std::string, std::set<DTCompra *>, std::set<DTVendedor *>, std::set<DTNotificacion *> );
  ~DTCliente();
};

#endif