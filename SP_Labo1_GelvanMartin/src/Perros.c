#include <stdlib.h>
#include "Perros.h"
#include "LinkedList.h"
#include "Inputs.h"
#include "Controller.h"
#include "ValidacionesPersonalizado.h"
#include <string.h>
#include <stdio.h>


/**
 * @fn Employee employee_new*()
 * @brief Crea espacio libre en memoria dinamica
 *
 * @return retorna el espacio creado dinamicamente
 */
Perro* perro_new()
{
	Perro* pListPerros;

	pListPerros= (Perro*) malloc(sizeof(Perro));

	return pListPerros;

}

/**
 * @fn Employee employee_newParametros*(char*, char*, char*, char*)
 * @brief Me guardo con los setters los datos del empleado utilizando auxiliares
 *
 * @param idStr
 * @param nombreStr
 * @param horasTrabajadasStr
 * @param sueldoStr
 * @return Me retorna un empleado
 */
Perro* perro_newParametros(char* idStr,char* nombreStr,char* pesoStr,char* edadStr, char* razaStr)
{
	Perro* pPerro;

	int IdTransformado;
	int EdadTransformado;
	float pesoTransformado;
	pPerro=perro_new();

	if(pPerro!=NULL && idStr!=NULL && nombreStr!=NULL && edadStr!=NULL && razaStr!=NULL && pesoStr!=NULL)
	{

		validacion_Numero(idStr);
		IdTransformado=atoi(idStr);
		perro_setId(pPerro, IdTransformado);
		validacion_Cadena(nombreStr);
		perro_setNombre(pPerro, nombreStr);
		validacion_Numero(edadStr);
		EdadTransformado=atoi(edadStr);
		perro_setEdad(pPerro, EdadTransformado);
		pesoTransformado=atof(pesoStr);
		perro_setPeso(pPerro, pesoTransformado);
		perro_setRaza(pPerro, razaStr);

	}

	return pPerro;
}

/**
 * @fn int employee_setId(Employee*, int)
 * @brief Seteo el ID
 *
 * @param this recibe algo de tipo empleado
 * @param id recibe un id
 * @return Me retorna 1 si lo pudo settear
 */
int perro_setId(Perro* this,int id)
{
	int retorno=0;

	if(this!=NULL)
	{
		this->id=id;
		retorno=1;
	}

	return retorno;
}

/**
 * @fn int employee_getId(Employee*, int*)
 * @brief Obtengo un ID
 *
 * @param this Recibe algo del tipo empleado
 * @param id recibe un id
 * @return Me retorna 1 si lo pudo obtener
 */
int perro_getId(Perro* this,int* id)
{
	int retorno=0;

	if(this!=NULL && id!=NULL)
	{
		*id=this->id;
		retorno=1;
	}

	return retorno;
}

/**
 * @fn int employee_setId(Employee*, int)
 * @brief Seteo el ID
 *
 * @param this recibe algo de tipo empleado
 * @param id recibe un id
 * @return Me retorna 1 si lo pudo settear
 */
int perro_setRacionesDeComida(Perro* this,float raciones)
{
	int retorno=0;

	if(this!=NULL)
	{
		this->racionesDeComida=raciones;
		retorno=1;
	}

	return retorno;
}

/**
 * @fn int employee_getId(Employee*, int*)
 * @brief Obtengo un ID
 *
 * @param this Recibe algo del tipo empleado
 * @param id recibe un id
 * @return Me retorna 1 si lo pudo obtener
 */
int perro_getRacionesDeComida(Perro* this,float* raciones)
{
	int retorno=0;

	if(this!=NULL && raciones!=NULL)
	{
		*raciones=this->racionesDeComida;
		retorno=1;
	}

	return retorno;
}

/**
 * @fn int employee_setNombre(Employee*, char*)
 * @brief Seteo el nombre
 *
 * @param this Recibe algo de tipo empleado
 * @param nombre Recibe un nombre
 * @return Me retorna 1 si lo pudo settear
 */
int perro_setNombre(Perro* this,char* nombre)
{
	int retorno=0;

	if(this!=NULL && nombre!=NULL)
	{
		strcpy(this->nombre,nombre);
		retorno=1;
	}

	return retorno;
}

/**
 * @fn int employee_getNombre(Employee*, char*)
 * @brief Obtengo el nombre
 *
 * @param this Recibe algo del tipo empleado
 * @param nombre Recibe un nombre
 * @return Me retorna 1 si lo pudo obtener
 */
int perro_getNombre(Perro* this,char* nombre)
{
	int retorno=0;

	if(this!=NULL && nombre!=NULL)
	{
		strcpy(nombre,this->nombre);
		retorno=1;
	}

	return retorno;
}


int perro_setEdad(Perro* this,int edad)
{
	int retorno=0;

	if(this!=NULL)
	{
		this->edad=edad;
		retorno=1;
	}

	return retorno;
}


int perro_getEdad(Perro* this,int* edad)
{
	int retorno=0;

	if(this!=NULL && edad!=NULL)
	{
		*edad=this->edad;
		retorno=1;
	}

	return retorno;
}



