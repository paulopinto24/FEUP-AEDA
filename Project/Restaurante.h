#pragma once

#include <vector>
#include <sstream>

using namespace std;


class Produto
{
private:
	string nome;
	string tipo;
	double preco;
public:
	Produto(string, string, double);
	string getNome();
	double getPreco();
	string getTipo();
	bool operator==(Produto& p);
};

/**
 * Restaurante integrante da empresa
 */
class Restaurante
{
private:
	string nome;/**< Nome do restaurante */
	string morada;/**< Morada do restaurante */
	string concelho;/**< Concelho do restaurante */
	vector<string> tipoCulinaria;/**< Tipos de culinaria do restaurante */
	vector<Produto> produtos;/**< Produtos oferecidos pelo restaurante */
	bool available;/**< Disponibilidade do restaurante */
public:

	/**
	 * @brief Construtor da classe restaurante
	 */
	Restaurante();

	/**
	 * @brief Construtor da classe restaurante
	 * @param n - nome do restaurante
	 * @param m - morada do restaurante
	 * @param t - vetor com os tipos de culinaria do restaurante
	 * @param a - disponibilidade do restaurante
	 */
	Restaurante(string n, string m, string c, vector<string>& t, bool a);

	/**
	 * @brief Getter da disponibilidade
	 * @return Retorna true se o restaurante se encontra disponivel, falso caso contrario
	 */
	bool isAvailable();

	/**
	 * @brief Sobrecarga do operador de comparacao
	 * @return Retorna true se os restaurantes comparados possuem a mesma morada
	 */
	bool operator==(Restaurante& r);

	/**
	 * @brief Getter do nome do restaurante
	 * @return Retorna uma string com o nome do restaurante
	 */
	string getNome();

	/**
	 * @brief Getter dos produtos do restaurante
	 * @return Retorna um vetor com os produtos oferecidos por um restaurante
	 */
	vector<Produto> getProdutos();

	/**
	 * @brief Getter da morada do restaurante
	 * @return Retorna uma string com a morada do restaurante
	 */
	string getMorada();

	/**
	 * @brief Getter do concelho do restaurante
	 * @return Retorna uma string com o concelho do restaurante
	 */
	string getConcelho();

	/**
	 * @brief Cria string com info dos produtos de um restaurante no ecra
	 * @return Retorna uma string a ser imprimida
	 */
	string printProducts();

	/**
	 * @brief Adiciona um produto ao vetor de produtos
	 * @param p - produto a ser adicionado
	 * @return Retorna true se for bem sucedido e false ca
	 */
	bool addProduto(Produto p);

	/**
	 * @brief Retorna vetor com produtos abaixo de um certo preco
	 * @param p - preco maximo
	 * @return Retorna o vetor com os produtos
	 */
	vector<Produto> getProdByPrice(double p);

	/**
	 * @brief Getter dos tipos de culinaria do restaurante
	 * @param t - tipo de culinaria
	 * @return Retorna o vetor com os tipos de culinaria
	 */
	vector<string> getType(string t);

	/**
	 * @brief Getter da disponibilidade
	 * @return Retorna true se o restaurante se encontra disponivel, falso caso contrario
	 */
	bool getAvailable();

	/**
	 * @brief Getter de um tipo de culinaria
	 * @param i - indicie do tipo de culinaria
	 * @return Retorna uma string com o tipo de culinaria desejado
	 */
	string getTpCul(int i);

	/**
	 * @brief Getter do tamanho do vetor dos tipos de culinaria
	 * @return Retorna o tamanho do vetor dos tipos de culinaria
	 */
	int getTpCulS();

	/**
	 * @brief Getter do tamanho do vetor dos produtos do restaurante
	 * @return Retorna o tamanho do vetor dos produtos do restaurante
	 */
	int getProdS();

	/**
	 * @brief Getter de um produto
	 * @param i - indicie do produto
	 * @return Retorna o produto desejado
	 */
	Produto getProd(int i);
};
