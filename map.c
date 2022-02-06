#include <stdio.h>
#include <stdlib.h>
#include "map.h"

void read_map(MAP* map){
    FILE* file;
    file = fopen("map.txt", "r");//"r" means "read"
    if(file == 0){
        printf("Game map not found.\n");
        exit(1);
    }

    fscanf(file, "%d %d", &(map->lines), &(map->columns));
    allocate_map(map);

    for(int i = 0; i < map->lines; i++){
        fscanf(file, "%s", map->matrix[i]);
    }
    fclose(file); 
}

void allocate_map(MAP* map){
    map->matrix = malloc(sizeof(char*) * map->lines);
    for(int i = 0; i < map->lines; i++){
        map->matrix[i] = malloc(sizeof(char) * (map->columns + 1));
    }
}

void free_map(MAP* map){
    for(int i = 0; i < map->lines; i++){
        free(map->matrix[i]);
    }
    free(map->matrix);
}

void print_map(MAP* map){
    for(int i = 0; i < map->lines; i++){
        printf("%s\n", map->matrix[i]);
    }
}
