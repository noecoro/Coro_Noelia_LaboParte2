
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "marca.h"
#include "avion.h"
#include "viaje.h"
#include "piloto.h"
#include "utn.h"
#define TAM_MARCA 4
#define TAM_VIAJE 5
#define TAM_AVION 4
#define TAM_PILOTO 4

int main(void) {
	setbuf(stdout,NULL);

	Avion  arrayAviones[TAM_AVION]={
			{1,10,100,1000,1,1900,0,{13,10,2022},5},
			{2,20,102,1001,2,1901,0,{14,11,2023},4},
			{3,30,103,1002,3,1902,0,{15,12,2024},3},
			{4,40,104,1003,4,1903,0,{16,10,2025},2}
	};

	Marca arrayMarcas[TAM_MARCA] = {
		{1000, "Boeing"},
		{1001, "Airbus"},
		{1002, "ATR"},
		{1003, "Bombardier"}
	};

	Viaje arrayViajes[TAM_VIAJE] = {
			{100, "Salta", 1462.5},
			{101, "Tucuman", 1247.6},
			{102, "Neuquen", 1139.4},
			{103, "Corrientes", 670},
			{104, "Chubut", 1735.8}};

	Piloto arrayPilotos[TAM_PILOTO]= {
			{1, "Sanchez"},
			{2, "Ana"},
			{3, "Juan"},
			{4, "Sol"}
	};

	int opcion;
	int idAvion;
	int flagA = 0;
	int flagB = 0;
	int flagC = 0;
	int flagD = 0;
	int flagE = 0;


	do {

		if(!utn_getNumero(&opcion,"\n1.ALTA AVION\n2.MODIFICAR AVION\n3.BAJA AVION\n4.LISTAR AVIONES\n5.LISTAR VIAJES\n6.LISTAR MARCAS\n7.SALIR\n","\nError opcion invalida",1,7,2) )

		switch(opcion)
		{
		/*
		 Modificar la opción A.Alta y
		 D.Listar para que tenga en cuenta el Piloto.
		Agregar la opción G. LISTAR PILOTOS
		 */
		case 1:
			if(altaAvion(arrayAviones,TAM_AVION,arrayMarcas,TAM_MARCA, arrayViajes,TAM_VIAJE,&idAvion,arrayPilotos, TAM_PILOTO))

			{
				printf("Alta ok\n");
			}
			else
				{
					printf("Error\n");
				}
			flagA = 1;

			break;
		case 2:
			if(flagA == 1)
			{
			if(avionesRegistrados(arrayAviones, TAM_AVION) != TAM_AVION)
			{
				//int modificarAvion(Avion aviones[], int tamAvion, Viaje viaje[], int tamViaje,Marca marca[], int tamMarca, Piloto pilotos, int tamPilotos)
					if(modificarAvion(arrayAviones, TAM_AVION, arrayViajes, TAM_VIAJE,arrayMarcas, TAM_MARCA,arrayPilotos, TAM_PILOTO ))
					{
						printf("\nModificacion realizada con exito");
					flagB = 1;
					}
					}
					else
					{
							printf("\nError");
					}
			}
			else
			{
				printf("\n No puede ingresar a esta opcion. No hay aviones ingresdos");
			}
			break;
		case 3:
			if(flagA == 1 && flagB == 1)
			{
			if(avionesRegistrados(arrayAviones, TAM_AVION) != TAM_AVION)
			{
						if(bajaAvion(arrayAviones, TAM_AVION, arrayViajes, TAM_VIAJE, arrayMarcas, TAM_MARCA,arrayPilotos, TAM_PILOTO))
						{
							printf("\nBaja exitosa\n");

						}
						flagC = 1;
			}
						else
						{
							printf("\nHubo un problema\n");
						}
					}
					else
					{
						printf(" No puede ingresar a esta opcion porque no hay aviones ingresdos\n ");
					}

					break;

			break;
		case 4:
			if(flagA == 1 && flagB == 1 && flagC == 1)
			{
			if(avionesRegistrados(arrayAviones,TAM_AVION) != TAM_AVION)
			{
				if(mostrarAviones(arrayAviones,TAM_AVION,arrayViajes, TAM_VIAJE,arrayMarcas, TAM_MARCA, arrayPilotos, TAM_PILOTO)==0)
					//int mostrarAviones(Avion aviones[], int tamAvion, Viaje viaje[] , int tamViaje, Marca marca[], int tamMarca, Piloto pilotos, int tamPilotos);
				//if(mostrarAviones(arrayAviones,TAM_AVION,arrayViajes, TAM_VIAJE,arrayMarcas, TAM_MARCA, arrayPilotos, TAM_PILOTO)==0)
				{
					printf("ok\n");

				}
				flagD = 1;
			}
				else
				{
					printf("error \n");
				}
			}

			else
			{
				printf(" No puede ingresar a esta opcion. No hay aviones registrados.\n");
			}
			break;

		case 5:
			if(flagA == 1 && flagB == 1 && flagC == 1 && flagD == 1)
			{
			mostrarViajes(arrayViajes,TAM_VIAJE);
			flagD = 1;
			}
			else
			{
				printf(" No puede ingresar a esta opcion. Debe tener ingresado datos \n");
			}
			break;
		case 6:
			if(flagA == 1 && flagB == 1 && flagC == 1 && flagD == 1)
			{
			mostrarMarcas(arrayMarcas,TAM_MARCA);
			flagE=1;
			}
			else
			{
				printf("No puede ingresar a esta opcion.Debe tener ingresado datos \n");
			}
				break;

		case 7:
			if(flagA == 1 && flagB == 1 && flagC == 1 && flagD == 1)
					{
			mostrarPilotos(arrayPilotos,TAM_PILOTO);
					}
			else
			{
				printf(" No puede ingresar  \n");
			}

		}
	}while(opcion != 7);



	return EXIT_SUCCESS;
}


