#pragma once

#ifndef GPScoord_H
#define GPScoord_H

/**
 *   Pessoa que participa na empresa
 */
class GPScoord
{
private:
	float latitude; /**< par�metro latitude da coordenada gps*/
	float longitude; /**< par�metro longitude da coordenada gps*/
public:
	/**
	 * @brief Construtor da classe GPScoord
	 */
	GPScoord();

	/**
	 * @brief Construtor da classe Utilizador
	 * @param lat - par�metro latitude da coordenada gps
	 * @param lat - par�metro longitude da coordenada gps
	 */
	GPScoord(float lat, float lon);

	/**
	 * @brief Permite obter o par�metro latitude da coordenada gps
	 * @return Retorna a latitude da coordenada gps
	 */
	float getLat();

	/**
	 * @brief Permite obter o par�metro longitude da coordenada gps
	 * @return Retorna a longitude da coordenada gps
	 */
	float getLon();
};


#endif // !GPScoord_H

