#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "LinkedList.h"
#include "Input.h"

/** \brief Setea el id dentro de una estructura de empleado.
 *
 * \param employee Employee*
 * \param _id int
 * \return int
 *
 */

int employee_setId(Employee* employee,int _id)
{
	if(employee!= NULL)
	{
		employee->id = _id;

	}

	return 1;
}

/** \brief Devuelve el id dentro de una estructura de empleado.
 *
 * \param employee Employee*
 * \param id int*
 * \return int
 *
 */
int employee_getId(Employee* employee,int* id)
{

	if(employee!=NULL && id!=NULL)
	{
		*id = employee->id;

	}


	return 1;
}

/** \brief Setea el nombre dentro de una estructura de empleado.
 *
 * \param employee Employee*
 * \param _nombre char*
 * \return int
 *
 */
int employee_setNombre(Employee* employee,char* _nombre)
{

	if(employee!= NULL)
	{
		strcpy(employee->nombre, _nombre);

	}

	return 1;
}

/** \brief Devuelve el nombre dentro de una estructura de empleado.
 *
 * \param employee Employee*
 * \param nombre char*
 * \return int
 *
 */
int employee_getNombre(Employee* employee,char* nombre)
{

	if(employee!=NULL && nombre!=NULL)
	{
		strcpy(nombre, employee->nombre);

	}

	return 1;
}

/** \brief Setea las horas de trabajo dentro de una estructura de empleado.
 *
 * \param employee Employee*
 * \param _horasTrabajadas int
 * \return int
 *
 */
int employee_setHorasTrabajadas(Employee* employee,int _horasTrabajadas)
{

	if(employee!= NULL)
	{
		employee->horasTrabajadas = _horasTrabajadas;

	}

	return 1;
}

/** \brief Devuelve las horas de trabajo dentro de una estructura de empleado.
 *
 * \param employee Employee*
 * \param horasTrabajadas int*
 * \return int
 *
 */
int employee_getHorasTrabajadas(Employee* employee,int* horasTrabajadas)
{

	if(employee!=NULL && horasTrabajadas!=NULL)
	{
		*horasTrabajadas = employee->horasTrabajadas;

	}

	return 1;
}

/** \brief Setea el sueldo dentro de una estructura de empleado.
 *
 * \param employee Employee*
 * \param _sueldo int
 * \return int
 *
 */
int employee_setSueldo(Employee* employee,int _sueldo)
{

	if(employee!= NULL)
	{
		employee->sueldo = _sueldo;

	}

	return 1;
}

/** \brief Devuelve el sueldo dentro de una estructura de empleado.
 *
 * \param employee Employee*
 * \param sueldo int*
 * \return int
 *
 */
int employee_getSueldo(Employee* employee,int* sueldo)
{

	if(employee!=NULL && sueldo!=NULL)
	{
		*sueldo = employee->sueldo;

	}

	return 1;
}


/** \brief Crea un nuevo empleado mediante mediante el parseo de sus pasajes en cadena.
 *
 * \param employee Employee*
 * \param idStr char*
 * \param nombreStr char*
 * \param horasTrabajadasStr char*
 * \param sueldoStr char*
 * \return Employee*
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr, int* nextId)
{
	Employee* employee = employee_new();

	int id;
	int horasTrabajadas;
	int sueldo;

	if(idStr!=NULL && nombreStr!=NULL && horasTrabajadasStr!=NULL && sueldoStr!=NULL)
	{

		if(*nextId == -1)
		{
			id = atoi(idStr);
		}
		else
		{
			id = *nextId;
		}

		horasTrabajadas = atoi(horasTrabajadasStr);
		sueldo = atoi(sueldoStr);


		if(employee_setId(employee, id)==1 && employee_setNombre(employee, nombreStr)==1 && employee_setHorasTrabajadas(employee, horasTrabajadas) == 1 && employee_setSueldo(employee, sueldo) ==1)
		{

		}
		else
		{
			printf("Error\n");
		}
	}

	return employee;

}

/** \brief Crea un nuevo empleado de manera dinamica.
 *
 * \return Employee*
 *
 */
Employee* employee_new()
{
	Employee* newEmployee;
	newEmployee = (Employee*)malloc(sizeof(Employee));

	return newEmployee;
}


/** \brief Agrega un empleado a la lista.
 *
 * \param pArrayListEmployee LinkedList*
 * \param nextId int*
 * \return int
 *
 */
int addEmployee(LinkedList* pArrayListEmployee, int* nextId)
{

	Employee* auxEmployee;

	if(pArrayListEmployee!=NULL)
	{

	    auxEmployee = employee_RequestData(pArrayListEmployee, nextId);

	    if(auxEmployee != NULL)
	    {
	    	ll_add(pArrayListEmployee, auxEmployee);
	    	*nextId = *nextId + 1;
	    }

	}

	return 1;
}

