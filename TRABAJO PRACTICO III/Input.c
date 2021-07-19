#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Input.h"
#include "LinkedList.h"
#include "Employee.h"

/** \brief Crea un menu para que el usuario interactur.
 *
 * \param void
 * \return int
 *
 */
int mainMenu(void)
{
	int option;

	option = getInt("Ingrese una opcion\n1- Cargar archivos desde el archivo data.csv\n2- Cargar archivos desde el archivo data.bin\n3- Alta de un empleado\n4- Modificacion de un empleado\n5- Baja de un empleado\n6- Listado de empleados\n7- Ordenar empleados\n8- Guardar los datos de los empleados en el archivo data.csv\n9- Guardar los datos de los empleados en el archivo data.bin\n10- Salir\n");

	return option;
}


/** \brief Oide un entero y lo devuelve
 *
 * \param mensaje char*
 * \return int
 *
 */

int getInt(char *mensaje)
{
    int numero;
    while((ValideGetInt(&numero, mensaje)) == -1)
    {
        printf("\nERROR: Recuerde no dejar espacios en blanco y no utilizar letras\n");
    }
    return numero;
}


/** \brief Vvalida si el valor ingresado es un entero o no
 *
 * \param numero int*
 * \param mensaje char*
 * \return int Devuelve -1 si no es un entero o es un entero mas otro valor no entero, o 0 si es entero
 *
 */
int ValideGetInt(int* numero, char* mensaje)
{
    int validacion = 1;
    char cadena [20];
    int i;

    printf("%s", mensaje);
    fflush(stdin);
    scanf("%[^\n]", cadena);

    for(i=0; i<strlen(cadena) ; i++)
    {
        if(cadena[i]==' ')
        {
        	validacion = -1;
            break;
        }

        if(cadena[i]!='\0')
        {
            if(cadena[i] < '0' || cadena[i] > '9')
            {
            	validacion = -1;
            }
        }
    }

    if(validacion == 1)
    {
        *numero = atoi (cadena);
    }

    return validacion;
}

/** \brief Valida el rango de un entero
 *
 * \param mensaje char*
 * \param numeroMaximo int
 * \param numeroMinimo int
 * \param numeroAValidar int
 * \return numeroAValidar int
 *
 */
int ValidateRange(char* mensaje, int numeroMaximo, int numeroMinimo, int numeroAValidar)
{
    while(numeroAValidar > numeroMaximo || numeroAValidar < numeroMinimo)
    {
    	numeroAValidar = getInt(mensaje);
    }

    return numeroAValidar;
}



/** \brief Verifica que el string ingresado consista solo de letras
 *
 * \param cadena char[]
 * \return int flag / Retorna -1 si hay otros caracteres ademas de letras, o 0 si es solo letras
 *
 */
int getStringLetters(char* cadena)
{
    int i;
    int flag = 0;
    int tam = strlen(cadena);

    for(i=0; i<tam; i++)
    {
        if(cadena[i] != '\0')
        {
            if (((cadena[i]<'a' || cadena[i]>'z') && (cadena[i]<'A'||cadena[i]>'Z')) || cadena[i] == ' ')
            {
                flag = -1;
            }
        }
    }

    return flag;
}

/** \brief Valida que una cadena consista solo de numeros
 *
 * \param cadena char[]
 * \return int flag / Retorna 0 si es solo numeros, caso contrario devuelve -1
 *
 */
int getStringNumbers(char* cadena)
{
    int i;
    int validacion;
    int tamCadena = strlen(cadena);

    validacion = 0;

    for(i=0; i<tamCadena; i++)
    {
        if(cadena[i] != '\0')
        {
            if ((cadena[i]<'0' || cadena[i]>'9') || cadena[i] == ' ')
            {
                validacion = -1;
            }

        }
    }

    return validacion;
}

/** \brief Pide un string y lo valida
 *
 * \param mensaje char[]
 * \param cadena char[]
 * \return void
 *
 */
void GetValidString (char* mensaje, char* cadena)
{
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%[^\n]", cadena);
    cadena[0] = toupper(cadena[0]);

    while(getStringLetters(cadena)== -1)
    {
        printf("\nERROR : Recuerde no utilizar numeros o dejar espacios en blanco!\n");
        printf("%s", mensaje);
        fflush(stdin);
        scanf("%[^\n]", cadena);
        cadena[0] = toupper(cadena[0]);
    }

}

/** \brief Pide y guarda una cadena de numeros
 *
 * \param mensaje char[]
 * \param cadena char[]
 * \return void
 *
 */
void GetValidStringNumbers (char* mensaje, char* cadena)
{
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%[^\n]", cadena);
    while(getStringNumbers(cadena)== -1)
    {
        printf("\nERROR: Recuerde no utilizar letras o dejar espacios en blanco!\n");
        printf("%s", mensaje);
        fflush(stdin);
        scanf("%[^\n]", cadena);
    }
}


/** \brief Menu de opciones para el ordenamiento.
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int SortMenu(LinkedList* pArrayListEmployee)
{
	int opcion;

	do
	{
		opcion = getInt("Como quiere ordenar la lista de empleados?\n1- Por nombre\n2- Por sueldo\n3- Por horas trabajadas\n4- Por ID\n5- Volver al menu\n");

		switch(opcion)
		{
			case 1:
				if(EmployeeListByName(pArrayListEmployee)==1)
				{

				}
				else
				{
					printf("Error\n");
				}
				break;

			case 2:
				if(EmployeeListBySalary(pArrayListEmployee)==1)
				{

				}
				else
				{
					printf("Error\n");
				}
				break;

			case 3:
				if(EmployeeListByHours(pArrayListEmployee)==1)
				{

				}
				else
				{
					printf("Error\n");
				}
				break;

			case 4:
				if(EmployeeListById(pArrayListEmployee)==1)
				{

				}
				else
				{
					printf("Error\n");
				}
				break;

			case 5:
				break;
		}
	}while(opcion!=5);


	return 1;
}
