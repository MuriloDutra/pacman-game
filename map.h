#define HERO '@'
#define GHOST 'F'
#define EMPTY '.'
#define VERTICAL_WALL '|'
#define HORIZONTAL_WALL '-'
#define PILL 'P'

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
int find_character_in_map(MAP* map, POSITION* position, char letter);
int next_position_is_valid(MAP* map, int line, int column);
void move_in_the_map(MAP* map, int origin_line, int origin_column, int next_line, int next_column);
int next_position_is_empty(MAP* map, int line, int column);
void copy_map(MAP* new_map, MAP* origin_map);
int able_to_move(MAP* map, char character, int line, int column);
int next_position_is_wall(MAP* map, int line, int column);
int next_position_is_character(MAP* map, char character, int line, int column);
