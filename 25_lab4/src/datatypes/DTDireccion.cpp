#include "../../include/datatypes/DTDireccion.hh"

std::string DTDireccion::getNombreCalle()
{
  return nombreCalle;
}
int DTDireccion::getNroPuerta()
{
  return nroPuerta;
}
DTDireccion *DTDireccion::copiarDireccion()
{
  DTDireccion *copia = new DTDireccion(nombreCalle, nroPuerta);
  return copia;
}
DTDireccion::DTDireccion(std::string nombreCalle, int nroPuerta)
{
  this->nombreCalle = nombreCalle;
  this->nroPuerta = nroPuerta;
}
DTDireccion::~DTDireccion() {}