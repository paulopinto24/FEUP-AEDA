#include "Encomenda.h"





Encomenda::Encomenda(Restaurante r, string d, const vector<Produto>& p)
{
	restaurante = r;
	data = d;
	produtos = p;
}

void Encomenda::printDados() {
	cout << restaurante.getNome() << endl;
	cout << "Produtos:" << endl;

	for (int i = 0; i < produtos.size(); i++) {
		cout << produtos.at(i).getNome() << endl;
	}

}

void Encomenda::setpTotal()
{
	double preco = 0.0;

	for (int i = 0; i < produtos.size(); i++) {
		preco += produtos.at(i).getPreco();
	}

	pTotal = pFixo + preco;
}

void Encomenda::setpFixo(double p)
{
	pFixo = p;
}

double Encomenda::getpFixo()
{
	return pFixo;
}

double Encomenda::getpTotal()
{
	return pTotal;
}
