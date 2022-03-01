#include <stdio.h>
#include <stdlib.h>
#include "ui.h"
#include "map.h"

char ghost_drawing[4][7] = {
    {" .-.  "},
    {"| OO| "},
    {"|   | "},
    {"'^^^' "}};

char wall_drawing[4][7] = {
    {"......"},
    {"......"},
    {"......"},
    {"......"}};

char hero_drawing[4][7] = {
    {" .--. "},
    {"/ _.-'"},
    {"\\  '-."},
    {" '--' "}};

char pill_drawing[4][7] = {
    {"      "},
    {" .-.  "},
    {" '-'  "},
    {"      "}};

char empty_drawing[4][7] = {
    {"      "},
    {"      "},
    {"      "},
    {"      "}};


void print_part(char drawing[4][7], int part){
    printf("%s", drawing[part]);
}

void print_map(MAP *map)
{
    for (int line = 0; line < map->lines; line++)
    {
        for (int part = 0; part < 4; part++)
        {
            for (int column = 0; column < map->columns; column++)
            {
                switch (map->matrix[line][column])
                {
                    case GHOST:
                        print_part(ghost_drawing, part);
                        break;

                    case HERO:
                        print_part(hero_drawing, part);
                        break;

                    case PILL:
                        print_part(pill_drawing, part);
                        break;

                    case VERTICAL_WALL:
                    case HORIZONTAL_WALL:
                        print_part(wall_drawing, part);
                        break;

                    case EMPTY:
                        print_part(empty_drawing, part);
                        break;

                    default:
                        break;
                }
            }
            printf("\n");
        }
    }
}