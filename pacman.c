#include <stdio.h>
#include <stdlib.h>

int main(){
    char map[5][10+1];

    FILE* file;
    file = fopen("map.txt", "r");//"r" means "read"

    if(file == 0){
        printf("Game map not found.\n");
        exit(1);
    }

    for(int i = 0; i < 5; i++){
        fscanf(file, "%s", map[i]);
    }

    for(int i = 0; i < 5; i++){
        printf("%s\n", map[i]);
    }

    fclose(file); 
}
