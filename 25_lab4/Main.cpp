#include "./include/fabrica/Fabrica.hh"
#include "./include/datatypes/DTFecha.hh"
#include "./include/Vendedor.hh"
#include "./include/Cliente.hh"
#include <string>
#include <iostream>

IControladorUsuario *controladorUsuario = Fabrica::getInterfazUsuario();
IControladorProducto *controladorProducto = Fabrica::getInterfazProducto();
IControladorPromocion *controladorPromocion = Fabrica::getInterfazPromocion();
IControladorCompra *controladorCompra = Fabrica::getInterfazCompra();

//--------------------------------------FUNCIONES AUXILIARES----------------------------------------------------
bool ExisteUsuario(std::string nickname) // funcion auxiliar
{
  std::set<DTUsuario *> usuarios = controladorUsuario->listarUsuarios();
  for (auto it = usuarios.begin(); it != usuarios.end(); it++)
  {
    if ((*it)->getNickname() == nickname)
    {
      return true;
    }
  }
  return false;
}
bool ExisteVendedor(std::string nickname, std::set<DTVendedor *> vendedores) // funcion auxiliar
{
  for (auto it = vendedores.begin(); it != vendedores.end(); it++)
  {
    if ((*it)->getNickname() == nickname)
    {
      return true;
    }
  }
  return false;
}
bool ExisteCliente(std::string nickname, std::set<DTCliente *> clientes) // funcion auxiliar
{
  for (auto it = clientes.begin(); it != clientes.end(); it++)
  {
    if ((*it)->getNickname() == nickname)
    {
      return true;
    }
  }
  return false;
}
DTVendedor *datoVendedor(std::string nickname) // funcion auxiliar
{
  std::set<DTVendedor *> vendedores = controladorUsuario->listarVendedores();
  for (auto it = vendedores.begin(); it != vendedores.end(); it++)
  {
    if ((*it)->getNickname() == nickname)
    {
      return (*it);
    }
  }
  return nullptr;
}
DTCliente *datoCliente(std::string nickname) // funcion auxiliar
{
  std::set<DTCliente *> clientes = controladorUsuario->listarClientes();
  for (auto it = clientes.begin(); it != clientes.end(); it++)
  {
    if ((*it)->getNickname() == nickname)
    {
      return (*it);
    }
  }
  return nullptr;
}
void listarInfoVendedores(std::set<DTVendedor *> vendedores)
{
  for (auto it = vendedores.begin(); it != vendedores.end(); it++)
  {
    std::string nick = (*it)->getNickname();
    DTFecha *fecha = (*it)->getFechaNacimiento();
    int dia = fecha->getDia();
    int mes = fecha->getMes();
    int anio = fecha->getAnio();
    std::string rut = (*it)->getCodigoRUT();
    std::cout << "Nickname: " << nick << ", Fecha de nacimiento: " << dia << "/" << mes << "/" << anio << ", Codigo RUT: " << rut;
    std::cout << std::endl;
  }
}
void listarInfoClientes(std::set<DTCliente *> clientes)
{
  for (auto it = clientes.begin(); it != clientes.end(); it++)
  {
    std::string nick = (*it)->getNickname();
    DTFecha *fecha = (*it)->getFechaNacimiento();
    int dia = fecha->getDia();
    int mes = fecha->getMes();
    int anio = fecha->getAnio();
    DTDireccion *adress = (*it)->getDireccion();
    int nroPuerta = adress->getNroPuerta();
    std::string calle = adress->getNombreCalle();
    std::string ciudad = (*it)->getCiudadDeResidencia();
    std::cout << "Nickname: " << nick << ", Fecha de nacimiento: " << dia << "/" << mes << "/" << anio << ", Direccion: " << calle << "," << nroPuerta << ", Ciudad: " << ciudad;
    std::cout << std::endl;
  }
}
void listarNickVendedores(std::set<DTVendedor *> vendedores) // funcion auxiliar
{
  for (auto it = vendedores.begin(); it != vendedores.end(); it++)
  {
    std::string nick = (*it)->getNickname();
    std::cout << "Nickname: " << nick;
    std::cout << std::endl;
  }
}
void listarNickClientes() // funcion auxiliar
{
  std::set<DTCliente *> clientes = controladorUsuario->listarClientes();
  for (auto it = clientes.begin(); it != clientes.end(); it++)
  {
    std::string nick = (*it)->getNickname();
    std::cout << "Nickname: " << nick;
    std::cout << std::endl;
  }
}
void listarNickUsuarios()
{
  std::set<DTUsuario *> usuarios = controladorUsuario->listarUsuarios();
  for (auto it = usuarios.begin(); it != usuarios.end(); it++)
  {
    std::string nick = (*it)->getNickname();
    std::cout << "Nickname: " << nick;
    std::cout << std::endl;
  }
}
void ListarProductosDeVendedor(std::string nickname) // funcion auxiliar
{
  std::set<DTProducto *> listaProductos = controladorUsuario->listarProductosVendedor(nickname);
  for (auto it = listaProductos.begin(); it != listaProductos.end(); it++)
  {
    int idProducto = (*it)->getId();
    std::string nombreProducto = (*it)->getNombre();
    std::cout << "Codigo: " << idProducto << ", Nombre: " << nombreProducto;
    std::cout << std::endl;
  }
}
void imprimirInfoProducto(DTProducto *producto)
{
  int precioProducto = producto->getPrecio();
  int stockProducto = producto->getCantidadEnStock();
  std::string descripcionProducto = producto->getDescripcion();
  TipoProducto tipoDelProducto = producto->getTipoProducto();
  std::string tipoDelPrudctoString;
  switch (tipoDelProducto)
  {
  case TipoProducto::Electrodomesticos:
    tipoDelPrudctoString = "Electrodomesticos";
    break;
  case TipoProducto::Ropa:
    tipoDelPrudctoString = "Ropa";
    break;

  default:
    tipoDelPrudctoString = "Otros";
    break;
  }
  DTVendedor *vendedorProducto = producto->getVendedor();
  std::string vendedorProductoString = vendedorProducto->getNickname();
  std::cout << "Precio: " << precioProducto << ", Stock: " << stockProducto << ", Descripcion: " << descripcionProducto << ", Categoria: " << tipoDelPrudctoString << ", Vendedor: " << vendedorProductoString;
  std::cout << std::endl;
}
bool EstaEnPromo(int idProducto) // funcion auxiliar
{
  DTProducto *producto = controladorProducto->obtenerProductoDisponible(idProducto);
  if (producto->getPromocion() != NULL)
  {
    return true;
  }
  return false;
}
void ListarPromosVigentesVendedor(DTVendedor *vendedor) // funcion auxiliar
{
  std::cout << "Promociones del vendedor: " << std::endl;
  std::cout << std::endl;
  for (auto it = (vendedor->getPromociones()).begin(); it != (vendedor->getPromociones()).end(); ++it)
  {
    int dia = ((*it)->getFechaVencimiento())->getDia();
    int mes = ((*it)->getFechaVencimiento())->getMes();
    int anio = ((*it)->getFechaVencimiento())->getAnio();
    std::cout << "Nombre: " << (*it)->getNombre() << std::endl
              << "Descripcion: " << (*it)->getDescripcion() << std::endl
              << "Fecha de vencimiento: " << dia << "/" << mes << "/" << anio << std::endl;
    std::cout << std::endl;
    std::cout << "Productos: " << std::endl;
    for (auto it2 = (*it)->getProductos().begin(); it2 != (*it)->getProductos().end(); it2++)
    {
      std::cout << "Codigo: " << (*it2).second->getId() << std::endl
                << "Nombre: " << (*it2).second->getNombre() << std::endl
                << "Cantidad minima para aprovechar la promocion: " << (*it2).second->getCantidadMinima() << std::endl
                << std::endl;
    }
    std::cout << std::endl;
  };
}
void ListarComprasRealizadas(DTCliente *cliente) // funcion auxiliar
{
  std::cout << "Compras realizadas:" << std::endl;
  for (auto it = (cliente->getComprasPasadas()).begin(); it != (cliente->getComprasPasadas()).end(); ++it)
  {
    int dia = ((*it)->getFechaDeCompra())->getDia();
    int mes = ((*it)->getFechaDeCompra())->getMes();
    int anio = ((*it)->getFechaDeCompra())->getAnio();
    std::cout << "Fecha de compra: " << dia << "/" << mes << "/" << anio << std::endl
              << "Monto final: " << (*it)->getMontoFinal() << std::endl;
    std::cout << std::endl;
    std::cout << "Productos: " << std::endl;
    for (auto it2 = (*it)->getRegistroProductos().begin(); it2 != (*it)->getRegistroProductos().end(); it2++)
    {
      std::cout << "ID: " << (*it2)->getId() << std::endl
                << "Nombre: " << (*it2)->getNombre() << std::endl
                << "Precio: " << (*it2)->getPrecio() << std::endl
                << "Unidades compradas: " << (*it2)->getCantidad() << std::endl
                << std::endl;
    }
    std::cout << std::endl;
  };
}
int idProducto(std::string nickProducto, std::string nickVendedor) // funcion auxiliar
{
  std::set<DTProducto *> productos = controladorProducto->obtenerProductosDisponibles();
  for (auto it = productos.begin(); it != productos.end(); it++)
  {
    if (((*it)->getNombre() == nickProducto) && ((*it)->getVendedor()->getNickname() == nickVendedor))
    {
      return (*it)->getId();
    };
  };
  return 0;
}
void listarProductosNoEnviadosVendedor(std::string nickV) //funcion auxiliar
{
  {
    std::set<DTProducto *> listaProductos = controladorUsuario->listarProductosVendedor(nickV);
    for (auto it = listaProductos.begin(); it != listaProductos.end(); it++)
    {
      if (!((*it)->enviadoCorrectamente()))
      {
        int idProducto = (*it)->getId();
        std::string nombreProducto = (*it)->getNombre();
        std::cout << "Codigo: " << idProducto << ", Nombre: " << nombreProducto;
        std::cout << std::endl;
      }
    }
  }
}
bool estaEnCompra(int id, DTCompra *compra) //funcion auxiliar
{
  if (compra->getRegistroProducto(id) != NULL)
  {
    return true;
  }
  return false;
}
void listarParClienteFechaDeCompra(DTCompra *compra)  //funcion auxiliar
{
  std::cout << "Cliente: " << compra->getCliente()->getNickname() << std::endl
            << "Fecha de compra: " << compra->getFechaDeCompra()->getDia() << "/"
            << compra->getFechaDeCompra()->getMes() << "/"
            << compra->getFechaDeCompra()->getAnio() << std::endl;
  std::cout << std::endl;
}

