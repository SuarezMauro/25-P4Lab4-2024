#include "../include/Usuario.hh"

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