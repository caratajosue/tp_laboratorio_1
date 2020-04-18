/*
 ============================================================================
 Name        : tp1.c
 Author      : Josue
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "matematica.h"
#define MENU "\n3. Calcular todas las operaciones \
\n\ta) Calcular la suma (A+B)\
\n\tb) Calcular la resta (A-B)\
\n\tc) Calcular la division (A/B)\
\n\td) Calcular la multiplicacion (A*B)\
\n\te) Calcular el factorial (A!)\
\n4. Informar resultados\
\n5. Salir \
\nElija la opcion: "

int main()
{
    int option;
    float A=0.00;
    float B=0.00;
    float resultadoSuma;
    float resultadoResta;
    float resultadoDivision;
    float resultadoMultiplicacion;
    long int resultadoFactorialUno;
    long int resultadoFactorialDos;
    float x,y;
    int validacionNumero;
    do
    {
     printf("1. Ingresar 1er operando (A=%.2f)",A);
     printf("\n2. Ingresar 2do operando (B=%.2f)",B);
     printf(MENU);
     scanf("%d",&option);
     switch(option)
     {
      case 1:
       printf("Primer operando: ");
       validacionNumero = scanf("%f",&x);
       __fpurge(stdin);
       if(validacionNumero==1)
       {
    	   A=x;
       }
       else
       {
    	   printf("no es un numero \n");
       }
       break;
      case 2:
       printf("Segundo operando: ");
       validacionNumero = scanf("%f",&y);
       if(validacionNumero==1)
       {
    	   B=y;
       }
       else
       {
    	   printf("no es un numero \n");
       }
       __fpurge(stdin);
       if(validacionNumero==1)
       {
           B=y;
       }
       else
       {
    	   printf("no es un numero \n");
       }
       break;
      case 3:
       resultadoSuma=suma(A,B);
       resultadoResta=resta(A,B);
       resultadoDivision=division(A,B);
       resultadoMultiplicacion=multiplicacion(A,B);
       resultadoFactorialUno=factorial(A);
       resultadoFactorialDos=factorial(B);
       printf("Se realizo correctamente las operaciones\n");
       break;
      case 4:
       if(A!=0 || B!=0)
       {
		   printf("a) El resultado de A+B es: %.2f\n",resultadoSuma);
		   printf("b) El resultado de A-B es: %.2f\n",resultadoResta);
		   if(B!=0)
		   {
			printf("c) El resultado de A/B es: %.2f\n",resultadoDivision);
		   }
		   else
		   {
			printf("c) No es posible dividir por cero\n");
		   }
		   printf("d) El resultado de A*B es: %.2f\n",resultadoMultiplicacion);
		   printf("e) El factorial de A es: %ld y El factorial de B es: %ld\n\n\n",
		   resultadoFactorialUno,resultadoFactorialDos);
       }
       else
       {
    	   printf("\nNo tiene ningun numero cargado en lo operandos A y B\n");
       }
       break;
      case 5:
       printf("Finalizo Aplicacion");
       break;
      }
     }while(option!=5);
     return 0;
}
