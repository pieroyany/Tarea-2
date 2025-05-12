#include "tdas/extra.h"
#include "tdas/list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
    k++;
  }

  fclose(archivo);
  printf("%d canciones cargadas correctamente.\n", k);
  presioneTeclaParaContinuar();
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
  printf("5: Salir\n");
}

void mostrar_cancion(cancion *c) {
  printf("\nID: %s", c->id);
  printf("\nTitulo: %s", c->titulo);
  printf("\nArtistas: ");
  for (char *art = list_first(c->artistas); art != NULL; art = list_next(c->artistas)) {
      printf("%s ", art);
  }
  printf("\nalbum: %s", c->album);
  printf("\nGenero: %s", c->genero);
  printf("\nTempo: %.2f BPM", c->tempo);
  printf("\n----------------------------------------");
}

void buscar_por_genero(List *lista) {
  limpiarPantalla();
  if (lista == NULL || list_size(lista) == 0) {
    printf("\nNo hay canciones cargadas. Primero cargue las canciones.\n");
    presioneTeclaParaContinuar();
    return;
  }

  char genero[100];
  printf("\nIngrese el genero a buscar: ");
  scanf(" %[^\n]", genero);

  int encontradas = 0;
  int contador = 0;
  char opcion;
    
  cancion *c = list_first(lista);
  while (c != NULL) {
    char genero_cancion[300];
    char genero_busqueda[100];
    strcpy(genero_cancion, c->genero);
    strcpy(genero_busqueda, genero);
        
    for(int i = 0; genero_cancion[i]; i++) genero_cancion[i] = tolower(genero_cancion[i]);
    for(int i = 0; genero_busqueda[i]; i++) genero_busqueda[i] = tolower(genero_busqueda[i]);
        
    if (strstr(genero_cancion, genero_busqueda) != NULL) {
      mostrar_cancion(c);
      encontradas++;
      contador++;

      // Pausa cada 5 canciones
      if (contador % 5 == 0) {
        printf("\nPresione 's' para ver mas resultados o cualquier tecla para volver al menu...");
        scanf(" %c", &opcion);
        if (tolower(opcion) != 's') {
          break;
        }
        limpiarPantalla();
        printf("Resultados para genero: %s (continuacion)\n", genero);
        puts("========================================");
        }
    }
    c = list_next(lista);
    }

    if (encontradas == 0) {
      printf("\nNo se encontraron canciones del genero '%s'\n", genero);
    } else {
      printf("\nTotal encontradas: %d\n", encontradas);
    }
    presioneTeclaParaContinuar();
}

void buscar_por_artista(List *lista) {
  limpiarPantalla();
  char artista[100];
  printf("Ingrese el artista a buscar: ");
  scanf(" %[^\n]", artista);

  int encontradas = 0;
  cancion *c = list_first(lista);
  while (c != NULL) {
      List *artistas = c->artistas;
      char *art = list_first(artistas);
      while (art != NULL) {
          if (strcasecmp(art, artista) == 0) {
              mostrar_cancion(c);
              encontradas++;
              break;
          }
          art = list_next(artistas);
      }
      c = list_next(lista);
  }

  if (!encontradas) {
      printf("\nNo se encontraron canciones del artista '%s'\n", artista);
  }
  presioneTeclaParaContinuar();
}

void buscar_por_tempo() {
  float tempo;
  printf("Ingrese el tempo de la cancion: ");
  scanf("%f", &tempo);
}

void salir(List *canciones) {
  if (canciones != NULL) {
      cancion *c;
      while (c = list_popFront(canciones)) {
          list_clean(c->artistas);
          free(c->artistas);
          free(c);
      }
      free(canciones);
  }
  printf("Saliendo del programa...\n");
  exit(0);
}

int main() {
  char opcion;
  List* canciones = NULL;
  do {
    menuPrincipal();
    scanf(" %c", &opcion);

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
        buscar_por_tempo();
        break;
      case '5':
        salir(canciones);
        break;
      default:
        printf("Opcion no valida. Intente de nuevo.\n");
        presioneTeclaParaContinuar();
    }
  } while (1);

  return 0;
}