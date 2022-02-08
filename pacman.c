#include <stdio.h>
#include <stdlib.h>
#include "pacman.h"
#include "map.h"

MAP map;
POSITION position;

int main(){
    read_map(&map);
    find_character_in_map(&map, &position, '@');

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
    int invalidCommand = (command != 'w' && command != 'a' && command != 's' && command != 'd');
    if(invalidCommand)
        return;

    map.matrix[position.line][position.column] = '.';
    switch(command){
        case 'w': //UP
            map.matrix[position.line - 1][position.column] = '@';
            position.line--;
            break;
        case 'a': //LEFT
            map.matrix[position.line][position.column - 1] = '@';
            position.column--;
            break;
        case 's': //DOWN
            map.matrix[position.line + 1][position.column] = '@';
            position.line++;
            break;
        case 'd': //RIGHT
            map.matrix[position.line][position.column + 1] = '@';
            position.column++;
            break;
    }
}
