/*
 * matematica.c
 *
 *  Created on: 2 abr. 2020
 *      Author: josue
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

int suma(float numeroUno, float numeroDos )
{

   return (numeroUno+numeroDos);
}
float resta(float numeroUno, float numeroDos)
{
	return (numeroUno-numeroDos);
}
float division(float numeroUno ,float numeroDos)
{
    float retorno;
    if(numeroDos!=0)
    {
        retorno=(numeroUno/numeroDos);
    }
    return retorno;
}
float multiplicacion(float numeroUno,float numeroDos)
{
    return (numeroUno*numeroDos);
}
long int factorial(float numero)
{
    int auxiliarNumero;
    auxiliarNumero=(long int)numero;
    long int auxiliar=1;
    int i;
     for(i=1;i<=auxiliarNumero;i++)
     {
      auxiliar= auxiliar * i;
     }
    return auxiliar;
}
