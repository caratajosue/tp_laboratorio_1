/*
 * utn.c
 *
 *  Created on: 20 abr. 2020
 *      Author: josue
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
/**
 * \brief
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 *
 */
static int getInt(int* pResultado);
/**
 * \brief 	Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
 * 			un máximo de 'longitud - 1' caracteres.
 * \param pResultado Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param longitud Define el tamaño de cadena
 * \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
 *
 */
static int getString(char* cadena, int longitud);
/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (vardadero) si la cadena es numerica y 0 (falso) si no lo es
 *
 */
static int esNumerica(char* cadena);

/**
 * \brief
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 *
 */
static int getFloat(float* pResultado);
/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (vardadero) si la cadena es numerica y 0 (falso) si no lo es
 *
 */
static int esFloat(char* cadena);
/**
 * \brief
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 *
 */
static int getChar(char* pResultado);
/**
 * \brief Verifica si la cadena ingresada es char(letra)
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (vardadero) si la cadena es numerica y 0 (falso) si no lo es
 *
 */
static int esChar(char* cadena);
/**
 * \brief Verifica si la cadena ingresada es char(letra)
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (vardadero) si la cadena es numerica y 0 (falso) si no lo es
 *
 */
static int esString(char* cadena,int limite);
/**
 * \brief Verifica si la cadena ingresada es char(letra)
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (vardadero) si la cadena es numerica y 0 (falso) si no lo es
 *
 */
static int getTelefono(char* pResultado);
/**
 * \brief Verifica si la cadena ingresada es char(letra)
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (vardadero) si la cadena es numerica y 0 (falso) si no lo es
 *
 */
static int esTelefono(char* cadena);
/**
 * \brief Verifica si la cadena ingresada es char(letra)
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (vardadero) si la cadena es numerica y 0 (falso) si no lo es
 *
 */
static int getDni(char* pResultado);
/**
 * \brief Verifica si la cadena ingresada es char(letra)
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (vardadero) si la cadena es numerica y 0 (falso) si no lo es
 *
 */
static int esDni(char* cadena);
/**
 * \brief Verifica si la cadena ingresada es char(letra)
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (vardadero) si la cadena es numerica y 0 (falso) si no lo es
 *
 */
static int getCuit(char* pResultado);
/**
 * \brief Verifica si la cadena ingresada es char(letra)
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (vardadero) si la cadena es numerica y 0 (falso) si no lo es
 *
 */
static int esCuit(char* cadena);
/**
 * \brief Verifica si la cadena ingresada es char(letra)
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (vardadero) si la cadena es numerica y 0 (falso) si no lo es
 *
 */
static int getEmail(char* pResultado);
/**
 * \brief Verifica si la cadena ingresada es char(letra)
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (vardadero) si la cadena es numerica y 0 (falso) si no lo es
 *
 */
