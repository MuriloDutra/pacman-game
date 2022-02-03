#include <stdio.h>
#include <stdlib.h>

char** map;
int lines;
int columns;

int main(){
    FILE* file;
    file = fopen("map.txt", "r");//"r" means "read"
    if(file == 0){
        printf("Game map not found.\n");
        exit(1);
    }

    fscanf(file, "%d %d", &lines, &columns);
    printf("lines %d | columns %d\n", lines, columns);

    map = malloc(sizeof(char*) * lines);
    for(int i = 0; i < lines; i++){
        map[i] = malloc(sizeof(char) * (columns + 1));
    }

    for(int i = 0; i < lines; i++){
        fscanf(file, "%s", map[i]);
    }

    for(int i = 0; i < lines; i++){
        printf("%s\n", map[i]);
    }

    fclose(file);

    for(int i = 0; i < lines; i++){
        free(map[i]);
    }
    free(map);
}
