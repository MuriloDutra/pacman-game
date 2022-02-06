struct map{
    char** matrix;
    int lines;
    int columns;
};
typedef struct map MAP;

struct position{
    int line;
    int column;
};
typedef struct position POSITION;

void free_map(MAP* map);
void read_map(MAP* map);
void allocate_map(MAP* map); 
void print_map(MAP* map);
void find_character_in_map(MAP* map, POSITION* position, char letter);