//------------------------------------------CARGA DE DATOS INICIALES-----------------------------------
// Usuarios, Productos, Promos // Falta: Compras Comentarios
void CargarDatos()
{
  // USUARIOS:
  // US1 - Usuario Uno - Vendedor
  std::string nickUS1 = "ana23";
  std::string passUS1 = "qwer1234";
  DTFecha *fechaUS1 = new DTFecha(15, 5, 1988);
  std::string rutUS1 = "212345678001";
  controladorUsuario->altaNuevoVendedor(nickUS1, passUS1, fechaUS1, rutUS1);
  // US2 - Usuario Dos - Vendedor
  std::string nickUS2 = "carlos78";
  std::string passUS2 = "asdfghj";
  DTFecha *fechaUS2 = new DTFecha(18, 6, 1986);
  std::string rutUS2 = "356789012345";
  controladorUsuario->altaNuevoVendedor(nickUS2, passUS2, fechaUS2, rutUS2);
  // US3 - Usuario Tres - Vendedor
  std::string nickUS3 = "diegom";
  std::string passUS3 = "zxcvbn";
  DTFecha *fechaUS3 = new DTFecha(28, 7, 1993);
  std::string rutUS3 = "190123456789";
  controladorUsuario->altaNuevoVendedor(nickUS3, passUS3, fechaUS3, rutUS3);
  // US4 - Usuario Cuatro - Cliente
  std::string nickUS4 = "juan87";
  std::string passUS4 = "1qaz2wsx";
  DTFecha *fechaUS4 = new DTFecha(20, 10, 1992);
  DTDireccion *adressUS4 = new DTDireccion("Av. 18 de Julio", 456);
  std::string cityUS4 = "Melo";
  controladorUsuario->altaNuevoCliente(nickUS4, passUS4, fechaUS4, adressUS4, cityUS4);
  // US5 - Usuario Cinco - Cliente
  std::string nickUS5 = "laura";
  std::string passUS5 = "3edc4rfv";
  DTFecha *fechaUS5 = new DTFecha(22, 9, 1979);
  DTDireccion *adressUS5 = new DTDireccion("Rondeau", 1617);
  std::string cityUS5 = "Montevideo";
  controladorUsuario->altaNuevoCliente(nickUS5, passUS5, fechaUS5, adressUS5, cityUS5);
  // US6 - Usuario Seis - Vendedor
  std::string nickUS6 = "maria01";
  std::string passUS6 = "5tgb6yhn";
  DTFecha *fechaUS6 = new DTFecha(25, 3, 1985);
  std::string rutUS6 = "321098765432";
  controladorUsuario->altaNuevoVendedor(nickUS6, passUS6, fechaUS6, rutUS6);
  // US7 - Usuario Siete - Cliente
  std::string nickUS7 = "natalia";
  std::string passUS7 = "poiuyt";
  DTFecha *fechaUS7 = new DTFecha(14, 4, 1982);
  DTDireccion *adressUS7 = new DTDireccion("Paysandu", 2021);
  std::string cityUS7 = "Salto";
  controladorUsuario->altaNuevoCliente(nickUS7, passUS7, fechaUS7, adressUS7, cityUS7);
  // US8 - Usuario Ocho - Cliente
  std::string nickUS8 = "pablo10";
  std::string passUS8 = "lkjhgv";
  DTFecha *fechaUS8 = new DTFecha(30, 11, 1995);
  DTDireccion *adressUS8 = new DTDireccion("Av. Rivera", 1819);
  std::string cityUS8 = "Mercedes";
  controladorUsuario->altaNuevoCliente(nickUS8, passUS8, fechaUS8, adressUS8, cityUS8);
  // US9 - Usuario Nueve - Cliente
  std::string nickUS9 = "roberto";
  std::string passUS9 = "mnbvcx";
  DTFecha *fechaUS9 = new DTFecha(12, 8, 1990);
  DTDireccion *adressUS9 = new DTDireccion("Av. Brasil", 1011);
  std::string cityUS9 = "Montevideo";
  controladorUsuario->altaNuevoCliente(nickUS9, passUS9, fechaUS9, adressUS9, cityUS9);
  // US10 - Usuario Diez - Vendedor
  std::string nickUS10 = "sofia25";
  std::string passUS10 = "1234asdf";
  DTFecha *fechaUS10 = new DTFecha(7, 12, 1983);
  std::string rutUS10 = "445678901234";
  controladorUsuario->altaNuevoVendedor(nickUS10, passUS10, fechaUS10, rutUS10);
  // PRODUCTOS:
  // PR1 - Producto 1 - US2
  std::string nombrePR1 = "Camiseta Azul";
  std::string descripcionPR1 = "Camiseta de poliester, color azul";
  float precioPR1 = 1400;
  int stockPR1 = 50;
  TipoProducto tipoPR1 = TipoProducto::Ropa;
  controladorProducto->registrarDatosProductos(nombrePR1, precioPR1, stockPR1, descripcionPR1, tipoPR1, nickUS2);
  // PR2 - Producto 2 - US1
  std::string nombrePR2 = "Televisor LED";
  std::string descripcionPR2 = "Televisor LED 55 pulgadas";
  float precioPR2 = 40500;
  int stockPR2 = 30;
  TipoProducto tipoPR2 = TipoProducto::Electrodomesticos;
  controladorProducto->registrarDatosProductos(nombrePR2, precioPR2, stockPR2, descripcionPR2, tipoPR2, nickUS1);
  // PR3 - Producto 3 - US2
  std::string nombrePR3 = "Chaqueta de Cuero";
  std::string descripcionPR3 = "Chaqueta de cuero, color negro";
  float precioPR3 = 699.99;
  int stockPR3 = 20;
  TipoProducto tipoPR3 = TipoProducto::Ropa;
  controladorProducto->registrarDatosProductos(nombrePR3, precioPR3, stockPR3, descripcionPR3, tipoPR3, nickUS2);
  // PR4 - Producto 4 - US1
  std::string nombrePR4 = "Microondas Digital";
  std::string descripcionPR4 = "Microondas digital, 30L";
  float precioPR4 = 1199.99;
  int stockPR4 = 15;
  TipoProducto tipoPR4 = TipoProducto::Electrodomesticos;
  controladorProducto->registrarDatosProductos(nombrePR4, precioPR4, stockPR4, descripcionPR4, tipoPR4, nickUS1);
  // PR5 - Producto 5 - US3
  std::string nombrePR5 = "Luz LED";
  std::string descripcionPR5 = "Luz Bluetooth LED";
  float precioPR5 = 599.99;
  int stockPR5 = 40;
  TipoProducto tipoPR5 = TipoProducto::Otros;
  controladorProducto->registrarDatosProductos(nombrePR5, precioPR5, stockPR5, descripcionPR5, tipoPR5, nickUS3);
  // PR6 - Producto 6 - US2
  std::string nombrePR6 = "Pantalones Vaqueros";
  std::string descripcionPR6 = "Pantalones vaqueros, talla 32";
  float precioPR6 = 60;
  int stockPR6 = 25;
  TipoProducto tipoPR6 = TipoProducto::Ropa;
  controladorProducto->registrarDatosProductos(nombrePR6, precioPR6, stockPR6, descripcionPR6, tipoPR6, nickUS2);
  // PR7 - Producto 7 - US3
  std::string nombrePR7 = "Auriculares Bluetooth";
  std::string descripcionPR7 = "Auriculares bluethooth para celular";
  float precioPR7 = 199.99;
  int stockPR7 = 35;
  TipoProducto tipoPR7 = TipoProducto::Otros;
  controladorProducto->registrarDatosProductos(nombrePR7, precioPR7, stockPR7, descripcionPR7, tipoPR7, nickUS3);
  // PR8 - Producto 8 - US1
  std::string nombrePR8 = "Refrigerador";
  std::string descripcionPR8 = "Refrigerador de doble puerta";
  float precioPR8 = 15499;
  int stockPR8 = 10;
  TipoProducto tipoPR8 = TipoProducto::Electrodomesticos;
  controladorProducto->registrarDatosProductos(nombrePR8, precioPR8, stockPR8, descripcionPR8, tipoPR8, nickUS1);
  // PR9 - Producto 9 - US1
  std::string nombrePR9 = "Cafetera";
  std::string descripcionPR9 = "Cafetera de goteo programable";
  float precioPR9 = 23000;
  int stockPR9 = 50;
  TipoProducto tipoPR9 = TipoProducto::Electrodomesticos;
  controladorProducto->registrarDatosProductos(nombrePR9, precioPR9, stockPR9, descripcionPR9, tipoPR9, nickUS1);
  // PR10 - Producto 10 - US2
  std::string nombrePR10 = "Zapatillas Deportivas";
  std::string descripcionPR10 = "Zapatillas para correr, talla 42";
  float precioPR10 = 5500;
  int stockPR10 = 20;
  TipoProducto tipoPR10 = TipoProducto::Ropa;
  controladorProducto->registrarDatosProductos(nombrePR10, precioPR10, stockPR10, descripcionPR10, tipoPR10, nickUS2);
  // PR11 - Producto 11 - US2
  std::string nombrePR11 = "Mochila";
  std::string descripcionPR11 = "Mochila de viaje, 40L";
  float precioPR11 = 9000;
  int stockPR11 = 30;
  TipoProducto tipoPR11 = TipoProducto::Otros;
  controladorProducto->registrarDatosProductos(nombrePR11, precioPR11, stockPR11, descripcionPR11, tipoPR11, nickUS2);
  // PR12 - Producto 12 - US3
  std::string nombrePR12 = "Plancha de Ropa";
  std::string descripcionPR12 = "2 Plancha a vapor, 1500W";
  float precioPR12 = 2534;
  int stockPR12 = 25;
  TipoProducto tipoPR12 = TipoProducto::Electrodomesticos;
  controladorProducto->registrarDatosProductos(nombrePR12, precioPR12, stockPR12, descripcionPR12, tipoPR12, nickUS3);
  // PR13 - Producto 13 - US10
  std::string nombrePR13 = "Gorra";
  std::string descripcionPR13 = "Gorra para deportes, color rojo";
  float precioPR13 = 200;
  int stockPR13 = 50;
  TipoProducto tipoPR13 = TipoProducto::Ropa;
  controladorProducto->registrarDatosProductos(nombrePR13, precioPR13, stockPR13, descripcionPR13, tipoPR13, nickUS10);
  // PR14 - Producto 14 - US3
  std::string nombrePR14 = "Tablet";
  std::string descripcionPR14 = "Tablet Android de 10 pulgadas";
  float precioPR14 = 15000;
  int stockPR14 = 15;
  TipoProducto tipoPR14 = TipoProducto::Electrodomesticos;
  controladorProducto->registrarDatosProductos(nombrePR14, precioPR14, stockPR14, descripcionPR14, tipoPR14, nickUS3);
  // PR15 - Producto 15 - US10
  std::string nombrePR15 = "Reloj de Pared";
  std::string descripcionPR15 = "Reloj de pared vintage";
  float precioPR15 = 150.50;
  int stockPR15 = 20;
  TipoProducto tipoPR15 = TipoProducto::Otros;
  controladorProducto->registrarDatosProductos(nombrePR15, precioPR15, stockPR15, descripcionPR15, tipoPR15, nickUS10);
  // PROMOCIONES:
  // PM1 - Promocion 1
  std::string nombrePM1 = "Casa nueva";
  std::string descrpcionPM1 = "Para que puedas ahorrar en la casa nueva";
  float porcentajeDescuentoPM1 = 30;
  DTFecha *vencimientoPM1 = new DTFecha(21, 10, 2024);
  controladorPromocion->registrarDatosPromo(nombrePM1, descrpcionPM1, vencimientoPM1, porcentajeDescuentoPM1);
  controladorPromocion->asignarVendedor(nickUS1);
  // Productos relacionados Promocion 1
  // PP1: producto: PR2, Min: 1
  int idPR1PR2 = idProducto(nombrePR2, nickUS1);
  controladorPromocion->agregarAPromo(idPR1PR2, 1);
  // PP2: producto: PR4, Min: 1
  int idPR1PR4 = idProducto(nombrePR4, nickUS1);
  controladorPromocion->agregarAPromo(idPR1PR4, 1);
  // PP3: producto: PR8, Min: 1
  int idPR1PR8 = idProducto(nombrePR8, nickUS1);
  controladorPromocion->agregarAPromo(idPR1PR8, 1);
  controladorPromocion->altaNuevaPromo();

  // PM2 - Promocion 2
  std::string nombrePM2 = "Fiesta";
  std::string descrpcionPM2 = "Para que no te quedes sin ropa para las fiestas";
  float porcentajeDescuentoPM2 = 20;
  DTFecha *vencimientoPM2 = new DTFecha(26, 10, 2024);
  controladorPromocion->registrarDatosPromo(nombrePM2, descrpcionPM2, vencimientoPM2, porcentajeDescuentoPM2);
  controladorPromocion->asignarVendedor(nickUS2);
  // Productos relacionados Promocion 2
  // PP4: producto: PR3, Min: 2
  int idPM2PR3 = idProducto(nombrePR3, nickUS2);
  controladorPromocion->agregarAPromo(idPM2PR3, 2);
  // PP5: producto: PR6, Min: 3
  int idPM2PR6 = idProducto(nombrePR6, nickUS2);
  controladorPromocion->agregarAPromo(idPM2PR6, 3);
  controladorPromocion->altaNuevaPromo();

  // PM3 - Promocion 3
  std::string nombrePM3 = "Domotica";
  std::string descrpcionPM3 = "Para modernizar tu casa";
  float porcentajeDescuentoPM3 = 10;
  DTFecha *vencimientoPM3 = new DTFecha(26, 10, 2024);
  controladorPromocion->registrarDatosPromo(nombrePM3, descrpcionPM3, vencimientoPM3, porcentajeDescuentoPM3);
  controladorPromocion->asignarVendedor(nickUS3);
  // Productos relacionados Promocion 3
  // PP6: producto: PR5, Min: 2
  int idPM3PR5 = idProducto(nombrePR5, nickUS3);
  controladorPromocion->agregarAPromo(idPM3PR5, 2);
  controladorPromocion->altaNuevaPromo();

  // PM4 - Promocion 4
  std::string nombrePM4 = "Liquidacion";
  std::string descrpcionPM4 = "Hasta agotar stock";
  float porcentajeDescuentoPM4 = 10;
  DTFecha *vencimientoPM4 = new DTFecha(26, 3, 2024);
  controladorPromocion->registrarDatosPromo(nombrePM4, descrpcionPM4, vencimientoPM4, porcentajeDescuentoPM4);
  controladorPromocion->asignarVendedor(nickUS3);
  // Productos relacionados Promocion 4
  // PP7: producto: PR14, Min: 1
  int idPM4PR14 = idProducto(nombrePR14, nickUS3);
  controladorPromocion->agregarAPromo(idPM4PR14, 1);
  controladorPromocion->altaNuevaPromo();

 ////////////////////////////////////////////////////////////////////////////
  ////////  Compras:
  ////////////////////////////////////////////////////////////////////////////
	// FALTA ASIGNAR COMO ENVIADOS LOS PRODUCTOS	

  // CO1 - Compra 1 //////////////////////////////////////////////////////////////////////
  controladorCompra->crearCompra(nickUS4, 01, 05, 2024);
  // CP1 - Producto: PR2 - Cantidad: 2 - Enviado: Si
  int idCO1PR2 = idProducto(nombrePR2, nickUS1);
  controladorCompra->agregarProductoACompra(idCO1PR2, 2);
  controladorProducto->enviarProd(controladorProducto->getProducto(idCO1PR2));
  // CP2 - Producto: PR4 - Cantidad: 1 - Enviado: No
  int idCO1PR4 = idProducto(nombrePR4, nickUS1);
  controladorCompra->agregarProductoACompra(idCO1PR4, 1);
  // CP3 - Producto: PR8 - Cantidad: 1 - Enviado: No
  int idCO1PR8 = idProducto(nombrePR8, nickUS1);
  controladorCompra->agregarProductoACompra(idCO1PR8, 1);
  bool des1 = controladorCompra->calcularDescuentos();
  controladorCompra->registrarCompraExitosa(true);
  // PR2 enviado
  // PR4 no enviado
  // PR8 no enviado
  
  // CO2 - Compra 2 //////////////////////////////////////////////////////////////////////
  controladorCompra->crearCompra(nickUS4, 01, 05, 2024);
  // CP4 - Producto: PR5 - Cantidad: 1 - Enviado: Si
  int idCO2PR5 = idProducto(nombrePR5, nickUS3);
  controladorCompra->agregarProductoACompra(idCO2PR5, 1);
  controladorProducto->enviarProd(controladorProducto->getProducto(idCO2PR5));
  bool des2 = controladorCompra->calcularDescuentos();
  controladorCompra->registrarCompraExitosa(true);
  // PR5 enviado

  // CO3 - Compra 3 //////////////////////////////////////////////////////////////////////
  controladorCompra->crearCompra(nickUS5, 15, 05, 2024);
  // CP5 - Producto: PR14 - Cantidad: 10 - Enviado: Si
  int idCO3PR14 = idProducto(nombrePR14, nickUS3);
  controladorCompra->agregarProductoACompra(idCO3PR14, 10);
  controladorProducto->enviarProd(controladorProducto->getProducto(idCO3PR14));
  bool des3 = controladorCompra->calcularDescuentos();
  controladorCompra->registrarCompraExitosa(true);
  // PR14 enviado

  // CO4 - Compra 4 //////////////////////////////////////////////////////////////////////
  controladorCompra->crearCompra(nickUS7, 25, 04, 2024);
  // CP6 - Producto: PR11 - Cantidad: 1 - Enviado: Si
  int idCO4PR11 = idProducto(nombrePR11, nickUS2);
  controladorCompra->agregarProductoACompra(idCO4PR11, 1);
  controladorProducto->enviarProd(controladorProducto->getProducto(idCO4PR11));
  // CP7 - Producto: PR12 - Cantidad: 1 - Enviado: Si
  int idCO4PR12 = idProducto(nombrePR12, nickUS3);
  controladorCompra->agregarProductoACompra(idCO4PR12, 1);
  controladorProducto->enviarProd(controladorProducto->getProducto(idCO4PR12));
  // CP8 - Producto: PR13 - Cantidad: 1 - Enviado: Si
  int idCO4PR13 = idProducto(nombrePR13, nickUS10);
  controladorCompra->agregarProductoACompra(idCO4PR13, 1);
  controladorProducto->enviarProd(controladorProducto->getProducto(idCO4PR13));
  bool des4 = controladorCompra->calcularDescuentos();
  controladorCompra->registrarCompraExitosa(true);
  // PR11 enviado
  // PR12 enviado
  // PR13 enviado

  // CO5 - Compra 5 //////////////////////////////////////////////////////////////////////
  controladorCompra->crearCompra(nickUS4, 20, 05, 2024);
  // CP8 - Producto: PR3 - Cantidad: 2 - Enviado: No
  int idCO5PR3 = idProducto(nombrePR3, nickUS2);
  controladorCompra->agregarProductoACompra(idCO5PR3, 2);
  // CP8 - Producto: PR6 - Cantidad: 3 - Enviado: Si
  int idCO5PR6 = idProducto(nombrePR6, nickUS2);
  controladorCompra->agregarProductoACompra(idCO5PR6, 3);
  controladorProducto->enviarProd(controladorProducto->getProducto(idCO5PR6));
  bool des5 = controladorCompra->calcularDescuentos();
  controladorCompra->registrarCompraExitosa(true);
  // PR3 no enviado
  // PR6 enviado

  // CO6 - Compra 6 //////////////////////////////////////////////////////////////////////
  controladorCompra->crearCompra(nickUS5, 12, 05, 2024);
  // CP9 - Producto: PR1 - Cantidad: 2 - Enviado: No
  int idCO6PR1 = idProducto(nombrePR1, nickUS2);
  controladorCompra->agregarProductoACompra(idCO6PR1, 2);
  bool des6 = controladorCompra->calcularDescuentos();
  controladorCompra->registrarCompraExitosa(true);
  // PR1 enviado

  // CO7 - Compra 7 //////////////////////////////////////////////////////////////////////
  controladorCompra->crearCompra(nickUS7, 12, 05, 2024);
  // CP10 - Producto: PR1 - Cantidad: 3 - Enviado: Si
  int idCO7PR1 = idProducto(nombrePR1, nickUS2);
  controladorCompra->agregarProductoACompra(idCO7PR1, 3);
  controladorProducto->enviarProd(controladorProducto->getProducto(idCO7PR1));
  bool des7 = controladorCompra->calcularDescuentos();
  controladorCompra->registrarCompraExitosa(true);
  // PR1 enviado

  // CO8 - Compra 8 //////////////////////////////////////////////////////////////////////
  controladorCompra->crearCompra(nickUS8, 14, 05, 2024);
  // CP11 - Producto: PR1 - Cantidad: 4 - Enviado: No
  int idCO8PR1 = idProducto(nombrePR1, nickUS2);
  controladorCompra->agregarProductoACompra(idCO8PR1, 4);
  bool des8 = controladorCompra->calcularDescuentos();
  controladorCompra->registrarCompraExitosa(true);
  // PR1 no enviado

  // CO9 - Compra 9 //////////////////////////////////////////////////////////////////////
  controladorCompra->crearCompra(nickUS9, 15, 05, 2024);
  // CP12 - Producto: PR1 - Cantidad: 5 - Enviado: No
  int idCO9PR1 = idProducto(nombrePR1, nickUS2);
  controladorCompra->agregarProductoACompra(idCO9PR1, 5);
  bool des9 = controladorCompra->calcularDescuentos();
  controladorCompra->registrarCompraExitosa(true);
  // PR1 no enviado

  //////////////////////////////////////////////////////////////////////////
  ///////// Comentarios: ///////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////
  // void comentarProducto(std::string, DTFecha, int, std::string);
  // void responderComentario(std::string, DTFecha , int, std::string);

  // CM 1 - Comentario 1 - comentario a PR1
  std::string textoCM1 = "¿La camiseta azul esta disponible en talla M?";
  DTFecha *fechaComentarioCM1 = new DTFecha(01, 06, 2024);
  int idCM1PR1 = idProducto(nombrePR1, nickUS2);
  std::string userComentarioCM1 = nickUS1;
  // controladorComentario->comentarProducto(textoCM1, fechaComentarioCM1, idCM1PR1, userComentarioCM1);

  // CM 2 - Comentario 2 - respuesta a CM1
  std::string textoCM2 = "Si, tenemos la camiseta azul en talla M.";
  DTFecha *fechaComentarioCM2 = new DTFecha(01, 06, 2024);
  int idCM2PR1 = idProducto(nombrePR1, nickUS2);
  std::string userComentarioCM2 = nickUS2;
  // controladorComentario->responderComentario(textoCM2, fechaComentarioCM2, idCM2PR1, userComentarioCM2);

  // CM 3 - Comentario 3 - respuesta a CM2
  std::string textoCM3 = "¿Es de buen material? Me preocupa la durabilidad.";
  DTFecha *fechaComentarioCM3 = new DTFecha(02, 06, 2024);
  int idCM3PR1 = idProducto(nombrePR1, nickUS2);
  std::string userComentarioCM3 = nickUS5;
  // controladorComentario->responderComentario(textoCM3, fechaComentarioCM3, idCM3PR1, userComentarioCM3);

  // CM 4 - Comentario 4 - respuesta a CM3
  std::string textoCM4 = "He comprado antes y la calidad es buena.";
  DTFecha *fechaComentarioCM4 = new DTFecha(02, 06, 2024);
  int idCM4PR1 = idProducto(nombrePR1, nickUS2);
  std::string userComentarioCM4 = nickUS4;
  // controladorComentario->responderComentario(textoCM4, fechaComentarioCM4, idCM4PR1, userComentarioCM4);

  // CM 5 - Comentario 5 - comentario a PR1
  std::string textoCM5 = "¿Como es el ajuste? ¿Es ajustada o holgada?";
  DTFecha *fechaComentarioCM5 = new DTFecha(02, 06, 2024);
  int idCM5PR1 = idProducto(nombrePR1, nickUS2);
  std::string userComentarioCM5 = nickUS7;
  // controladorComentario->comentarProducto(textoCM5, fechaComentarioCM5, idCM5PR1, userComentarioCM5);

  // CM 6 - Comentario 6 - comentario a PR2
  std::string textoCM6 = "¿Cual es la resolucion del Televisor LED?";
  DTFecha *fechaComentarioCM6 = new DTFecha(02, 06, 2024);
  int idCM6PR2 = idProducto(nombrePR2, nickUS1);
  std::string userComentarioCM6 = nickUS5;
  // controladorComentario->comentarProducto(textoCM6, fechaComentarioCM6, idCM6PR2, userComentarioCM6);

  // CM 7 - Comentario 7 - respuesta a CM6
  std::string textoCM7 = "El televisor LED tiene una resolucion de 4K UHD.";
  DTFecha *fechaComentarioCM7 = new DTFecha(02, 06, 2024);
  int idCM7PR2 = idProducto(nombrePR2, nickUS1);
  std::string userComentarioCM7 = nickUS1;
  // controladorComentario->responderComentario(textoCM7, fechaComentarioCM7, idCM7PR2, userComentarioCM7);

  // CM 8 - Comentario 8 - comentario a PR2
  std::string textoCM8 = "¿Tiene soporte para HDR10?";
  DTFecha *fechaComentarioCM8 = new DTFecha(03, 06, 2024);
  int idCM8PR2 = idProducto(nombrePR2, nickUS1);
  std::string userComentarioCM8 = nickUS8;
  // controladorComentario->comentarProducto(textoCM8, fechaComentarioCM8, idCM8PR2, userComentarioCM8);

  // CM 9 - Comentario 9 - respuesta a CM8
  std::string textoCM9 = "Si, soporta HDR10.";
  DTFecha *fechaComentarioCM9 = new DTFecha(03, 06, 2024);
  int idCM9PR2 = idProducto(nombrePR2, nickUS1);
  std::string userComentarioCM9 = nickUS1;
  // controladorComentario->responderComentario(textoCM9, fechaComentarioCM9, idCM9PR2, userComentarioCM9);

  // CM 10 - Comentario 10 - comentario a PR3
  std::string textoCM10 = "¿La chaqueta de cuero es resistente al agua?";
  DTFecha *fechaComentarioCM10 = new DTFecha(03, 06, 2024);
  int idCM10PR3 = idProducto(nombrePR3, nickUS2);
  std::string userComentarioCM10 = nickUS7;
  // controladorComentario->comentarProducto(textoCM10, fechaComentarioCM10, idCM10PR3, userComentarioCM10);

  // CM 11 - Comentario 11 - respuesta a CM10
  std::string textoCM11 = "No, la chaqueta de cuero no es resistente al agua.";
  DTFecha *fechaComentarioCM11 = new DTFecha(03, 06, 2024);
  int idCM11PR3 = idProducto(nombrePR3, nickUS2);
  std::string userComentarioCM11 = nickUS2;
  // controladorComentario->responderComentario(textoCM11, fechaComentarioCM11, idCM11PR3, userComentarioCM11);

  // CM 12 - Comentario 12 - respuesta a CM10
  std::string textoCM12 = "¿Viene en otros colores?";
  DTFecha *fechaComentarioCM12 = new DTFecha(04, 06, 2024);
  int idCM12PR3 = idProducto(nombrePR3, nickUS2);
  std::string userComentarioCM12 = nickUS5;
  // controladorComentario->responderComentario(textoCM12, fechaComentarioCM12, idCM12PR3, userComentarioCM12);

  // CM 13 - Comentario 13 - respuesta a CM12
  std::string textoCM13 = "Si, tambien esta disponible en marron.";
  DTFecha *fechaComentarioCM13 = new DTFecha(04, 06, 2024);
  int idCM13PR3 = idProducto(nombrePR3, nickUS2);
  std::string userComentarioCM13 = nickUS2;
  // controladorComentario->responderComentario(textoCM13, fechaComentarioCM13, idCM13PR3, userComentarioCM13);

  // CM 14 - Comentario 14 - respuesta a CM10
  std::string textoCM14 = "¿Es adecuada para climas frios?";
  DTFecha *fechaComentarioCM14 = new DTFecha(04, 06, 2024);
  int idCM14PR3 = idProducto(nombrePR3, nickUS2);
  std::string userComentarioCM14 = nickUS9;
  // controladorComentario->responderComentario(textoCM14, fechaComentarioCM14, idCM14PR3, userComentarioCM14);

  // CM 15 - Comentario 15 - comentario a PR4
  std::string textoCM15 = "¿Es adecuada para climas frios?";
  DTFecha *fechaComentarioCM15 = new DTFecha(04, 06, 2024);
  int idCM15PR4 = idProducto(nombrePR4, nickUS1);
  std::string userComentarioCM15 = nickUS8;
  // controladorComentario->comentarProducto(textoCM15, fechaComentarioCM15, idCM15PR4, userComentarioCM15);

  // CM 16 - Comentario 16 - respuesta a CM15
  std::string textoCM16 = "Si, el microondas digital incluye una funcion de descongelacion rapida.";
  DTFecha *fechaComentarioCM16 = new DTFecha(04, 06, 2024);
  int idCM16PR4 = idProducto(nombrePR4, nickUS1);
  std::string userComentarioCM16 = nickUS1;
  // controladorComentario->responderComentario(textoCM16, fechaComentarioCM16, idCM16PR4, userComentarioCM16);

  // CM 17 - Comentario 17 - respuesta a CM15
  std::string textoCM17 = "¿Cuantos niveles de potencia tiene?";
  DTFecha *fechaComentarioCM17 = new DTFecha(05, 06, 2024);
  int idCM17PR4 = idProducto(nombrePR4, nickUS1);
  std::string userComentarioCM17 = nickUS7;
  // controladorComentario->responderComentario(textoCM17, fechaComentarioCM17, idCM17PR4, userComentarioCM17);

  // CM 18 - Comentario 18 - respuesta a CM17
  std::string textoCM18 = "Tiene 10 niveles de potencia.";
  DTFecha *fechaComentarioCM18 = new DTFecha(05, 06, 2024);
  int idCM18PR4 = idProducto(nombrePR4, nickUS1);
  std::string userComentarioCM18 = nickUS1;
  // controladorComentario->responderComentario(textoCM18, fechaComentarioCM18, idCM18PR4, userComentarioCM18);

  // CM 19 - Comentario 19 - respuesta a CM15
  std::string textoCM19 = "¿Es facil de limpiar?";
  DTFecha *fechaComentarioCM19 = new DTFecha(05, 06, 2024);
  int idCM19PR4 = idProducto(nombrePR4, nickUS1);
  std::string userComentarioCM19 = nickUS9;
  // controladorComentario->responderComentario(textoCM19, fechaComentarioCM19, idCM19PR4, userComentarioCM19);

  // CM 20 - Comentario 20 - comentario a PR5
  std::string textoCM20 = "¿La luz LED se puede controlar con una aplicacion movil?";
  DTFecha *fechaComentarioCM20 = new DTFecha(05, 06, 2024);
  int idCM20PR5 = idProducto(nombrePR5, nickUS3);
  std::string userComentarioCM20 = nickUS9;
  // controladorComentario->comentarProducto(textoCM20, fechaComentarioCM20, idCM20PR5, userComentarioCM20);

  // CM 21 - Comentario 21 - respuesta a CM20
  std::string textoCM21 = "Si, la luz LED se puede controlar a traves de una aplicacion movil.";
  DTFecha *fechaComentarioCM21 = new DTFecha(05, 06, 2024);
  int idCM21PR5 = idProducto(nombrePR5, nickUS3);
  std::string userComentarioCM21 = nickUS3;
  // controladorComentario->responderComentario(textoCM21, fechaComentarioCM21, idCM21PR5, userComentarioCM21);

  // CM 22 - Comentario 22 - respuesta a CM20
  std::string textoCM22 = "¿Es compatible con Alexa o Google Home?";
  DTFecha *fechaComentarioCM22 = new DTFecha(06, 06, 2024);
  int idCM22PR5 = idProducto(nombrePR5, nickUS3);
  std::string userComentarioCM22 = nickUS8;
  // controladorComentario->responderComentario(textoCM22, fechaComentarioCM22, idCM22PR5, userComentarioCM22);

  // CM 23 - Comentario 23 - respuesta a CM22
  std::string textoCM23 = "Si, es compatible con ambos.";
  DTFecha *fechaComentarioCM23 = new DTFecha(06, 06, 2024);
  int idCM23PR5 = idProducto(nombrePR5, nickUS3);
  std::string userComentarioCM23 = nickUS3;
  // controladorComentario->responderComentario(textoCM23, fechaComentarioCM23, idCM23PR5, userComentarioCM23);

  // CM 24 - Comentario 24 - respuesta a CM20
  std::string textoCM24 = "¿Cuanto dura la bateria?";
  DTFecha *fechaComentarioCM24 = new DTFecha(06, 06, 2024);
  int idCM24PR5 = idProducto(nombrePR5, nickUS3);
  std::string userComentarioCM24 = nickUS7;
  // controladorComentario->responderComentario(textoCM24, fechaComentarioCM24, idCM24PR5, userComentarioCM24);

  // CM 25 - Comentario 25 - respuesta a CM20
  std::string textoCM25 = "¿La aplicacion movil es facil de usar?";
  DTFecha *fechaComentarioCM25 = new DTFecha(07, 06, 2024);
  int idCM25PR5 = idProducto(nombrePR5, nickUS3);
  std::string userComentarioCM25 = nickUS8;
  // controladorComentario->responderComentario(textoCM25, fechaComentarioCM25, idCM25PR5, userComentarioCM25);

  std::cout << "Los datos iniciales fueron cargados." << std::endl;
}

