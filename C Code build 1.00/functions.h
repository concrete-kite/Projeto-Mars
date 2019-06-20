#ifndef _FUN_H
#define _FUN_H

struct Pos{
	int x;
	int y;
	int height;
	int width;
};

struct Node{
	struct Pos * data;
	struct Node * link;
};

// struct Root{
// 	struct Node * first;
// 	struct Node * last;
// };

//struct Root * root;

struct Node * first;
struct Node * last;

void free_memory(struct Node * temp);
void write_data(struct Pos wpos, char file[30]);
void reed_data(char file[30]);
void createRoot();
void create_liked_list(char file[30]);
void enqueue(struct Pos * pos);
void print_data(struct Node * temp);

#endif

