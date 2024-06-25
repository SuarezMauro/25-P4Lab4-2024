#include "../../include/controladores/ControladorCompra.hh"
#include "../../include/fabrica/Fabrica.hh"

std::set<DTCompra *> ControladorCompra::getDataComprasExitosas()
{
	std::set<DTCompra *> dataCompras;
	for (auto it = comprasExitosas.begin(); it != comprasExitosas.end(); it++)
	{
		dataCompras.insert((*it)->getDataCompra());
	}
	return dataCompras;
}
DTCompra *ControladorCompra::obtenerDatosCompra()
{
	DTCliente *datacliente = compraActual->getCliente()->getDataCliente();

	DTCompra *datacompra = new DTCompra(compraActual->getFechaCompra(), compraActual->getMontoFinal(), compraActual->getRegistroProductos(), datacliente);
	return datacompra;
}
bool ControladorCompra::estaEnCompra(int id)
{
	if (compraActual->getRegistroProducto(id) == NULL)
	{
		return false;
	}
	return true;
};
void ControladorCompra::crearCompra(std::string nickname, int dia, int mes, int anio)
{
	DTFecha *fechaCompra = new DTFecha(dia, mes, anio);
	float precioInicial = 0;
	Cliente *cliente = Fabrica::getInterfazUsuario()->getCliente(nickname);
	Compra *nuevaCompra = new Compra(fechaCompra, precioInicial, cliente);
	this->compraActual = nuevaCompra;
};
void ControladorCompra::agregarProductoACompra(int id, int cantidad)
{
	DTProducto *producto = Fabrica::getInterfazProducto()->obtenerProductoDisponible(id);
	DTRegistroProducto *registro = new DTRegistroProducto(id, producto->getNombre(), cantidad, producto->getPrecio(), producto->getPromocion());
	compraActual->addRegistroProducto(registro);
	compraActual->setMontoFinal(compraActual->getMontoFinal() + producto->getPrecio() * cantidad);
};
void ControladorCompra::registrarCompraExitosa(bool b)
{
	if (b)
	{
		std::set<DTRegistroProducto*> regi = compraActual->getRegistroProductos();
		for(auto it = regi.begin(); it != regi.end(); it++){
			Producto *producto = Fabrica::getInterfazProducto()->getProducto((*it)->getId());
			producto->setCantidadEnStock(producto->getCantidadEnStock() - (*it)->getCantidad());
		}
		comprasExitosas.insert(compraActual);
		(compraActual->getCliente())->añadirCompra(compraActual->getDataCompra());
	}
	else
	{
		compraActual->~Compra();
	}
}
bool ControladorCompra::calcularDescuentos()
{
	std::set<DTRegistroProducto *> productos = compraActual->getRegistroProductos();
	for (std::set<DTRegistroProducto *>::iterator it = productos.begin(); it != productos.end(); ++it)
	{
		if ((*it)->getInfoPromo() != NULL)
		{
			std::map<int, DTProductoPromo *> productosPromo = (*it)->getInfoPromo()->getProductos();
			std::set<DTRegistroProducto *> auxiliar;
			for (std::set<DTRegistroProducto *>::iterator it = productos.begin(); it != productos.end(); ++it)
			{
				if (productosPromo[(*it)->getId()]->getCantidadMinima() <= (*it)->getCantidad())
				{
					auxiliar.insert(*it);
				}
			}
			if (auxiliar.size() == productosPromo.size())
			{
				int monto1 = compraActual->getMontoFinal();
				int monto2 = (*it)->getInfoPromo()->getPorcentajeDescuento();
				int montoF = monto1 - (monto1 * monto2 / 100);
				compraActual->setMontoFinal(montoF);
				return true;
			}
			else
			{
				return false;
			};
		}
	};return false;
}
ControladorCompra::ControladorCompra() {}
ControladorCompra::~ControladorCompra()
{
	delete compraActual;
	while (!comprasExitosas.empty())
	{
		std::set<Compra *>::iterator inicio = comprasExitosas.begin();
		Compra *aBorrar = *inicio;
		comprasExitosas.erase(inicio);
		delete aBorrar;
	}
}
ControladorCompra *ControladorCompra::instancia = NULL;
ControladorCompra *ControladorCompra::getInstancia()
{
	if (instancia == NULL)
	{
		instancia = new ControladorCompra();
	}
	return instancia;
}
