#include "tdas/extra.h"
#include "tdas/list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char id[100];
  char titulo[100];
  List *artistas;
  char album[300];
  char genero[300];
  float tempo;
} cancion;

List* leer_canciones() {
  char ruta[300];
  printf("Ingrese la ruta del archivo CSV: ");
  scanf(" %[^\n]", ruta);

  FILE *archivo = fopen(ruta, "r");
  if (archivo == NULL) {
    perror("Error al abrir el archivo");
    return NULL;
  }

  List* lista_canciones = list_create();
  char **campos;

  // Leer encabezado
  campos = leer_linea_csv(archivo, ',');

  int k = 0;
  while ((campos = leer_linea_csv(archivo, ',')) != NULL) {
    k++;
    if (k > 1000) break;

    cancion* nueva = (cancion*) malloc(sizeof(cancion));
    if (!nueva) {
      perror("Error al asignar memoria");
      fclose(archivo);
      return lista_canciones;
    }

    strcpy(nueva->id, campos[0]);
    strcpy(nueva->titulo, campos[4]);
    nueva->artistas = split_string(campos[2], ";");
    strcpy(nueva->album, campos[3]);
    strcpy(nueva->genero, campos[20]);
    nueva->tempo = atof(campos[18]);

    list_pushBack(lista_canciones, nueva);
  }

  fclose(archivo);
  printf("%d canciones cargadas correctamente.\n", k);
  return lista_canciones;
}


void menuprincipal() {
  limpiarPantalla();
  puts("========================================");
  puts("     Bienvenido A Spotifind");
  puts("========================================");

  printf("Ingrese su opción: \n");

  printf("1: Leer canciones\n");
  printf("2: Buscar por género\n");
  printf("3: Buscar por artista\n");
  printf("4: Buscar por tempo\n");
  printf("5: Salir\n");
}

void buscar_por_genero() {
  char genero[100];
  printf("Ingrese el género de la canción: ");
  scanf("%s", genero);
}

void buscar_por_artista() {
  char artista[100];
  printf("Ingrese el artista de la canción: ");
  scanf("%s", artista);
}

void buscar_por_tempo() {
  float tempo;
  printf("Ingrese el tempo de la canción: ");
  scanf("%f", &tempo);
}

void mostrarTodas(){
}

void salir() {
  printf("Saliendo...\n");
  exit(0);
}

int main() {
  char opcion;
  do {
    menuprincipal();
    scanf(" %c", &opcion);
    List* canciones = NULL;

    switch (opcion) {
      case '1':
      canciones = leer_canciones();
      break;
      case '2':
        buscar_por_genero(canciones);
        break;
      case '3':
        buscar_por_artista(canciones);
        break;
      case '4':
        buscar_por_tempo(canciones);
        break;
      case '5':
        mostrarTodas(canciones);
        break;
      case '6':
        salir();
      default:
        printf("Opción no válida. Intente de nuevo.\n");
    }
  } while (opcion != '0');

  return 0;
}