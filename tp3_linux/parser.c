#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int r;
    char bufferId[4096];
    char bufferName[4096];
    char bufferHoras[4096];
    char bufferSueldo[4096];
    Employee* auxEmp;
    r=fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", bufferId, bufferName, bufferHoras, bufferSueldo);
    do
    {
    	r=fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", bufferId, bufferName, bufferHoras, bufferSueldo);
        if(r==4)
        {
        	auxEmp=employee_newParametros(bufferId, bufferName, bufferHoras,bufferSueldo);
        	if(auxEmp != NULL)
        	{
        		ll_add(pArrayListEmployee, auxEmp);
        	}
        }
    } while(!feof(pFile));
    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee auxEmp;
    Employee *pEmp=NULL;
    char bufferId[4096];
    char bufferName[4096];
    char bufferHoras[4096];
    char bufferSueldo[4096];

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        while(!feof(pFile))
        {
           fread(&auxEmp,sizeof(Employee),1,pFile);
           if(employee_setNombre(pEmp,bufferName)==0&&
        	  employee_setHorasTrabajadasTxt(pEmp,bufferHoras)==0&&
              employee_setIdTxt(pEmp,bufferId)==0&&
              employee_setSueldoTxt(pEmp,bufferSueldo)==0)
            {
            ll_add(pArrayListEmployee, pEmp);
            }
        }
    }
    return 1;
}
