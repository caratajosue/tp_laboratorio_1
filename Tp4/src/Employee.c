#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

Employee* employee_new()
{
	Employee* emp = (Employee*)malloc( sizeof(Employee));
	return emp;
}
Employee* employee_newParametros(char* idTxt,char* nombreTxt,char* horasTrabajadasTxt, char* sueldoTxt)
{
    Employee *retorno = NULL;
    Employee *auxEmployee;
	if(idTxt != NULL && nombreTxt!=NULL && horasTrabajadasTxt!=NULL && sueldoTxt!=NULL )
	{
	    auxEmployee=employee_new();
	    if(auxEmployee!=NULL)
	    {
	    	if(	employee_setIdTxt(auxEmployee,idTxt)==0
		    		&& employee_setNombre(auxEmployee,nombreTxt)==0
					&& employee_setHorasTrabajadasTxt(auxEmployee,horasTrabajadasTxt)==0
					&& employee_setSueldoTxt(auxEmployee,sueldoTxt)==0)
	    	{
	    		retorno = auxEmployee;
	    	}
	    }
	}
    return retorno;
}
void employee_delete(Employee* auxEmployee)
{
    if(auxEmployee != NULL)
    {
        free(auxEmployee);
    }
}
int employee_setIdTxt(Employee* this,char* idTxt)
{
	int retorno = -1;
	if(this != NULL && idTxt != NULL)
	{
		if(esNumerica(idTxt,9022)==1)
		{
			this->id = atoi(idTxt);
			retorno = 0;
		}
	}
	return retorno;
}
int employee_setId(Employee* this,int id)
{
    int retorno = -1;
    if(this != NULL  && id >=0)
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}
int employee_getId(Employee* this,int* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        retorno = 0;
    }
    return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		if(esString(nombre,128)==1)
		{
			strncpy(this->nombre,nombre,128);
			retorno = 0;
		}
	}
	return retorno;
}
int employee_getNombre(Employee* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre,this->nombre);
		retorno=0;
	}
	return retorno;
}

int employee_setHorasTrabajadasTxt(Employee* this,char* horasTrabajadasTxt)
{
	int retorno = -1;
	if(this != NULL && horasTrabajadasTxt != NULL)
	{
		if(esNumerica(horasTrabajadasTxt,4096)==1)
		{
			this->horasTrabajadas = atoi(horasTrabajadasTxt);
			retorno = 0;
		}
	}
	return retorno;
}
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno = -1;
	if(this != NULL && horasTrabajadas >= 0)
	{
        this->horasTrabajadas = horasTrabajadas;
        retorno = 0;
	}
	return retorno;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno = -1;
    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}

int employee_setSueldoTxt(Employee* this,char* sueldoTxt)
{
	int retorno = -1;
	if(this != NULL && sueldoTxt != NULL)
	{
		if(esFloat(sueldoTxt))
		{
			this->sueldo = atof(sueldoTxt);
			retorno = 0;
		}
	}
	return retorno;
}
int employee_setSueldo(Employee* this,float sueldo)
{
	int retorno = -1;
	if(this != NULL && sueldo >= 0)
	{
        this->sueldo = sueldo;
        retorno = 0;
	}
	return retorno;
}
int employee_getSueldo(Employee* this,float* sueldo)
{
    int retorno = -1;
    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        retorno = 0;
    }
    return retorno;
}
int generadorId(LinkedList* pArrayListEmployee)
{
    Employee* auxiliar;
    int cant;
    int auxId;
    int maxID = -1;
    int i;
    if(pArrayListEmployee != NULL)
    {
        cant = ll_len(pArrayListEmployee);
        for(i=0;i<cant;i++)
        {
            auxiliar = ll_get(pArrayListEmployee, i);
            employee_getId(auxiliar, &auxId);
            if(auxId > maxID)
            {
                maxID = auxId;
            }
        }
    }
    maxID ++;
    return maxID;
}
int employee_buscarPorIdArray(LinkedList* pArrayListEmploye,int* indice)
{
	int retorno=-1;
	Employee* empleado;
	int i;
	int id;
	int cantidad;
	int auxId;
	if(pArrayListEmploye != NULL && indice != NULL)
	{
		cantidad = ll_len(pArrayListEmploye);
		if(!utn_getNumero(&auxId,"Ingrese id a buscar: ","Error-No exite Id buscado",1,cantidad,2))
		{
			for(i=0;i<cantidad;i++)
			{
				empleado = ll_get(pArrayListEmploye,i);
				employee_getId(empleado,&id);
				if(auxId==id)
				{
					*indice = i;
					retorno=0;
					break;
				}
			}
		}
	}
	return retorno;
}
int employee_compararPorNombre(void* this1,void* this2)
{
	int retorno=0;
	char auxNombreA[128];
	char auxNombreB[128];
	employee_getNombre((Employee*)this1,auxNombreA);
	employee_getNombre((Employee*)this2,auxNombreB);
	if(strncmp(auxNombreA,auxNombreB,128)>0)
	{
		retorno = 1;
	}
	else if(strncmp(auxNombreA,auxNombreB,128)<0)
	{
		retorno = -1;
	}
	return retorno;
}


