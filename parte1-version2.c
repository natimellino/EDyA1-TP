#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <locale.h>

#define MIN_PERSONAS 2000
#define MAX_PERSONAS 3000


//Declaracion de funciones
char ** archivoEntrada( char **array,  char *nombreArchivo, int *cant, int size);
void archivoSalida(char **nombres, char **paises, int *cantNombres, int *cantPaises);
int elegir_numero(int min, int max);

int main(){
	srand(time(NULL));
	int *cantNombres=malloc(sizeof(int)), *cantPaises=malloc(sizeof(int)), minN=2000,minP=400;
	char **nombres=NULL, **paises=NULL;
	nombres= malloc(sizeof(char*)*MIN_PERSONAS);
	paises= malloc(sizeof(char*)*MIN_PAISES);
	nombres=archivoEntrada(nombres,"nombres.txt",cantNombres,minN);
	printf("%d\n", *cantNombres );
	paises=archivoEntrada(paises, "paises.txt",cantPaises,minP);
	/*for (int i = 0; i < (*cantNombres); ++i)
	{
		printf("entra for\n");
		printf("%s\n", nombres[i] );
		printf("%d\n", i);
	}*/

	archivoSalida(nombres, paises, cantNombres, cantPaises);

	return 1;
}

char** archivoEntrada(char **array,  char* nombreArchivo, int *cant, int size){
	int lineas=0,i=0;
	char linea[50];
	FILE * fp;
	fp = fopen(nombreArchivo, "r");

	while (!feof(fp)){
			char *c=malloc(sizeof(char));
    	*c=fgetc(fp);
			if(lineas>=size){
				array=realloc(array, sizeof(char*)*(lineas+(size/2)));
				size+=size/2;
			}
			if(isalpha(*c)){
				linea[i]=*c;
				i++;
			}
			elseif(*c=='\r'||*c=='\n'){
				linea[i] = '\0';
				int len=strlen(linea);
				array[lineas] = malloc(sizeof(char) * (len+1));
				strcpy(array[lineas],linea);
				i=0;
				lineas++;
			}

	}


	fclose(fp);
	(*cant)=lineas;
	return array;
}

void archivoSalida(char **nombres, char **paises, int *cantNombres, int *cantPaises){
	int cantPersonas, n, p, edad;
	cantPersonas=elegir_numero(MIN_PERSONAS, MAX_PERSONAS);
	FILE * fp;
	fp=fopen("personas.txt", "w+");
	for(int i = 0; i < cantPersonas; i++){
		n=elegir_numero(0, *(cantNombres)-1);
		p=elegir_numero(0, *(cantPaises)-1);
		edad=elegir_numero(0, 100);
		fprintf(fp, "%s, %d, %s\n", nombres[n], edad, paises[p]);
	}
	fclose(fp);
	return;
}
// Devuelve un número aleatorio entre min y max (incluyendo a ambos).
int elegir_numero(int min, int max){
	int numero;
	numero = rand() % (max-min+1) + min;
	return numero;
}