int perro_setPeso(Perro* this,float peso)
{
	int retorno=0;

	if(this!=NULL)
	{
		this->peso=peso;
		retorno=1;
	}

	return retorno;
}


int perro_getPeso(Perro* this,float* peso)
{
	int retorno=0;

	if(this!=NULL && peso!=NULL)
	{
		*peso=this->peso;
		retorno=1;
	}

	return retorno;
}



int perro_setRaza(Perro* this,char* raza)
{
	int retorno=0;

	if(this!=NULL && raza!=NULL)
	{
		strcpy(this->raza,raza);
		retorno=1;
	}

	return retorno;
}


int perro_getRaza(Perro* this,char* raza)
{
	int retorno=0;

	if(this!=NULL && raza!=NULL)
	{
		strcpy(raza,this->raza);
		retorno=1;
	}

	return retorno;
}



/**
 * @fn void employee_delete(Employee*)
 * @brief Me realiza el free
 *
 * @param this Recibe algo del tipo empleado
 */
void perro_delete(Perro* this)
{
	if(this!=NULL)
	{
		free(this);
		this=NULL;
	}
}

/**
 * @fn int employee_CompareById(void*, void*)
 * @brief  Compara los id de los empleados para despues ordenarlos de forma ascendente o descendente
 *
 * @param employeeOne Recibe un empleado
 * @param employeeTwo Recibe otro empleado
 * @return Me retorna 1 si el Id del empleado 1 es mayor que el empleado 2, me retorna -1 si el Id del empleado 1 es menor que el empleado 2
 */
int perro_CompareById(void* perroUno, void* perroDos)
{
	int comparacion=0;
	Perro* perroA;
	Perro* perroB;
	int auxIdUno;
	int auxIdDos;

	if(perroUno!=NULL && perroDos!=NULL)
	{
		perroA=(Perro*)perroUno;
		perroB=(Perro*)perroDos;

		perro_getId(perroA, &auxIdUno);
		perro_getId(perroB, &auxIdDos);

		if(auxIdUno>auxIdDos)
		{
			comparacion=1;

		}else
		{
			if(auxIdUno<auxIdDos)
			{
				comparacion=-1;
			}
		}

		perroA=NULL;
		perroB=NULL;
	}

	return comparacion;
}

/**
 * @fn int employee_CompareByName(void*, void*)
 * @brief Compara los nombres de los empleados y luego los ordena tanto de forma A a la Z o de la Z a la A
 *
 * @param employeeOne Recibe un empleado
 * @param employeeTwo Recibe otro empleado
 * @return Me retorna la comparacion de los nombres
 */
int perro_CompareByName(void* perroUno, void* perroDos)
{
	int retorno=-1;
	Perro* perroA;
	Perro* perroB;
	char auxNombreUno[128];
	char auxNombreDos[128];

	if(perroUno!=NULL && perroDos!=NULL)
	{
		perroA=(Perro*)perroUno;
		perroB=(Perro*)perroDos;

		perro_getNombre(perroA, auxNombreUno);
		perro_getNombre(perroB, auxNombreDos);

		retorno=strcmp(auxNombreUno,auxNombreDos);

		perroA=NULL;
		perroB=NULL;

	}

	return retorno;
}


/**
 * @fn int employee_CompareByName(void*, void*)
 * @brief Compara los nombres de los empleados y luego los ordena tanto de forma A a la Z o de la Z a la A
 *
 * @param employeeOne Recibe un empleado
 * @param employeeTwo Recibe otro empleado
 * @return Me retorna la comparacion de los nombres
 */
int perro_CompareByRaza(void* perroUno, void* perroDos)
{
	int retorno=-1;
	Perro* perroA;
	Perro* perroB;
	char auxRazaUno[128];
	char auxRazaDos[128];

	if(perroUno!=NULL && perroDos!=NULL)
	{
		perroA=(Perro*)perroUno;
		perroB=(Perro*)perroDos;

		perro_getRaza(perroA, auxRazaUno);
		perro_getRaza(perroB, auxRazaDos);

		retorno=strcmp(auxRazaUno,auxRazaDos);

		perroA=NULL;
		perroB=NULL;

	}

	return retorno;
}
/**
 * @fn int employee_CompareBySueldo(void*, void*)
 * @brief Compara los sueldos de los empleados y luego los forma de madera ascendente o descendente
 *
 * @param employeeOne Recibe un empleado
 * @param employeeTwo Recibe otro empleado
 * @return Retorna 1 si el suelado del empleado 1 es mayor al del empleado 2, y retorna -1 si el sueldo del empleado 1 es menor al sueldo del empleado 2
 */
int perro_CompareByEdad(void* perroUno, void* perroDos)
{
	int comparacion=0;
	Perro* perroA;
	Perro* perroB;
	int auxSueldoUno;
	int auxSueldoDos;

	if(perroUno!=NULL && perroDos!=NULL)
	{
		perroA=(Perro*)perroUno;
		perroB=(Perro*)perroDos;

		perro_getEdad(perroA, &auxSueldoUno);
		perro_getEdad(perroB, &auxSueldoDos);

		if(auxSueldoUno>auxSueldoDos)
		{
			comparacion=1;

		}else
		{
			if(auxSueldoUno<auxSueldoDos)
			{
				comparacion=-1;
			}
		}

		perroA=NULL;
		perroB=NULL;
	}

	return comparacion;
}


