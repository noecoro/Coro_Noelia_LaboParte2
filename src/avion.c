
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "marca.h"
#include "avion.h"
#include "piloto.h"
#include "utn.h"

void iniAviones(Avion aviones[], int tam)
{
	int i;
	for(i = 0; i < tam; i ++)
	{
		aviones[i].isEmpty = 1;
	}

}
/**
 * \brief Inicializa el array con isEmpty en 1
 * \param lista de aviones  a ser inicializado
 * \param tam Limite del array de aviones
 */
//duda tener aviones cargados
//inxrementa suma cambiar nombre de funcion cuenta los espacios vacos
int avionesRegistrados(Avion aviones[], int tam)
{
int acumulador = 0;
if(aviones != NULL && tam > 0)
{
	for(int i = 0; i < tam; i++){

		if(aviones[i].isEmpty == 1){
			acumulador ++;
		}
	}
}
	return acumulador;
}


/**
 * recorre cuenta indices vacios
 * @param array de aviones
 * @param tam Limite del array de aviones
 * @return acumulador
 */
int buscarIndiceLibreAvion(Avion aviones[], int tam)
{
	int retorno = -1;
	int i;
	if(aviones != NULL && tam > 0)
	{
		for(i = 0; i < tam; i++)
		{

			if(aviones[i].isEmpty )
			{
			retorno = i;


			break;
			}
		}
	}
	return retorno;
}
/**
 * busca 1er posicion vacia
 * @param array de aviones
 * @param tam Limite del array de aviones
 * @return Retorna el indice de la posicion vacia y -1 (ERROR)
 */
