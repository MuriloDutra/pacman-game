void free_map();
void read_map();
void allocate_map(); 
void print_map();
int game_is_over();
void find_character(int* x, int* y);
void move(char command);
struct map{
    char** matrix;
    int lines;
    int columns;
};
