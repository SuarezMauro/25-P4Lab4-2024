#ifndef COMENTARIO
#define COMENTARIO
#include "./datatypes/DTFecha.hh"
#include "./datatypes/DTProducto.hh"
#include "./datatypes/DTComentario.hh"

#include <iostream>
#include <set>

class Comentario
{
private:
  int id;
  DTFecha *fecha;
  std::string comentario;
  std::string nickRemitente;
  std::set<Comentario *> respuestas;
  Comentario *comentarioRespondido;
  DTProducto *infoProductoComentado;

public:
  bool esRespuesta();
  int getId();
  std::string getNickRemitente();
  DTProducto *getInfoProductoComentado();
  Comentario *getComentarioRespondido();
  DTComentario *getDataComentario();
  void agregarRespuesta(Comentario *);
  void eliminarRespuesta(Comentario *);
  Comentario(int, DTFecha *, std::string, std::string, Comentario *, DTProducto *);
  ~Comentario();
};

#endif