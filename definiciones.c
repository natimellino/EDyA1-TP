#include <stdio.h>
#include <stdlib.h>
#include "declaraciones.h"
#include <string.h>
#include <assert.h>

int glist_vacia(GList lista) {
  return lista == NULL;
}

GList glist_crear() {
  return NULL;
}

GList glist_agregar_inicio(GList lista, void* p) {
  GNodo *nuevoNodo = malloc(sizeof(GNodo));
  nuevoNodo->dato = p;
  nuevoNodo->sig = lista;
  return nuevoNodo;
}

void glist_destruir(GList lista){
	GNodo* nodoAEliminar;
	while(lista != NULL){
		nodoAEliminar = lista;
		lista = lista->sig;
		free(nodoAEliminar);
	}
}

char* reconocer_cadena(int *i, char* linea){
  char* cadena=malloc(sizeof(char)*50);
  assert(cadena != NULL);
  for(; linea[*i]!= ','&& linea[*i]!= '\0' ; (*i)++){
    char *ptr=malloc(sizeof(char));
    (*ptr)=linea[(*i)];
    strcat(cadena, ptr);
  }
  return cadena;
}

// Lee una lista de personas y la guarda en una lista enlazada.

GList lectura_archivo(){
  FILE * fp;
  fp = fopen("personas.txt", "r");
  assert(fp != NULL);
  GList ListaDePersonas=glist_crear();
  char *linea = malloc(sizeof(char)*100);
  assert(linea != NULL);
  int *i=malloc(sizeof(int));
  while (fgets(linea, 100, fp) != NULL && !feof(fp)){
    *(i)=0;
    Persona* p = malloc(sizeof(Persona*));
   	p->nombre = reconocer_cadena(i, linea);
   	*(i)+=2;
   	p->edad = atoi(reconocer_cadena(i, linea));
   	*(i)+=2;
   	p->lugarDeNacimiento = reconocer_cadena(i, linea);
   	int j;
   	for(j = 0; j < strlen(p->lugarDeNacimiento) && p->lugarDeNacimiento[j]!='\n'&& p->lugarDeNacimiento[j] != '\r'; j++);
   	p->lugarDeNacimiento[j] = '\0';

    ListaDePersonas = glist_agregar_inicio(ListaDePersonas,p);
    
  }
  free(linea);
  free(i);
  return ListaDePersonas;
}

// Función para map.

void* aumentar_edad(void* pers){
    ((Persona*)pers)->edad += 10;
    return pers;
}

// Función para map.

void* ocultar_nombre(void* persona){
	for (int i = 0; i < strlen(((Persona*)persona)->nombre); i++){
		((Persona*)persona)->nombre[i] = 'x';
	}
	return persona;
}

// Funcion para filter
int mayor_de_edad(void *dato){
  return (((Persona *) dato)->edad > 18);
}

void test_es_mayor_de_edad(){
	void* pers1 = malloc(sizeof(Persona*));
	((Persona*) pers1)->edad = 21;

	void* pers2 = malloc(sizeof(Persona*));
	((Persona*) pers2)->edad = 13;

	assert(mayor_de_edad(pers1) == 1);
	assert(mayor_de_edad(pers2) == 0);

	free(pers1);
	free(pers2);

}

//Funcion para filter
int empieza_con_a(void *dato){
  return (((Persona *) dato)->nombre[0]=='A');
}

void test_empieza_con_a(){
	void* pers1 = malloc(sizeof(Persona*));
	((Persona*) pers1)->nombre = malloc(sizeof(char)*50);
	((Persona*) pers1)->nombre = "Agustina";

	void* pers2 = malloc(sizeof(Persona*));
	((Persona*) pers2)->nombre = malloc(sizeof(char)*50);
	((Persona*) pers2)->nombre = "Camila";

	assert(empieza_con_a(pers1) == 1);
	assert(empieza_con_a(pers2) == 0);

	free(pers1);
	free(pers2);

}

void* copiar_nodo(void* p){
    void* nuevap = malloc(sizeof(Persona*));
    assert(nuevap != NULL);


    ((Persona*) nuevap)->nombre = malloc(sizeof(char)*50);
    assert(((Persona*) nuevap)->nombre != NULL);
    strcpy(((Persona*) nuevap)->nombre, ((Persona*) p)->nombre);

    ((Persona*) nuevap)->edad = ((Persona*) p)->edad;

    ((Persona*) nuevap)->lugarDeNacimiento = malloc(sizeof(char)*50);
    assert( ((Persona*) nuevap)->lugarDeNacimiento != NULL);
    strcpy(((Persona*) nuevap)->lugarDeNacimiento, ((Persona*) p)->lugarDeNacimiento);

    return nuevap;
}

GList map(GList lista, Funcion f, Copia c){
    GList nuevaLista = glist_crear();
    for(GList i = lista; i != NULL; i = i->sig){
        void* copia = c((i->dato));
        nuevaLista = glist_agregar_inicio(nuevaLista, copia);
    }
    for (GList j = nuevaLista; j != NULL; j = j->sig){
    	f(j->dato);
    }
    return nuevaLista;
}

GList filter(GList lista, Predicado f, Copia c){
  GList listaRetorno=glist_crear();
  for(GList i=lista;i!=NULL;i=i->sig){
    if(f(i->dato)){
      void *nuevoNodo=c(i->dato);
      listaRetorno=glist_agregar_inicio(listaRetorno,nuevoNodo);
    }
  }

  return listaRetorno;
}

void mostrar_persona(void *dato){
  printf("%s %d %s\n", ((Persona *) dato)->nombre, ((Persona *) dato)->edad, ((Persona *) dato)->lugarDeNacimiento);
}


void escribir_lista(char* nombreArchivo, GList lista){
	FILE* fp;
    fp = fopen(nombreArchivo, "w+");
	for(GList i = lista; i != NULL; i = i->sig){
		fprintf(fp, "%s, %d, %s\n", ((Persona*) i->dato)->nombre, ((Persona*) i->dato)->edad, ((Persona*) i->dato)->lugarDeNacimiento);
	}

	fclose(fp);
}

void mapear_lista(GList lista, Funcion f, Copia c, char* nombreArchivo){

    GList nuevaLista = map(lista, f, c);

    escribir_lista(nombreArchivo, nuevaLista);

    glist_destruir(nuevaLista);
}

void filtrar_lista(char *nombreArchivo, Predicado f, GList ListaDePersonas, Copia c){
  GList lista1=filter(ListaDePersonas,f,c);
  escribir_lista(nombreArchivo,lista1);
  glist_destruir(lista1);
}



