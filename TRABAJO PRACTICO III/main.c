#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Input.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/

int main()
{
    int option = 0;
    int flagArchivoCsv;
    int flagArchivoBin;
    int nextId;
    int validacionId;


    setbuf(stdout, NULL);


    LinkedList* listaEmpleados = ll_newLinkedList();
    flagArchivoCsv = 0;
    flagArchivoBin = 0;


    do{
    	option = mainMenu();

        switch(option)
        {
            case 1:
            validacionId = Employee_getNextId(&nextId, "ultimaId.txt");

            if(validacionId == 1)
            {
              nextId = 0;
            }
            if(controller_loadFromText("data.csv",listaEmpleados, &nextId)==1)
            {
            	flagArchivoCsv = 1;
            }
            else
            {
            	printf("Hubo un error en el controlador de cargar el listado por archivo de texto\n\n");
            }
            break;

            case 2:
            if(flagArchivoBin == 1)
            {
                validacionId = Employee_getNextId(&nextId, "ultimaId.txt");

                if(validacionId == 1)
                {
                  nextId = 0;
                }

            	if(controller_loadFromBinary("data.bin", listaEmpleados, &nextId)==1)
            	{

            	}
            	else
            	{
            		printf("Hubo un error en el controlador de cargar el listado por archivo binario\n\n");
            	}
            }
            else
            {
            	printf("Para cargar el archivo bin es necesario que lo guarde primero\n\n");
            }
            break;

            case 3:
            if(flagArchivoCsv == 1)
            {

            	if(controller_addEmployee(listaEmpleados, &nextId)==1)
            	{

            	}
            	else
            	{
            		printf("Hubo un error en el controlador de añadir un empleado al sistema\n\n");
            	}
            }
            else
            {
            	printf("Para dar de alta un empleado, es necesario que cargue el archivo\n\n");
            }
            break;

            case 4:
            if(flagArchivoCsv == 1)
            {
            	if(controller_editEmployee(listaEmpleados)==1)
            	{

            	}
            	else
            	{
            		printf("Hubo un error en el controlador de modificar a un empleado\n\n");
            	}
            }
            else
            {
            	printf("Para modificar un empleado es necesario que ingrese por lo menos a un empleado\n\n");
            }
            break;

            case 5:
            if(flagArchivoCsv == 1)
            {
            	if(controller_removeEmployee(listaEmpleados)==1)
            	{

            	}
            	else
            	{
            		printf("Hubo un error en el controlador de remover a un empleado del sistema\n\n");
            	}
            }
            else
            {
            	printf("Para dar de baja a un empleado es necesario que ingrese por por lo menos un empleado\n\n");
            }
            break;

            case 6:
            if(flagArchivoCsv == 1)
            {
            	if(controller_ListEmployee(listaEmpleados)==1)
            	{

            	}
            	else
            	{
            		printf("Hubo un error en el controlador de listar a los empleados\n\n");
            	}
            }
            else
            {
            	printf("Para listar es necesario que ingrese empleados\n\n");
            }
            break;

            case 7:
            if(flagArchivoCsv == 1)
            {
            	if(controller_sortEmployee(listaEmpleados)==1)
            	{

            	}
            	else
            	{
            		printf("Hubo un error en el controlador de ordenar a los empleados\n\n");
            	}
            }
            else
            {
            	printf("Para ordenar es necesario que ingrese empleados\n\n");
            }
            break;

            case 8:
            if(flagArchivoCsv == 1)
            {
            	if(controller_saveAsText("data.csv", listaEmpleados, &nextId)!= -1)
            	{

            	}
            	else
            	{
            		printf("Hubo un error en el controlador de guardar el listado en un archivo de texto\n\n");
            	}
            }
            else
            {
            	printf("Para guardar en el archivo es necesario que ingrese empleados\n");
            }

            break;

            case 9:
            if(flagArchivoCsv == 1)
            {
            	if(controller_saveAsBinary("data.bin", listaEmpleados, &nextId)!= -1)
            	{
            		flagArchivoBin = 1;
            	}
            	else
            	{
            		printf("Error\n");
            	}
            }
            else
            {
            	printf("Para guardar en el archivo es necesario que ingrese empleados\n");
            }
            break;

            case 10:
            printf("Ha salido correctamente del programa\n\n");
            break;
        }

    }while(option != 10);

    return 0;
}
