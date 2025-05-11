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


void menuPrincipal() {
  limpiarPantalla();
  puts("========================================");
  puts("     Bienvenido A Spotifind");
  puts("========================================");

  printf("Ingrese su opcion: \n");

  printf("1: Leer canciones\n");
  printf("2: Buscar por genero\n");
  printf("3: Buscar por artista\n");
  printf("4: Buscar por tempo\n");
  printf("5: Mostrar todas las canciones\n");
  printf("6: Salir\n");
}

void buscar_por_genero(lista) {
  char genero[100];
  printf("Ingrese el género de la canción: ");
  scanf("%s", genero);
}

void buscar_por_artista(lista) {
  char artista[100];
  printf("Ingrese el artista de la canción: ");
  scanf("%s", artista);
}

void buscar_por_tempo(lista) {
  float tempo;
  printf("Ingrese el tempo de la canción: ");
  scanf("%f", &tempo);
}

void mostrar_Todas(List *lista) {
  if (!lista || list_size(lista) == 0) {
    printf("No hay canciones para mostrar.\n");
    return;
  }

  int count = 0;
  char opcion;

  for (cancion *c = list_first(lista); c != NULL; c = list_next(lista)) {
    printf("ID: %s\n", c->id);
    printf("Título: %s\n", c->titulo);
    printf("Artistas:\n");
    for (char *artista = list_first(c->artistas); artista != NULL; artista = list_next(c->artistas)) {
      printf("  - %s\n", artista);
    }
    printf("Álbum: %s\n", c->album);
    printf("Género: %s\n", c->genero);
    printf("Tempo: %.2f\n", c->tempo);
    printf("------------------------------------------------\n");

    count++;
    if (count % 10 == 0) {
      printf("¿Deseas ver más canciones? (s/n): ");
      scanf(" %c", &opcion);
      if (opcion != 's' && opcion != 'S') break;
    }
  }
}


void salir() {
  printf("Saliendo...\n");
  exit(0);
}

int main() {
  char opcion;
  do {
    menuPrincipal();
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