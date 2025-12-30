#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
        char valor[12];
        int prioridad;
} Linea;

int main(int argc, char **argv) {
        if (argc != 4) {
                printf("Uso: ./upsert <nom_archivo> <valor> <prioridad>\n");
                exit(1);
        }
        
        FILE *archivo = fopen(argv[1], "r+");
        if (archivo == NULL) {
                archivo = fopen(argv[1], "w+");
                if (archivo == NULL) {
                        perror(argv[1]);  
                        exit(1);
                }
        }
        char *valor = argv[2];
        int prioridad = atoi(argv[3]); 
        int n = 0;
        fread(&n, sizeof(int), 1, archivo);
        int encontrado = 0;
        int pos = 0;

        Linea linea;
        int prioridad_anterior = 0;
        for (int i = 0; i < n; i++) {
                fread(&linea, sizeof(Linea), 1, archivo);
                if (strcmp(linea.valor, valor) == 0) {
                        encontrado = 1;
                        pos = i;
                        prioridad_anterior = linea.prioridad;
                }
                
        }
        if (encontrado == 1) {
                fseek(archivo, sizeof(int) + pos * sizeof(Linea) + 12, SEEK_SET);
                fwrite(&prioridad, sizeof(int), 1, archivo);
                printf("Prioridad de %s actualizada de %d a %d\n", valor, prioridad_anterior, prioridad);
        }
        else {
                Linea nueva_linea;
                for (int i = 0; i < 12; i++) {
                nueva_linea.valor[i] = '\0';
                }
                strcpy(nueva_linea.valor, valor);
                nueva_linea.prioridad = prioridad;
                n++;
                fseek(archivo, 0, SEEK_SET);
                fwrite(&n, sizeof(int), 1, archivo);
                fseek(archivo, 0, SEEK_END);
                fwrite(&nueva_linea, sizeof(Linea), 1, archivo);
                printf("Agregado %s con prioridad %d\n", valor, prioridad);
        }
        fclose(archivo);
        return 0;
}