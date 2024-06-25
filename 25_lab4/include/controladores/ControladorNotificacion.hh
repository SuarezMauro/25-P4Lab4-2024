#ifndef CONTROLADOR_NOTIFICACION
#define CONTROLADOR_NOTIFICACION

#include "../interfaces/IControladorNotificacion.hh"
#include <set>

class ControladorNotificacion : public IControladorNotificacion
{
private:
  std::set<DTNotificacion *> notificaciones;
  static ControladorNotificacion *instancia;
  ControladorNotificacion();

public:
  static ControladorNotificacion *getInstancia();
  ~ControladorNotificacion();
};

#endif