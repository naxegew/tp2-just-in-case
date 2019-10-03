/*
 ============================================================================
 Name        : TP2.c
 Author      : Ignacio Canay
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include "ArrayEmployees.h"
#include "lib_tp2.h"

#define LIMITE 50
#define LIMSTR 51

int main(void) {
Employee listaEmpleados[LIMITE];

int option,optionMod;
int fRuns=0,triesBorrar=3;
int id,sector,contEmployee;
char name[LIMSTR], lastName[LIMSTR], opBorrar, strBuffer[LIMSTR];
float salary, acumSalary,averSalary;
int position;

do{

mainMenu(&option);

switch(option)
{
case 1:
	if(fRuns==0)							//checks if Employees Array already initialized
	{
	initEmployees(listaEmpleados,LIMITE);
	fRuns=1;
	}

	do{
	getStr(name,LIMSTR,"ingrese nombre");
	}while(isValidAlphabetic(name)!=0);

	do{
	getStr(lastName,LIMSTR,"ingrese Apellido");
	}while(isValidAlphabetic(lastName)!=0);

	do{
	do{
	getStr(strBuffer,LIMSTR,"ingrese Salario");
	}while(isValidFloat(strBuffer)!=0);

	}while(GetCheckedFloat(strBuffer,14000.0,15000.0,LIMSTR,&salary));

	getInt(&sector, "ingrese el sector","Error el sector debe ser del 1 al 5", 1, 5, 3);

	addEmployees(listaEmpleados,LIMITE,id,name,lastName,LIMSTR,&salary,&sector);
	break;
case 2:
		getInt(&id,"Ingrese id de Empleado que quiere buscar.","Error en la busqueda vuelva a intentar", 1, LIMITE, 3);
		if(findEmployeeById(listaEmpleados,LIMITE,&id,&position)==0) //si encuentra el id y esta lleno, da el menu de modificacion
		{
			printEmployeById(listaEmpleados,LIMITE,&id);
			printf("que desea hacer con este empleado?");
			modificarMenu(&optionMod);

			//menu de opciones de cambios a empleado encontrado
			switch(optionMod)
			{
				case 1:
					getStr(name,LIMSTR, "ingrese el nuevo nombre para el empleado");
					strncpy(listaEmpleados[position].name,name,LIMSTR);

					break;
				case 2:
					//modificar apellido
					getStr(lastName,LIMSTR, "ingrese el nuevo nombre para el empleado");
					strncpy(listaEmpleados[position].lastName,lastName,LIMSTR);
					break;
				case 3:
					//modificar salario
					getFloat(&salary,"ingrese el nuevo salario para el empleado", "error el salario debe estar entre $14000 y $55000", 14000, 55000, 3);
					listaEmpleados[position].salary = salary;
					break;
				case 4:
					//modificar sector
					getInt(&sector,"ingrese el nuevo sector para el empleado", "error el sector debe estar entre el 1 y el 5", 1, 5, 3);
					listaEmpleados[position].sector = sector;
					break;
				case 5:

					break;
				case 6:
					//volver al menu ppal
					break;
				default:
					printf("opcion incorrecta debe ser de las opciones 1 a 6");//error?
					break;
			}

		}
	break;

case 3:
	//baja
	getInt(&id,"Ingrese id de Empleado que quiere Borrar.","Error en la busqueda vuelva a intentar", 1, LIMITE, 3);
			if(findEmployeeById(listaEmpleados,LIMITE,&id,&position)==0) //si encuentra el id y esta lleno
			{
				printEmployeById(listaEmpleados,LIMITE,&id);
				printf("\ndesea borrar este empleado de la lista?(s/n)");

				__fpurge(stdin);
				scanf("%c",&opBorrar);
				do{
					if(opBorrar=='s')
					{
					listaEmpleados[position].isEmpty = 0;
					printf("\nel Empleado id: %d, fue borrado con exito.", listaEmpleados[position].id);
					break;
					}
					else if(opBorrar=='n')
					{
						break;
					}
					else if(opBorrar!='n' && opBorrar !='s')
					{
						triesBorrar--;
					}

				}while(opBorrar!='s'|| opBorrar!='n' || triesBorrar>0);



			}

	break;
case 4:
	printf("\nlistado de empleados");
	printEmployees(listaEmpleados,LIMITE);
	printf("\nlistado de empleados ordenado por apellido y sector de mayor a menor");

	sortEmployeesByLastName(listaEmpleados, LIMITE,LIMSTR,1);
	printEmployees(listaEmpleados,LIMITE);

	printf("\nlistado de empleados ordenado por apellido y de menor a mayor");
	sortEmployeesByLastName(listaEmpleados, LIMITE,LIMSTR,0);
	printEmployees(listaEmpleados,LIMITE);

	totalSalary(listaEmpleados,LIMITE,&acumSalary);
	printf("\n el total acumulado de salarios es: %.2f",acumSalary);

	employeeCounter(listaEmpleados,LIMITE,&contEmployee);
	printf("\n el total de empleados activos es: %d", contEmployee);

	employeesAverageSalary(listaEmpleados,LIMITE,&acumSalary,&contEmployee,&averSalary);
	printf("\n el salario promedio es: %.2f", averSalary);

	printf("\nlistado de empleados impreso despues del acomodamiento");
	printEmployees(listaEmpleados,LIMITE);
	break;
case 5:
	//exit
	break;
default:
	//error
	break;
}
}while(option!=6);

return EXIT_SUCCESS;
}

//--get float original--	getFloat(&salary, "ingrese salario","Error el salario debe ser minimo $14000 y max de $55000",14000,55000,3);
