#ifndef CLIENTE
#define CLIENTE

#include "./interfaces/IObservador.hh"
#include "./datatypes/DTCliente.hh"
#include "./datatypes/DTDireccion.hh"
#include "./datatypes/DTCompra.hh"
#include "./datatypes/DTVendedor.hh"
#include "./datatypes/DTNotificacion.hh"
#include "./Usuario.hh"

#include <set>

class Vendedor;

class Cliente : public Usuario
{
private:
  DTDireccion *direccion;
  std::string ciudadDeResidencia;
  std::set<DTVendedor *> suscripciones;
  std::set<DTNotificacion *> notificaciones;
  std::set<DTCompra *> comprasPasadas;

public:
  DTDireccion *getDireccion();
  std::string getCiudadDeResidencia();
  std::set<DTVendedor *> getSuscripciones();
  std::set<DTCompra *> getComprasPasadas();
  DTCliente *getDataCliente();
  std::set<DTNotificacion *> getNotificaciones();
  void añadirCompra(DTCompra *);
  void removerCompra(DTCompra *);
  void añadirSuscripcion(DTVendedor *);
  void removerSuscripcion(DTVendedor *);
  void notificar(std::string, std::string);
  void eliminarNotificaciones();
  std::set<DTNotificacion *> listarNotificaciones();
  Cliente(std::string nickname, std::string password, DTFecha *fechaNacimiento, DTDireccion *direccion, std::string ciudadDeResidencia);
  ~Cliente();
};

#endif