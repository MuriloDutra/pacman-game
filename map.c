#include <stdio.h>
#include <stdlib.h>
#include "map.h"

void move_in_the_map(MAP* map, int origin_line, int origin_column, int next_line, int next_column){
    char character = map->matrix[origin_line][origin_column];
    map->matrix[next_line][next_column] = character;
    map->matrix[origin_line][origin_column] = EMPTY;
}

int next_position_is_valid(MAP* map, int line, int column){
    if(line >= map->lines)
        return 0;
    if(column >= map->columns)
        return 0;
    if(map->matrix[line][column] != EMPTY)
        return 0;
    return 1;
}

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

void find_character_in_map(MAP* map, POSITION* position){
    for(int line = 0; line < map->lines; line++){
        for(int column = 0; column < map->columns; column++){
            if(map->matrix[line][column] == HERO){
                position->line = line;
                position->column = column;
            }
        }
    }
}