//-------------------------------------------------CASOS DE USO----------------------------------------
void NuevoVendedor() // Implementado //
{
  std::string nickUS;
  std::cout << "Escriba su nickname" << std::endl;
  std::cin >> nickUS;
  while (nickUS.length() <= 5)
  {
    std::cout << "El nickname debe tener al menos 6 caracteres" << std::endl;
    std::cin >> nickUS;
  }
  if (!ExisteUsuario(nickUS))
  {
    std::string passUS;
    std::cout << "Escriba su password" << std::endl;
    std::cin >> passUS;
    while (passUS.length() <= 5)
    {
      std::cout << "Su password debe tener al menos 6 caracteres" << std::endl;
      std::cin >> passUS;
    }
    int diaUS;
    std::cout << "Escriba su dia de naciemiento" << std::endl;
    std::cin >> diaUS;
    while (diaUS >= 32)
    {
      std::cout << "Ingrese un numero de dia valido" << std::endl;
      std::cin >> diaUS;
    }
    int mesUS;
    std::cout << "Escriba su mes de naciemiento" << std::endl;
    std::cin >> mesUS;
    while (mesUS >= 13)
    {
      std::cout << "Ingrese un numero de mes valido" << std::endl;
      std::cin >> mesUS;
    }
    int anioUS;
    std::cout << "Escriba su anio de naciemiento" << std::endl;
    std::cin >> anioUS;
    while (anioUS >= 2025)
    {
      std::cout << "Ingrese un numero de anio valido" << std::endl;
      std::cin >> anioUS;
    }
    DTFecha *fechaUS = new DTFecha(diaUS, mesUS, anioUS);
    std::string rutUS;
    std::cout << "Escriba su codigo RUT" << std::endl;
    std::cin >> rutUS;
    while (rutUS.length() != 12)
    {
      std::cout << "El codigo RUT debe contener 12 caracteres" << std::endl;
      std::cin >> rutUS;
    }
    controladorUsuario->altaNuevoVendedor(nickUS, passUS, fechaUS, rutUS);
    std::cout << "Vendedor registrado con exito." << std::endl;
  }
  else
  {
    std::cout << "El nickname seleccionado no esta disponible." << std::endl;
  }
}
void NuevoCliente() // Implementado //
{
  std::string nickUS;
  std::cout << "Escriba su nickname" << std::endl;
  std::cin >> nickUS;
  while (nickUS.length() <= 5)
  {
    std::cout << "El nickname debe tener al menos 6 caracteres" << std::endl;
    std::cin >> nickUS;
  }
  if (!ExisteUsuario(nickUS))
  {
    std::string passUS;
    std::cout << "Escriba su password" << std::endl;
    std::cin >> passUS;
    while (passUS.length() <= 5)
    {
      std::cout << "Su password debe tener al menos 6 caracteres" << std::endl;
      std::cin >> passUS;
    }
    int diaUS;
    std::cout << "Escriba su dia de naciemiento" << std::endl;
    std::cin >> diaUS;
    while (diaUS >= 32)
    {
      std::cout << "Ingrese un numero de dia valido" << std::endl;
      std::cin >> diaUS;
    }
    int mesUS;
    std::cout << "Escriba su mes de naciemiento" << std::endl;
    std::cin >> mesUS;
    while (mesUS >= 13)
    {
      std::cout << "Ingrese un numero de mes valido" << std::endl;
      std::cin >> mesUS;
    }
    int anioUS;
    std::cout << "Escriba su anio de naciemiento" << std::endl;
    std::cin >> anioUS;
    while (anioUS >= 2025)
    {
      std::cout << "Ingrese un numero de anio valido" << std::endl;
      std::cin >> anioUS;
    }
    DTFecha *fechaUS = new DTFecha(diaUS, mesUS, anioUS);
    std::string calleUS;
    std::cout << "Escriba la calle de su domicilio" << std::endl;
    std::getline(std::cin >> std::ws, calleUS);
    int nroPuertaUS;
    std::cout << "Escriba su numero de puerta" << std::endl;
    std::cin >> nroPuertaUS;
    DTDireccion *adressUS = new DTDireccion(calleUS, nroPuertaUS);
    std::string cityUS;
    std::cout << "Escriba la ciudad en la que vive" << std::endl;
    std::getline(std::cin >> std::ws, cityUS); // uso ws para limpiar los espacios pendientes
    controladorUsuario->altaNuevoCliente(nickUS, passUS, fechaUS, adressUS, cityUS);
    std::cout << "Cliente registrado con exito." << std::endl;
  }
  else
  {
    std::cout << "El nickname seleccionado no esta disponible." << std::endl;
  }
}
void ListarUsuarios() // Implementado //
{
  std::set<DTVendedor *> listaVendedores = controladorUsuario->listarVendedores();
  listarInfoVendedores(listaVendedores);
  std::set<DTCliente *> listaClientes = controladorUsuario->listarClientes();
  listarInfoClientes(listaClientes);
}
void AltaDeProducto() // Implementado //
{
  std::string nickVendedor;
  std::set<DTVendedor *> listaVendedores = controladorUsuario->listarVendedores();
  listarNickVendedores(listaVendedores);
  std::cout << "Escriba el nombre del vendedor" << std::endl;
  std::cin >> nickVendedor;
  if (ExisteVendedor(nickVendedor, listaVendedores))
  {
    std::string nombreProducto;
    std::cout << "Escriba el nombre del producto" << std::endl;
    std::getline(std::cin >> std::ws, nombreProducto);
    float precioProducto;
    std::cout << "Escriba el precio del producto" << std::endl;
    std::cin >> precioProducto;
    int stockProducto;
    std::cout << "Escriba el stock del producto" << std::endl;
    std::cin >> stockProducto;
    std::string descripcionProducto;
    std::cout << "Escriba la descripcion del producto" << std::endl;
    std::getline(std::cin >> std::ws, descripcionProducto);
    int intCategoriaProducto;
    std::cout << "Seleccione la categoria del producto" << std::endl
              << "1-Electrodomestico" << std::endl
              << "2-Ropa" << std::endl
              << "3-Otros" << std::endl;
    std::cin >> intCategoriaProducto;
    TipoProducto categoriaProducto = (TipoProducto)intCategoriaProducto;
    controladorProducto->registrarDatosProductos(nombreProducto, precioProducto, stockProducto, descripcionProducto, categoriaProducto, nickVendedor);
    std::cout << "El producto fue registrado con exito" << std::endl;
  }
  else
  {
    std::cout << "El vendedor ingresado no existe" << std::endl;
  }
}
void ConsultarUnProducto() // Implementado //
{
  std::set<DTProducto *> productos = controladorProducto->obtenerProductosDisponibles();
  for (auto it = productos.begin(); it != productos.end(); it++)
  {
    int idProductos = (*it)->getId();
    std::string nickProductos = (*it)->getNombre();
    std::cout << "Codigo: " << idProductos << ", Nombre: " << nickProductos;
    std::cout << std::endl;
  }
  int idProducto;
  std::cout << "Escriba el ID del producto que desea ver." << std::endl;
  std::cin >> idProducto;
  DTProducto *producto = controladorProducto->obtenerProductoDisponible(idProducto);
  imprimirInfoProducto(producto);
}
void CrearPromocion() // Implementado // ANDA // Puede mejorar evitando agregar productos a vendedores que no los tienen y evitar loop al agregar mismo producto a promo varias veces.
{
  // ingreso de datos de la promo
  std::string nombrePromo;
  std::cout << "Escriba el nombre de la promocion" << std::endl;
  std::getline(std::cin >> std::ws, nombrePromo);
  std::string descripcionPromo;
  std::cout << "Escriba la descripcion de la promocion" << std::endl;
  std::getline(std::cin >> std::ws, descripcionPromo);
  int diaPromo;
  std::cout << "Escriba el dia de vencimiento de la promocion" << std::endl;
  std::cin >> diaPromo;
  while (diaPromo >= 32)
  {
    std::cout << "Ingrese un numero de dia valido" << std::endl;
    std::cin >> diaPromo;
  }
  int mesPromo;
  std::cout << "Escriba el mes de vencimiento de la promocion" << std::endl;
  std::cin >> mesPromo;
  while (mesPromo >= 13)
  {
    std::cout << "Ingrese un numero de mes valido" << std::endl;
    std::cin >> mesPromo;
  }
  int anioPromo;
  std::cout << "Escriba el anio de vencimiento de la promocion" << std::endl;
  std::cin >> anioPromo;
  DTFecha *fechaPromo = new DTFecha(diaPromo, mesPromo, anioPromo);
  // porcentaje de descuento a la promocion
  int descuentoPromo;
  std::cout << "Escriba el porcentaje de descuento de la promocion" << std::endl;
  std::cin >> descuentoPromo;
  while (descuentoPromo >= 101)
  {
    std::cout << "El descuento no puede ser mayor al 100%" << std::endl;
    std::cin >> descuentoPromo;
  }
  controladorPromocion->registrarDatosPromo(nombrePromo, descripcionPromo, fechaPromo, descuentoPromo);
  // seleccion de vendedor
  std::set<DTVendedor *> listaVendedores = controladorUsuario->listarVendedores();
  listarNickVendedores(listaVendedores);
  std::string vendedorPromo;
  std::cout << "Escriba el nickname del vendedor de la promocion" << std::endl;
  std::cin >> vendedorPromo;
  std::set<DTVendedor *> vendedores = controladorUsuario->listarVendedores();
  while (!ExisteVendedor(vendedorPromo, vendedores))
  {
    std::cout << "El vendedor ingresado no existe" << std::endl;
    std::cout << "Porfavor ingrese un vendedor valido" << std::endl;
    std::cin >> vendedorPromo;
  }
  controladorPromocion->asignarVendedor(vendedorPromo);
  // seleccion de productos del vendedor mencionado.
  int opcion = 1;
  while (opcion != 2)
  {
    if (opcion == 1)
    {
      ListarProductosDeVendedor(vendedorPromo);
      int IdAgregarPromo;
      std::cout << "Escriba el codigo de producto que desea asignar a la promocion" << std::endl;
      std::cin >> IdAgregarPromo;
      while (EstaEnPromo(IdAgregarPromo))
      {
        std::cout << "El producto seleccionado ya se encuentra en una promocion" << std::endl;
        std::cout << "Porfavor ingrese un producto valido" << std::endl;
        std::cin >> IdAgregarPromo;
      };
      int stockAgregarPromo;
      std::cout << "Escriba la cantidad minima del producto" << std::endl;
      std::cin >> stockAgregarPromo;
      controladorPromocion->agregarAPromo(IdAgregarPromo, stockAgregarPromo);
    }
    std::cout << "1-Agregar otro producto a la promocion" << std::endl
              << "2-Dar de alta la promocion" << std::endl;
    std::cin >> opcion;
  }
  // se realiza el alta de la promocion
  controladorPromocion->altaNuevaPromo();
}
void ConsultarPromocion() // Implementado //
{
  std::cout << "PROMOCIONES VIGENTES EN EL SISTEMA" << std::endl;
  std::cout << std::endl;
  std::set<DTPromocion *> promociones = controladorPromocion->obtenerPromocionesVigentes();
  for (auto it = promociones.begin(); it != promociones.end(); it++)
  {
    std::string nombrePromo = (*it)->getNombre();
    std::string descripcionPromo = (*it)->getDescripcion();
    DTFecha *fechaVPromo = (*it)->getFechaVencimiento();
    float descuentoPromo = (*it)->getPorcentajeDescuento();
    std::cout << "Nombre: " << nombrePromo << std::endl
              << "Descripcion: " << descripcionPromo << std::endl
              << "Fecha de vencimiento: " << fechaVPromo->getDia() << "/" << fechaVPromo->getMes() << "/" << fechaVPromo->getAnio() << std::endl
              << "Descuento: " << descuentoPromo << "%" << std::endl
              << "Productos: " << std::endl;
    // imprimo todos los productos de cada promo
    std::map<int, DTProductoPromo *> productos = (*it)->getProductos();
    for (auto it = productos.begin(); it != productos.end(); it++)
    {
      int idProductos = (it)->first;
      std::string nickProductos = ((it)->second)->getNombre();
      int cantidadMinima = ((it)->second)->getCantidadMinima();
      std::cout << "Codigo: " << idProductos << ", Nombre: " << nickProductos <<", Cantidad Minima:"<< cantidadMinima;
      std::cout << std::endl;
    }
    std::cout << std::endl;
  }
  std::cout << "1-Ver en detalle los productos de una promocion" << std::endl
            << "2-Salir";
  std::cout << std::endl;
  int opcionElegida;
  std::cin >> opcionElegida;
  if (opcionElegida == 1)
  {
    std::cout << "Ingrese el nombre de la promocion: ";
    std::cout << std::endl;
    std::string nombrePromoElegida;
    std::cin >> nombrePromoElegida;
    std::cout << std::endl;
    DTPromocion *promoElegida = controladorPromocion->getPromocion(nombrePromoElegida)->getDataPromocion();
    std::cout << "Informacion del vendedor de la promocion: " << std::endl;
    DTVendedor *vendedorElegido = (promoElegida->getInfoVendedor());
    std::cout << "Nombre: " << vendedorElegido->getNickname() << std::endl
              << "Fecha de nacimiento" << vendedorElegido->getFechaNacimiento()->getDia() << vendedorElegido->getFechaNacimiento()->getMes() << vendedorElegido->getFechaNacimiento()->getAnio() << std::endl
              << "Codigo Rut: " << vendedorElegido->getCodigoRUT() << std::endl;
    std::cout << std::endl;
    std::cout << "Informacion de los productos de la promocion: " << std::endl;
    ListarProductosDeVendedor(vendedorElegido->getNickname());
  }
  else if (opcionElegida == 2)
  {
    return;
  }
}

