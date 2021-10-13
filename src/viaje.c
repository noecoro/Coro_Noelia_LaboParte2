#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "marca.h"
#include "avion.h"
#include "viaje.h"

void mostrarViaje(Viaje unSoloViaje)
{

    printf("%d  %-10s  %.2fKms\n", unSoloViaje.idViaje, unSoloViaje.descripcionViaje, unSoloViaje.kms);

}
void mostrarViajes(Viaje viajes[], int tam)
{
	printf("id    viaje     kms \n");
	for (int i = 0; i < tam; i ++)
	{
		mostrarViaje(viajes[i]);
	}
}

int validarBuscarIdViajes(int id, Viaje viajes[], int tam )
{

    int rta = 0;

    if(viajes != NULL && tam > 0 && id >= 100 && id <= 104)
    {

        for(int i = 0; i < tam; i++)
        {
            if(viajes[i].idViaje == id)
            {
                rta = 1;
                break;
            }
        }
    }
    return rta;
}
//cargar
int copiarProvinciaViaje(int id, Viaje viajes[], int tam, char descripcionProvincia[])
{
    int ok = 0;

    if(id >= 100 && id <= 104 && viajes != NULL && tam > 0 && descripcionProvincia != NULL  )
    {

        for(int i = 0; i < tam; i++)
        {
            if(viajes[i].idViaje == id)
            {
                strcpy(descripcionProvincia, viajes[i].descripcionViaje);
                ok = 1;
                break;
            }
        }
    }

    return ok;
}