/** \brief Pide los datos de un empleado
 *
 * \param pArrayListEmployee LinkedList*
 * \param int* id
 * \return Employee* pAux
 *
 */
Employee* employee_RequestData(LinkedList* pArrayListEmployee, int* id)
{

    char name[128];
    char hoursWorked[128];
    char salary[128];
    Employee* pAux;

    if(pArrayListEmployee!=NULL && id!=NULL)
    {
        do
        {
        	GetValidString("Ingrese el nombre del empleado: ", name);
        	GetValidStringNumbers("Ingrese cantidad de horas trabajadas: ", hoursWorked);
        	GetValidStringNumbers("Ingrese sueldo del empleado: ", salary);
            pAux = employee_newParametros("",name, hoursWorked, salary, id);

        } while (pAux == NULL);

    }

	return pAux;
}


/** \brief Modifica a un empleado.
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int ModifyEmployee(LinkedList* pArrayListEmployee)
{

	Employee* auxEmployee;
	int opcion;
	char nombre[50];
	int horasTrabajadas;
	int sueldo;

	if(pArrayListEmployee != NULL)
	{
		auxEmployee = ObtenerEmpleadoPorId(pArrayListEmployee);

		if(auxEmployee != NULL)
		{
			opcion = getInt("Presione uno de los siguientes numeros segun lo que quiera modificar: | 1: NOMBRE | 2: HORAS TRABAJADAS | 3: SUELDO\n");
			opcion = ValidateRange("ERROR: Presione uno de los siguientes numeros segun lo que quiera modificar: | 1: NOMBRE | 2: HORAS TRABAJADAS | 3: SUELDO\n", 3, 1, opcion);

			switch(opcion)
			{
				case 1:
					GetValidString("Ingrese el nuevo nombre del empleado\n", nombre);
					employee_setNombre(auxEmployee, nombre);
					break;
				case 2:
					 horasTrabajadas = getInt("Ingrese las nuevas horas trabajadas del empleado\n");
					 employee_setHorasTrabajadas(auxEmployee, horasTrabajadas);
					break;
				case 3:
					sueldo = getInt("Ingrese las nuevas horas trabajadas del empleado\n");
					employee_setSueldo(auxEmployee, sueldo);
					break;

			}

		}
		else
		{
			printf("No se encontro al empleado\n");
		}


	}

	return 1;

}


/** \brief Genera una lista de empleados.
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int EmployeesList(LinkedList* pArrayListEmployee)
{

	int len;
	int i;
	Employee* aux;
	len = ll_len(pArrayListEmployee);
	i = 0;

	if(pArrayListEmployee!=NULL)
	{
		if(ll_isEmpty(pArrayListEmployee)==0)
		{
			printf("ID         NOMBRE      HT   SUELDO\n");
			for(i=0;i<len;i++)
			{
				aux = (Employee*) ll_get(pArrayListEmployee,i);
				printf("%d %11s %8d %7d\n", aux->id, aux->nombre, aux->horasTrabajadas, aux->sueldo);
			}
		}
		else
		{
			printf("La lista es inexistente, por lo que no se puede listar\n");
		}


	}

	return 1;

}

/** \brief Remueve a un empleado de la lista.
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int RemoveEmployee(LinkedList* pArrayListEmployee)
{

	int indice;

	if(pArrayListEmployee != NULL)
	{
		indice = ObtenerId(pArrayListEmployee);

		if(indice != -1)
		{
			ll_remove(pArrayListEmployee,indice);
			printf("Usted ha dado de baja correctamente al empleado\n");

		}
		else
		{
			printf("ERROR: Usted ha ingresado una ID erronea.\n");
		}


	}

	return 1;
}

/** \brief Ordena la lista de empleados por nombre.
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int EmployeeListByName(LinkedList* pArrayListEmployee)
{

	if(pArrayListEmployee!=NULL)
	{
		if(ll_isEmpty(pArrayListEmployee)==0)
		{
			if(ll_sort(pArrayListEmployee, CompareEmployeeByName, 1)==0)
			{
				printf("Se han ordenado los empleados con exito!\n");
			}
		}
		else
		{
			printf("No existe ninguna lista para ordenar\n");
		}

	}

	return 1;

}

/** \brief Ordena la lista de empleados por salario.
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int EmployeeListBySalary(LinkedList* pArrayListEmployee)
{

	if(pArrayListEmployee!=NULL)
	{
		if(ll_isEmpty(pArrayListEmployee)==0)
		{
			ll_sort(pArrayListEmployee, CompareEmployeeBySalary, 1);
			printf("Se han ordenado los empleados con exito!\n");
		}
		else
		{
			printf("No existe ninguna lista para ordenar\n");
		}

	}

	return 1;

}

/** \brief Ordena la lista de empleados por ID.
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int EmployeeListById(LinkedList* pArrayListEmployee)
{

	if(pArrayListEmployee!=NULL)
	{
		if(ll_isEmpty(pArrayListEmployee)==0)
		{
			ll_sort(pArrayListEmployee, CompareEmployeeById, 0);
			printf("Se han ordenado los empleados con exito!\n");
		}
		else
		{
			printf("No existe ninguna lista para ordenar\n");
		}


	}

	return 1;

}

/** \brief Ordena la lista de empleados por horas.
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int EmployeeListByHours(LinkedList* pArrayListEmployee)
{


	if(pArrayListEmployee!=NULL)
	{
		if(ll_isEmpty(pArrayListEmployee)==0)
		{
			ll_sort(pArrayListEmployee, CompareEmployeeByHours, 1);
			printf("Se han ordenado los empleados con exito!\n");
		}
		else
		{
			printf("No existe ninguna lista para ordenar\n");
		}


	}

	return 1;

}


/** \brief Obtiene una estructura de empleado
 *
 * \param pArrayListEmployee LinkedList*
 * \return employee Employee*
 *
 */
