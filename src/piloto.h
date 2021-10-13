
#ifndef PILOTO_H_
#define PILOTO_H_

typedef struct
{
	int idDni;
	char nombre[20];
}Piloto;


void mostrarPiloto(Piloto unSoloPiloto);
void mostrarPilotos(Piloto pilotos[], int tamPilotos);
int validarBuscarIdPiloto(int id, Piloto pilotos[], int tamPiloto );
int copiarNombrePiloto(int id, Piloto pilotos[], int tam, char descripcionNombrePiloto[]);

#endif /* PILOTO_H_ */
