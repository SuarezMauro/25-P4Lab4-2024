#ifndef DTDIRECCION
#define DTDIRECCION
#include <string>

class DTDireccion
{
private:
  std::string nombreCalle;
  int nroPuerta;

public:
  std::string getNombreCalle();
  int getNroPuerta();
  DTDireccion *copiarDireccion();
  DTDireccion(std::string nombreCalle, int nroPuerta);
  ~DTDireccion();
};

#endif