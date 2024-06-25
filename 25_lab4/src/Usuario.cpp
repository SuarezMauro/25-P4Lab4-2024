#include "../include/Usuario.hh"

DTUsuario *Usuario::getDataUsuario()
{
  DTFecha *copiaFecha = fechaNacimiento->copiarFecha();
  DTUsuario *dataUsuario = new DTUsuario(nickname, copiaFecha);
  return dataUsuario;
}
DTFecha *Usuario::getFechaNacimiento()
{
  return fechaNacimiento;
}
std::string Usuario::getNickname()
{
  return nickname;
}
std::string Usuario::getPassword()
{
  return password;
}
std::set<DTComentario *> Usuario::listarComentarios()
{
  std::set<DTComentario *> retorno;
  for (std::set<Comentario *>::iterator it = comentarios.begin(); it != comentarios.end(); it++)
  {
    DTComentario *dataComentario = (*it)->getDataComentario();
    retorno.insert(dataComentario);
  }
  return retorno;
}
void Usuario::añadirComentario(Comentario *comentario)
{
  comentarios.insert(comentario);
}
void Usuario::eliminarComentario(Comentario *comentario)
{
  comentarios.erase(comentario);
}
Usuario::Usuario(std::string nickname, std::string password, DTFecha *fechaNacimiento)
{
  this->nickname = nickname;
  this->password = password;
  this->fechaNacimiento = fechaNacimiento;
}
Usuario::~Usuario()
{
  delete fechaNacimiento;
}