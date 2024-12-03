#include <stdio.h>
#include <stdlib.h>

void printMatrix(double **matrix, double **inverse, int n, int showIdentity);
void gaussJordan(double **matrix, double **inverse, int n, int showSteps);
double determinant(double **matrix, int n);
int findNonZeroPivot(double **matrix, int n, int col);
void showsteps(double **matrix, double **inverse, int n);

int main() {
    int n, showSteps;
    double **matrix, **inverse;

    // Step 1: Input the order of the matrix
    Start:
    printf("Enter the order of the matrix (n x n): ");
    scanf("%d", &n);

    // Step 2: Dynamically allocate memory for the matrix and inverse matrix
    matrix = (double **)malloc(n * sizeof(double *));
    inverse = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++) {
        matrix[i] = (double *)malloc(n * sizeof(double));
        inverse[i] = (double *)malloc(n * sizeof(double));
    }

    // Step 3: Input matrix elements row by row
    printf("Enter the elements of the matrix row by row:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Enter element A[%d][%d]: ", i + 1, j + 1);
            scanf("%lf", &matrix[i][j]);
        }
    }

    // Step 4: Ask the user if they want to see each step
    printf("Show Steps? (1 for Yes, 0 for No): ");
    scanf("%d", &showSteps);

    // Step 5: Initialize the identity matrix for the inverse
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inverse[i][j] = (i == j) ? 1.0 : 0.0;
        }
    }

    // Step 6: Check if the matrix is singular (determinant = 0)
    double det = determinant(matrix, n);
    if (det == 0) {
        printf("The matrix is singular and cannot be inverted (determinant = 0).\n");
        // Free dynamically allocated memory
        for (int i = 0; i < n; i++) {
            free(matrix[i]);
            free(inverse[i]);
        }
        free(matrix);
        free(inverse);
        goto Start;
    } else {
        printf("The determinant of the matrix is %lf, which is non-zero. Proceeding...\n", det);
    }

    // Step 7: Print the initial matrices (Matrix A and Identity Matrix)
    printf("\nInitial matrices:\n");
    printf("Matrix A    |    Identity Matrix\n");
    printMatrix(matrix, inverse, n, 1);  // Print both matrix A and the Identity matrix side by side
    getchar(); // Wait for user input to continue

    // Step 8: Perform Gauss-Jordan elimination with optional step display
    gaussJordan(matrix, inverse, n, showSteps);

    // Step 9: Print the final inverse matrix
    printf("\nThe inverse matrix is:\n");
    printMatrix(inverse, NULL, n, 0);  // Only print the final inverse matrix, not the identity side

    // Free dynamically allocated memory
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
        free(inverse[i]);
    }
    free(matrix);
    free(inverse);

    goto Start;
}

// Function to print the matrix with better formatting
void printMatrix(double **matrix, double **inverse, int n, int showIdentity) {
    for (int i = 0; i < n; i++) {
        // Print the elements of matrix A
        for (int j = 0; j < n; j++) {
            printf("%10.3f ", matrix[i][j]);  // Display floats with 3 decimal places, aligned
        }

        // Print the identity matrix or the inverse matrix side by side
        if (showIdentity && inverse != NULL) {
            printf(" | ");
            for (int j = 0; j < n; j++) {
                printf("%10.3f ", inverse[i][j]);  // Display floats with 3 decimal places, aligned
            }
        }
        printf("\n");
    }
}

// Function to find a non-zero pivot in a column
int findNonZeroPivot(double **matrix, int n, int col) {
    for (int i = col + 1; i < n; i++) {
        if (matrix[i][col] != 0) {
            return i; // Return the row with a non-zero pivot
        }
    }
    return -1; // Return -1 if no non-zero pivot is found
}

// Function to display the current step, matrix A, and the identity matrix
void showsteps(double **matrix, double **inverse, int n) {
    // Print the current matrices
    printf("Matrix A    |    Identity Matrix\n");
    printMatrix(matrix, inverse, n, 1);  // Print both matrix A and the inverse matrix (identity)
    getchar(); // Wait for user input to continue
}

