/*
 * ArrayEmployees.c
 *
 *  Created on: 15 may. 2020
 *      Author: josue
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "utn.h"
#define MENU "\n1. NOMBRE\
\n2. APELLIDO\
\n3. SALARIO\
\n4. SECTOR\
\n5. SALIR\
\nSELECCIONE OPCION: "
#define ERROR "\nError de opcion[1-5]\n"
static int generarId(void);
static int generarId(void)
{
    static int id=1;
    return id++;
}
int initEmployees(Employee* list, int len)
{
	int retorno=-1;
	int i;
	if(list != NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			list[i].isEmpty = 1;
		}
		retorno=0;
	}
	return retorno;
}
int buscarLugarVacio(Employee* list,int len)
{
	int respuesta;
	int i;
	if(list!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty==1)
			{
				respuesta=i;
				break;
			}
			else
			{
				respuesta=-1;
			}
		}
	}
	return respuesta;
}
int addEmployee(Employee* list, int len, char name[],char lastName[],float salary,int sector)
{
	int retorno=-1;
	int indice;
	Employee bufferEmploye[1000];
	if(list != NULL && len>0)
	{
		indice=buscarLugarVacio(list,len);
		if(indice!=-1)
		{
			if(!utn_getString(bufferEmploye[indice].name,"\nNombre: ","\nERROR-NOMBRE",2)&&
			   !utn_getString(bufferEmploye[indice].lastName,"\nApellido: ","\nERROR-APELLIDO",2) &&
			   !utn_getFloat(&bufferEmploye[indice].salary,"\nIngrese Salario: ","\nERROR-SALARIO",10500.50,50000.50,2)&&
			   !utn_getNumero(&bufferEmploye[indice].sector,"\n1-Administracion\n2-Mantenimiento\n3-Limpieza\nSector: ","\nERRROR-SECTOR",1,3,2))
			{
				bufferEmploye[indice].id=generarId();
				bufferEmploye[indice].isEmpty=0;
				list[indice] = bufferEmploye[indice];
				retorno=0;
			}
		}
		else
		{
			printf("\nNO HAY LUGAR VACIO\n");
		}
	}

	return retorno;
}
void printEmployees(Employee* list,int len)
{
	int i;
	if(list!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty == 0)
			{
				printf("\nNombre: %s--Apellido: %s--Salario: %.2f--Sector: %d--ID: %d--isEmpty: %d",list[i].name,list[i].lastName,list[i].salary,list[i].sector,list[i].id,list[i].isEmpty);
			}
		}
	}
}
int findEmployeeById(Employee* list, int len,int id)
{
	int retorno =-1;
	int i;
	if(list!=NULL && len>0)
	{
			for(i=0;i<len;i++)
			{
				if(list[i].id==id && list[i].isEmpty==0)
				{
					retorno = i;
					break;
				}
			}
	}
	return retorno;
}
int getEmptyIndex(Employee* list,int len,int* indiceVacio)
{
    int i=0;
    int retorno = -1;
    if(list != NULL && len > 0)
    {
         while(i<len)
        {
            if(list[i].isEmpty==1)
            {
                *indiceVacio=i;
                retorno = 0;
                break;
            }
            i++;
        }
    }
    return retorno;
}
int addForceEmployee(Employee* list, int len, char name[],char lastName[],float salary,int sector,int* alta)
{
    int retorno=-1;
    int indice;
    getEmptyIndex(list,len,&indice);
    if(list != NULL && len >0)
    {
		if(indice >= 0)
		{
		strncpy(list[indice].name,name,51);
		strncpy(list[indice].lastName,lastName,51);
		list[indice].sector=sector;
		list[indice].salary=salary;
		list[indice].id=generarId();
		list[indice].isEmpty=0;
		*alta=0;
		retorno = 0;
		}
    }
    return retorno;
}
int modifyEmployeeById(Employee* list,int len,int id)
{
	int retorno=-1;
	int indice;
	int opcion;
	int modifico=0;
	Employee bufferEmploye[1000];
	if(list!=NULL && len>0 )
	{
		indice=findEmployeeById(list,len,id);
		if(list[indice].id==id && list[indice].isEmpty==0)
		{
			do{
					if(!utn_getNumero(&opcion,MENU,ERROR,1,5,2))
					{
						switch(opcion)
						{
							case 1:
								if(!utn_getString(bufferEmploye[indice].name,"\nNombre: ","\nERROR-NOMBRE",2))
								{
									strncpy(list[indice].name,bufferEmploye[indice].name,NAME_SIZE);
									bufferEmploye[indice].id=id;
									list = bufferEmploye;
									retorno=0;
									modifico=1;
									printf("\nSe modifico nombre\n");
								}
								break;
							case 2:
								if(!utn_getString(bufferEmploye[indice].lastName,"\nApellido: ","\nERROR-APELLIDO",2))
								{
									strncpy(list[indice].lastName,bufferEmploye[indice].lastName,LASTNAME_SIZE);
									bufferEmploye[indice].id=id;
									list = bufferEmploye;
									retorno=0;
									modifico=1;
									printf("\nSe modifico apellido\n");
								}
								break;
							case 3:
								if(!utn_getFloat(&bufferEmploye[indice].salary,"\nIngrese Salario: ","\nERROR-SALARIO",10500.50,50000.50,2))
								{
									list[indice].salary=bufferEmploye[indice].salary;
									bufferEmploye[indice].id=id;
									list = bufferEmploye;
									retorno=0;
									modifico=1;
									printf("\nSe modifico salario\n");
								}
								break;
							case 4:
								if(!utn_getNumero(&bufferEmploye[indice].sector,"\n1-Administracion\n2-Mantenimiento\n3-Limpieza\nSector: ","\nERRROR-SECTOR",1,3,2))
								{
									list[indice].sector=bufferEmploye[indice].sector;
									bufferEmploye[indice].id=id;
									list = bufferEmploye;
									retorno=0;
									modifico=1;
									printf("\nSe modifico sector\n");
								}
								break;
							case 5:
								if(modifico==0)
								{
									retorno=-1;
								}
								break;
						}
					}
			}while(opcion!=5);
		}
		else
		{
			printf("\nID no tiene datos o no existe");
			retorno=-1;
		}
	}
	return retorno;
}
int removeEmployee(Employee* list, int len, int id)
{
	int retorno=-1;
	int i;
	if(list != NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].id==id && list[i].isEmpty==0)
			{
				list[i].isEmpty=-1;
				retorno=0;
				id=list[i].id++;
				break;
			}
			else
			{
				retorno=-1;
			}
		}
		if(retorno==-1)
		{
			printf("\nID no cargado no tiene datos cargados o no existe\n");
		}
	}
	return retorno;
}
int sortEmployees(Employee* list, int len, int orden)
{
	int retorno=-1;
	int flagSawp;
	int newLen;
	Employee bufferEmploye;
	int i;
	if(list!=NULL && len>0)
	{
		newLen=len-1;
		do
		{
			flagSawp=0;
			for(i=0;i<newLen;i++)
			{
				if(orden==1 && strncmp(list[i].lastName,list[i+1].lastName,LASTNAME_SIZE)>0)
				{
					flagSawp=1;
					bufferEmploye=list[i];
					list[i]=list[i+1];
					list[i+1]=bufferEmploye;
					retorno=0;
				}
				if(orden==0 && strncmp(list[i].lastName,list[i+1].lastName,LASTNAME_SIZE)<0)
				{
					flagSawp=1;
					bufferEmploye=list[i];
					list[i]=list[i+1];
					list[i+1]=bufferEmploye;
					retorno=0;
				}
			}
			newLen--;
		}while(flagSawp);
	}
	return retorno;
}
void totalAndAverageSalary(Employee* list,int len)
{
    int i;
    float acum=0;
    float prom;
    int cont=0;
    int contDeProm=0;
    for(i=0;i<len;i++)
    {
        if(list[i].isEmpty==0)
        {
        	acum=acum+list[i].salary;
            cont++;
        }
    }
    prom=acum/cont;
    for(i=0;i<len;i++)
    {
        if(list[i].salary>prom && list[i].isEmpty==0)
        {
            contDeProm++;
        }
    }
    printf("\nEl salario total es:%.2f y el promedio es:%.2f\n",acum,prom);
    printf("\nLa cantidad de  empleados que superaron el salario promedio son:%d\n",contDeProm);
}
