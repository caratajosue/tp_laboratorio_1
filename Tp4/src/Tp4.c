/*
 ============================================================================
 Name        : Tp4.c
 Author      : Carata
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"
#define MENU "\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\
\n2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\
\n3. Alta de empleado\
\n4. Modificar datos de empleado\
\n5. Baja de empleado\
\n6. Listar empleados\
\n7. Ordenar empleados\
\n8. Guardar los datos de los empleados en el archivo data2.csv (modo texto).\
\n9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\
\n10. Informes\
\n11.Salir\n\n"


#define ERORR_MENU "\nERROR\n"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
     10.Informe:
     	 a)Ajustar sueldo segun horas trabajadas:
     	 	 -si horas>=120 -> sueldo=horas*500*20 dias
     	 	 -si horas<120 -> sueldo=horas*300*20 dias
     	 b)Obtener una lista de empleados que trabajan mas de 120 horas e imprimirla
     	 c)Obtener el saldo total a pagar de sueldos
     	 d)Obtener el empleado que mas cobra
     	 e)
    11. Salir
*****************************************************/

int main()
{
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
    	if(!utn_getNumero(&option,MENU,ERORR_MENU,1,11,2))
    	{
			switch(option)
			{
				case 1:
					controller_loadFromText("data.csv",listaEmpleados);
					printf("\nSe realizo la carga de los datos(Texto) \n");
					break;
				case 2:
					controller_loadFromBinary("data.csv",listaEmpleados);
					printf("\nSe realizo la carga de los datos(Binario) \n");
					break;
				case 3:
					controller_addEmployee(listaEmpleados);
					break;
				case 4:
					controller_editEmployee(listaEmpleados);
					break;
				case 5:
					controller_removeEmployee(listaEmpleados);
					break;
				case 6:
					controller_ListEmployee(listaEmpleados);
					break;
				case 7:
					controller_sortEmployee(listaEmpleados);
					break;
				case 8:
					controller_saveAsText("data2.csv",listaEmpleados);
					break;
				case 9:
					controller_saveAsBinary("data.bin",listaEmpleados);
					break;
				case 10:
					controller_informe(listaEmpleados);
					break;
				case 11:
					printf("\nSALISTE DE APLICAION");
					break;
			}
    	}
    }while(option != 11);
    return 0;
}

/*\n\na)Ajustar sueldo segun horas trabajadas\
\n		-si horas>=120 -> sueldo=horas*500*20 dias\
\n		-si horas<120 -> sueldo=horas*300*20 dias\
\nb)Obtener una lista de empleados que trabajan mas de 120 horas e imprimirla\
\nc)Obtener el saldo total a pagar de sueldos\
\nd)Obtener el empleado que mas cobra\*/
