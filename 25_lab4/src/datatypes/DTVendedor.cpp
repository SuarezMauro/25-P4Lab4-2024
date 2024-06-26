#include "../../include/datatypes/DTVendedor.hh"

std::string DTVendedor::getCodigoRUT()
{
  return codigoRUT;
}
std::set<DTPromocion *> DTVendedor::getPromociones()
{
  return promociones;
}
DTVendedor::DTVendedor(std::string nickname, DTFecha *fechaNacimiento, std::string codigoRUT,std::set<DTPromocion*> promociones,std::set<DTCliente*> sus)
    : DTUsuario(nickname, fechaNacimiento)
{
  this->codigoRUT = codigoRUT;
  this->promociones = promociones;
  this->suscriptores = sus;
}
DTVendedor::~DTVendedor()
{
  DTUsuario::~DTUsuario();
}
