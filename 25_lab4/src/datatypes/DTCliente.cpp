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
};
DTCliente::DTCliente(std::string nickname, DTFecha *fechaNacimiento, DTDireccion *direccion, std::string ciudadDeResidencia)
    : DTUsuario(nickname, fechaNacimiento)
{
  this->direccion = direccion;
  this->ciudadDeResidencia = ciudadDeResidencia;
}
DTCliente::~DTCliente()
{
  delete direccion;
  DTUsuario::~DTUsuario();
}
