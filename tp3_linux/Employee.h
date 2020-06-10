#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    float sueldo;
}Employee;
/** \brief crea un empleado en memoria
 *
 * \param void
 * \return employee
 *
 */
Employee* employee_new();
/** \brief retorna el puntero al empleado
 *
 * \param idTxt char*
 * \param nombreTxt char*
 * \param horasTrabajadasTxt char*
 * \param sueldoTxt char*
 * \return retorno
 *
 */
Employee* employee_newParametros(char* idTxt,char* nombreTxt,char* horasTrabajadasTxt,char* sueldoTxt);
/** \brief elimina el empleado en memoria
 *
 * \param auxEmployee Employee*
 * \return void
 *
 */
void employee_delete();

/** \brief setea el valor como char y verifica que sea numero
 *
 * \param Employee* this
 * \param char* idTxt
 * \return int
 *
 */
int employee_setIdTxt(Employee* this,char* idTxt);
/** \brief setea el valor
 *
 * \param Employee* this
 * \param int id
 * \return int
 *
 */
int employee_setId(Employee* this,int id);
/** \brief toma el valor
 *
 * \param Employee* this
 * \param int* id
 * \return int
 *
 */
int employee_getId(Employee* this,int* id);

/** \brief setea el valor y verifica que letra
 *
 * \param Employee* this
 * \param char* nombre
 * \return int
 *
 */
int employee_setNombre(Employee* this,char* nombre);
/** \brief toma el valor
 *
 * \param Employee* this
 * \param char* nombre
 * \return int
 *
 */
int employee_getNombre(Employee* this,char* nombre);

/** \brief setea el valor como char y verifica que sea numero
 *
 * \param Employee* this
 * \param char* horasTrabajadasTxt
 * \return int
 *
 */
int employee_setHorasTrabajadasTxt(Employee* this,char* horasTrabajadasTxt);
/** \brief setea el valor
 *
 * \param Employee* this
 * \param int horasTrabajadas
 * \return int
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
/** \brief toma  el valor
 *
 * \param Employee* this
 * \param int* horasTrabajadas
 * \return int
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/** \brief setea el valor como char y verifica que sea numero y decimal
 *
 * \param Employee* this
 * \param char* sueldo
 * \return int
 *
 */
int employee_setSueldoTxt(Employee* this,char* sueldoTxt);
/** \brief setea el valor
 *
 * \param Employee* this
 * \param float sueldo
 * \return int
 *
 */
int employee_setSueldo(Employee* this,float sueldo);
/** \brief toma el valor
 *
 * \param Employee* this
 * \param float* sueldo
 * \return int
 *
 */
int employee_getSueldo(Employee* this,float* sueldo);
/** \brief busca el proximo id en la linkedlist
 *
 * \param LinkedList* pArrayListEmployee
 * \return int
 *
 */
int generadorId(LinkedList* pArrayListEmployee);
/** \brief se comparan dos id y se retorna la pocision de donde esta ese id
 *
 * \param LinkedList* pArrayListEmployee
 * \return int
 *
 */
int employee_buscarPorIdArray(LinkedList* pArrayListEmploye,int* indice);
/** \brief compara los nombres
 *
 * \param void* this1
 * \param void* this2
 * \return int
 *
 */
int employee_compararPorNombre(void* this1,void* this2);
#endif // employee_H_INCLUDED
