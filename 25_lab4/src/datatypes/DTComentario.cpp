#include "../../include/datatypes/DTComentario.hh"

int DTComentario::getId()
{
  return id;
}
DTFecha *DTComentario::getFecha()
{
  return fecha;
}
std::string DTComentario::getTexto()
{
  return texto;
}
DTComentario::DTComentario(int id, DTFecha *fecha, std::string texto)
{
  this->id = id;
  this->fecha = fecha;
  this->texto = texto;
}
DTComentario::~DTComentario() {}
// Sobrecarga de operador '<<'
void DTComentario::setPrint(std::ostream &out)
{
  out << id << ", " << fecha->toString() << ", " << texto;
}

std::ostream &operator<<(std::ostream &out, DTComentario &obj)
{
  obj.setPrint(out);
  return out;
}