
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <ctype.h>
#include "marca.h"

void mostrarUnaMarca(Marca unaSolaMarca)
{
    printf("%d      %-10s\n", unaSolaMarca.idMarca, unaSolaMarca.descripcion);
}
void mostrarMarcas(Marca marcas[], int tam)
{
    printf("ID       Descripcion\n");

    for(int i = 0; i < tam; i++){

       mostrarUnaMarca(marcas[i]);
    }
}
int validarBuscarIdMarca(Marca marca[], int tam,int id)
{
    int rta = 0;

    if(marca != NULL && tam > 0 && id >= 1000 && id <= 1003)
    {
        for(int i = 0; i < tam; i++){
            if(marca[i].idMarca == id){
                rta = 1;
                break;
            }
        }
    }
    return rta;
}

int copiarNombreMarca(int id, Marca marca[],int tam, char descripcionNombreMarca[])
{
	int ok = 0;
	int i;
	if (id >= 1000 && id <= 1003 && marca != NULL && tam> 0 && descripcionNombreMarca != NULL )
	{
		for(i = 0; i < tam; i++)
		{
			if(marca[i].idMarca == id)
			{
				strcpy(descripcionNombreMarca,marca[i].descripcion);
				ok = 1;
				break;
			}
		}
	}
	return ok;
}
















