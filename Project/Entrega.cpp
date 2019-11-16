#include "Entrega.h"



Entrega::Entrega(Encomenda enc, Entregador ent, string r, string nif)
{
	custoFixo = enc.getpFixo();
	custoTotal = enc.getpTotal();
	restaurante = r;
	time = enc.getData();
	this->nif = nif;
	entregador.push_back(ent);
}

void Entrega::setSuccess(bool ans)
{
	success = ans;
}

double Entrega::getCustoTotal()
{
	return custoTotal;
}

Entregador Entrega::getEntregador()
{
	return entregador.at(0);
}

string Entrega::getRestaurante()
{
	return restaurante;
}

string Entrega::getNIF()
{
	return nif;
}

string Entrega::getTime()
{
	return time;
}