void RealizarCompra() // Implementado // Error al ingresar productos en promocion a la vez que productos fuera de promo (Aunque no esta en los casos de uso por lo que no es prioridad).
{
  // seleccion de cliente
  listarNickClientes();
  std::string clienteCompra;
  std::cout << "Escriba el nickname del cliente de la compra" << std::endl;
  std::cin >> clienteCompra;
  std::set<DTCliente *> clientes = controladorUsuario->listarClientes();
  while (!ExisteCliente(clienteCompra, clientes))
  {
    std::cout << "El cliente ingresado no existe" << std::endl;
    std::cout << "Porfavor ingrese un cliente valido" << std::endl;
    std::cin >> clienteCompra;
  }
  std::cout << "Ingrese fecha de hoy (dia/mes/anio)" << std::endl;
  int dia;
  int mes;
  int anio;
  std::cin >> dia;
  std::cin >> mes;
  std::cin >> anio;
  controladorCompra->crearCompra(clienteCompra, dia, mes, anio);
  // Imprimir productos
  std::set<DTProducto *> productosDisp = controladorProducto->obtenerProductosDisponibles();
  std::cout << "Productos disponibles:" << std::endl;
  for (auto it = productosDisp.begin(); it != productosDisp.end(); it++)
  {
    int idProductos = (*it)->getId();
    std::string nickProductos = (*it)->getNombre();
    std::cout << "Codigo: " << idProductos << ", Nombre: " << nickProductos;
    std::cout << std::endl;
  }
  // Seleccion de productos
  int opcion = 1;
  while (opcion != 2)
  {
    if (opcion == 1)
    {
      int IdAgregarCompra;
      std::cout << "Escriba el codigo de producto que desea asignar a la compra" << std::endl;
      std::cin >> IdAgregarCompra;
      while (controladorCompra->estaEnCompra(IdAgregarCompra))
      {
        std::cout << "El producto seleccionado ya se encuentra en la compra" << std::endl;
        std::cout << "Porfavor ingrese un nuevo producto" << std::endl;
        std::cin >> IdAgregarCompra;
      };
      int cantidadAgregarCompra;
      std::cout << "Escriba la cantidad del producto" << std::endl;
      std::cout << "Cantidad actual en stock: " << controladorProducto->getProducto(IdAgregarCompra)->getCantidadEnStock() << std::endl;
      std::cin >> cantidadAgregarCompra;
      while(cantidadAgregarCompra > controladorProducto->getProducto(IdAgregarCompra)->getCantidadEnStock()){
        std::cout << "Cantidad en stock excedida ingrese menor cantidad" << std::endl;
        std::cin >> cantidadAgregarCompra;
      }
      controladorCompra->agregarProductoACompra(IdAgregarCompra, cantidadAgregarCompra);
    }
    std::cout << "1-Agregar otro producto a la compra" << std::endl;
    std::cout << "2-No agregar mas productos" << std::endl;
    std::cin >> opcion;
  }
  // Calculo de descuentos
  std::cout << "Calcular descuentos:" << std::endl;
  bool des = controladorCompra->calcularDescuentos();
  if(des){
    std::cout << "Descuento aplicado" << std::endl;
  }else{
    std::cout << "No hay descuento disponible" << std::endl;
  }
  // Mostrar detalles compra
  DTCompra *dataCompra = controladorCompra->obtenerDatosCompra();
  std::cout << "Datos compra:" << std::endl;
  std::cout << *dataCompra << std::endl;
  // Confirmacion de compra
  int confirmacion;
  std::cout << "Desea confirmar la compra? (SI(1) / NO(2))" << std::endl;
  std::cin >> confirmacion;
  if (confirmacion == 1)
  {
    controladorCompra->registrarCompraExitosa(true);
    std::cout << "Compra registrada con exito" << std::endl;
  }
  else
  {
    controladorCompra->registrarCompraExitosa(false);
    std::cout << "Compra cancelada" << std::endl;
  }
}
                      // chequear comprar varios productos

