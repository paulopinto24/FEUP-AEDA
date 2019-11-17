#pragma once
#include "Pessoa.h"

class Entregador;
class Encomenda;

/**
 * Entrega efetuada por um entregador da empresa
 */
class Entrega
{
	double custoFixo;/**< Custo fixo da entrega */
	double custoTotal;/**< Custo total da entrega */
	bool success;/**< Indica se a entrega foi realizada com sucesso ou nao */
	vector<Entregador> entregador; /**< Vetor que contem o(s) entregador(es) responsavel/responsaveis pela entrega */
	string restaurante;/**< Restaurante que envia os produtos */
	string nif;/**< NIF do cliente que efetua a entrega */
	string time;/**< Data da entrega */
public:
	
	/**
	 * @brief Construtor da classe entrega
	 * @param enc - encomenda que levou a entrega
	 * @param ent - entregador que realiza a entrega
	 * @param r - nome do restaurante que envia os produtos
	 * @param nif - nif do cliente que efetua a entrega
	 */
	Entrega(Encomenda enc, Entregador ent, string r, string nif);

	/**
	 * @brief Setter do sucesso da entrega
	 * @param ans - true se a entrega foi bem sucedida e false se nao foi
	 */
	void setSuccess(bool ans);

	/**
	 * @brief Getter do custo total da entrega
	 * @return Retorna o custo total sob a forma de double
	 */
	double getCustoTotal();

	/**
	 * @brief Getter do entregador que realiza a entrega
	 * @return Retorna o entregador desejado
	 */
	Entregador getEntregador();

	/**
	 * @brief Getter do nome do restaurante que envia os produtos
	 * @return Retorna uma string com o nome do restaurante
	 */
	string getRestaurante();

	/**
	 * @brief Getter do nif do cliente que efetua a entrega
	 * @return Retorna uma string com o nif do cliente
	 */
	string getNIF();

	/**
	 * @brief Getter da data da entrega
	 * @return Retorna uma string com a data
	 */
	string getTime();
	
};

