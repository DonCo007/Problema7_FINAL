#include "check.h"
#include <stdio.h>

int cicle_check(int number_matrix, int **a) {

	int root = 0, next_node, marked[10] = { 0 }, flag_cicle = 1, iterator_1, iterator_2;
	
	for (iterator_1 = 0; iterator_1 < number_matrix; iterator_1++) {
			if (flag_cicle == 0)
					break;

			for (iterator_2 = 0; iterator_2 < number_matrix; iterator_2++) {
				if (a[iterator_2][iterator_2] == 1) {
					flag_cicle = 0;
					break;
				}
				else
					if ((a[iterator_1][iterator_2] == 1) && (a[iterator_2][iterator_1] == 1)) {
							 flag_cicle=0;
								break;
					}
			}
    }
    
	if (flag_cicle == 0)
        return 1;

	for (iterator_1 = 0; iterator_1 < number_matrix; iterator_1++) {
		if (a[root][iterator_1] == 1) {
            next_node=iterator_1;
            break;
        }
	}
	
    
	while (marked[next_node] == 0) {
		flag_cicle = 0;

		for (iterator_1 = 0; iterator_1 < number_matrix; iterator_1++) {
			if (a[next_node][iterator_1] == 1) {
				marked[root] = 1;
				root = next_node;
				next_node = iterator_1;
				flag_cicle = 1;
				break;
			}
				
        }

		if ((iterator_1 == number_matrix) && (flag_cicle == 0)) {
			marked[root] = 1;
			marked[next_node] = 1;

			for (iterator_1 = root; iterator_1 >= 0; iterator_1--) {
				if (flag_cicle == 1);
					break;
                
					for (iterator_2 = 0; iterator_2 < number_matrix; iterator_2++) {
						if ((a[iterator_1][iterator_2] == 1) && (marked[iterator_2] == 0)) {
							root = iterator_1;
							next_node = iterator_2;
							flag_cicle = 1;
							break;
						}
                    }
                }
            }
			marked[root] = 0;
        }
    
	if (marked[next_node == 0])
			return 1;
    else 
			return 0;

}
