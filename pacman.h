#define UP 'w'
#define LEFT 'a'
#define DOWN 's'
#define RIGHT 'd'

int game_is_over();
void find_character(int* x, int* y); 
void move(char command);
int is_a_valid_command(char command);
