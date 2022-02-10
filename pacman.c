#include <stdio.h>
#include <stdlib.h>
#include "pacman.h"
#include "map.h"

MAP map;
POSITION position;

int main(){
    read_map(&map);
    find_character_in_map(&map, &position);

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
    return (command == UP || command == LEFT || command == DOWN || command == RIGHT);
}

void move(char command){
    if(!is_a_valid_command(command))
        return;

    int next_line = position.line;
    int next_column = position.column;

    switch(command){
        case UP:
            next_line--;
            break;
        case LEFT:
            next_column--;
            break;
        case DOWN:
            next_line++;
            break;
        case RIGHT:
            next_column++;
            break;
    }
    
    if(!next_position_is_valid(&map, next_line, next_column))
        return;
    
    move_in_the_map(&map, position.line, position.column, next_line, next_column);
    position.line = next_line;
    position.column = next_column;
}
