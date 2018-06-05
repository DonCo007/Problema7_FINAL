#include "adjmat.h"
#include "topsort.h"
#include "check.h"
#include <stdio.h>
#include <stdlib.h>


void adjacency_matrix_in() {
    //declaring and opening the in file.
	FILE *file_in;
	file_in = fopen("in.txt", "r");

    //declaration of the used variables
	int iterator_1, iterator_2, number_matrix;

    //read of number of lines and collums
	fscanf(file_in, "%d", &number_matrix);

    //declaration and allocating memory of matrix a
	int ** a = (int**)malloc(number_matrix * sizeof(int*));
	for (iterator_1 = 0; iterator_1 < number_matrix; iterator_1++) {
		a[iterator_1] = (int*)malloc(number_matrix * sizeof(int));
	}


    //read form file the adjacency matrix
	for (iterator_1 = 0; iterator_1 < number_matrix; iterator_1++) {
		for (iterator_2 = 0; iterator_2 < number_matrix; iterator_2++)
			fscanf(file_in, "%d", &a[iterator_1][iterator_2]);
	}

	//appending the topological sort function if the graph is acyclic
	if(cicle_check(number_matrix, a) == 0)
        topological_sort(number_matrix, a);
    else
        printf("The graph haves cicle.");

	//freeing the allocated memory
	for (iterator_1 = 0; iterator_1 < number_matrix; iterator_1++) {
		free(a[iterator_1]);
	}
	free(a);
}
