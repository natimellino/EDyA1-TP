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

// Determina si una persona es mayor de 18 años.

int mayor_de_edad(void* dato);

// Testing

void test_mayor_de_edad();

// Testing

void test_empieza_con_a();

// Lee de un archivo una lista de Personas y la pasa a una lista.

GList lectura_archivo();

// Muestra los datos de una Persona por pantalla.

void mostrar_persona(void *dato);

// Aumenta la edad de una persona en 10 años.

void* aumentar_edad(void* p);

// Oculta el nombre de una Persona poniendo 'x' en las letras de su nombre.

void* ocultar_nombre(void* persona);

// Determina si el nombre de una persona empieza con A.

int empieza_con_a(void *dato);

// Crea una copia del dato recibido.

void* copiar_nodo(void* p);

// Toma una lista, le aplica la función map y vuelva la nueva
// lista en un archivo.

void mapear_lista(GList lista, Funcion f, Copia c, char* nombreArchivo);

// Toma una lista, le aplica la función map y vuelva la nueva
// lista en un archivo.

void filtrar_lista(char *nombreArchivo, Predicado f, GList ListaDePersonas, Copia c);

// Recibe una lista y la escribe en un archivo.

void escribir_lista(char* nombreArchivo, GList lista);

