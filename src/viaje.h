

#ifndef VIAJE_H_
#define VIAJE_H_

typedef struct{
	int idViaje;
	char descripcionViaje[25];
	float kms;
	int isEmpty;
}Viaje;
void mostrarViaje(Viaje unSoloViaje);
void mostrarViajes(Viaje viajes[], int tam);
int validarBuscarIdViajes(int id, Viaje viajes[], int tam );
//int validarBuscarIdViajes(Viaje viajes[], int tam, int id );
int copiarProvinciaViaje(int id, Viaje viajes[], int tam, char descripcionProvincia[]);
#endif /* VIAJE_H_ */
