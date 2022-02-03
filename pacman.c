#include <stdio.h>
#include <stdlib.h>
#include "pacman.h"

char** map;
int lines;
int columns;

int main(){
    read_map();

    for(int i = 0; i < lines; i++){
        printf("%s\n", map[i]);
    }

    free_map();
}

void read_map(){
    FILE* file;
    file = fopen("map.txt", "r");//"r" means "read"
    if(file == 0){
        printf("Game map not found.\n");
        exit(1);
    }

    fscanf(file, "%d %d", &lines, &columns);

    allocate_map();

    for(int i = 0; i < lines; i++){
        fscanf(file, "%s", map[i]);
    }
    fclose(file); 
}

void allocate_map(){
    map = malloc(sizeof(char*) * lines);
    for(int i = 0; i < lines; i++){
        map[i] = malloc(sizeof(char) * (columns + 1));
    }
}

void free_map(){
    for(int i = 0; i < lines; i++){
        free(map[i]);
    }
    free(map);
}
