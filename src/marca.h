#ifndef MARCA_H_
#define MARCA_H_

typedef struct
{
	int idMarca;
	char descripcion[20];
}Marca;

void mostrarUnaMarca(Marca unaSolaMarca);
void mostrarMarcas(Marca marcas[], int tam);
int validarBuscarIdMarca(Marca marca[], int tam,int id);
int copiarNombreMarca(int id, Marca marca[],int tam, char descripcionNombreMarca[]);
#endif /* MARCA_H_ */
