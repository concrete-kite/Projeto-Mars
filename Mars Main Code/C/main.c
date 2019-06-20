#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

void sleep();

int main(void)
{		
		first = NULL;
		last = NULL;

		update();
		create_liked_list("testeposfile.txt");
		print_data(first);
		free_memory(first);

		sleep(120);
		
}