void DejarComentario() // faltan funciones//
{
  std::set<DTVendedor *> vendedores = controladorUsuario->listarVendedores();
  listarInfoVendedores(vendedores);
  listarNickClientes();
  std::string nickUsuario;
  std::cout << "Escriba su nickname de usuario" << std::endl;
  std::cin >> nickUsuario;
  while (!ExisteUsuario(nickUsuario))
  {
    std::cout << "El usuario ingresado no existe" << std::endl;
    std::cout << "Porfavor ingrese un usuario valido" << std::endl;
    std::cin >> nickUsuario;
  }
  std::set<DTProducto*> productos = controladorProducto->obtenerProductosDisponibles();
  for (auto it = productos.begin(); it != productos.end(); it++)
  {
    int idProductos = (*it)->getId();
    std::string nickProductos = (*it)->getNombre();
    std::cout << "Codigo: " << idProductos << ", Nombre: " << nickProductos;
    std::cout << std::endl;
  }
  int idDelProducto;
  std::cout << "Escriba el ID del producto que desea comentar." << std::endl;
  std::cin >> idDelProducto;
  std::cout << "1-Realizar un nuevo comentario" << std::endl
            << "2-Responder un comentario existente";
  std::cout << std::endl;
  int opcionElegida;
  std::cin >> opcionElegida;
  if (opcionElegida == 1)
  {
    std::string texto;
    std::cout << "Escriba su comentario del producto" << std::endl;
    std::getline(std::cin >> std::ws, texto);
    // comentar ese texto en "idDelProducto"
  }
  else if (opcionElegida == 2)
  {
    // lsitar comentarios del producto
    int aResponder;
    std::cout << "Escriba el ID del comentario que desea responder." << std::endl;
    std::cin >> aResponder;
    std::string texto;
    std::cout << "Escriba su comentario del producto" << std::endl;
    std::getline(std::cin >> std::ws, texto);
    // comentar ese texto en respuesta de "aResponder"
  }
  else
  {
    std::cout << "Opcion invalida" << std::endl;
  }
}

