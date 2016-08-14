/*
 *  conways_game_of_life.c
 *  Robert Ricketts
 *  
 */

#include "conways_game_of_life.h"

#include <stdio.h>
#include <stdlib.h>

#include "binary_matrix.h"
#include "coordinate.h"

/*
 * Input:
 *      int num_rows, the number of rows in the game
 *      int num_cols, the number of cols in the game
 * Output:
 *      Returns a BinaryMatrix* that corresponds to the
 *      first generation game state
 * Summary:
 *      Returns the game state of the first generation
 */
BinaryMatrix *FirstGeneration(int num_rows, int num_cols,
			      List * seed_cells)
{
    BinaryMatrix *M;
    int i;
    ListNode *temp = seed_cells->head;
    M = ConstructBinaryMatrix(num_rows, num_cols);
    for (i = 0; i < seed_cells->size; i++) {
	UpdateEntry(M, temp->data.x, temp->data.y, 1);
	temp = temp->next;
    }
    return M;
}

/*
 * Input:
 *      BinaryMatrix* generation, a pointer to a game state
 * Output:
 *      Returns a BinaryMatrix*, a pointer to a game state
 * Summary:
 *      Calculates the game state of the generation directly
 *      after *generation and returns it
 */

BinaryMatrix *NextGeneration(BinaryMatrix * generation)
{
    int i, j, m;
    Coordinate k;
    List *neighbors;
    BinaryMatrix *M =
	ConstructBinaryMatrix(generation->num_rows, generation->num_cols);
    for (i = 0; i < generation->num_rows; i++) {
	for (j = 0; j < generation->num_cols; j++) {
	    k = ConstructCoordinate(i, j);
	    neighbors = NeighboringCells(k, generation);
	    m = LivingNeighbors(generation, neighbors);
	    if (Live(generation, k)) {
		if (m >= 4 || m <= 1) {
		    UpdateEntry(M, i, j, 0);
		} else {
		    UpdateEntry(M, i, j, 1);
		}
	    } else {
		if (m == 3) {
		    UpdateEntry(M, i, j, 1);
		}
	    }
	}
    }
    return M;
}

/*
 * Input:
 *      BinaryMatrix* generation, a pointer to a game state
 *      Coordinate coord, a cell of the game state
 * Output:
 *      Returns true if the cell is Live
 * Summary:
 *      Checks if coord is a valid index of *generation and
 *      its corresponding cell is Live
 */
int Live(BinaryMatrix * generation, Coordinate coord)
{
    int j, k;
    j = coord.x;
    k = coord.y;
    if (IsMatrixIndex(generation, j, k) && (*generation).data[j][k] == 1) {
	return 1;
    } else {
	return 0;
    }
}

/*
 * Input:
 *      Coordinate coord, a cell of the game state
 *      BinaryMatrix* generation, a pointer to a game state
 * Output:
 *      Returns a List* to a List of neighboring cells
 * Summary:
 *      Calculates neighboring cells of *generation at coord and
 *      returns them as a List
 */
List *NeighboringCells(Coordinate coord, BinaryMatrix * generation)
{
    List *result = ConstructList();
    int i, j;
    if (result == (List *) NULL) {
	printf("Error in NeighboringCells: List construction failed\n");
	exit(EXIT_FAILURE);
    }
    for (i = -1; i <= 1; i++) {
	for (j = -1; j <= 1; j++) {
	    Coordinate coord_neighbor =
		ConstructCoordinate(coord.x + i, coord.y + j);
	    if (IsNeighbor(coord, coord_neighbor)
		&& IsMatrixIndex(generation, coord.x + i, coord.y + j)) {
		PushFrontList(result, coord_neighbor);
	    }
	}
    }
    return result;
}

/*
 * Input:
 *      BinaryMatrix* generation, a pointer to a game state
 *      List* neighbors, a List of neighbors of a coordinate
 * Output:
 *      Returns the number of neighboring cells that are Live
 * Summary:
 *      Counts the number of Coordinates in *neighbors that
 *      correspond to live cells in *generation
 */
int LivingNeighbors(BinaryMatrix * generation, List * neighbors)
{
    int i, j = 0;
    ListNode *temp = neighbors->head;
    for(i = 0; i < neighbors->size; i++) {
	if (Live(generation, temp->data)) {
	    j++;
	}
	temp = temp->next;
    }
    return j;
}

/*
 * Input:
 *      BinaryMatrix* generation, a pointer to a game state
 *      FILE* fp, a file opened for writing
 * Summary:
 *      Prints the game state of *generation to *fp
 */
void PrintGeneration(BinaryMatrix * generation, FILE * fp)
{
    int i, j;
    for (i = 0; i < generation->num_rows; i++) {
	for (j = 0; j < generation->num_cols; j++) {
	    if (Live(generation, ConstructCoordinate(i, j))) {
		fprintf(fp, "#");
	    } else {
		fprintf(fp, " ");
	    }
	}
	fprintf(fp, "\n");
    }
    return;
}