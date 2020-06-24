#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"

#define OPCION "\nElija que campo desea modificar:\
\n 1- Nombre\
\n 2- Horas de trabajo\
\n 3- Sueldo\
\n 4- Volver al menu\
\n Eliga opcion: "

#define INFORME "\n---INFORME---\
\n1)Ajustar sueldo segun horas trabajadas:\
\n-si horas>=120 -> sueldo=horas*500*20 dias\
\n-si horas<120 -> sueldo=horas*300*20 dias\
\n2)Obtener una lista de empleados que trabajan mas de 120 horas e imprimirla\
\n3)Obtener el saldo total a pagar de sueldos\
\n4)Obtener el empleado que mas cobra\
\n5)Lista por Letra\
\n6)Obtene el promedio de los sueldos\
\n7)Volver a menu\
\n Eliga opcion:"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	FILE* fArchivo = fopen(path,"r");
	if(path !=NULL && pArrayListEmployee != NULL)
	{
		if(fArchivo == NULL)
		{
			printf("\nNo exite archivo");
			retorno = -1;
		}
		else
		{
			parser_EmployeeFromText(fArchivo,pArrayListEmployee);
			retorno = 0;
		}
	}
	fclose(fArchivo);
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	FILE* pArchivo =  NULL;
	pArchivo = fopen(path,"r");
	if(path != NULL && pArrayListEmployee != NULL)
	{
		if(pArchivo != NULL)
		{
			parser_EmployeeFromBinary(pArchivo,pArrayListEmployee);
			retorno = 0;
		}
		fclose(pArchivo);
	}
    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	char bufferName[4096];
	char bufferHoras[4096];
	char bufferSueldo[4096];
	int bufferId;
	Employee* auxEmp= employee_new();
	if(!utn_getString(bufferName,"\nIngrese nombre: ","Error",2))
	{
		employee_setNombre(auxEmp,bufferName);
		if(!utn_getNumeroTxt(bufferHoras,"\nIngrese las horas: ","Error",2))
		{
			employee_setHorasTrabajadasTxt(auxEmp,bufferHoras);
			if(!utn_getFloatTxt(bufferSueldo,"\nIngrese el sueldo: ","Error",2))
			{
				employee_setSueldoTxt(auxEmp,bufferSueldo);
				bufferId=generadorId(pArrayListEmployee);
				employee_setId(auxEmp,bufferId);
				ll_add(pArrayListEmployee,auxEmp);
				printf("\nAlta correcta\n");
			}
		}
	}
    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int indice;
	int opcion;
	//char bufferNombre[4096];
	char bufferHoras[4096];
	char bufferSueldo[4096];
	Employee* empleado;
	if(pArrayListEmployee != NULL)
	{
		if(!employee_buscarPorIdArray(pArrayListEmployee,&indice))
		{
			empleado = ll_get(pArrayListEmployee,indice);
			do
			{
				if(!utn_getNumero(&opcion,OPCION,"ERROR",1,4,2))
				{
					switch(opcion)
					{
					case 1:
						if(!utn_getString(empleado->nombre,"\n Ingrese nuevo nombre: ","ERROR-SOLO SE ACEPTAN LETRAS,ESPACIO,GUION",2))
						{
							employee_setNombre(empleado,empleado->nombre);
							//if(ll_set(pArrayListEmployee,indice,empleado->nombre)==0)
							//{
								printf("\n Se modifico nombre\n");
							//}
						}
						break;
					case 2:
						if(!utn_getNumeroTxt(bufferHoras,"\n Ingrese la nueva cantidad de horas: ","\nERROR-SOLO SE ACEPTAN NUMERO",2))
						{
							employee_setHorasTrabajadasTxt(empleado,bufferHoras);
							printf("\n Se modifico horas trabajadas\n");
						}
						break;
					case 3:
						if(!utn_getFloatTxt(bufferSueldo,"\n Ingrese nuevo Sueldo: ","ERROR-SOLO SE ACEPTAN NUEMROS",2))
						{
							employee_setSueldoTxt(empleado,bufferSueldo);
							printf("\n Se modifico sueldo\n");
						}
						break;
					case 4:
						break;
					}
				}
			}while(opcion != 4);
		}
	}
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int indice;
	Employee* empleado = NULL;
	if(pArrayListEmployee != NULL)
	{
		if(!employee_buscarPorIdArray(pArrayListEmployee,&indice))
		{
			empleado = ll_get(pArrayListEmployee,indice);
			employee_delete(empleado);
			ll_remove(pArrayListEmployee,indice);
			printf("\n Se elimino empleado\n");
		}
	}
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Employee* auxEmp;
    int auxID;
    int auxHoras;
    float auxSueldo;
    char bufferName[4096];
    int i;
    if(pArrayListEmployee != NULL)
    {
        for(i=0; i<ll_len(pArrayListEmployee); i++)
        {
            auxEmp = ll_get(pArrayListEmployee, i);
            employee_getId(auxEmp, &auxID);
            employee_getNombre(auxEmp, bufferName);
            employee_getHorasTrabajadas(auxEmp, &auxHoras);
            employee_getSueldo(auxEmp, &auxSueldo);
            printf("ID: %d , Nombre: %s , Horas Trabajadas: %d , Sueldo: $%.2f \n",
            auxID, bufferName, auxHoras, auxSueldo);
        }
    }
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int orden;
	if(pArrayListEmployee != NULL)
	{
		if(!utn_getNumero(&orden,"Como desea ordenar los nombres \n0-Ascendente\n1-Desendente\nEliga opcion: ","Error-solo tiene opcion de 1 o 0",0,1,2))
		{
			if(!ll_sort(pArrayListEmployee,employee_compararPorNombre,orden))
			{
				controller_ListEmployee(pArrayListEmployee);
			}
		}
	}
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee;
    int i;
    int auxId;
    char auxNombre[128];
    int auxHorasTrabajadas;
    float auxSueldo;
    FILE* pArchivo = NULL;
    pArchivo=fopen(path,"w");

    if(pArchivo != NULL && pArrayListEmployee != NULL)
    {
        for(i=0; i<ll_len(pArrayListEmployee); i++)
        {
            auxEmployee = ll_get(pArrayListEmployee,i);
            employee_getId(auxEmployee,&auxId);
            employee_getHorasTrabajadas(auxEmployee,&auxHorasTrabajadas);
            employee_getNombre(auxEmployee,auxNombre);
            employee_getSueldo(auxEmployee,&auxSueldo);
            fprintf(pArchivo,"%d,%s,%d,%.2f\n",auxId,auxNombre,auxHorasTrabajadas,auxSueldo);
        }
        printf("\n El grabado de datos en formato texto ha sido un exito.\n");
    }
    fclose(pArchivo);
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE *pFile = NULL;
    int i;
    int cant;
    Employee *auxEmp=NULL;
    cant=ll_len(pArrayListEmployee);
    if( path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path, "w");
        if(pFile != NULL)
        {
            for(i=0; i<cant; i++)
            {
                auxEmp=ll_get(pArrayListEmployee,i);
                fwrite(auxEmp,sizeof(Employee),1,pFile);
            }
            printf("\n El grabado de datos en formato binario ha sido un exito.\n");
        }
        fclose(pFile);
    }
    return 1;
}
int controller_informe(LinkedList* pArrayListEmployee)
{
	int returnAux = -1;
	int opcion;
	LinkedList* listafiltrada;
	char letra;
	float auxSueldo;
	if(pArrayListEmployee != NULL)
	{
		do
		{
			if(!utn_getNumero(&opcion,INFORME,"ERROR",1,7,2))
			{
				switch(opcion)
				{
				case 1:
					if(ll_map(pArrayListEmployee,calculoSueldoEmpleado)==0)
					{
						controller_ListEmployee(pArrayListEmployee);
					}
					break;
				case 2:
					listafiltrada = ll_filter(pArrayListEmployee,listaHorasMayorA8);
					controller_ListEmployee(listafiltrada);
					break;
				case 3:
					auxSueldo = ll_count(pArrayListEmployee,sueldoTotal);
					if(auxSueldo != -1)
					{
						printf("\nSueldo total a pagar es : %.4f",auxSueldo);
					}
					else
					{
						printf("\n Error en las suma de sueldos");
					}
					break;
				case 4:
					auxSueldo=ll_reduce(pArrayListEmployee,sueldoMayorDeEmpleadoEmpleados);
					if(auxSueldo != -1 )
					{
						printf("\nEl sueldo mas alto es: %.2f",auxSueldo);
					}
					break;
				case 5:
					if(!utn_getChar(&letra,"\nIngrese la Letra en Mayuscula: ","No es letra",'A','Z',2))
					{
						listafiltrada = ll_filterLetra(pArrayListEmployee,listarPorLetra,letra);
						controller_ListEmployee(listafiltrada);
					}
					break;
				case 6:
					auxSueldo=ll_countPromedioYMayorsueldo(pArrayListEmployee,promedioSueldo);
					if(auxSueldo != -1 )
					{
						printf("\nEl sueldo promedio es: %.2f",auxSueldo);
					}
					break;
				case 7:
					break;
				}
			}

		}while(opcion != 7);
	}
	return returnAux;
}

