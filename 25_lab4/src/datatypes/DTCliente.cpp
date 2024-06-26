#include "../../include/datatypes/DTCliente.hh"

DTDireccion *DTCliente::getDireccion()
{
  return direccion;
}
std::string DTCliente::getCiudadDeResidencia()
{
  return ciudadDeResidencia;
}
std::set<DTCompra *> DTCliente::getComprasPasadas()
{
  return comprasPasadas;
}
std::set<DTNotificacion *> DTCliente::getNotificaciones(){
  return notificaciones;
}
std::set<DTVendedor *> DTCliente::getSuscripciones()
{
  return suscripciones;
}
DTCliente::DTCliente(std::string nickname, DTFecha *fechaNacimiento, DTDireccion *direccion, std::string ciudadDeResidencia,std::set<DTCompra *> comprasPasadas, std::set<DTVendedor *> susc, std::set<DTNotificacion *> notifi)
    : DTUsuario(nickname, fechaNacimiento)
{
  this->direccion = direccion;
  this->ciudadDeResidencia = ciudadDeResidencia;
  this->comprasPasadas = comprasPasadas;
  this->notificaciones = notifi;
  this->suscripciones = susc;
}
DTCliente::~DTCliente()
{
  delete direccion;
  DTUsuario::~DTUsuario();
}
