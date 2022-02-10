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

int is_a_valid_command(char command){
    return (command == 'w' || command == 'a' || command == 's' || command == 'd');
}

void move(char command){
    if(!is_a_valid_command(command))
        return;

    int next_line = position.line;
    int next_column = position.column;

    switch(command){
        case 'w': //UP
            next_line--;
            break;
        case 'a': //LEFT
            next_column--;
            break;
        case 's': //DOWN
            next_line++;
            break;
        case 'd': //RIGHT
            next_column++;
            break;
    }
    if(next_line >= map.lines)
        return;
    if(next_column >= map.columns)
        return;
    if(map.matrix[next_line][next_column] != '.')
        return;
    
    map.matrix[next_line][next_column] = '@';
    map.matrix[position.line][position.column] = '.';
    position.line = next_line;
    position.column = next_column;
}