Employee* ObtenerEmpleadoPorId(LinkedList* pArrayListEmployee)
{

	int id;
	int i;
	int len;
	Employee* aux;
	Employee* employee;

	employee = NULL;

	if(pArrayListEmployee != NULL)
	{
		EmployeesList(pArrayListEmployee);

		id = getInt("Ingrese la id del empleado que busca\n");

		len = ll_len(pArrayListEmployee);

		for(i=0;i<len;i++)
		{
			aux = (Employee*) ll_get(pArrayListEmployee,i);
			if(id==aux->id)
			{
				employee = aux;
				break;
			}
		}


	}

	return employee;
}


/** \brief Obtiene un indice mediante la busqueda de ID
 *
 * \param pArrayListEmployee LinkedList*
 * \return indice int / Retorna -1 si el ID no existe / Retorna el indice si se encontro el ID
 *
 */
int ObtenerId(LinkedList* pArrayListEmployee)
{
	int id;
	int i;
	int len;
	int indice;
	Employee* aux;

	if(pArrayListEmployee != NULL)
	{
		EmployeesList(pArrayListEmployee);

		indice = -1;

		id = getInt("Ingrese la id del empleado que busca\n");

		len = ll_len(pArrayListEmployee);

		for(i=0;i<len;i++)
		{
			aux = (Employee*) ll_get(pArrayListEmployee,i);
			if(id==aux->id)
			{
				indice = i;
				break;

			}
		}

	}

	return indice;
}


/** \brief Compara dos nombres.
 *
 * \param employeeOne Employee*
 * \param employeeTwo Employee*
 * \return int
 *
 */

int CompareEmployeeByName(void* employeeOne, void* employeeTwo)
{
	int comparison;
	char firstName[128];
	char secondName[128];

	if(employeeOne!=NULL && employeeTwo!=NULL)
	{
		if(employee_getNombre((Employee*)employeeOne,firstName)==1 && employee_getNombre((Employee*)employeeTwo,secondName)==1)
		{

			comparison = strcmp(firstName, secondName);

			if(comparison > 0)
			{
				comparison = 1;
			}
			else
			{
				if(comparison < 0 )
				{
					comparison = -1;
				}
				else
				{
					comparison = 0;
				}
			}
		}

	}

	return comparison;
}

/** \brief Compara dos ID's.
 *
 * \param employeeOne Employee*
 * \param employeeTwo Employee*
 * \return int
 *
 */
int CompareEmployeeById(void* employeeOne, void* employeeTwo)
{
	int comparison;
	int firstId;
	int secondId;

	if(employeeOne!=NULL && employeeTwo!=NULL)
	{
		if(employee_getId((Employee*)employeeOne,&firstId)==1 && employee_getId((Employee*)employeeTwo,&secondId)==1)
		{
			if(firstId > secondId)
			{
				comparison = 1;
			}
			else
			{
				if(firstId == secondId)
				{
					comparison = 0;

				}
				else
				{
					comparison = -1;
				}
			}
		}

	}

	return comparison;
}

/** \brief Compara dos salarios.
 *
 * \param employeeOne Employee*
 * \param employeeTwo Employee*
 * \return int
 *
 */