void EliminarComentario() // faltan funciones//
{
  std::set<DTVendedor *> vendedores = controladorUsuario->listarVendedores();
  listarInfoVendedores(vendedores);
  listarNickClientes();
  std::string nickUsuario;
  std::cout << "Escriba su nickname de usuario" << std::endl;
  std::cin >> nickUsuario;
  while (!ExisteUsuario(nickUsuario))
  {
    std::cout << "El usuario ingresado no existe" << std::endl;
    std::cout << "Porfavor ingrese un usuario valido" << std::endl;
    std::cin >> nickUsuario;
  }
  // Listar todos los comentarios de "nickUsuario"
  int idComentario;
  std::cout << "Escriba el ID del comentario que desea eliminar." << std::endl;
  std::cin >> idComentario;
  // Eliminar el comentario "idComentario" y todas sus respuestas "en cascada"
}

void EnviarProducto() //Implementado// Envia la compra, falta que SOLO imprima los productos con envios pendientes.
{
  std::set<DTVendedor *> vendedores = controladorUsuario->listarVendedores();
  listarInfoVendedores(vendedores);
  std::string nickVendedor;
  std::cout << "Escriba su nickname de vendedor" << std::endl;
  std::cin >> nickVendedor;
  while (!ExisteVendedor(nickVendedor, vendedores))
  {
    std::cout << "El vendedor ingresado no existe" << std::endl;
    std::cout << "Porfavor ingrese un vendedor valido" << std::endl;
    std::cin >> nickVendedor;
  };
  // se listan los productos que vende ese vendedor que tienen al menos una compra pendiente de envío//
  listarProductosNoEnviadosVendedor(nickVendedor);
  int idProducto;
  std::cout << "Escriba el ID del producto que desea enviar." << std::endl;
  std::cin >> idProducto;
  // lista todas las compras como parejas (nickname del cliente, fecha de compra), para aquellas compras que tienen pendientes de enviar el producto//
  std::set<DTCompra *> compras = controladorCompra->getDataComprasExitosas();
  for (auto it = compras.begin(); it != compras.end(); it++)
  {
    if (estaEnCompra(idProducto, (*it)))
    {
      listarParClienteFechaDeCompra((*it));
    }
  }
  std::string nickCliente;
  std::cout << "Escriba el nickname del cliente al que desea enviar el producto." << std::endl;
  std::cin >> nickCliente;
  std::cout << "Ingrese fecha de la compra (dia/mes/anio)" << std::endl;
  int dia;
  int mes;
  int anio;
  std::cin >> dia;
  std::cin >> mes;
  std::cin >> anio;
  DTFecha *fechaCompra = new DTFecha(dia, mes, anio);
  // Se marca como enviado "idProducto" de la compra de "nickCliente" con fecha "fechaCompra"
  // for (compras de nickCliente) if compra.fecha = fechaCompra actualizarEnvio(idProducto)
  for (auto it2 = datoCliente(nickCliente)->getComprasPasadas().begin(); it2 != datoCliente(nickCliente)->getComprasPasadas().end(); it2++)
  {
    std::cout << fechaCompra->getDia() << std::endl;
    std::cout << (*it2)->getFechaDeCompra()->getDia() << std::endl;
    if ((*it2)->getFechaDeCompra()->compararFecha(fechaCompra))
    {
      controladorProducto->enviarProd(controladorProducto->getProducto(idProducto));
      std::cout << "Producto Enviado Correctamente" << std::endl;
      break; // Agregue Break para cortar iteracion luego de enviado el producto
    }
  }
}

