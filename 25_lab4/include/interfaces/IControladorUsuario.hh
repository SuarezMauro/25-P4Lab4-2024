#ifndef I_CONTROLADOR_USUARIO
#define I_CONTROLADOR_USUARIO

#include "../datatypes/DTFecha.hh"
#include "../datatypes/DTDireccion.hh"
#include "../datatypes/DTCliente.hh"
#include "../datatypes/DTVendedor.hh"
#include "../datatypes/DTNotificacion.hh"
#include "../datatypes/DTProducto.hh"
#include "../datatypes/DTComentario.hh"
#include "../Cliente.hh"

#include <iostream>
#include <set>

class IControladorUsuario
{
public:
  virtual Cliente *getCliente(std::string) = 0;
  virtual Vendedor *getVendedor(std::string) = 0;
  virtual Usuario *getUsuario(std::string) = 0;
  virtual void altaNuevoCliente(std::string, std::string, DTFecha *, DTDireccion *, std::string) = 0;
  virtual void altaNuevoVendedor(std::string, std::string, DTFecha *, std::string) = 0;
  virtual void realizarSuscripciones(std::string, std::set<std::string>) = 0;
  virtual void eliminarSuscripciones(std::string, std::set<std::string>) = 0;
  virtual void eliminarNotificaciones(std::string) = 0;
  virtual std::set<DTUsuario *> listarUsuarios() = 0;
  virtual std::set<DTCliente *> listarClientes() = 0;
  virtual std::set<DTVendedor *> listarVendedores() = 0;
  virtual std::set<DTVendedor *> listarVendedoresNoSuscritos(std::string) = 0;
  virtual std::set<DTProducto *> listarProductosVendedor(std::string) = 0;
  virtual std::set<DTNotificacion *> listarNotificaciones(std::string) = 0;
  virtual std::set<DTVendedor *> listarSuscripciones(std::string) = 0;
  virtual std::set<DTComentario *> listarComentariosUsuario(std::string) = 0;

  virtual std::set<DTVendedor *> listarVendedoresSuscritos(std::string) = 0;
  // virtual void RegistroNuevoProducto(std::string nickVendedor, Producto *producto) = 0;
};

#endif