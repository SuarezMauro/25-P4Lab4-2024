#ifndef DTNOTIFICACION
#define DTNOTIFICACION
#include "./DTPromocion.hh"

#include <string>

class DTNotificacion
{
private:
  std::string nombrePromocion;
  std::string nicknameVendedor;

public:
  std::string getNombrePromocion();
  std::string getNicknameVendedor();
  DTNotificacion(std::string, std::string);
  ~DTNotificacion();
};

#endif