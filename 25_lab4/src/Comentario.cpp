#include "../include/Comentario.hh"

bool Comentario::esRespuesta()
{
  return comentarioRespondido != NULL;
}
int Comentario::getId()
{
  return id;
}
std::string Comentario::getNickRemitente()
{
  return nickRemitente;
}
DTProducto *Comentario::getInfoProductoComentado()
{
  return infoProductoComentado;
}
Comentario *Comentario::getComentarioRespondido()
{
  return comentarioRespondido;
}
DTComentario *Comentario::getDataComentario()
{
  std::set<DTComentario*> dataRespuestas;
  if (!respuestas.empty()){
    for (std::set<Comentario *>::iterator it = respuestas.begin(); it != respuestas.end(); it++)
    {
      DTComentario *respuesta = (*it)->getDataComentario();
      dataRespuestas.insert(respuesta);
    }
  }
  DTComentario *dataComentarioRespondido = NULL;
  if (comentarioRespondido != NULL){
    DTComentario *dataComentarioRespondido = comentarioRespondido->getDataComentario();
  }
  DTComentario *dataComentario = new DTComentario(id, fecha, comentario, nickRemitente, dataRespuestas, dataComentarioRespondido, infoProductoComentado);

  return dataComentario;
}
void Comentario::agregarRespuesta(Comentario *comentario)
{
  respuestas.insert(comentario);
}
void Comentario::eliminarRespuesta(Comentario *comentario)
{
  respuestas.erase(comentario);
}
Comentario::Comentario(int id, DTFecha *fecha, std::string comentario, std::string nickRemitente, Comentario *comentarioRespondido, DTProducto *infoProductoComentado)
{
  this->id = id;
  this->fecha = fecha;
  this->comentario = comentario;
  this->nickRemitente = nickRemitente;
  this->infoProductoComentado = infoProductoComentado;
  this->comentarioRespondido = comentarioRespondido;
}
Comentario::~Comentario()
{
}