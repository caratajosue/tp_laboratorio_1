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
\n10.Salir\n\n"

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
    10. Salir
*****************************************************/

int main()
{
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
    	if(!utn_getNumero(&option,MENU,ERORR_MENU,1,10,2))
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
					printf("\nSALISTE DE APLICAION");
					break;
			}
    	}
    }while(option != 10);
    return 0;
}

