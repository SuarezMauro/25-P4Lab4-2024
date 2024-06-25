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
DTCliente::DTCliente(std::string nickname, DTFecha *fechaNacimiento, DTDireccion *direccion, std::string ciudadDeResidencia,std::set<DTCompra *> comprasPasadas)
    : DTUsuario(nickname, fechaNacimiento)
{
  this->direccion = direccion;
  this->ciudadDeResidencia = ciudadDeResidencia;
  this->comprasPasadas = comprasPasadas;
}
DTCliente::~DTCliente()
{
  delete direccion;
  DTUsuario::~DTUsuario();
}
