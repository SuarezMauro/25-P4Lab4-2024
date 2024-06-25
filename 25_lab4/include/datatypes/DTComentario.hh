#ifndef DTCOMENTARIO
#define DTCOMENTARIO
#include "./DTFecha.hh"
#include "./DTProducto.hh"
#include "./DTUsuario.hh"
#include <iostream>
#include <set>

class DTComentario
{
private:
  int id;
  DTFecha *fecha;
  std::string comentario;
  std::string nickRemitente;
  std::set<DTComentario *> respuestas;
  DTComentario *comentarioRespondido;
  DTProducto *productoComentado;

public:
  bool esRespuesta();
  int getId();
  DTFecha *getFecha();
  std::string getComentario();
  std::string getNickRemitente();
  std::set<DTComentario *> getInfoRespuestas();
  DTComentario *getInfoComentarioRespondido();
  DTProducto *getInfoProductoComentado();
  DTComentario(int, DTFecha *, std::string, std::string, std::set<DTComentario *>, DTComentario *, DTProducto *);
  ~DTComentario();
  void setPrint(std::ostream &out); // Sobrecarga de operador '<<'
};

std::ostream &operator<<(std::ostream &out, DTComentario &obj); // cout DTComentario

#endif