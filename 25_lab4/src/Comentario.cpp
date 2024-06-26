#include "../include/Comentario.hh"

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

std::string Comentario::getTexto() 
{
  return texto;
}


DTComentario *Comentario::getDataComentario()
{
  std::set<DTComentario *>listaRespuestas;
  if (!respuestas.empty())
  {
    for (std::set<Comentario *>::iterator it = respuestas.begin(); it != respuestas.end(); it++)
    {
        DTComentario *respuesta = (*it)->getDataComentario();
        listaRespuestas.insert(respuesta);
    }
  }
  DTComentario *dataComentario = new DTComentario(id, fecha, texto, nickRemitente, listaRespuestas, infoProductoComentado);
  return dataComentario;
}
DTComentario *Comentario::getDataType()
{
  return new DTComentario(id, fecha, texto, nickRemitente, std::set<DTComentario*>(), infoProductoComentado); 
}

std::set<Comentario *> Comentario::getRespuestas(){
  return respuestas;
}

void Comentario::agregarRespuesta(Comentario *comentario)
{
  respuestas.insert(comentario);
}

void Comentario::eliminarRespuesta(Comentario *comentario)
{
  respuestas.erase(comentario);

}

Comentario::Comentario(int id, DTFecha *fecha, std::string texto, std::string nickRemitente, DTProducto *infoProductoComentado)
{
  this->id = id;
  this->fecha = fecha;
  this->texto = texto;
  this->nickRemitente = nickRemitente;
  this->infoProductoComentado = infoProductoComentado;
  this->respuestas = std::set<Comentario*>();
}
Comentario::~Comentario()
{
}