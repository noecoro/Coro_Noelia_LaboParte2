#ifndef AVION_H_
#define AVION_H_
#include "marca.h"
#include "viaje.h"
#include "piloto.h"

#include <string.h>

typedef struct
{
	int dia;
	int mes;
	int anio;
}Fecha;

typedef struct
{
	int idAvion;
	int matricula;
	int idViaje;
	int idMarca;
	int modelo;
	int idPiloto;// agregado
	int isEmpty;
	Fecha fechaS;
	int cantAsientos;
}Avion;

void iniAviones(Avion aviones[], int tam);
int avionesRegistrados(Avion aviones[], int tam);
int buscarIndiceLibreAvion(Avion aviones[], int tam);
int buscarAvionId(Avion aviones[], int tam, int id);
int altaAvion(Avion aviones[], int tamAvion, Marca marca[], int tamMarca, Viaje viajes[], int tamViaje, int* punteroId, Piloto pilotos[], int tamPilotos);
void mostrarAvion(Avion unSoloAvion, Viaje viaje[],int tamViaje, Marca marca[], int tamMarca, Piloto pilotos[], int tamPilotos);
int buscarUnaMatricula(Avion aviones[], int tamAvion, int id);
int mostrarAviones(Avion aviones[], int tamAvion, Viaje viaje[] , int tamViaje, Marca marca[], int tamMarca, Piloto pilotos[], int tamPilotos);
//int mostrarAviones(Avion aviones[], int tamAvion, Viaje viaje[] , int tamViaje, Marca marca[], int tamMarca,Piloto pilotos, int tamPilotos);
//int modificarAvion(Avion aviones[], int tamAvion, Viaje viaje[], int tamViaje,Marca marca[], int tamMarca);

int modificarAvion(Avion aviones[], int tamAvion, Viaje viaje[], int tamViaje,Marca marca[], int tamMarca, Piloto pilotos[], int tamPilotos);
int bajaAvion(Avion aviones[],int tamAvion, Viaje viajes[], int tamViaje,Marca marcas[], int tamMarca,Piloto pilotos[], int tamPilotos);
//int bajaAvion(Avion aviones[],int tamAvion, Viaje viajes[], int tamViaje,Marca marcas[], int tamMarca);
void ordenarAvionesMarcaYMatricula(Avion aviones[], int tamAvion, Marca marcas[], int tamMarca);
#endif /* AVION_H_ */
