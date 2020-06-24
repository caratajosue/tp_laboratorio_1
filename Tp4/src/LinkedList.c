#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= (LinkedList*)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
    	this->pFirstNode = NULL;
    	this->size = 0;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
    	returnAux = this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* pNode = NULL;
	int i ;
	if(this != NULL  && nodeIndex >= 0 && nodeIndex < ll_len(this))
	{
		if(nodeIndex==0)
		{
			pNode = this->pFirstNode;
		}
		else
		{
			pNode = this->pFirstNode;
			for(i=0;i<nodeIndex;i++)
			{
				pNode=pNode->pNextNode;
			}
		}
	}
    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* pNodoAnterior;
    Node* pNodoNuevo;
    pNodoNuevo = (Node*)malloc(sizeof(Node));
    pNodoAnterior = getNode(this,nodeIndex-1);

    if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this) && pNodoNuevo != NULL)
    {
    	pNodoNuevo->pElement = pElement;
		if(nodeIndex == 0)
		{
			pNodoNuevo->pNextNode = this->pFirstNode;
			this->pFirstNode = pNodoNuevo;
		}
		else
		{
			pNodoNuevo->pNextNode = pNodoAnterior->pNextNode;
			pNodoAnterior->pNextNode = pNodoNuevo;
		}
		this->size++;
		returnAux = 0;
	}
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int ultimoNodo = ll_len(this);
    if(this != NULL && ultimoNodo >= 0)
    {
    	if(!addNode(this,ultimoNodo,pElement))
    	{
    		returnAux = 0;
    	}
    	else
    	{
    		returnAux = -1;
    	}
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* auxNodo = NULL;
    if(this != NULL && index >= 0 && index < ll_len(this))
    {
    	auxNodo=getNode(this,index);
    	if(auxNodo->pElement != NULL)
    	{
    		returnAux = auxNodo->pElement;
    	}
    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* auxNodo = NULL;
    if(this != NULL && index >= 0 && index < ll_len(this))
    {
    	auxNodo=getNode(this,index);
    	if(auxNodo != NULL)
    	{
    		auxNodo->pElement = pElement;
    		returnAux = 0;
    	}
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* pNodo=getNode(this,index);
    Node* nodoAnterior=getNode(this,index-1);

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
    	if(index==0)
    	{
    		this->pFirstNode=pNodo->pNextNode;
    		free(pNodo);
    	}
    	else
    	{
    		nodoAnterior->pNextNode=pNodo->pNextNode;
    		free(pNodo);
    	}
    	this->size--;
    	returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int i;
    if(this != NULL)
    {
    	for(i=0;i<ll_len(this);i++)
    	{
    		ll_remove(this,0);
    	}
    	returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
    	ll_clear(this);
    	free(this);
    	returnAux = 0;
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int len= ll_len(this);
    int i;
    Node* pNodo=NULL;
    if(this != NULL)
    {
    	for(i=0;i<len;i++)
    	{
    		pNodo=getNode(this,i);
    		if(pNodo->pElement == pElement)
    		{
    			returnAux = i;
    		}
    	}
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    int len = ll_len(this);
    if(this != NULL)
    {
    	if(len==0)
    	{
    		returnAux = 1;
    	}
    	else if(len>0)
    	{
    		returnAux = 0;
    	}
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    if(this != NULL && index >= 0 && index <= ll_len(this))
    {
    	if(!addNode(this,index,pElement))
    	{
    		returnAux = 0;
    	}
    }
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    Node* pNodo;
    Node* pNodoAnterior;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
    	pNodo = getNode(this,index);
    	pNodoAnterior = getNode(this,index-1);
    	if(index == 0)
    	{
    		returnAux = pNodo->pElement;
    		this->pFirstNode = pNodo->pNextNode;
    		free(pNodo);
    	}
    	else
    	{
    		returnAux = pNodo->pElement;
    		pNodoAnterior->pNextNode = pNodo->pNextNode;
    		free(pNodo);
    	}
    	this->size--;

    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int len = ll_len(this);
    int i;
    if(this != NULL)
    {
		returnAux=0;
		for(i=0;i<len;i++)
		{
			if(ll_get(this,i)==pElement)
			{
				returnAux = 1;
				break;
			}
		}
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    void* pAux;
    int i;
    if(this != NULL && this2 != NULL)
    {
    	returnAux = 1;
    	for(i=0;i<ll_len(this2);i++)
    	{
    		pAux=ll_get(this2,i);
    		if(!ll_contains(this,pAux))
    		{
    			returnAux = 0;
    			break;
    		}
    	}
    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    void* pAux;
    int i;
    if(this != NULL)
    {
    	if(from >= 0 && to <= this->size)
    	{
    		cloneArray = ll_newLinkedList();
    		for(i=from;i<to;i++)
    		{
    			pAux = ll_get(this,i);
    			ll_add(cloneArray,pAux);
    		}
    	}
    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    int len = ll_len(this);
    if(this != NULL)
    {
    	cloneArray = ll_newLinkedList();
    	if(cloneArray != NULL)
    	{
    		cloneArray = ll_subList(this,0,len);
    	}
    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    void* pElementoUno;
    void* pElementoDos;
    int flagSwap;
    int i;
    int len = ll_len(this);
    int nuevoLen;
    if(this != NULL && pFunc != NULL && (order == 1 || order == 0))
    {
		nuevoLen =len-1;
    	do
    	{
    		flagSwap = 0;
    		for(i=0;i<nuevoLen;i++)
    		{
    			pElementoUno = ll_get(this,i);
    			pElementoDos = ll_get(this,i+1);
    			if((pFunc(pElementoUno,pElementoDos)==1 && order)
    				|| (pFunc(pElementoUno,pElementoDos)==-1 && !order))
    			{

					ll_set(this,i,pElementoDos);
					ll_set(this,i+1,pElementoUno);
					flagSwap = 1;
					returnAux = 0;
    			}
    		}
    		nuevoLen--;
    	}while(flagSwap);
    }
    return returnAux;
}

int ll_map(LinkedList* this, int (*pFunc)(void*))
{
	int returnAux = -1;
	int i;
	int len = ll_len(this);
	void* aux = NULL;
	if(this != NULL && pFunc != NULL)
	{
		returnAux = 0;
		for(i=0;i<len;i++)
		{
			aux=ll_get(this,i);
			if(pFunc(aux) == -1)
			{
				returnAux=-1;
				break;
			}
			else
			{
				returnAux = 0;
			}
		}
	}
	return returnAux;
}
LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*))
{
	LinkedList* returnAux= NULL;
	LinkedList* filterList = NULL;
	int len=ll_len(this);
	void* aux = NULL;
	if(this!=NULL && pFunc!=NULL && len>0)
	{
		filterList = ll_newLinkedList();
		if(filterList!=NULL)
		{
			for(int i=0;i<len;i++)
			{
				aux=ll_get(this,i);
				if(pFunc(aux) == 1)
				{
					ll_add(filterList,aux);
				}
			}
			returnAux=filterList;
		}
	}
	return returnAux;
}
int ll_count(LinkedList* this, float (*pFunc)(void*,float))
{
	int returnAux = -1;
	void* pElement = NULL;
	int len = ll_len(this);
	int i;
	float valor=0;
	if(this != NULL && pFunc != NULL)
	{
		for(i=0;i<len;i++)
		{
			pElement = ll_get(this,i);
			if(pElement != NULL)
			{
				valor = pFunc(pElement,valor);
			}
		}
		returnAux = valor;
	}
	return returnAux;
}
float ll_reduce(LinkedList* this, float (*pFunc)(void*,float ,int))
{
	float returnAux = -1;
	void* pElement = NULL;
	int len = ll_len(this);
	int i;
	float valor=0;
	if(this != NULL && pFunc != NULL)
	{
		for(i=0;i<len;i++)
		{
			pElement = ll_get(this,i);
			if(pElement != NULL)
			{
				valor = pFunc(pElement,valor,i);
				returnAux = valor;
			}
		}
	}
	return returnAux;
}
LinkedList* ll_filterLetra(LinkedList* this, int (*pFunc)(void*,char*),char letra)
{
	LinkedList* returnAux= NULL;
	LinkedList* filterList = NULL;
	int len=ll_len(this);
	void* aux = NULL;
	if(this!=NULL && pFunc!=NULL && len>0)
	{
		filterList = ll_newLinkedList();
		if(filterList!=NULL)
		{
			for(int i=0;i<len;i++)
			{
				aux=ll_get(this,i);
				if(pFunc(aux,&letra) == 1)
				{
					ll_add(filterList,aux);
				}
			}
			returnAux=filterList;
		}
	}
	return returnAux;
}
float ll_countPromedioYMayorsueldo(LinkedList* this, float (*pFunc)(void*,float))
{
	float returnAux = -1;
	void* pElement = NULL;
	int len = ll_len(this);
	int i;
	float valor=0;
	if(this != NULL && pFunc != NULL)
	{
		for(i=0;i<len;i++)
		{
			pElement = ll_get(this,i);
			if(pElement != NULL)
			{
				valor = pFunc(pElement,valor);
			}
		}
		returnAux = valor/len;
	}
	return returnAux;
}



int listaHorasMayorA8(void* pElement)
{
	int returnAux =-1;
	Employee* pEmployee = (Employee*)pElement;
	int auxHoras;
	if(pElement != NULL)
	{
		if(!employee_getHorasTrabajadas(pEmployee,&auxHoras))
		{
			if(auxHoras>=120)
			{
				returnAux = 1;
			}
			else
			{
				returnAux = -1;
			}
		}
	}
	return returnAux;
}
int calculoSueldoEmpleado(void* pElement)
{
	int returnAux = -1;
	Employee* pEmployee = (Employee*)pElement;
	int horas;
	int sueldoCalculado;
	if(pElement!=NULL)
	{
		employee_getHorasTrabajadas(pElement,&horas);
		if(horas <= 120)
		{
			sueldoCalculado = pEmployee->horasTrabajadas *500*20;
		}
		else if(horas >= 120)
		{
			sueldoCalculado = pEmployee->horasTrabajadas *300*20;
		}
		if(employee_setSueldo(pElement,(float)sueldoCalculado)==0)
		{
			returnAux = 0;
		}
	}
	return returnAux;
}
float sueldoTotal(void* pElement, float valor)
{
	int returnAux = -1;
	Employee* empleado = (Employee*)pElement;
	if(pElement != NULL)
	{
		returnAux = valor + empleado->sueldo;
	}
	return returnAux;
}
int listarPorLetra(void* pElement,char* letra)
{
	int returnAux =-1;
	Employee* pEmployee = (Employee*)pElement;
	char auxNombre[128];
	int i;
	int len;
	if(pElement != NULL)
	{
		if(!employee_getNombre(pEmployee,auxNombre))
		{
			len=strlen(auxNombre);
			for(i=0;i<len;i++)
			{
				if(auxNombre[i]==*letra)
				{
					returnAux = 1;
					break;
				}
				else
				{
					returnAux = 0;
				}
			}
		}
	}
	return returnAux;
}
float promedioSueldo(void* pElement, float valor)
{
	float returnAux = -1;
	Employee* empleado = (Employee*)pElement;
	if(pElement != NULL)
	{
		returnAux = valor + empleado->sueldo;
	}
	return returnAux;
}
float sueldoMayorDeEmpleadoEmpleados(void* pElement, float mayor,int indice)
{
	Employee* empleado = (Employee*)pElement;
	if(indice == 0)
	{
		mayor = empleado->sueldo;
	}
	else
	{
		if(empleado->sueldo> mayor)
		{
			mayor = empleado->sueldo;
		}
	}
	return mayor;
}
