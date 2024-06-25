#include "../../include/datatypes/DTNotificacion.hh"

std::string DTNotificacion::getNombrePromocion()
{
  return nombrePromocion;
}
std::string DTNotificacion::getNicknameVendedor()
{
  return nicknameVendedor;
}
DTNotificacion::DTNotificacion(std::string nombrePromocion, std::string nicknameVendedor)
{
  this->nombrePromocion = nombrePromocion;
  this->nicknameVendedor = nicknameVendedor;
}
DTNotificacion::~DTNotificacion() {}