/**
 * @fn int employee_searchIdEmployee(LinkedList*, int)
 * @brief Busco por Id el indice de un empleado en especifico
 *
 * @param this Recibe algo del tipo empleado
 * @param auxId Recibe un Id
 * @return Me retorna el indice del empleado buscado
 */
int perro_searchIdPerro(LinkedList* this, int auxId)
{
	int tam;
	int i;
	Perro* auxPerro;
	int idPerro;
	int index=-1;

	if(this!=NULL)
	{
		tam=ll_len(this);

		for(i=0;i<tam;i++)
		{
			auxPerro=(Perro*)ll_get(this,i);
			idPerro=auxPerro->id;
			perro_getId(auxPerro, &idPerro);

			if(auxId==idPerro)
			{
				index=i;
				break;
			}
		}
	}

	return index;
}

/**
 * @fn int employee_ultimoId(LinkedList*)
 * @brief  Me trae el ultimo id de la lista de empleados
 *
 * @param this Algo de tipo LinkedList
 * @return Me retorna el ultimo id
 */
int perro_ultimoId(LinkedList* this)
{
	int tam;
	int i;
	int ultimoId=-1;
	Perro* perro;

	if(this!=NULL)
	{
		tam=ll_len(this);
		for(i=0;i<tam;i++)
		{
			perro=ll_get(this, i);
			if(perro!=NULL)
			{
				perro_getId(perro, &ultimoId);
			}
		}
	}

	return ultimoId;
}

int filtroRazaGolden(void* pElement)
{
	int retorno=-1;
	char raza[128];

	Perro* auxPerro;
	if(pElement!=NULL)
	{
		auxPerro=(Perro*)pElement;
		perro_getRaza(auxPerro, raza);

		if(strcmp(raza,"Female")==0)
		{
			retorno=0;
		}
	}

	return retorno;

}

int filtroGalgoMasDe10AniosMenos200Gramos(void* pElement)
{
	int retorno=-1;
	char raza[128];
	int edad;
	float raciones;

	Perro* auxPerro;
	if(pElement!=NULL)
	{
		auxPerro=(Perro*)pElement;
		perro_getRaza(auxPerro, raza);
		perro_getEdad(auxPerro,&edad );
		perro_getRacionesDeComida(auxPerro,&raciones );

		if((strcmp(raza,"Galgo")==0) && edad>10 && raciones<200)
		{
			retorno=0;
		}
	}

	return retorno;

}

int filtroEdad(void* pElement)
{
	int retorno=-1;
	int edad;

	Perro* auxPerro;
	if(pElement!=NULL)
	{
		auxPerro=(Perro*)pElement;

		perro_getEdad(auxPerro,&edad );

		if(edad>10)
		{
			retorno=0;
		}
	}

	return retorno;

}

int ePerrito_laQueMapea(void* perro)
{
	int retorno=-1;
	float pesoCalculado;
	Perro* auxPerro=NULL;
	float peso;


	if(perro!=NULL)
	{
		auxPerro=(Perro*)perro;
		perro_getPeso(auxPerro, &peso);
		pesoCalculado=peso*23;
		perro_setRacionesDeComida(auxPerro,pesoCalculado);

		retorno=1;
	}
	return retorno;
}




int perro_ListPerrosConRaciones(LinkedList* pArrayListPerros)
{
	int i;
	int tam;
	int auxId;
	int auxEdad;
	float auxPeso;
	float auxRaciones;
	char auxNombre[120];
	char auxRaza[120];
	Perro* auxPerro;
	int exito=0;



	printf("%-10s %-10s %-10s %-10s %-10s %-10s\n","ID","NOMBRE","PESO","EDAD","RAZA","RACIONES COMIDA");

	if(pArrayListPerros!=NULL) //Verifico que pArrayListPerros sea distinto de NULL
	{
		tam=ll_len(pArrayListPerros); //guardo el tamaño del array en una variable

		for(i=0;i<tam;i++)
		{
			auxPerro=(Perro*)ll_get(pArrayListPerros, i); //Guardo los perros en auxPerro

			perro_getId(auxPerro, &auxId); //traigo el id del perro
			perro_getNombre(auxPerro, auxNombre); //traigo el nombre del perro
			perro_getRaza(auxPerro, auxRaza); //traigo la raza del perro
			perro_getEdad(auxPerro, &auxEdad); //traigo la edad del perro
			perro_getPeso(auxPerro, &auxPeso);
			perro_getRacionesDeComida(auxPerro, &auxRaciones);
			printf("%-10d %-10s %-10.2f %-10d %-10s %-10.2f\n",auxId,auxNombre,auxPeso,auxEdad,auxRaza,auxRaciones); //Imprimo los perros


		}

		exito=1;
	}

    return exito;
}

