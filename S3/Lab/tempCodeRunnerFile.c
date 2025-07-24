#include <stdio.h>

struct Element {
    int row;
    int col;
    int value;
};

// Function to read a sparse matrix
void readSparse(struct Element mat[], int nonZero) {
    for (int i = 0; i < nonZero; i++) {
        printf("Enter row, col, value: ");
        scanf("%d %d %d", &mat[i].row, &mat[i].col, &mat[i].value);
    }
}

// Print a sparse matrix
void printSparse(struct Element mat[], int n, const char* label) {
    printf("\n%s:\n", label);
    for (int i = 0; i < n; i++) {
        printf("(%d, %d, %d)\n", mat[i].row, mat[i].col, mat[i].value);
    }
}

// Bubble sort by (row, col)
void sortSparse(struct Element mat[], int n) {
    struct Element temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (mat[j].row > mat[j + 1].row || 
               (mat[j].row == mat[j + 1].row && mat[j].col > mat[j + 1].col)) {
                temp = mat[j];
                mat[j] = mat[j + 1];
                mat[j + 1] = temp;
            }
        }
    }
}

int main() {
    int rows, cols, n1, n2;
    printf("Enter number of rows and columns (same for both matrices): ");
    scanf("%d %d", &rows, &cols);

    // Input Matrix A
    printf("Enter number of non-zero elements in Matrix A: ");
    scanf("%d", &n1);
    struct Element A[n1];
    readSparse(A, n1);
    sortSparse(A, n1);

    // Input Matrix B
    printf("Enter number of non-zero elements in Matrix B: ");
    scanf("%d", &n2);
    struct Element B[n2];
    readSparse(B, n2);
    sortSparse(B, n2);

    // Add two sparse matrices)
    struct Element sum[n1 + n2];
    int i = 0, j = 0, k = 0;
    // Add two sparse matrices)
    while (i < n1 && j < n2) {
        if (A[i].row == B[j].row && A[i].col == B[j].col) {
            sum[k] = A[i];
            sum[k].value += B[j].value;
            i++; j++; k++;
        } else if (A[i].row < B[j].row || (A[i].row == B[j].row && A[i].col < B[j].col)) {
            sum[k++] = A[i++];
        } else {
            sum[k++] = B[j++];
        }
    }
    while (i < n1) sum[k++] = A[i++];
    while (j < n2) sum[k++] = B[j++];

    // Transpose of Matrix A (code moved here)
    struct Element transA[n1];
    for (int t = 0; t < n1; t++) {
        transA[t].row = A[t].col;
        transA[t].col = A[t].row;
        transA[t].value = A[t].value;
    }
    sortSparse(transA, n1);

    // Output
    printSparse(sum, k, "Sum Matrix");
    printSparse(transA, n1, "Transpose of Matrix A");

    return 0;
}