int buscarAvionId(Avion aviones[], int tam, int id)
{
    int indice = -1;//error
    int i;

    if(aviones != NULL && tam > 0)
    {
        for(i = 0; i < tam; i++)
        {
            if(aviones[i].idAvion == id && aviones[i].isEmpty == 0)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}

int altaAvion(Avion aviones[], int tamAvion, Marca marca[], int tamMarca, Viaje viajes[], int tamViaje, int* punteroId, Piloto pilotos[], int tamPilotos)
{
	int ok = 0;
	int indiceLibre;
	iniAviones(aviones,tamAvion);
	printf("Id de avion: %d\n",*punteroId);// va incrementado
		if(aviones != NULL && tamAvion > 0 && marca != NULL && tamMarca > 0 && viajes != NULL &&  tamViaje > 0 && punteroId != NULL && pilotos != NULL && tamPilotos > 0)
		{
			indiceLibre = buscarIndiceLibreAvion(aviones,tamAvion);
		if (indiceLibre == -1)
		{
			printf("No hay mas lugar\n");
		}
		else// cambiar el orden del ingreso
		{
			printf("ingrese Nro de Matricula(1a5): \n");//de 1 a 5 o mayores a 0
			fflush(stdin);
			scanf("%d",&aviones[indiceLibre].matricula);

			while(aviones[indiceLibre].matricula <= 1 && aviones[indiceLibre].matricula >= 5)
			{
				printf("Error. Reingrese Matricula : \n");//\n pueden verse mal
				fflush(stdin);
				scanf("%d", &aviones[indiceLibre].matricula);
			}
				printf("Ingrese  modelo (año de fabricación): \n");
				fflush(stdin);
				scanf("%d", &aviones[indiceLibre].modelo);
				printf("\n");
			while(aviones[indiceLibre].modelo < 1900)
			{
				printf("Error. Reingrese modelo (año de fabricación): \n ");//rango de año aclarar
				fflush(stdin);
				scanf("%d", &aviones[indiceLibre].modelo);
				printf("\n");
			}//cambiar orden marca 1ro y desp viajes
			mostrarViajes(viajes, tamViaje);
				printf("\nIngrese Id de viaje: ");
				scanf("%d", &aviones[indiceLibre].idViaje);


			while(validarBuscarIdViajes(aviones[indiceLibre].idViaje, viajes, tamViaje) != 1)
			{
				printf("Error, reingrese Id : ");
				scanf("%d", &aviones[indiceLibre].idViaje);
			}

//====================0
			mostrarPilotos(pilotos, tamPilotos);
						printf("\nIngrese IdDni de piloto: \n");
						scanf("%d", &aviones[indiceLibre].idPiloto);


					while(validarBuscarIdPiloto(aviones[indiceLibre].idPiloto, pilotos, tamPilotos) != 1)
					{
						printf("Error, reingrese IdDni : ");
						scanf("%d", &aviones[indiceLibre].idPiloto);
					}

//===========================
			mostrarMarcas(marca, tamMarca);
			printf("\nIngrese Id de marca: ");
			fflush(stdin);
			scanf("%d", &aviones[indiceLibre].idMarca);

			while(validarBuscarIdMarca(marca, tamMarca,aviones[indiceLibre].idMarca) != 1)
			{
			printf("Error. Reingrese Id marca: ");
			scanf("%d", &aviones[indiceLibre].idMarca);
			}
			printf("Ingrese cantidad de asientos (menor o igual a 5): \n");
			fflush(stdin);
			scanf("%d", &aviones[indiceLibre].cantAsientos);
			printf("\n");

			while(aviones[indiceLibre].cantAsientos >= 5)
			{
			printf("Error. Reingrese cantidad de asientos : ");//5
			fflush(stdin);
			scanf("%d", &aviones[indiceLibre].cantAsientos);
			printf("\n");
			}

			printf("\nIngrese fecha DD/MM/AAAA : ");//limitar rango de año
			fflush(stdin);
			scanf("%d/%d/%d", &aviones[indiceLibre].fechaS.dia, &aviones[indiceLibre].fechaS.mes, &aviones[indiceLibre].fechaS.anio);
			printf("\n");
			while(aviones[indiceLibre].fechaS.dia > 31 || aviones[indiceLibre].fechaS.dia < 1 || aviones[indiceLibre].fechaS.mes > 12 ||
				aviones[indiceLibre].fechaS.mes < 1 || aviones[indiceLibre].fechaS.anio < 2022 || aviones[indiceLibre].fechaS.anio > 2027 )
			{
				printf("\nError. Reingrese fecha DD/MM/AAAA(2021-2026) : ");//limitar rango de año
				fflush(stdin);
				scanf("%d/%d/%d", &aviones[indiceLibre].fechaS.dia, &aviones[indiceLibre].fechaS.mes, &aviones[indiceLibre].fechaS.anio);
				printf("\n");

			}
				aviones[indiceLibre].idAvion = *punteroId;
				(*punteroId)++;
				aviones[indiceLibre].isEmpty = 0;//
				ok = 1;


		}
		}
	return ok;
}

int modificarAvion(Avion aviones[], int tamAvion, Viaje viaje[], int tamViaje,Marca marca[], int tamMarca, Piloto pilotos[], int tamPilotos)
{
	int ok = 0;
	int indice;
	int matricula;
	int opcion;

	mostrarAviones(aviones, tamAvion, viaje, tamViaje,marca, tamMarca,pilotos,tamPilotos);
	printf("Ingrese matricula: ");
	fflush(stdin);
	scanf("%d",&matricula);

	if(buscarUnaMatricula(aviones,tamAvion,matricula) == -1)
	{
		printf("Error, no existe");
		printf("Reingrese matricula: ");
		fflush(stdin);
		scanf("%d", &matricula);
	}

	if(aviones != NULL && tamAvion > 0 && tamViaje > 0 && viaje != NULL && marca != NULL && tamMarca > 0 && pilotos != NULL && tamPilotos >0)
	{
		indice = buscarUnaMatricula(aviones, tamAvion,matricula);
		if (indice == -1)
		{
			printf("Nada para modificar");
		}
		else
		{
			mostrarAvion(aviones[indice],viaje,tamViaje,marca,tamMarca,pilotos,tamPilotos);//
		}

		do {

				if(!utn_getNumero(&opcion,"\n1.Modificar año de modelo\n2.Modificar cantidad de asientos\n3.Salir\n","\nError opcion invalida",1,3,1) )
				{
					switch(opcion)
					{
					case 1:
							printf("Ingrese año de modelo: ");
							fflush(stdin);
							scanf("%d",&aviones[indice].modelo);
						break;
					case 2:
							printf("Ingrese cantidad de asientos: ");
							fflush(stdin);
							scanf("%d",&aviones[indice].modelo);
						break;

					default:
						printf("Salio\n");
						break;
					}
					ok = 1;
				}

		}while(opcion != 3);


	}
	return ok;
}




void mostrarAvion(Avion unSoloAvion, Viaje viaje[] , int tamViaje, Marca marca[], int tamMarca, Piloto pilotos[], int tamPilotos)
{

	char copiarDescripcionV[20];
	char copiarDescripcionM[20];
	char copiarDescripcionP[20];

	if(copiarProvinciaViaje(unSoloAvion.idViaje, viaje, tamViaje, copiarDescripcionV) &&
	   copiarNombreMarca(unSoloAvion.idMarca, marca, tamMarca,copiarDescripcionM )&&
	   copiarNombrePiloto(unSoloAvion.idPiloto,pilotos, tamPilotos,copiarDescripcionP))
	{

		printf("%d   %d	    %d	  %-13s   %-6s   %-6s  %d   %-2d       %d/%02d/%d\n",
				unSoloAvion.idAvion,
				unSoloAvion.matricula,
				unSoloAvion.cantAsientos,//falta una desc de piloto
				copiarDescripcionM,
				copiarDescripcionV,
				copiarDescripcionP,
				unSoloAvion.idPiloto,
				unSoloAvion.modelo,
				unSoloAvion.fechaS.dia,
				unSoloAvion.fechaS.mes,
				unSoloAvion.fechaS.anio);
	}

}

//busca el avion x medio de la matricula si existe devuelve el indice sino 0
int buscarUnaMatricula(Avion aviones[], int tamAvion, int matricula)
{
    int indice = -1;

    if(aviones != NULL && tamAvion > 0)
    {
    	for(int i = 0; i < tamAvion; i++)
    	{
            if(aviones[i].matricula == matricula && aviones[i].isEmpty == 0)
    		{
                indice = i;
                break;
            }
        }
    }
    return indice;
}
//modificada
int mostrarAviones(Avion aviones[], int tamAvion, Viaje viaje[] , int tamViaje, Marca marca[], int tamMarca, Piloto pilotos[], int tamPilotos)
{
	int retorno=-1;
	int i;
	int flag = 1;

	printf("ID  MATR  ASIENTOS  MARCA  pilotos    VIAJE  MODELO     FECHA\n");

	ordenarAvionesMarcaYMatricula(aviones, tamAvion, marca, tamMarca);

	for(i = 0; i < tamAvion; i++)
	{

		if(aviones[i].isEmpty == 0)
		{
			mostrarAvion(aviones[i], viaje, tamViaje, marca, tamMarca, pilotos, tamPilotos);
			flag = 0;
			retorno =0;
		}

	}
	if(flag)
	{
		printf("No hay Aviones para mostrar");
    }
	return retorno;
}
//para dar de baja deberia tener aviones cargados hardcodeados p mostrar y elegir cual dar d baja
int bajaAvion(Avion aviones[],int tamAvion, Viaje viajes[], int tamViaje,Marca marcas[], int tamMarca,Piloto pilotos[], int tamPilotos)
{
	int ok = 0;
	int indice = -1;
	int rta=1;
	int matricula;

	printf("Ingrese Nro de matricula: \n");
	fflush(stdin);
	scanf("%d", &matricula);

	while(buscarUnaMatricula(aviones, tamAvion, matricula) == -1)
	{
		printf("Error. Reingrese  Nro de Matricula: ");
		fflush(stdin);
		scanf("%d", &matricula);
	}

	if(aviones != NULL && tamAvion > 0 && viajes != NULL && tamViaje > 0 && marcas !=  NULL && tamMarca > 0)
	{

			indice = buscarUnaMatricula(aviones, tamAvion, matricula);

			if(indice == -1)
			{
				printf("Errror.No existe  : %d", matricula);
			}
			else
			{
				mostrarAvion(aviones[indice], viajes, tamViaje, marcas, tamMarca,pilotos, tamPilotos);
			printf("Desea dar de baja? 1= si\n");
			if(rta == 1)
			{
				aviones[indice].isEmpty = 1;
				ok = 1;
			}
			else
			{
				printf("Ha cancelado la baja?\n");
			}

		}
	}
	return ok;
}
int buscarindiceMarcas(Marca marcas[],int tamMarca, int idMarcaDeAvion)
{
	int i;
	int retorno =-1;

	if(marcas != NULL && tamMarca > 0 && idMarcaDeAvion >= 0)
	{
		for(i=0; i< tamMarca; i++)
		{
			if(idMarcaDeAvion == marcas[i].idMarca)
			{
				retorno = i;
			}
		}
	}
	return retorno;
}


void ordenarAvionesMarcaYMatricula(Avion aviones[], int tamAvion, Marca marcas[], int tamMarca)
{
	Avion aux;
	int i;
	int j;
	int indiceI;
	int indiceJ;

	for(i = 0; i < tamAvion - 1; i++)
	{
		for(j = i + 1; j < tamAvion; j++)
		{
			indiceI = buscarindiceMarcas(marcas, tamMarca,aviones[i].idMarca);
			indiceJ = buscarindiceMarcas(marcas, tamMarca,aviones[j].idMarca);

			if(strcmp(marcas[indiceI].descripcion, marcas[indiceJ].descripcion)> 0)
			{
				aux = aviones[i];
				aviones[i] = aviones[j];
				aviones[j] = aux;
			}

			if(strcmp(marcas[indiceI].descripcion,marcas[indiceJ].descripcion) == 0 && aviones[i].matricula > aviones[j].matricula)
			{
				aux = aviones[i];
				aviones[i] = aviones[j];
				aviones[j] = aux;
			}
		}
	}

}

































