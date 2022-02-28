#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pacman.h"
#include "map.h"

MAP map;
POSITION position;
int has_pill = 0;
 
int main(){
    read_map(&map);
    find_character_in_map(&map, &position, HERO);

    do{
        printf("PILLS: %s\n", has_pill ? "yes" : "no");
        print_map(&map);
        char command;
        scanf(" %c", &command);
        move(command);
        if(command == BOMB)
            handle_bomb();
        ghosts();
    }while(!game_is_over());
    
    free_map(&map);
}

int game_is_over(){
    POSITION aux;
    return !find_character_in_map(&map, &aux, HERO);
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

    if(!able_to_move(&map, HERO, next_line, next_column))
        return;
    if(next_position_is_character(&map, PILL, next_line, next_column)){
        has_pill = 1;
    }

    move_in_the_map(&map, position.line, position.column, next_line, next_column);
    position.line = next_line;
    position.column = next_column;
}

void ghosts(){
    MAP copy;
    copy_map(&copy, &map);

    for(int line = 0; line < map.lines; line++){
        for(int column = 0; column < map.columns; column++){
            if(copy.matrix[line][column] == GHOST){
                int x_destiny;
                int y_destiny;
                int able_to_move_ghost = move_ghosts(line, column, &x_destiny, &y_destiny);

                if(able_to_move_ghost){
                    move_in_the_map(&map, line, column, x_destiny, y_destiny);
                }
            }
        }
    }
}

int move_ghosts(int current_x, int current_y, int* x_destiny, int* y_destiny){
    int move_options [4][2] = {
        {current_x, current_y + 1},
        {current_x + 1, current_y},
        {current_x, current_y - 1},
        {current_x - 1, current_y}
    };

    srand(time(0));
    for(int i = 0; i < 10; i++){
        int position = rand() % 4;
        if(able_to_move(&map, GHOST, move_options[position][0], move_options[position][1])){
            *x_destiny = move_options[position][0];
            *y_destiny = move_options[position][1];
            return 1;
        }
    }

    return 0;
}

void handle_bomb(){
    if(!has_pill)
        return;

    blow_up(position.line, position.column, 0, 1, 3); //RIGHT
    blow_up(position.line, position.column, 0, -1, 3); //LEFT
    blow_up(position.line, position.column, 1, 0, 3); //DOWN
    blow_up(position.line, position.column, -1, 0, 3); //UP

    has_pill = 0;
}

void blow_up(int line, int column, int sum_line, int sum_column, int quantity){
    if( quantity == 0)
        return;

    int new_line = line + sum_line;
    int new_column = column + sum_column;

    if(!next_position_is_valid(&map, new_line, new_column))
        return;
    if(next_position_is_wall(&map, new_line, new_column))
        return;

    map.matrix[new_line][new_column] = EMPTY;
    blow_up(new_line, new_column, sum_line, sum_column, quantity - 1);
}
