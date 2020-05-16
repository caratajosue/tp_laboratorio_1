/*
 ============================================================================
 Name        : tp2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "utn.h"
#define MENU "\n1. ALTAS\
\n2. MODIFICAR\
\n3. BAJA\
\n4. INFORMAR\
\n5. SALIR\
\nSELECCIONE MENU: "
#define ERROR "\nError de opcion[1-5]\n"
#define INFORME "\n1.Listado de los empleados ordenados alfabéticamente por Apellido y Sector.\
\n2.Total y promedio de los salarios, y cuántos empleados superan el salario promedio.\
\n3.Salir de informe\
\nSELECCIONE INFORME:  "
#define ERRORDOS "\nError de opcion[1-2]\n"
#define MAXIMO_EMPLEADOS 1000
int main()
{
    Employee employees[MAXIMO_EMPLEADOS];
    initEmployees(employees,MAXIMO_EMPLEADOS);
    int id;
    char name[NAME_SIZE];
    char lastName[LASTNAME_SIZE];
    float salary=0;
    int sector=0;
    int opcion;
    int informe;
    int orden;
    int alta=1;
    //addForceEmployee(employees,MAXIMO_EMPLEADOS,"Josue","Carata",44500.50,1,&alta); //CARGA FORZADA PARA PROBAR LOS INFORMES
    //addForceEmployee(employees,MAXIMO_EMPLEADOS,"Abel","Colque",15555.50,3,&alta);
    //addForceEmployee(employees,MAXIMO_EMPLEADOS,"Adria","Noce",19555.30,2,&alta);
    //addForceEmployee(employees,MAXIMO_EMPLEADOS,"Estefy","Mareño",29334.32,1,&alta);
    //addForceEmployee(employees,MAXIMO_EMPLEADOS,"Lucas","Ramirez",34543.67,2,&alta);
    //addForceEmployee(employees,MAXIMO_EMPLEADOS,"Leandro","Mieres",23553.30,2,&alta);
    //addForceEmployee(employees,MAXIMO_EMPLEADOS,"Matias","Aguirre",20553.30,1,&alta);
    //addForceEmployee(employees,MAXIMO_EMPLEADOS,"Sebastian","Guevara",21535.30,3,&alta);
		do{
		    if(!utn_getNumero(&opcion,MENU,ERROR,1,5,2))
		    {
				switch(opcion)
				{
					case 1:
						if(addEmployee(employees,MAXIMO_EMPLEADOS,name,lastName,salary,sector)==0)
						{
							printf("\nSe cargo correctamente empleado\n");
							alta=0;
						}
					break;
					case 2:
						if(alta==0 && !utn_getNumero(&id,"\nIngrese ID de empleado que quiere modificar: ","\nERROR-ID",1,MAXIMO_EMPLEADOS,2))
						{
							if(!modifyEmployeeById(employees,MAXIMO_EMPLEADOS,id))
							{
								printf("\nModifico Empleado\n");
							}
						}
						else if(alta)
						{
							printf("\nPrimero dar alta un empleado");
						}
						break;
					case 3:
						if(alta==0 && !utn_getNumero(&id,"\nIngrese ID de empleado: ","\nERROR-ID",1,MAXIMO_EMPLEADOS,2))
						{
							if(!removeEmployee(employees,MAXIMO_EMPLEADOS,id))
							{
								printf("\nSe elimino Empleado\n");
							}
						}
						else if(alta)
						{
							printf("\nPrimero dar alta un empleado");
						}
						break;
					case 4:
						if(alta==0)
						{
							do
							{
								if(!utn_getNumero(&informe,INFORME,ERRORDOS,1,3,2))
								{
									switch(informe)
									{
									case 1:
										if(!utn_getNumero(&orden,"\nIngrese Orden 1-ascendente 0-descendente: ","\nERROR-ORDEN",0,1,2))
										{
											if(sortEmployees(employees,MAXIMO_EMPLEADOS,orden))
											{
												printf("\nSe Ordeno Correctamente\n");
											}
											printEmployees(employees,MAXIMO_EMPLEADOS);
										}
										break;
									case 2:
										totalAndAverageSalary(employees,MAXIMO_EMPLEADOS);
										break;
									case 3:
										break;
									}
								}

							}while(informe!=3);
						}
						else if(alta)
						{
							printf("\nPrimero dar alta un empleado");
						}
						break;
					case 5:
						printf("\nSALISTE DE APLICACION");
					break;
				}
		    }
		}while(opcion!=5);
    return 0;
}
