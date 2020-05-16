/*
 * ArrayEmployees.h
 *
 *  Created on: 15 may. 2020
 *      Author: josue
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
#define NAME_SIZE 51
#define LASTNAME_SIZE 51

typedef struct{
	int id;
	char name[NAME_SIZE];
	char lastName[LASTNAME_SIZE];
	float salary;
	int sector;
	int isEmpty;

}Employee;
/** \brief To indicate that all position in the array are empty,this function put the flag (isEmpty) in TRUE in all position of the array
*
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initEmployees(Employee* list, int len);
/** \bried Busca busca el primer lugar vacio y devuelve el indice
*
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) si no encontro lugar o [Invalid length or NULL pointer] - devuelve el indice
*
*/
int buscarLugarVacio(Employee* list,int len);
/** \brief add in a existing list of employees the values received as parameters in the first empty position
*
* \param list employee*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
*
*/
int addEmployee(Employee* list, int len, char name[],char lastName[],float salary,int sector);
/** \brief busca indice vacio y lo devuelve la posicion dentro de la direccion de memoria que me pasaron como parametro
*
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \param int* indiceVacio
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (indiceVacio) if ok
*
*/
int getEmptyIndex(Employee* list,int len,int* indiceVacio);
/** \brief Realiza un alta forzada para poder hacer debug
*
* \param list employee*
* \param len int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \param int* alta
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
*
*/
int addForceEmployee(Employee* list, int len, char name[],char lastName[],float salary,int sector,int* alta);
/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
*
*/
int findEmployeeById(Employee* list, int len,int id);
/** \brief print the content of employees array
*
* \param list Employee*
* \param length int
* \
*
*/
void printEmployees(Employee* list,int len);
/** \brief modifica empleado mediante id, el campo de la estructura que uno desea
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
*
*/
int modifyEmployeeById(Employee* list,int len,int id);
/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
*
*/
int removeEmployee(Employee* list, int len, int id);
/** \brief Sort the elements in the array of employees, the argument order indicate UP or DOWN order
*
* \param list Employee*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployees(Employee* list, int len, int orden);
/** \brief Muestra por pantalla el total y promedio de salario y la cantidad
*
* \param list Employee*
* \param len int
*
*/
void totalAndAverageSalary(Employee* list,int len);
#endif /* ARRAYEMPLOYEES_H_ */
