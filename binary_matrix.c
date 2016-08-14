/*
 * binary_matrix.c
 * Robert Ricketts
 * this contains the functions for binary_matrix_driver.c
 */ 

#include "binary_matrix.h"

#include <stdio.h>
#include <stdlib.h>

/*
 * Input:
 *      int num_rows, an integer value that tells the function how many
 *      rows they want in the matrix.
 *      int num_cols,an integer value that tells the function how many
 *      columns they want in the matrix.
 * Output:
 *      A matrix of the determined size that contains all 0's.
 * Summary:
 *      This builds a matrix of a desired size, and fills it with 0's.
 */
BinaryMatrix *ConstructBinaryMatrix(int num_rows, int num_cols)
{
    int a;
    BinaryMatrix *M = (BinaryMatrix *) malloc(sizeof(BinaryMatrix));
    M->num_rows = num_rows;
    M->num_cols = num_cols;
    M->data = (int **) calloc(num_rows, sizeof(int *));

    if (num_rows <= 0 || num_cols <= 0) {
	printf
	    ("Error in CreateMatrix: number of rows and columns must be positive\n");
	exit(0);
    }

    for (a = 0; a < num_rows; a++) {
	M->data[a] = (int *) calloc(num_cols, sizeof(int));
    }
    return M;
}

/*       
 * Input: 
 *      BinaryMatrix * M, A binary Matrix that is updated by the user.
 * Summary:
 *      This frees the memory that the input matrix is occupying.
 */
void DeleteBinaryMatrix(BinaryMatrix * M)
{
    int f;
    for (f = 0; f < (*M).num_rows; f++) {
	free(M->data[f]);
    }
    free(M->data);
    free(M);
}

/*
 * Input:
 *      BinaryMatrix * M, A binary Matrix that is updated by the user.
 *      int row, an int index of a row.
 *      int col, an int index of a column.
 *      int content, a character that should be loaded into the matrix
 * Summary:
 *      Enters a 0 or 1 value into the desired row and column of the matrix.
 */
void UpdateEntry(BinaryMatrix * M, int row, int col, int content)
{
    if (row < (*M).num_rows && col < (*M).num_cols && row >= 0 && col >= 0) {
	if (content > 1 || content < 0) {
	    printf("Error in Update Entry: content must be 0 or 1\n");
	    exit(0);
	}
	M->data[row][col] = content;
    } else {
	printf("Error in Update Entry: index out of bounds\n");
	exit(0);
    }
}

/*
 * Input:
 *      BinaryMatrix * M, A binary Matrix that is updated by the user.
 *      int row, an int index of a row.
 *      int col, an int index of a column.
 * Output:
 *      Puts out a integer truth value 1 or 0.
 * Summary:
 *      it tells whether or not the unput row and column are in
 *      the matrix.
 */
int IsMatrixIndex(BinaryMatrix * M, int row, int col)
{
    if (row < (*M).num_rows && col < (*M).num_cols && row >= 0 && col >= 0) {
	return 1;
    } else {
	return 0;
    }
}

/*
 * Input:
 *      BinaryMatrix * M, a binary matrix that s updated by the user.
 * Summary:
 *      Prints the binary matrix.
 */
void PrintMatrix(BinaryMatrix * M)
{
    int i, j;
    for (i = 0; i < (*M).num_rows; i++) {
	for (j = 0; j < (*M).num_cols; j++) {
	    printf("%d", M->data[i][j]);
	}
	printf("\n");
    }
}
