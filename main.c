#include<stdio.h>
#include <stdlib.h>
#include "declaraciones.h"

int main(){
  GList ListaDePersonas=lectura_archivo();
  /*for ( GList i = ListaDePersonas; i!=NULL; i=i->sig) {
    printf("%s %d %s\n", ((Persona*) i->dato)->nombre, ((Persona*)i->dato)->edad,((Persona*)i->dato)->lugarDeNacimiento);
  }*/
  GList nuevaLista = glist_crear();
  
  nuevaLista = map(ListaDePersonas, aumentar_edad, copiar_nodo);
  char nombre1[30]="aumentaedad.txt";
  archivo_salida(nuevaLista, nombre1);

  nuevaLista = map(ListaDePersonas, ocultar_nombre, copiar_nodo);
  char nombre2[30]="ocultanombre.txt";
  archivo_salida(nuevaLista, nombre2);

  /*for (GList i = nuevaLista; i != NULL; i = i->sig){
  	printf("%s %d %s", ((Persona*)i->dato)->nombre, ((Persona*)i->dato)->edad, ((Persona*)i->dato)->lugarDeNacimiento);

  }*/
  return 1;
}
