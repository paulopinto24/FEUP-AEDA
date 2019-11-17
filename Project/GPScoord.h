#pragma once

#ifndef GPScoord_H
#define GPScoord_H

/**
 *   Pessoa que participa na empresa
 */
class GPScoord
{
private:
	float latitude; /**< parâmetro latitude da coordenada gps*/
	float longitude; /**< parâmetro longitude da coordenada gps*/
public:
	/**
	 * @brief Construtor da classe GPScoord
	 */
	GPScoord();

	/**
	 * @brief Construtor da classe Utilizador
	 * @param lat - parâmetro latitude da coordenada gps
	 * @param lat - parâmetro longitude da coordenada gps
	 */
	GPScoord(float lat, float lon);

	/**
	 * @brief Permite obter o parâmetro latitude da coordenada gps
	 * @return Retorna a latitude da coordenada gps
	 */
	float getLat();

	/**
	 * @brief Permite obter o parâmetro longitude da coordenada gps
	 * @return Retorna a longitude da coordenada gps
	 */
	float getLon();
};


#endif // !GPScoord_H

