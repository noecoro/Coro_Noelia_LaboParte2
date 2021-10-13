#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "piloto.h"

void mostrarPiloto(Piloto unSoloPiloto)
{

    printf("%d  %-10s  \n",unSoloPiloto.idDni, unSoloPiloto.nombre);

}


void mostrarPilotos(Piloto pilotos[], int tamPilotos)
{
	printf("idDni    piloto    \n");
	for (int i = 0; i < tamPilotos; i ++)
	{
		mostrarPiloto(pilotos[i]);
	}
}
int validarBuscarIdPiloto(int id, Piloto pilotos[], int tamPiloto )
{

    int rta = 0;

    if(pilotos!= NULL && tamPiloto > 0 && id >= 1 && id <= 4)
    {

        for(int i = 0; i < tamPiloto; i++)
        {
            if(pilotos[i].idDni == id)
            {
                rta = 1;
                break;
            }
        }
    }
    return rta;
}

int copiarNombrePiloto(int id, Piloto pilotos[], int tam, char descripcionNombrePiloto[])
{
    int ok = 0;

    if(id >= 1 && id <= 4 && pilotos != NULL && tam > 0 && descripcionNombrePiloto != NULL  )
    {

        for(int i = 0; i < tam; i++)
        {
            if(pilotos[i].idDni == id)
            {
                strcpy(descripcionNombrePiloto, pilotos[i].nombre);
                ok = 1;
                break;
            }
        }
    }

    return ok;
}

