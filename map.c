#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "map.h"

void copy_map(MAP* new_map, MAP* origin_map){
    new_map->lines = origin_map->lines;
    new_map->columns = origin_map->columns;
    
    allocate_map(new_map);
    for(int line = 0; line < origin_map->lines; line++){
        strcpy(new_map->matrix[line], origin_map->matrix[line]);
    }
    free_map(new_map);
}

void move_in_the_map(MAP* map, int origin_line, int origin_column, int next_line, int next_column){
    char character = map->matrix[origin_line][origin_column];
    map->matrix[next_line][next_column] = character;
    map->matrix[origin_line][origin_column] = EMPTY;
}

int able_to_move(MAP* map, char character, int line, int column){
    return (
        next_position_is_valid(map, line, column) &&
        !next_position_is_wall(map, line, column) &&
        !next_position_is_character(map, character, line, column)
    );
}

int next_position_is_empty(MAP* map, int line, int column){
    return (map->matrix[line][column] == EMPTY);
}

int next_position_is_valid(MAP* map, int line, int column){
    if(line >= map->lines)
        return 0;
    if(column >= map->columns)
        return 0;
    return 1;
}

int next_position_is_wall(MAP* map, int line, int column){
    return (
        map->matrix[line][column] == HORIZONTAL_WALL ||
        map->matrix[line][column] == VERTICAL_WALL
    );
}

int next_position_is_character(MAP* map, char character, int line, int column){
    return (map->matrix[line][column] == character);
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

int find_character_in_map(MAP* map, POSITION* position, char letter){
    for(int line = 0; line < map->lines; line++){
        for(int column = 0; column < map->columns; column++){
            if(map->matrix[line][column] == letter){
                position->line = line;
                position->column = column;
                return 1;
            }
        }
    }
    return 0;
}
