#ifndef perros_H_INCLUDED
#define perros_H_INCLUDED
#include "LinkedList.h"

typedef struct
{
    int id;
    char nombre[128];
    int edad;
    char raza[128];
    float peso;
    float racionesDeComida;

}Perro;

Perro* perro_new();
Perro* perro_newParametros(char* idStr,char* nombreStr,char* razaStr,char* edadStr, char* pesoStr);
void perro_delete(Perro* this);


int perro_setId(Perro* this,int id);
int perro_getId(Perro* this,int* id);

int perro_setNombre(Perro* this,char* nombre);
int perro_getNombre(Perro* this,char* nombre);

int perro_setRaza(Perro* this,char* raza);
int perro_getRaza(Perro* this,char* raza);

int perro_setEdad(Perro* this,int edad);
int perro_getEdad(Perro* this,int* edad);

int perro_setPeso(Perro* this,float peso);
int perro_getPeso(Perro* this,float* peso);

int perro_setRacionesDeComida(Perro* this,float raciones);
int perro_getRacionesDeComida(Perro* this,float* raciones);

int perro_CompareById(void* perroUno, void* perroDos);
int perro_CompareByName(void* perroUno, void* perroDos);
int perro_CompareByRaza(void* perroUno, void* perroDos);
int perro_CompareByEdad(void* perroUno, void* perroDos);


int perro_searchIdPerro(LinkedList* this, int auxId);
int perro_ultimoId(LinkedList* this);


int filtroRazaGolden(void* pElement);
int filtroEdad(void* pElement);
int perro_ListPerro(Perro* perro);
int ePerrito_laQueMapea(void* perro);
int perro_ListPerrosConRaciones(LinkedList* pArrayListPerros);
int filtroGalgoMasDe10AniosMenos200Gramos(void* pElement);
#endif // perros_H_INCLUDED
