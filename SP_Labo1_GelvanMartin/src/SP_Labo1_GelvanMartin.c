/*
 ============================================================================
 Name        : SP_Labo1_GelvanMartin.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Perros.h"
#include "Inputs.h"





int main()
{
	setbuf(stdout,NULL);
    int option = 10;
    int exito;
    int banderaTexto=0;

    LinkedList* listaPerrosFiltrado;
    int banderaTerceraOpcion=0;
    int banderaFiltrado=0;
    int banderaSegundaOpcion=0;



    LinkedList* listaPerros = ll_newLinkedList();
    do{
    	pedirEntero(&option, "1.Cargar los datos de los perros desde el archivo perritos200.csv (modo texto)\n"
    			 "2.Ordenar perros\n"
    			"3.Realizar Mapeo\n"
    		     "4.Listar Perros con sus raciones\n"
    		     "5.Filtrar Perros\n"
    		     "6. Guardar en forma de texto\n"
    		     "7. Salir\n"
    		    "Elija la opcion: ", "Error, esa opcion no existe, reingrese la opcion\n"
    		    "1. Cargar los datos de los perros desde el archivo perritos200.csv (modo texto)\n"
				 "2.Ordenar perros\n"
				 "3.Realizar Mapeo\n"
				 "4.Listar Perros con sus raciones\n"
				 "5.Filtrar Perros\n"
				 "6. Guardar en forma de texto\n"
				 "7. Salir\n"
				"Elija la opcion: ", 1, 7);

        switch(option)
        {
            case 1:
                exito=controller_loadFromText("src\\perritos200.csv",listaPerros);
                if(exito==1)
                {
                	printf("\nSe cargo en forma de texto con exito!\n\n");
                	banderaTexto=1;
                }else
                {
                	printf("\nNo se logro cargar en forma de texto\n");
                }


                system("pause");
                break;
            case 2:

            	if(banderaTexto==1)
				{
					exito=controller_sortPerro(listaPerros);

					if(exito==1)
					{
						printf("\nSe ordeno con exito!\n\n");
						banderaSegundaOpcion=1;

					}else
					{
						printf("\nNo se logro ordenar\n");
					}
				}else
				{
					printf("\nIngrese la opcion 1 primero\n");
				}
				system("pause");

			break;

			case 3:
				if(banderaTexto==1 && banderaSegundaOpcion==1)
				{
					ll_map(listaPerros, ePerrito_laQueMapea);
					printf("\nSe mapeo con exito!\n");
					banderaTerceraOpcion=1;
				}else
				{
					printf("\nIngrese la opcion 1 primero y la 2\n");
				}

				system("pause");
			break;

			case 4:
				if(banderaTexto==1 && banderaSegundaOpcion==1 && banderaTerceraOpcion==1)
				{
					perro_ListPerrosConRaciones(listaPerros);
				}else
				{
					printf("\nIngrese la opcion 1 primero, la 2 y la 3\n");
				}

				system("pause");

			break;

			case 5:
				if(banderaTexto==1 &&  banderaSegundaOpcion==1 && banderaTerceraOpcion==1)
				{
					listaPerrosFiltrado=ll_filtro(listaPerros, filtroGalgoMasDe10AniosMenos200Gramos);
					perro_ListPerrosConRaciones(listaPerrosFiltrado);
					banderaFiltrado=1;
				}else
				{
					printf("\nIngrese la opcion 1 primero , por la 2 y por la 3\n");
				}


				system("pause");

			break;

			case 6:
				if(banderaTexto==1 && banderaSegundaOpcion==1 && banderaTerceraOpcion==1 && banderaFiltrado==1)
				{

					exito=controller_saveAsText("galgosFlaquitos.csv" , listaPerrosFiltrado);
					if(exito==1)
					{
						printf("\nSe guardo en forma de texto con exito!\n\n");
					}else
					{
						printf("\nNo se logro guardar en forma de texto\n");
					}

				}else
				{
					printf("\nIngrese la opcion 1 primero, la 2, la 3 y por el filtro\n");
				}

				system("pause");

			break;

			case 7:
					printf("\nFinalizado!\n");
			break;

        }
    }while(option != 7);
    return 0;
}

