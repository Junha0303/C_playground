#include <stdio.h>
#include <stdlib.h>

void printMatrix(char **matrix, int k) {
	for(int i = 0; i < k; i++) {
		for(int j = 0; j < k; j++) printf("%c", matrix[i][j]);
		printf("\n");
	}
}

void clearMatrix(char **matrix, int k) {
	for(int i = 0; i < k; i++) {
		for(int j = 0; j < k; j++) matrix[i][j] = ' ';
	}
}

void fillMatrix(char **matrix, int i, int j, int k) {

	if(k == 1) matrix[i][j] = '*';

	else {
		int vArray[3] = {i, i + k / 3, i + (2 * k / 3)};
		int hArray[3] = {j, j + k / 3, j + (2 * k / 3)};

		// fill the top part of matrix
		for(int n = 0; n < 3; n++) {
			for(int m = 0; m < 3; m++) {
				if(n != 1 || m != 1) fillMatrix(matrix, vArray[n], hArray[m], k / 3);
			}
		}	
	}
}

int main(int argc, char const *argv[])
{
	int k;
	scanf("%d", &k);

	//allocating matrix
	char** matrix = (char **) malloc(sizeof(char *) * k);
	for(int i = 0; i < k; i++) matrix[i] = (char *) malloc(sizeof(char) * k);

	clearMatrix(matrix, k);
	fillMatrix(matrix, 0, 0, k);

	printMatrix(matrix, k);
}