#include<stdio.h>
#include <stdlib.h>
#include "declaraciones.h"

int main(){
  GList ListaDePersonas=lectura_archivo();
  /*for ( GList i = ListaDePersonas; i!=NULL; i=i->sig) {
    printf("%s %d %s\n", ((Persona*) i->dato)->nombre, ((Persona*)i->dato)->edad,((Persona*)i->dato)->lugarDeNacimiento);
  }*/
  //GList nuevaLista = glist_crear();
  
  char nombre1[30]="ocultanombre.txt";
  char nombre2[30]="aumentaedad.txt";

  mapear_lista(ListaDePersonas, ocultar_nombre, copiar_nodo, nombre1);
  mapear_lista(ListaDePersonas, aumentar_edad, copiar_nodo, nombre2);

  for ( GList i = ListaDePersonas; i!=NULL; i=i->sig) {
    printf("%s %d %s\n", ((Persona*) i->dato)->nombre, ((Persona*)i->dato)->edad,((Persona*)i->dato)->lugarDeNacimiento);
  }
  test_empieza_con_a();
  test_es_mayor_de_edad();
  return 1;
}