int CompareEmployeeBySalary(void* employeeOne, void* employeeTwo)
{
	int comparison;
	int firstSalary;
	int secondSalary;

	if(employeeOne!=NULL && employeeTwo!=NULL)
	{
		if(employee_getSueldo((Employee*)employeeOne,&firstSalary)==1 && employee_getSueldo((Employee*)employeeTwo,&secondSalary)==1)
		{
			if(firstSalary > secondSalary)
			{
				comparison = 1;
			}
			else
			{
				if(firstSalary == secondSalary)
				{
					comparison = 0;

				}
				else
				{
					comparison = -1;
				}
			}

		}
	}


	return comparison;
}

/** \brief Compara las horas trabajadas.
 *
 * \param employeeOne Employee*
 * \param employeeTwo Employee*
 * \return int
 *
 */
int CompareEmployeeByHours(void* employeeOne, void* employeeTwo)
{
	int comparison;
	int firstHours;
	int secondHours;

	if(employeeOne!=NULL && employeeTwo!=NULL)
	{
		if(employee_getHorasTrabajadas((Employee*)employeeOne,&firstHours)== 1 && employee_getHorasTrabajadas((Employee*)employeeTwo,&secondHours) ==1)
		{
			if(firstHours > secondHours)
			{
				comparison = 1;
			}
			else
			{
				if(firstHours == secondHours)
				{
					comparison = 0;

				}
				else
				{
					comparison = -1;
				}
			}
		}

	}

	return comparison;
}


/** \brief Inicializa el ID a añadir por primera vez
 *
 * \param nextId int*
 * \param pArrayListEmployee LinkedList*
 * \param len int
 * \return void
 *
 */
void Employee_initId(int* nextId, LinkedList* pArrayListEmployee)
{
	int idMayor;
	idMayor = BuscarIdMayorEmpleado(pArrayListEmployee);

	if(idMayor > *nextId)
	{
		*nextId = idMayor + 1;
	}

}

/** \brief Obtiene la siguiente ID
 *
 * \param nextId int*
 * \param path char*
 * \return int
 *
 */
int Employee_getNextId(int* nextId, char* path)
{

    FILE* pFile;
    char id[10];
    int validacionId = 1;

    pFile = fopen(path, "r");

    if (pFile != NULL)
    {
        fgets(id, 9, pFile);
        *nextId = atoi(id);
        validacionId = 0;
    }
    fclose(pFile);

    return validacionId;
}


/** \brief Guarda la siguiente ID en un archivo de texto
 *
 * \param nextId int*
 * \param path char*
 * \return void
 *
 */
void Employee_saveNextId(int* nextId, char* path)
{
    FILE* pFile;

    pFile = fopen(path, "w");

    if (pFile != NULL)
    {
        fprintf(pFile,"%d", *nextId);

    }
    fclose(pFile);

}

/** \brief Guarda el listado en un archivo csv
 *
 * \param pArrayListEmployee LinkedList*
 * \param path char*
 * \return void
 *
 */
void employee_saveTxt(LinkedList* pArrayListEmployee, char* path)
{

    int len;
    Employee* pAux;
    FILE* pFile;

    len = ll_len(pArrayListEmployee);
    pFile = fopen(path, "w");

    if (pFile != NULL && pArrayListEmployee != NULL)
    {
        fprintf(pFile, "%s,%s,%s,%s\n","id","nombre","horasTrabajadas","sueldo");
        for (int i = 0; i < len; i++)
        {
            pAux = ll_get(pArrayListEmployee, i);
            if (pAux != NULL)
            {

              fprintf(pFile, "%d,%s,%d,%d\n", pAux->id, pAux->nombre, pAux->horasTrabajadas, pAux->sueldo);


            }
        }
    }
    fclose(pFile);

}


/** \brief Guarda el listado en un archivo bin
 *
 * \param pArrayListEmployee LinkedList*
 * \param path char*
 * \return void
 *
 */
void employee_saveBin(LinkedList* pArrayListEmployee, char* path)
{

    int len;

    Employee* pAux;
    FILE* pFile;

    len = ll_len(pArrayListEmployee);
    pFile = fopen(path, "wb");

    if (pFile != NULL && pArrayListEmployee != NULL)
    {
        for (int i = 0; i < len; i++)
        {
            pAux = ll_get(pArrayListEmployee, i);
            if (pAux != NULL)
            {

               fwrite(pAux, sizeof(Employee),1, pFile);

            }
        }
    }
    fclose(pFile);

}

/** \brief Busca el ID mas grande entre los empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int idMayor
 *
 */
int BuscarIdMayorEmpleado(LinkedList* pArrayListEmployee)
{
	int i;
	int len;
	int idMayor;
	Employee* auxEmployee;

	len = ll_len(pArrayListEmployee);

	for(i=0;i<len;i++)
	{
		auxEmployee = (Employee*)ll_get(pArrayListEmployee, i);

		if(i == 0 || idMayor < auxEmployee->id)
		{
			idMayor = auxEmployee->id;
		}
	}

	return idMayor;
}








