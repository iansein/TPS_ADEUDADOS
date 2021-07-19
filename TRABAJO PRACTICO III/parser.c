#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(char* path , LinkedList* pArrayListEmployee)
{
	Employee* employee;
	FILE* pFile;
	int len;
	char name[128];
	char id [50] ;
	char salary [50] ;
	char hoursWorked[50];
	int flagId = -1;
	int* pFlagId;

	pFlagId = &flagId;
	ll_clear(pArrayListEmployee);

	pFile = fopen(path, "r");

	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, name, hoursWorked, salary);

		while(!feof(pFile))
		{
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, name, hoursWorked, salary);
			employee = employee_newParametros(id,name,hoursWorked,salary, pFlagId);
			ll_add(pArrayListEmployee, employee);
		}

		fclose(pFile);

		len = ll_len(pArrayListEmployee);
		printf("Se ha cargado %d empleados desde el archivo csv\n", len);
	}

    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(char* path, LinkedList* pArrayListEmployee)
{
	ll_clear(pArrayListEmployee);

    Employee* employee = NULL;
    FILE* pFile;
    int len;

    pFile = fopen(path, "rb");

    if(pArrayListEmployee != NULL && path != NULL)
    {


        while(!feof(pFile))
        {
        	employee = employee_new();

            if(employee != NULL)
            {
                if(fread(employee, sizeof(Employee), 1, pFile) == 1)
                {
                	ll_add(pArrayListEmployee, employee);
                }

            }
        }

        fclose(pFile);

        len = ll_len(pArrayListEmployee);

        printf("Se ha cargado %d empleados desde el archivo bin\n", len);
        pFile = NULL;
    }

    return 1;
}