void ExpedienteUsuario() // falta testear
{
  ListarUsuarios();
  std::string nickUsuario;
  std::cout << "Escriba su nickname" << std::endl;
  std::cin >> nickUsuario;
  while (!ExisteUsuario(nickUsuario))
  {
    std::cout << "El usuario ingresado no existe" << std::endl;
    std::cout << "Porfavor ingrese un usuario valido" << std::endl;
    std::cin >> nickUsuario;
  }
  std::set<DTCliente *> clientes = controladorUsuario->listarClientes();
  if (ExisteCliente(nickUsuario, clientes))
  {
    DTCliente *esCliente = datoCliente(nickUsuario);
    std::string nick = esCliente->getNickname();
    DTFecha *fecha = esCliente->getFechaNacimiento();
    int dia = fecha->getDia();
    int mes = fecha->getMes();
    int anio = fecha->getAnio();
    std::cout << "Nickname: " << nick << ", Fecha de nacimiento: " << dia << "/" << mes << "/" << anio << std::endl;
    std::cout << std::endl;
    ListarComprasRealizadas(esCliente);
  }
  else
  {
    DTVendedor *esVendedor = datoVendedor(nickUsuario);
    std::string nickVendedor = esVendedor->getNickname();
    DTFecha *fechaVendedor = esVendedor->getFechaNacimiento();
    int dia = fechaVendedor->getDia();
    int mes = fechaVendedor->getMes();
    int anio = fechaVendedor->getAnio();
    std::cout << "Nickname: " << nickVendedor << ", Fecha de nacimiento: " << dia << "/" << mes << "/" << anio << std::endl;
    std::cout << std::endl;
    ListarProductosDeVendedor(nickVendedor);
    ListarPromosVigentesVendedor(esVendedor);
  }
}
void SuscribirseNotificacion() // Implementado //
{
  listarNickClientes();
  std::string nickCliente;
  std::cout << "Escriba su nickname" << std::endl;
  std::cin >> nickCliente;
  std::set<DTCliente *> clientes = controladorUsuario->listarClientes();
  while (!ExisteCliente(nickCliente, clientes))
  {
    std::cout << "El cliente ingresado no existe" << std::endl;
    std::cout << "Porfavor ingrese un cliente valido" << std::endl;
    std::cin >> nickCliente;
  }
  int opcion = 1;
  std::set<std::string> nickVendedores;
  while (opcion != 2)
  {
    if (opcion == 1)
    {
      std::set<DTVendedor *> vendedoresNoSuscripto = controladorUsuario->listarVendedoresNoSuscritos(nickCliente);
      listarNickVendedores(vendedoresNoSuscripto);
      std::string vendedor;
      std::cout << "Ingrese el nickname del vendedor al que desea suscribirse" << std::endl;
      std::cin >> vendedor;

      while (!ExisteVendedor(vendedor, vendedoresNoSuscripto))
      {
        std::cout << "Porfavor ingrese un vendedor valido" << std::endl;
        std::cin >> vendedor;
      };
      nickVendedores.insert(vendedor);
      controladorUsuario->realizarSuscripciones(nickCliente, nickVendedores);
      nickVendedores.erase(vendedor);
    }
    std::cout << "1-Agregar otra suscripcion" << std::endl
              << "2-Salir de realizar suscripciones" << std::endl;
    std::cin >> opcion;
  }
}
void ConsultaNotificacion() // incompleto // falta  "eliminarNotificaciones"
{
  listarNickClientes();
  std::string nickCliente;
  std::cout << "Escriba su nickname" << std::endl;
  std::cin >> nickCliente;
  std::set<DTCliente *> clientes = controladorUsuario->listarClientes();
  while (!ExisteCliente(nickCliente, clientes))
  {
    std::cout << "El cliente ingresado no existe" << std::endl;
    std::cout << "Porfavor ingrese un cliente valido" << std::endl;
    std::cin >> nickCliente;
  }
  std::set<DTNotificacion *> notificaciones = controladorUsuario->listarNotificaciones(nickCliente);
  std::set<std::string> nickVendedores;
  for (auto it = notificaciones.begin(); it != notificaciones.end(); it++)
  {
    std::string nickVendedor = (*it)->getNicknameVendedor();
    std::string nombrePromocion = (*it)->getNombrePromocion();
    std::set<DTProducto *> productosEnPromo = controladorPromocion->productosEnUnaPromo(nombrePromocion);
    std::cout << "Vendedor: " << nickVendedor << ", Promocion: " << nombrePromocion;
    for (auto it2 = productosEnPromo.begin(); it2 != productosEnPromo.end(); it2++)
    {
      std::cout << ", Producto: " << (*it2);
    };
    
    std::cout << std::endl;
    nickVendedores.insert(nickVendedor);
  };
  // controladorUsuario->eliminarNotificaciones(nickCliente, nickVendedores);
}
void EliminarSuscripcion() // Implementado //
{
  listarNickClientes();
  std::string nickCliente;
  std::cout << "Escriba su nickname" << std::endl;
  std::cin >> nickCliente;
  std::set<DTCliente *> clientes = controladorUsuario->listarClientes();
  while (!ExisteCliente(nickCliente, clientes))
  {
    std::cout << "El cliente ingresado no existe" << std::endl;
    std::cout << "Porfavor ingrese un cliente valido" << std::endl;
    std::cin >> nickCliente;
  }
  std::set<DTVendedor *> vendedoresSuscripto = controladorUsuario->listarVendedoresSuscritos(nickCliente);
  listarNickVendedores(vendedoresSuscripto);
  std::string vendedor;
  std::cout << "Ingrese el nickname del vendedor al que desea eliminar su suscripcion" << std::endl;
  std::cin >> vendedor;
  int opcion = 1;
  std::set<std::string> nickVendedores;
  while (opcion != 2)
  {
    if (opcion == 1)
    {
      std::set<DTVendedor *> vendedoresSuscripto = controladorUsuario->listarVendedoresSuscritos(nickCliente);
      listarNickVendedores(vendedoresSuscripto);
      std::string vendedor;
      std::cout << "Ingrese el nickname del vendedor al que desea eliminar su suscripcion" << std::endl;
      std::cin >> vendedor;
      while (!ExisteVendedor(vendedor, vendedoresSuscripto))
      {
        std::cout << "Porfavor ingrese un vendedor valido" << std::endl;
        std::cin >> vendedor;
      };
      nickVendedores.insert(vendedor);
      controladorUsuario->eliminarSuscripciones(nickCliente, nickVendedores);
      nickVendedores.erase(vendedor);
    }
    std::cout << "1-Eliminar otra suscripcion" << std::endl
              << "2-Salir de eliminar suscripciones" << std::endl;
    std::cin >> opcion;
  }
}

