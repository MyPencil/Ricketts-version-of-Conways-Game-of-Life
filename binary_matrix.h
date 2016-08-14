/*
 * binary_matrix.h
 * Robert Ricketts
 * An implementation of a Binary Matrix
 */

#ifndef _BINARY_MATRIX_H_
#define _BINARY_MATRIX_H_

typedef struct {
    int num_rows;
    int num_cols;
    int **data;
} BinaryMatrix;

/*
 * Input:
 *      BinaryMatrix * M, a binary matrix that s updated by the user.
 * Summary:
 *      Prints the binary matrix.
 */
void PrintMatrix(BinaryMatrix * M);

/*
 * Input:
 *	BinaryMatrix * M, A binary Matrix that is updated by the user.
 *	int row, an int index of a row.
 *	int col, an int index of a column.
 * Output:
 * 	Puts out a integer truth value 1 or 0.
 * Summary:
 *	it tells whether or not the unput row and column are in
 *	the matrix.
 */
int IsMatrixIndex(BinaryMatrix * M, int row, int col);

/*
 * Input:
 * 	BinaryMatrix * M, A binary Matrix that is updated by the user.
 * 	int row, an int index of a row.
 *	int col, an int index of a column.
 *	int content, a character that should be loaded into the matrix
 * Summary:
 * 	Enters a 0 or 1 value into the desired row and column of the matrix.
 */
void UpdateEntry(BinaryMatrix * M, int row, int col, int content);

/*
 * Input:
 * 	BinaryMatrix * M, A binary Matrix that is updated by the user.
 * Summary:
 * 	This frees the memory that the input matrix is occupying.
 */
void DeleteBinaryMatrix(BinaryMatrix * M);

/*
 * Input:
 * 	int num_rows, an integer value that tells the function how many
 * 	rows they want in the matrix.
 * 	int num_cols,an integer value that tells the function how many
 * 	columns they want in the matrix.
 * Output:
 * 	A matrix of the determined size that contains all 0's.
 * Summary:
 *	This builds a matrix of a desired size, and fills it with 0's.
 */
BinaryMatrix *ConstructBinaryMatrix(int num_rows, int num_cols);

#endif				/* _BINARY_MATRIX_H_ */
