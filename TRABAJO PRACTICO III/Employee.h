#include "LinkedList.h"

#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr, int*);
void employee_delete();

int employee_setId(Employee*,int);
int employee_getId(Employee*,int*);
int employee_setNombre(Employee*, char*);
int employee_getNombre(Employee*, char*);
int employee_setHorasTrabajadas(Employee*, int);
int employee_getHorasTrabajadas(Employee*, int*);
int employee_setSueldo(Employee*, int);
int employee_getSueldo(Employee*, int*);

int CompareEmployeeByName(void*, void*);
int CompareEmployeeById(void*, void*);
int CompareEmployeeByHours(void*, void*);
int CompareEmployeeBySalary(void*, void*);

int Employee_getNextId(int*, char*);
void Employee_saveNextId(int*, char*);
void Employee_initId(int*, LinkedList*);
void employee_saveBin(LinkedList*, char*);
void employee_saveTxt(LinkedList*, char*);

Employee* employee_RequestData(LinkedList*, int*);
int addEmployee(LinkedList*, int*);
int ModifyEmployee(LinkedList*);
int RemoveEmployee(LinkedList*);

Employee* ObtenerEmpleadoPorId(LinkedList*);
int ObtenerId(LinkedList*);
int BuscarIdMayorEmpleado(LinkedList*);

int EmployeesList(LinkedList*);
int EmployeeListByName(LinkedList*);
int EmployeeListBySalary(LinkedList*);
int EmployeeListById(LinkedList*);
int EmployeeListByHours(LinkedList*);


#endif // employee_H_INCLUDED
