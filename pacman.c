#include <stdio.h>
#include <stdlib.h>
#include "pacman.h"

struct map map;
 
int main(){
    read_map();
    do{
        print_map();
        char command;
        scanf(" %c", &command);
        move(command);
    }while(!game_is_over());
    
    free_map();
}

void read_map(){
    FILE* file;
    file = fopen("map.txt", "r");//"r" means "read"
    if(file == 0){
        printf("Game map not found.\n");
        exit(1);
    }

    fscanf(file, "%d %d", &(map.lines), &(map.columns));
    allocate_map();

    for(int i = 0; i < map.lines; i++){
        fscanf(file, "%s", map.matrix[i]);
    }
    fclose(file); 
}

void allocate_map(){
    map.matrix = malloc(sizeof(char*) * map.lines);
    for(int i = 0; i < map.lines; i++){
        map.matrix[i] = malloc(sizeof(char) * (map.columns + 1));
    }
}

void free_map(){
    for(int i = 0; i < map.lines; i++){
        free(map.matrix[i]);
    }
    free(map.matrix);
}

void print_map(){
    for(int i = 0; i < map.lines; i++){
        printf("%s\n", map.matrix[i]);
    }
}

int game_is_over(){
    return 0;
}

void move(char command){
    int line;
    int column;

    find_character(&line, &column);
    switch(command){
        case 'w': //UP
            map.matrix[line - 1][column] = '@';
            break;
        case 'a': //LEFT
            map.matrix[line][column - 1] = '@';
            break;
        case 's': //DOWN
            map.matrix[line + 1][column] = '@';
            break;
        case 'd': //RIGHT
            map.matrix[line][column + 1] = '@';
            break;
    }

    map.matrix[line][column] = '.';
}

void find_character(int* x, int* y){
    for(int line = 0; line < map.lines; line++){
        for(int column = 0; column < map.columns; column++){
            if(map.matrix[line][column] == '@'){
                (*x) = line;
                (*y) = column;
            }
        }
    }
}