// Function to perform Gauss-Jordan elimination
void gaussJordan(double **matrix, double **inverse, int n, int showSteps) {
    double ratio;
    int step = 1;  // Step counter
    getchar(); // Wait for user input to continue

    // Start Gauss-Jordan elimination
    for (int i = 0; i < n; i++) {
        
        // Step 2: Check if the pivot element is non-zero
        double pivot = matrix[i][i];

        // If pivot is zero, find a non-zero pivot by swapping rows
        if (pivot == 0) {
            int pivotRow = findNonZeroPivot(matrix, n, i);

            // Swap rows i and pivotRow
            for (int j = 0; j < n; j++) {
                double temp = matrix[i][j];
                matrix[i][j] = matrix[pivotRow][j];
                matrix[pivotRow][j] = temp;

                temp = inverse[i][j];
                inverse[i][j] = inverse[pivotRow][j];
                inverse[pivotRow][j] = temp;
            }

            // Recalculate pivot after row swap
            pivot = matrix[i][i];

            // Show row swapping step
            if (showSteps) {
                printf("\nStep %d: Swapping rows R%d and R%d (Pivot is zero)\n", step, i + 1, pivotRow + 1);
                showsteps(matrix, inverse, n);
                step++;
            }
        }

        // Only divide if the pivot is not 1 (to avoid unnecessary division)
        if (pivot != 1.0) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] /= pivot;
                inverse[i][j] /= pivot;
            }

            // Show the matrix after this operation
            if (showSteps) {
                printf("\nStep %d: R%d' = R%d / %g (Making A[%d][%d] = 1)\n", step, i + 1, i + 1, pivot, i + 1, i + 1);
                showsteps(matrix, inverse, n);
                step++;
            }
        }

        // Step 3: Make all other elements in the column 0
        for (int j = 0; j < n; j++) {
            if (i != j && matrix[j][i] != 0) {
                ratio = matrix[j][i];
                for (int k = 0; k < n; k++) {
                    matrix[j][k] -= ratio * matrix[i][k];
                    inverse[j][k] -= ratio * inverse[i][k];
                }

                // Show the matrix after elimination
                if (showSteps) {
                    printf("\nStep %d: R%d' = R%d - (%g) * R%d (Making A[%d][%d] = 0)\n", step, j + 1, j + 1, ratio, i + 1, j + 1, i + 1);
                    showsteps(matrix, inverse, n);
                    step++;
                }
            }
        }
    }
}

// Function to calculate the determinant of a matrix
double determinant(double **matrix, int n) {
    double det = 1;
    double **temp = (double **)malloc(n * sizeof(double *));
    
    // Allocate memory for the temp matrix
    for (int i = 0; i < n; i++) {
        temp[i] = (double *)malloc(n * sizeof(double));
    }

    // Copy the matrix to temp to avoid modifying the original matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[i][j] = matrix[i][j];
        }
    }

    // Perform Gaussian elimination to get the upper triangular matrix
    for (int i = 0; i < n; i++) {
        if (temp[i][i] == 0) {
            // Find a row below the i-th row with a non-zero element in the i-th column
            int swapRow = -1;
            for (int j = i + 1; j < n; j++) {
                if (temp[j][i] != 0) {
                    swapRow = j;
                    break;
                }
            }

            if (swapRow == -1) {
                // Free the allocated memory for temp matrix
                for (int i = 0; i < n; i++) {
                    free(temp[i]);
                }
                free(temp);
                return 0; // Singular matrix (determinant is 0)
            }

            // Swap rows i and swapRow
            for (int j = 0; j < n; j++) {
                double tempVal = temp[i][j];
                temp[i][j] = temp[swapRow][j];
                temp[swapRow][j] = tempVal;
            }

            det = -det; // Change the sign of the determinant when swapping rows
        }

        // Eliminate entries below the pivot
        for (int j = i + 1; j < n; j++) {
            if (temp[j][i] != 0) {
                double ratio = temp[j][i] / temp[i][i];
                for (int k = i; k < n; k++) {
                    temp[j][k] -= ratio * temp[i][k];
                }
            }
        }

        det *= temp[i][i]; // Multiply the diagonal elements to get the determinant
    }

    // Free the allocated memory for temp matrix
    for (int i = 0; i < n; i++) {
        free(temp[i]);
    }
    free(temp);

    return det;
}
