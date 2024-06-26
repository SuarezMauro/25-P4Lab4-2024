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
  std::string texto;
  std::string nickRemitente;
  std::set<Comentario *> respuestas;
  DTProducto *infoProductoComentado;

public:
  int getId();
  std::string getNickRemitente();
  DTProducto *getInfoProductoComentado();
  DTComentario *getDataComentario();
  DTComentario *getDataType(); //Retorna comentario sin respuestas
  std::set<Comentario *> getRespuestas();
  void agregarRespuesta(Comentario *);
  void eliminarRespuesta(Comentario *);
  Comentario(int id, DTFecha * fecha, std::string texto, std::string nickRemitente, DTProducto * infoProductoComentado);
  ~Comentario();
  std::string getTexto();
};

#endif