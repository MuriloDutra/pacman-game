#define HERO '@'
#define GHOST 'F'
#define EMPTY '.'
#define VERTICAL_WALL '|'
#define HORIZONTAL_WALL '-'

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
void find_character_in_map(MAP* map, POSITION* position);
int next_position_is_valid(MAP* map, int line, int column);
void move_in_the_map(MAP* map, int origin_line, int origin_column, int next_line, int next_column);
int next_position_is_not_wall(MAP* map, int line, int column);
void copy_map(MAP* new_map, MAP* origin_map);
