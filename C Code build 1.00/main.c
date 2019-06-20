#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

int main(void)
{		
		//createRoot();
		srand(time(0));
		struct Pos temp;

		FILE * fw;
		fw = fopen("testeposfile.txt", "wb");

		if(fw == NULL){
				printf("\nError: Arquivo não encontrado.\n");
		}

		for (int i = 0; i < 100; i++){
				temp.x = i + 200; //(rand() % 100);
				temp.y = i + 300; //(rand() % 100);
				temp.height = 400;
				temp.width = 550;

				fwrite(&temp, sizeof(struct Pos), 1, fw);
		}

		fclose(fw);

		create_liked_list("testeposfile.txt");

		print_data(first);

		free_memory(first);

		sleep(120);
		
}







