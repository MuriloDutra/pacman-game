#include <stdio.h>
#include <stdlib.h>
#include "pacman.h"
#include "map.h"

MAP map;
 
int main(){
    read_map(&map);
    do{
        print_map(&map);
        char command;
        scanf(" %c", &command);
        move(command);
    }while(!game_is_over());
    
    free_map(&map);
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
