#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

//sudo leaks marslog
//MallocStackLoggin=1 ./marslog

void write_data(struct Pos wpos, char file[30])
{
	    FILE * fw;
		struct Pos pos;
		fw = fopen(file, "wb");

		if(fw == NULL){
				printf("\nError: Arquivo não encontrado.\n");
		}
		fwrite(&pos, sizeof(struct Pos), 1, fw);
		fclose(fw);

}

void reed_data(char file[30])
{

        FILE * fr;
		fr = fopen(file, "rb");
		if(fr == NULL){
				printf("\nError: Arquivo não encontrado.\n");
				exit(1);
		}
		struct Pos poz;

		while(!feof(fr)){
			
				if(fread(&poz, sizeof(struct Pos), 1, fr))
					printf("X: %d Y: %d Height: %d Width: %d \n",poz.x, poz.y, poz.height, poz.width);
				
		}
		fclose(fr);
}

void create_liked_list(char file[30])
{		

		FILE * f;
		f = fopen(file, "rb");
		if(f == NULL){
				printf("\nError: Arquivo nao encontrado");
				exit(1);
		}


		while(!feof(f)){
				struct Pos * newpos = (struct Pos *)malloc(sizeof(struct Node));

				if(!newpos)
					exit(1);

				if(fread(newpos, sizeof(struct Pos), 1, f))
						enqueue(newpos);

		}

		fclose(f);

}

void enqueue(struct Pos * pos)
{
		struct Node * newnode;

		newnode = (struct Node *)malloc(sizeof(struct Node));
		if(!newnode)
			exit(1);

		newnode->data = pos;

		if(first == NULL){
				first = newnode;
				last = newnode;
		}else{	

				last->link = newnode;
				last = newnode;
		}
}

void print_data(struct Node * temp)
{		
		if(temp == NULL)
				return;

		printf("Pos x: %d ", temp->data->x);
		printf("Pos y: %d ", temp->data->y);
		printf("Height: %d ",temp->data->height);
		printf("Width: %d\n",temp->data->width);

		print_data(temp->link);
}

void free_memory(struct Node * temp)
{		
		if(temp == NULL){
				free(temp);
				return;
		}
		free_memory(temp->link);
		free(temp->data);
		free(temp);
}

// void createRoot(){
// 	root = (struct Root *)malloc(sizeof(struct Root));

// 		if(!root)
// 				exit(1);
			
// 		root->first = NULL;
// 		root->last = NULL;
// }
