#include "../../include/datatypes/DTComentario.hh"


int DTComentario::getId()
{
  return id;
}
DTFecha *DTComentario::getFecha()
{
  return fecha;
}
std::string DTComentario::getComentario()
{
  return comentario;
}
std::string DTComentario::getNickRemitente()
{
  return nickRemitente;
}
std::set<DTComentario *> DTComentario::getInfoRespuestas()
{
  return respuestas;
}
DTProducto *DTComentario::getInfoProductoComentado()
{
  return productoComentado;
}
DTComentario::DTComentario(int id, DTFecha *fecha, std::string comentario, std::string nickRemitente, std::set<DTComentario *> respuestas, DTProducto *productoComentado)
{
  this->id = id;
  this->fecha = fecha;
  this->comentario = comentario;
  this->nickRemitente = nickRemitente;
  this->respuestas = respuestas;
  this->productoComentado = productoComentado;
}
DTComentario::~DTComentario() {}
// Sobrecarga de operador '<<'
void DTComentario::setPrint(std::ostream &out)
{
  out << id << ", " << fecha->toString() << ", " << comentario;
}

std::ostream &operator<<(std::ostream &out, DTComentario &obj)
{
  obj.setPrint(out);
  return out;
}