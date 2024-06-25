#include "../../include/datatypes/DTUsuario.hh"

std::string DTUsuario::getNickname()
{
  return nickname;
}
DTFecha *DTUsuario::getFechaNacimiento()
{
  return fechaNacimiento;
}
DTUsuario::DTUsuario(std::string nickname, DTFecha *fechaNacimiento)
{
  this->nickname = nickname;
  this->fechaNacimiento = fechaNacimiento;
}
DTUsuario::~DTUsuario()
{
  delete fechaNacimiento;
}
