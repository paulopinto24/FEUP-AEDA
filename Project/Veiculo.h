#pragma once

#include <string>

using namespace std;

/**
 *   Veículo pertencente à empresa e que é conduzido por um entregador da mesma
 */
class Veiculo
{
private:
	string marca; /**< marca do veículo*/
	string tipo; /**< tipo de veículo*/
	string dataAquisicao; /**< data em que a empresa adquiriu o veículo*/
public:
	/**
	 * @brief Construtor da classe Veículo
	 */
	Veiculo();

	/**
	 * @brief Construtor da classe Administrativo
	 * @param m - Marca do veículo
	 * @param t - Tipo de veículo
	 * @param da - data em que a empresa adquiriu o veículo
	 */
	Veiculo(string m, string t, string da);

	/**
	 * @brief Permite obter o tipo de veículo
	 * @return Retorna o tipo de veículo
	 */
	string getTipo();

	/**
	 * @brief Permite obter a marca do veículo
	 * @return Retorna a marca do veículo
	 */
	string getMarca();

	/**
	 * @brief Permite obter a data em que a empresa adquiriu o veículo
	 * @return Retorna a data em que a empresa adquiriu o veículo
	 */
	string getDataAquisicao();

	/**
	 * @brief Permite alterar a marca de um veículo
	 * @param m - Nova marca atribuída ao veículo
	 */
	void setMarca(string m);

	/**
	 * @brief Permite alterar o tipo de veículo
	 * @param t - Nova tipo atribuído ao veículo
	 */
	void setTipo(string t);

	/**
	 * @brief Permite alterar a data em que a empresa adquiriu o veículo
	 * @param m - Nova data de aquisição do veículo
	 */
	void setDataAquisicao(string);

	/**
	 * @brief Overload do operador de igualidade para a classe Veiculo
	 * @param v - Veículo a ser comparado
	 * @return Retorna true caso os veículos a ser comparados forem iguais, caso contrário retorna falso
	 */
	bool operator == (const Veiculo& v) const;
};


