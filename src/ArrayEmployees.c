/*
 * ArrayEmployees.c
 *
 *  Created on: 26 sep. 2019
 *      Author: alumno
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include "ArrayEmployees.h" // va aca?

int initEmployees(Employee list[],int length)
{
	int retorno =-1;
	int i;
	if(list!=NULL && length>0)
	{
		for(i=0;i<length;i++)
		{
			list[i].isEmpty =0;
		}
		retorno =0;
	}

	return retorno;
}
int addEmployees(Employee list[], int length,int id, char name[], char lastName[],int strLength, float *salary, int *sector)
{
int retorno =-1;
int i;

if(list!= NULL && length>0)
   {
	for(i=0;i<length;i++)
	{
		if(list[i].isEmpty==1)
		{
			printf("\nla posicion %d esta siendo utilizada", list[i].id);
		}
		if(list[i].isEmpty==0){
			strncpy(list[i].name,name,strLength);
			strncpy(list[i].lastName,lastName,strLength);
			list[i].salary=*salary;
			list[i].sector=*sector;
			list[i].isEmpty=1;
			list[i].id=i+1;

			break;
		}
	}
}


return retorno;

}

int findEmployeeById(Employee list[],int length,int *pId,int *position)
{
int retorno =-1;
int i;
int id=*pId;
if(list!=NULL && length>0)
{
	for(i=0;i<length;i++) //recorre el array hasta que i = a
	{
		if(list[i].isEmpty==0)
		{
			continue; //si la posicion i de la lista esta vacia (isEmpty==0), sigue con al siguiente
		}
		else if(list[i].id==id)//si la posicion de la lista i, el id es = al id buscado.
		{
			retorno=0;
			*position=i; //devuelve en id la posicion en el array
		}
	}
}


	return retorno;
}

int printEmployeById(Employee list[],int length, int *id)
{
	int retorno =-1;
	int i;
	int buffer = *id;

	if(list!=NULL && length>0)
	{
		for(i=0;i<length;i++)
		{
			if(list[i].id==buffer)
			{
				printf("\n****************************************");

				printf("\n Id Empleado: %d", list[i].id);
				printf("\n nombre Empleado: %s", list[i].name);
				printf("\n Apellido Empleado: %s", list[i].lastName);
				printf("\n salario Empleado: %.2f", list[i].salary);
				printf("\n sector Empleado: %d\n", list[i].sector);
				printf("\n****************************************\n");

				retorno=0;

				break;
			}
		}
	}


	return retorno;
}

int printEmployees(Employee list[], int length)
{
int i, retorno =-1;
	if(list!=NULL && length>0)
	{
		printf("\nid\t nombre y apellido \t salario\t sector");
		for(i=0;i<length;i++)
		{
			if(list[i].isEmpty==1)
			{
				printf("\n****************************************\n");
				printf("%d %s %s %.2f %d", list[i].id, list[i].name, list[i].lastName,list[i].salary, list[i].sector);
				printf("\n****************************************\n");
			}
		}
		retorno=0;
	}

	return retorno;
}
int sortEmployeesByLastName(Employee list[], int length,int strLength, int option)
{//1
int i;
int flagCambio=-1;
int retorno=-1;

Employee buffer;

	if(list!=NULL && length>0)
	{
		switch(option)
		{
		case 1:
			while(flagCambio==-1)
			{
				flagCambio=0;
				for(i=0;i<length;i++)
				{
					if(list[i].isEmpty!=0)
					{
						if(strcmp(list[i].lastName,list[i+1].lastName)==0)
						{
							if(list[i].sector>list[i+1].sector)
							{
								//si el sector de i es mayor que el de i+1, no mover
								continue;
							}
							else if(list[i].sector<list[i+1].sector)
							{
								//si el sector de i es menor que el de i+1, swap
								buffer = list[i];
								list[i] = list[i+1];
								list[i+1]=buffer;
								flagCambio=-1;
							}
						}
					else if(strcmp(list[i].lastName,list[i+1].lastName)>0)
						{
							continue;//i es mayor que i+1 entonces no mover
						}
						else if(strcmp(list[i].lastName,list[i+1].lastName)<0)
						{
							// i es menor que i+1 entonces mover
							buffer = list[i];
							list[i] = list[i+1];
							list[i+1]=buffer;
							flagCambio=-1;
						}
					}
				}
			}

			retorno=0;
			break;
// el coment va a ca
		case 0:
			while(flagCambio==-1)
			{
				flagCambio=0;
				for(i=0;i<length;i++)
				{
					if(strcmp(list[i].lastName,list[i+1].lastName)==0)
					{
						if(list[i].sector>list[i+1].sector)
						{
							buffer = list[i];
							list[i] = list[i+1];
							list[i+1]=buffer;
							flagCambio=-1;
							continue;
						}
					}
				}
			}
			break;


		default:
			printf("solo se puede ordenar de mayor a menor o vicebersa");
			retorno=-1;
		break;
		}
	}
	return retorno;
}

int totalSalary(Employee list[],int length,float *pTotalSalary)
{
	int i;
	float acumSalary=0;
	int retorno =-1;

	if(list!=NULL && length>0)
		{
		for(i=0;i<length;i++)
		{
			if(list[i].isEmpty==1)
			{
			acumSalary = acumSalary + list[i].salary;
			retorno=0;
			}
		}
		}

	*pTotalSalary=acumSalary;
return retorno;
}
int employeeCounter(Employee list[], int length, int *pCountEmployee)
{
int i, contEmployee=0,retorno =-1;
	if(list!=NULL && length>0)
	{
		for(i=0;i<length;i++)
		{
			if(list[i].isEmpty==1)
			{
				contEmployee++;
				retorno=0;
			}
		}
	}
	*pCountEmployee=contEmployee;
	return retorno;
}

int employeesAverageSalary(Employee list[], int lenght, float *pTotalSalary, int *pCountEmployees, float *pAverSalary)
{
int retorno=-1;
int countEmployees=*pCountEmployees;
float buffer;
float totalSalary=*pTotalSalary;

	if(pTotalSalary==0 || countEmployees ==0)
	{
		printf("no se puede dividir por 0");
		return retorno;
	}
	buffer = totalSalary/countEmployees;
	*pAverSalary=buffer;
	retorno=0;
	return retorno;
}

/* case 0:
	while(flagCambio==-1)
	{
		flagCambio=0;
		for(i=0;i<length;i++)
		{
			if(strcmp(list[i].lastName,list[i+1].lastName)==0)
			{
				if(list[i].sector<list[i+1].sector)
				{
					continue;//si el sector de i es menor que el de i+1, no mover
				}
				else if(list[i].sector>list[i+1].sector)
				{
					//si el sector de i es mayor que el de i+1, swap
					buffer = list[i];
					list[i] = list[i+1];
					list[i+1]=buffer;
					flagCambio=-1;
				}
			}
			if(strcmp(list[i].lastName,list[i+1].lastName)<0)
			{
				continue;//i es menor que i+1 entonces no mover
			}
			else if(strcmp(list[i].lastName,list[i+1].lastName)>0)
			{
				// i es mayor que i+1 entonces mover
				buffer = list[i];
				list[i] = list[i+1];
				list[i+1]=buffer;
				flagCambio=-1;
			}
		}
	retorno=0;
	}
	break;
*/
