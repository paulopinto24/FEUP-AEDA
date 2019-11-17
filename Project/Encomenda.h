#pragma once

#include <iostream>
#include "Restaurante.h"

using namespace std;

/**
 * Encomenda pedida por um cliente da empresa
 */
class Encomenda
{
	Restaurante restaurante;/**< Restaurante que recebe a encomenda */
	string data;/**< Data da encomenda */
	vector<Produto> produtos;/**< Vetor que contem os produtos encomendados */
	double pTotal;/**< Preco total da entrega que segue a encomenda */
	double pFixo;/**< Preco fixo proveniente da localizacao do restaurante e do cliente */
public:
	
	/**
	 * @brief Construtor da classe encomenda
	 * @param r - restaurante que recebe a encomenda
	 * @param d - data da encomenda
	 * @param p - vetor que contem os produtos encomendados
	 */
	Encomenda(Restaurante r, string d, const vector<Produto>& p);

	/**
	 * @brief Imprime dados relativos a encomenda
	 */
	void printDados();

	/**
	 * @brief Calcula e atribui um valor ao custo total da entrega que se seguira
	 */
	void setpTotal();

	/**
	 * @brief Atribui um valor ao custo fixo
	 * @param p - custo fixo (3 ou 5)
	 */
	void setpFixo(double p);

	/**
	 * @brief Getter do preco fixo
	 * @return Preco fixo como double
	 */
	double getpFixo();

	/**
	 * @brief Getter do preco total
	 * @return Preco total da entrega que se segue
	 */
	double getpTotal();

	/**
	 * @brief Getter data 
	 * @return String com a data da encomenda
	 */
	string getData();
};

