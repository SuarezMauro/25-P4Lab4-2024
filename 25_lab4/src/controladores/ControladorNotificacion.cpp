#include "../../include/controladores/ControladorNotificacion.hh"

ControladorNotificacion::~ControladorNotificacion() {}
ControladorNotificacion::ControladorNotificacion() {}
ControladorNotificacion *ControladorNotificacion::instancia = NULL;
ControladorNotificacion *ControladorNotificacion::getInstancia()
{
  if (instancia == NULL)
  {
    instancia = new ControladorNotificacion();
  }
  return instancia;
}