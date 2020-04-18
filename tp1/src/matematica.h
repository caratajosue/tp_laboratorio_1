/*
 * matematica.h
 *
 *  Created on: 2 abr. 2020
 *      Author: josue
 */

#ifndef MATEMATICA_H_
#define MATEMATICA_H_

/**
* \brief Se solicita 2 numero float al usuario.
* \param Se realiza la Suma de dichos numeros
* \return El valor de la suma.
*/
int suma(float numeroUno, float numeroDos);
/**
* \brief Se solicita 2 numeros al usuario.
* \param Se realiza la Resta de dichos numeros
* \return El valor de la resta.
*/
float resta(float numeroUno, float numeroDos);
/**
* \brief Se solicita 2 numeros al usuario.
* \param Se realiza la Division de dichos numeros
* \return El valor de la division.
*/
float division(float numeroUno ,float numeroDos);
/**
* \brief Se solicita 2 numeros al usuario.
* \param Se realiza la Multiplicacion de dichos numeros
* \return El valor de la Multiplacion.
*/
float multiplicacion(float numeroUno,float numeroDos);
/**
* \brief Se solicita un numero al usuario.
* \param Se realiza el factoreo de dichos numeros
* \return El valor del factoreo.
*/
long int factorial(float numeroUno);

#endif /* MATEMATICA_H_ */
