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

		if (fw == NULL) {
				printf("\nError: Arquivo não encontrado.\n");
		}
		fwrite(&pos, sizeof(struct Pos), 1, fw);
		fclose(fw);

}

void reed_data(char file[30])
{

        FILE * fr;
		fr = fopen(file, "rb");
		if (fr == NULL) {
				printf("\nError: Arquivo não encontrado.\n");
				exit(1);
		}
		struct Pos poz;

		while (!feof(fr)) {
			
				if (fread(&poz, sizeof(struct Pos), 1, fr)) {
					printf("X: %d Y: %d Height: %d Width: %d \n",poz.x, poz.y, poz.height, poz.width);
				}
				
		}
		fclose(fr);
}

void create_liked_list(char file[30])
{		

		FILE * f;
		f = fopen(file, "rb");
		if (f == NULL) {
				printf("\nError: Arquivo nao encontrado");
				exit(1);
		}

		struct Pos * newpos;
		while (!feof(f)) {
				newpos = (struct Pos *)malloc(sizeof(struct Node));

				if (!newpos)
					    exit(1);

				if (fread(newpos, sizeof(struct Pos), 1, f))
					    enqueue(newpos);

		}

		free(newpos);
		fclose(f);

}

void enqueue(struct Pos * pos)
{
		struct Node * newnode;

		newnode = (struct Node *)malloc(sizeof(struct Node));
		if (!newnode)
			    exit(1);

		newnode->data = pos;

		if (first == NULL){
				first = newnode;
				last = newnode;
		}else{	

				last->link = newnode;
				last = newnode;
		}
}

void print_data(struct Node * temp)
{		
		if (temp == NULL)
				return;

		printf("Pos x: %d ", temp->data->x);
		printf("Pos y: %d ", temp->data->y);
		printf("Height: %d ",temp->data->height);
		printf("Width: %d\n",temp->data->width);

		print_data(temp->link);
}


void free_memory(struct Node * temp)
{		
		if (temp == NULL)
				return;
		
		free_memory(temp->link);
		free(temp->data);
		free(temp);
}

int update()
{		
		char c; 
		printf("Update Binary File? (Y/N)\n");
		scanf("%c",&c);

		if(c == 'Y') {

				struct Pos * temp = (struct Pos *)malloc(sizeof(struct Pos));
				if(!temp)
					    exit(1);

				FILE * fw;
				fw = fopen("testeposfile.txt", "wb");
				if(fw == NULL){
						printf("\nError: Arquivo não encontrado.\n");
						exit(1);
				}
				
				FILE * p;
				p = fopen("pyndata.txt", "r+");

				if (p == NULL) {
						printf("\nError: Arquivo Python não encontrado.\n");
						exit(1);
				}

				while (!feof(p)) {
						if (fscanf(p,"%d %d %d %d",&temp->x,&temp->x,
								&temp->height,&temp->width))
						    	fwrite(temp, sizeof(struct Pos), 1, fw);		
				}

				fclose(fw);
				fclose(p);
				free(temp);

				return 1;
		}
		
		return 0;

}



