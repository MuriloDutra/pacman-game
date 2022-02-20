#define UP 'w'
#define LEFT 'a'
#define DOWN 's'
#define RIGHT 'd'
#define BOMB 'b'

int game_is_over();
void find_character(int* x, int* y); 
void move(char command);
int is_a_valid_command(char command);
void ghosts();
int move_ghosts(int current_x, int current_y, int* x_destiny, int* y_destiny);
void blow_up();
