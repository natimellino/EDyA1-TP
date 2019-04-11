#include <stdlib.h>

typedef struct {
	char *nombre, *lugarDeNacimiento;
	int edad;
}Persona;


typedef struct _GNodo{
  void* dato;
  struct _GNodo *sig;
} GNodo;

typedef GNodo *GList;

typedef int (*Predicado) (void* dato);

typedef void* (*Funcion) (void* dato);

typedef void* (*Copia) (void*);

GList map(GList lista, Funcion f, Copia c);

GList filter(GList lista, Predicado p, Copia c);

// Devuelve una lista vacía.

GList glist_crear();

// Destruccion de la lista.
 
void glist_destruir(GList lista);

// Determina si la lista es vacía.

int glist_vacia(GList lista);

// Agrega un elemento al inicio de la lista.
 
GList glist_agregar_inicio(GList lista, void* dato);

int mayor_de_edad(void* dato);

void test_es_mayor_de_edad();

void test_empieza_con_a();

/**
 * Recorrido de la lista, utilizando la funcion pasada.
 */
//void glist_recorrer(GList lista, FuncionVisitante visit);

GList lectura_archivo();

void mostrar_persona(void *dato);

void* aumentar_edad(void* p);

void* ocultar_nombre(void* persona);

int mayor_de_edad(void *dato);

int empieza_con_a(void *dato);

void* copiar_nodo(void* p);

void mapear_lista(GList lista, Funcion f, Copia c, char* nombreArchivo);

void escribir_lista(char* nombreArchivo, GList lista);

