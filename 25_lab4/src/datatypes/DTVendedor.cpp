#include "../../include/datatypes/DTVendedor.hh"

std::string DTVendedor::getCodigoRUT()
{
  return codigoRUT;
}
std::set<DTPromocion *> DTVendedor::getPromociones()
{
  return promociones;
}
DTVendedor::DTVendedor(std::string nickname, DTFecha *fechaNacimiento, std::string codigoRUT)
    : DTUsuario(nickname, fechaNacimiento)
{
  this->codigoRUT = codigoRUT;
}
DTVendedor::~DTVendedor()
{
  DTUsuario::~DTUsuario();
}
