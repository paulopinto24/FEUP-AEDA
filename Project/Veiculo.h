#pragma once

#include <string>

using namespace std;

/**
 *   Ve�culo pertencente � empresa e que � conduzido por um entregador da mesma
 */
class Veiculo
{
private:
	string marca; /**< marca do ve�culo*/
	string tipo; /**< tipo de ve�culo*/
	string dataAquisicao; /**< data em que a empresa adquiriu o ve�culo*/
public:
	/**
	 * @brief Construtor da classe Ve�culo
	 */
	Veiculo();

	/**
	 * @brief Construtor da classe Administrativo
	 * @param m - Marca do ve�culo
	 * @param t - Tipo de ve�culo
	 * @param da - data em que a empresa adquiriu o ve�culo
	 */
	Veiculo(string m, string t, string da);

	/**
	 * @brief Permite obter o tipo de ve�culo
	 * @return Retorna o tipo de ve�culo
	 */
	string getTipo();

	/**
	 * @brief Permite obter a marca do ve�culo
	 * @return Retorna a marca do ve�culo
	 */
	string getMarca();

	/**
	 * @brief Permite obter a data em que a empresa adquiriu o ve�culo
	 * @return Retorna a data em que a empresa adquiriu o ve�culo
	 */
	string getDataAquisicao();

	/**
	 * @brief Permite alterar a marca de um ve�culo
	 * @param m - Nova marca atribu�da ao ve�culo
	 */
	void setMarca(string m);

	/**
	 * @brief Permite alterar o tipo de ve�culo
	 * @param t - Nova tipo atribu�do ao ve�culo
	 */
	void setTipo(string t);

	/**
	 * @brief Permite alterar a data em que a empresa adquiriu o ve�culo
	 * @param m - Nova data de aquisi��o do ve�culo
	 */
	void setDataAquisicao(string);

	/**
	 * @brief Overload do operador de igualidade para a classe Veiculo
	 * @param v - Ve�culo a ser comparado
	 * @return Retorna true caso os ve�culos a ser comparados forem iguais, caso contr�rio retorna falso
	 */
	bool operator == (const Veiculo& v) const;
};