static int esEmail(char* cadena);

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int bufferInt;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			if(getInt(&bufferInt) == 0 && bufferInt >= minimo && bufferInt <= maximo)
			{
				*pResultado = bufferInt;
				retorno = 0;
				break;
			}
			reintentos--;
			printf("%s",mensajeError);
		}while(reintentos >= 0);
	}
	return retorno;
}
static int getInt(int* pResultado)
{
    int retorno=-1;
    char buffer[4096];

    if(getString(buffer,sizeof(buffer))==0 && esNumerica(buffer))
    {
    	*pResultado = atoi(buffer);
    	retorno = 0;
    }
    return retorno;
}
static int getString(char* cadena, int longitud)
{
	int retorno=-1;
	__fpurge(stdin);
	fgets(cadena,longitud,stdin);
	if(cadena != NULL && longitud > 0 )
	{
		if(cadena[strlen(cadena)-1] == '\n')
		{
			cadena[strlen(cadena)-1] = '\0';
		}
		retorno = 0;
	}
	return  retorno;
}
static int esNumerica(char* cadena)
{
	int retorno = 0;
	int i;
	int contadorMenos=0;
	if(cadena != NULL)
	{
		for(i=0 ; cadena[i] != '\0' ; i++)
		{
			if((cadena[i] >= '0' && cadena[i] <= '9') || cadena[0]=='-')
			{
				if(cadena[i] == '-')
				{
					contadorMenos = contadorMenos +1;
				}
				if(contadorMenos==1)
				{
					retorno = 1;
				}
				else if(contadorMenos>1)
				{
					retorno = 0;
					break;
				}
				retorno =  1;
			}
			else
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
int utn_getFloat(float* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo,int reintentos)
{
	float bufferFloat;
	int retorno = -1;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			if(getFloat(&bufferFloat)==0 && bufferFloat > minimo && bufferFloat < maximo)
			{
				*pResultado = bufferFloat;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >=0 );
	}
	return retorno;
}
static int getFloat(float* pResultado)
{
    int retorno=-1;
    char bufferFloat[4096];

    if(getString(bufferFloat,sizeof(bufferFloat))==0 && esFloat(bufferFloat))
    {
    	*pResultado = atof(bufferFloat);
    	retorno = 0;
    }
    return retorno;
}
static int esFloat(char* cadena)
{
	int retorno = 0;
	int i=0;
	int contadorPunto=0;
	int contadorMas=0;
	int contadorMenos=0;
	if(cadena != NULL)
	{
		for(i=0 ; cadena[i] != '\0' ; i++)
		{

			if((cadena[i] <= '9' && cadena[i] >= '0') || cadena[i] == '.' || cadena[i] == '+' || cadena[i] == '-')
			{
				if(cadena[i] == '.')
				{
					contadorPunto = contadorPunto +1;
				}
				if(cadena[i] == '-')
				{
					contadorMenos = contadorMenos +1;
				}
				if(cadena[i] == '+')
				{
					contadorMas = contadorMas +1;
				}
				if(contadorPunto==1)
				{
					retorno = 1;
				}
				else if(contadorPunto>1)
				{
					retorno = 0;
					break;
				}
				if(contadorMas==1)
				{
					retorno = 1;
				}
				else if(contadorMas>1)
				{
					retorno = 0;
					break;
				}
				if(contadorMenos==1)
				{
					retorno = 1;
				}
				else if(contadorMenos>1)
				{
					retorno = 0;
					break;
				}
				if(cadena[i] == '-')
				{
					if(cadena[i+1]== '.')
					{
						retorno = 0;
						break;
					}
				}
				if(cadena[i] == '+')
				{
					if(cadena[i+1]== '.')
					{
						retorno = 0;
						break;
					}
				}
				if(cadena[i] == '.')
				{
					if(cadena[i+1]== '-')
					{
						retorno = 0;
						break;
					}
				}
				if(cadena[i] == '.')
				{
					if(cadena[i+1]== '+')
					{
						retorno = 0;
						break;
					}
				}
				retorno = 1;
			}
			else
			{
				retorno= 0;
				break;
			}
		}
	}

	return retorno;
}
int utn_getChar(char* pResultado,char* mensaje,char* mensajeError,char minimo,char maximo,int reintentos)
{
	int retorno = -1;
	char bufferChar;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL)
	{
		do
		{
			printf("%s",mensaje);
			if(getChar(&bufferChar)==0 && bufferChar >= minimo && bufferChar <= maximo)
			{
				*pResultado=bufferChar;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >=0);
	}
	return retorno;
}
static int getChar(char* pResultado)
{
    int retorno=-1;
    char bufferChar[4096];
    if(getString(bufferChar,sizeof(bufferChar)) == 0 && esChar(bufferChar))
    {
    	strcpy(pResultado,bufferChar);
    	retorno = 0;
    }
    return retorno;
}
static int esChar(char* cadena)
{
	int retorno = 0;
	int i;
	int contadorLetra=0;
	if(cadena != NULL)
	{
		for(i=0 ; cadena[i] != '\0' ; i++)
		{
			if((cadena[i] >= 'a' && cadena[i] <= 'z') || (cadena[i] >= 'A' && cadena[i] <= 'Z'))
			{
				contadorLetra = contadorLetra + 1;
			}
			if((cadena[i] >= 'a' && cadena[i] <= 'z') || (cadena[i] >= 'A' && cadena[i] <= 'Z'))
			{
				if((cadena[i+1] >= 'a' && cadena[i+1] <= 'z') || (cadena[i+1] >= 'A' && cadena[i+1] <= 'Z'))
				{
					retorno = 0;
					break;
				}
			}
			if(contadorLetra==1)
			{
				retorno=1;
			}
			else if(contadorLetra>2)
			{
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}
int utn_getString(char* pResultado,char* mensaje,char* mensajeError,int reintentos)
{
	char bufferString[50];
	int retorno = -1;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			if(getString(bufferString,sizeof(bufferString))==0 && esString(bufferString,sizeof(bufferString)))
			{
				strncpy(pResultado,bufferString,sizeof(bufferString));
				retorno = 0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >=0 );
	}
	return retorno;
}
static int esString(char* cadena,int limite)
{
	int retorno = 0;
	int i;
	if(cadena != NULL)
	{
		for(i=0 ;i<limite && cadena[i] != '\0' ; i++)
		{
			if(((cadena[i] >= 'a' && cadena[i] <= 'z') || (cadena[i] >= 'A' && cadena[i] <= 'Z')) && (cadena[i] != ' '))
			{
				retorno=1;
			}
			else
			{
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}
int utn_getTelefono(char* pResultado,char* mensaje,char* mensajeError,char* minimo,char* maximo,int reintentos)
{
	int retorno = -1;
	char bufferTelefono[4096];
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL)
	{
		do
		{
			printf("%s",mensaje);
			if(getTelefono(bufferTelefono)==0 )
			{
				if(strcmp(bufferTelefono,minimo)>0 && strcmp(bufferTelefono,maximo)<0)
				{
					strcpy(pResultado,bufferTelefono);
				}
				else
				{
					printf("%s",mensajeError);
					reintentos--;
					continue;
				}
				retorno = 0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >=0);
	}
	return retorno;
}
static int getTelefono(char* pResultado)
{
    int retorno=-1;
    char bufferTelefono[4096];
    if(getString(bufferTelefono,sizeof(bufferTelefono)) == 0 && esTelefono(bufferTelefono))
    {
    	strncpy(pResultado,bufferTelefono,sizeof(bufferTelefono));
    	retorno = 0;
    }
    return retorno;
}
static int esTelefono(char* cadena)
{
	int retorno = 0;
	int i;
	int j;
	int contadorGuion=0;
	int contadorMas=0;
	if(cadena != NULL)
	{
		for(i=0 ; cadena[i] != '\0' ; i++)
		{
			if((cadena[i] >= '0' && cadena[i] <= '9') || cadena[i]=='-')
			{
				if(cadena[3] == '-')
				{
					j=4;
					do
					{
						if(cadena[j] >= '0' && cadena[j] <= '9')
						{
							retorno = 1;
						}
						else
						{
							retorno = 0;
							break;
						}
						j++;
					}while(cadena[j]=='-');
				}
				if(cadena[i] == '-')
				{
					contadorGuion++;
				}
				if(cadena[i] == '+')
				{
					contadorMas++;
				}
				if(contadorGuion==2 || contadorGuion==1)
				{
					retorno = 1;
				}
				else if(contadorGuion>3)
				{
					retorno = 0;
					break;
				}
				if(contadorMas == 1)
				{
					retorno = 1;
				}
				else if(contadorMas>2)
				{
					retorno = 0;
					break;
				}
				retorno =  1;
			}
			else
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
int utn_getDni(char* pResultado,char* mensaje,char* mensajeError,char* minimo,char* maximo,int reintentos)
{
	int retorno = -1;
	char bufferDni[4096];
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL)
	{
		do
		{
			printf("%s",mensaje);
			if(getDni(bufferDni)==0 )
			{
				if(strcmp(bufferDni,minimo)>0 && strcmp(bufferDni,maximo)<0)
				{
					strcpy(pResultado,bufferDni);
				}
				else
				{
					printf("%s",mensajeError);
					reintentos--;
					continue;
				}
				retorno = 0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >=0);
	}
	return retorno;
}
static int getDni(char* pResultado)
{
    int retorno=-1;
    char bufferTelefono[4096];
    if(getString(bufferTelefono,sizeof(bufferTelefono)) == 0 && esDni(bufferTelefono))
    {
    	strncpy(pResultado,bufferTelefono,sizeof(bufferTelefono));
    	retorno = 0;
    }
    return retorno;
}
static int esDni(char* cadena)
{
	int retorno = 0;
	int i;
	int j;
	int contadorPunto=0;
	if(cadena != NULL)
	{
		for(i=0 ; cadena[i] != '\0' ; i++)
		{
			if((cadena[i] >= '0' && cadena[i] <= '9') || cadena[i]=='.')
			{
				if(cadena[2] == '.' && cadena[6]== '.')
				{
					j=3;
					do
					{
						if(cadena[j] >= '0' && cadena[j] <= '9')
						{
							retorno = 1;
						}
						else
						{
							retorno = 0;
							break;
						}
						j++;
					}while(cadena[j]=='-');
				}
				if(cadena[i] == '.')
				{
					contadorPunto++;
				}
				if(contadorPunto==2)
				{
					retorno = 1;
				}
				else if(contadorPunto>3)
				{
					retorno = 0;
					break;
				}
				if(cadena[i] == '.')
				{
					if(cadena[i+1]== '.')
					{
						retorno = 0;
						break;
					}
				}
				retorno =  1;
			}
			else
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
int utn_getCuit(char* pResultado,char* mensaje,char* mensajeError,char* minimo,char* maximo,int reintentos)
{
	int retorno = -1;
	char bufferCuit[4096];
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL)
	{
		do
		{
			printf("%s",mensaje);
			if(getCuit(bufferCuit)==0 )
			{
				if(strcmp(bufferCuit,minimo)>0 && strcmp(bufferCuit,maximo)<0)
				{
					strcpy(pResultado,bufferCuit);
				}
				else
				{
					printf("%s",mensajeError);
					reintentos--;
					continue;
				}
				retorno = 0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >=0);
	}
	return retorno;
}
static int getCuit(char* pResultado)
{
    int retorno=-1;
    char bufferCuit[4096];
    if(getString(bufferCuit,sizeof(bufferCuit)) == 0 && esCuit(bufferCuit))
    {
    	strncpy(pResultado,bufferCuit,sizeof(bufferCuit));
    	retorno = 0;
    }
    return retorno;
}
static int esCuit(char* cadena)
{
	int retorno = 0;
	int i;
	int j;
	int contadorGuion=0;
	if(cadena != NULL)
	{
		for(i=0 ; cadena[i] != '\0' ; i++)
		{
			if((cadena[i] >= '0' && cadena[i] <= '9') || cadena[i]=='-')
			{
				if(cadena[2] == '-')
				{
					j=3;
					do
					{
						if(cadena[j] >= '0' && cadena[j] <= '9')
						{
							retorno = 1;
						}
						else
						{
							retorno = 0;
							break;
						}
						j++;
					}while(cadena[j]=='-');
				}

				if(cadena[i] == '-')
				{
					contadorGuion++;
				}
				if(contadorGuion==2)
				{
					retorno = 1;
				}
				else if(contadorGuion>3)
				{
					retorno = 0;
					break;
				}
				retorno =  1;
			}
			else
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
int utn_getEmail(char* pResultado,char* mensaje,char* mensajeError,int reintentos)
{
	int retorno = -1;
	char bufferEmail[4096];
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL)
	{
		do
		{
			printf("%s",mensaje);
			if(getEmail(bufferEmail)==0 )
			{
				strcpy(pResultado,bufferEmail);
				retorno = 0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >=0);
	}
	return retorno;
}
static int getEmail(char* pResultado)
{
    int retorno=-1;
    char bufferEmail[4096];
    if(getString(bufferEmail,sizeof(bufferEmail)) == 0 && esEmail(bufferEmail))
    {
    	strncpy(pResultado,bufferEmail,sizeof(bufferEmail));
    	retorno = 0;
    }
    return retorno;
}
static int esEmail(char* cadena)
{
	int retorno = 0;
	int i;
	int j;
	int contadorGuion=0;
	int contadorPunto=0;
	int contadorArroba=0;
	int contadorGuionBajo=0;
	int contadorLetra=0;
	if(cadena != NULL)
	{
		for(i=0 ; cadena[i] != '\0' ; i++)
		{
			if((cadena[i] >= '0' && cadena[i] <= '9')
				|| (cadena[i] >= 'a' && cadena[i] <= 'z')
				|| (cadena[i] >= 'A' && cadena[i] <= 'Z')
				|| cadena[i]=='-' || cadena[i]=='.' || cadena[i]=='_' || cadena[i]=='@')
			{
				if(cadena[i] == '@')
				{
					contadorArroba++;
					j=i+1;
					if(cadena[j]=='@')
					{
						retorno = 0;
						break;
					}
					if(cadena[j]=='.')
					{
						retorno = 0;
						break;
					}
					do
					{
						if((cadena[j] >= 'a' && cadena[j] <= 'z'))
						{
							contadorLetra++;
							retorno = 1;
						}
						else
						{
							retorno = 0;
							break;
						}
						if(cadena[j] == '.')
						{
							contadorPunto++;
						}
						if(contadorPunto==1 || contadorPunto==2)
						{
							retorno = 1;
						}
						else if(contadorPunto>3)
						{
							retorno = 0;
							break;
						}
						if(contadorArroba==1)
						{
							retorno = 1;
						}
						else if(contadorArroba>2)
						{
							retorno = 0;
							break;
						}
						j++;

					}while(cadena[j]=='.');
				}
				if(cadena[i]=='.')
				{
					if(cadena[i+1]=='.')
					{
						retorno = 0;
						break;
					}
				}
				if(cadena[i]=='-')
				{
					if(cadena[i+1]=='.')
					{
						retorno = 0;
						break;
					}
				}
				if(cadena[i]=='.')
				{
					if(cadena[i+1]=='@')
					{
						retorno = 0;
						break;
					}
				}
				if(cadena[i]=='.')
				{
					if(cadena[i+1]=='-')
					{
						retorno = 0;
						break;
					}
				}
				if(cadena[i] == '-')
				{
					contadorGuion++;
				}
				if(contadorGuion==3)
				{
					retorno = 1;
				}
				else if(contadorGuion>3)
				{
					retorno = 0;
					break;
				}
				if(cadena[i] == '_')
				{
					contadorGuionBajo++;
				}
				if(contadorGuionBajo==3)
				{
					retorno = 1;
				}
				else if(contadorGuionBajo>3)
				{
					retorno = 0;
					break;
				}
				retorno =  1;
			}
			else
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}