//---------------------------------------------MAIN-----------------------------------------------------
int main()
{
  while (true)
  {
    int input = 0;
    std::cout << "Menu de Opciones" << std::endl
              << "1-Cargar datos iniciales" << std::endl
              << "2-Registrar nuevo usuario" << std::endl
              << "3-Listado de usuarios exitentes" << std::endl
              << "4-Alta de producto" << std::endl
              << "5-Consultar un producto" << std::endl
              << "6-Crear una nueva promocion" << std::endl
              << "7-Consultar una promocion" << std::endl
              << "8-Realizar una compra" << std::endl
              << "9-Dejar un comentario" << std::endl
              << "10-Eliminar un comentario" << std::endl
              << "11-Enviar un producto" << std::endl
              << "12-Expediente de usuario" << std::endl
              << "13-Suscribirse a notificacion" << std::endl
              << "14-Consulta de notificaciones" << std::endl
              << "15-Eliminar suscripcion" << std::endl
              << "16-Salir" << std::endl;
    std::cin >> input;
    switch (input)
    {
    case 1: // Cargar datos iniciales
      CargarDatos();
      break;

    case 2: // Registrar nuevo usuario
      std::cout << "Elija el tipo de usuario que desea registrar" << std::endl
                << "1-Vendedor" << std::endl
                << "2-Cliente" << std::endl;
      std::cin >> input;
      switch (input)
      {
      case 1:
        NuevoVendedor();
        break;
      case 2:
        NuevoCliente();
        break;
      default:
        std::cout << "Opcion invalida" << std::endl;
        break;
      }
      break;

    case 3: // Listado de usuarios exitentes
      ListarUsuarios();
      break;

    case 4: // Alta de producto
      AltaDeProducto();
      break;

    case 5: // Consultar un producto
      ConsultarUnProducto();
      break;

    case 6: // Crear una nueva promocion
      CrearPromocion();
      break;

    case 7: // Consultar una promocion
      ConsultarPromocion();
      break;

    case 8: // Realizar una compra
      RealizarCompra();
      break;

    case 9: // Dejar un comentario
      DejarComentario();
      break;

    case 10: // Eliminar un comentario
      EliminarComentario();
      break;

    case 11: // Enviar un producto
      EnviarProducto();
      break;

    case 12: // Expediente de usuario
      ExpedienteUsuario();
      break;

    case 13: // Suscribirse a notificacion
      SuscribirseNotificacion();
      break;

    case 14: // Consulta de notificaciones
      ConsultaNotificacion();
      break;

    case 15: // Eliminar suscripcion
      EliminarSuscripcion();
      break;

    case 16: // Salir
      return 0;
      break;

    default: // Otro numero
      std::cout << "Opcion invalida" << std::endl;
      break;
    }
  }

  return 0;
}



// Makefile para linux:

// SOURCE= makefile
// DEF= include/*.hh include/**/*.hh
// CLSS= src/*.cpp src/**/*.cpp main.cpp
// OBJS= *.o
// OUT= main
// CFLAGS= -Wall -ggdb

// all: compile generate

//compile: $(DEF)
//	g++ -c $(CLSS) $(CFLAGS)

//main: $(DEF)
//	g++ -c main.cpp $(CFLAGS)

////generate:
//	g++ $(OBJS) -o $(OUT) $(CFLAGS)

//clean:
//	rm -f $(OBJS) $(OUT)

