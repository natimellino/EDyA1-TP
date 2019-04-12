#include<stdio.h>
#include <stdlib.h>
#include "declaraciones.h"

int main(){
  GList ListaDePersonas=lectura_archivo();
  /*for ( GList i = ListaDePersonas; i!=NULL; i=i->sig) {
    printf("%s %d %s\n", ((Persona*) i->dato)->nombre, ((Persona*)i->dato)->edad,((Persona*)i->dato)->lugarDeNacimiento);
  }*/
  //GList nuevaLista = glist_crear();
  
  char nombre1[17]="ocultanombre.txt";
  char nombre2[16]="aumentaedad.txt";

  mapear_lista(ListaDePersonas, ocultar_nombre, copiar_nodo, nombre1);
  mapear_lista(ListaDePersonas, aumentar_edad, copiar_nodo, nombre2);

  char nombre3[18]="mayoresedad.txt";
  char nombre4[16]="nombresconA.txt";

  filtrar_lista(nombre3, mayor_de_edad, ListaDePersonas, copiar_nodo);
  filtrar_lista(nombre4, empieza_con_a, ListaDePersonas, copiar_nodo);

  /*for ( GList i = ListaDePersonas; i!=NULL; i=i->sig) {
    printf("%s %d %s\n", ((Persona*) i->dato)->nombre, ((Persona*)i->dato)->edad,((Persona*)i->dato)->lugarDeNacimiento);
  }*/

  // Testing:
  test_empieza_con_a();
  test_mayor_de_edad();
  return 1;
}
