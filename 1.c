#include <stdio.h>
#include <stdlib.h>

float **createMatrix(int n, int m) {
    float **matrix = (float **) malloc(n * sizeof(float *));
    for (int i = 0; i < n; i++) {
        matrix[i] = (float *) malloc(m * sizeof(float));
    }
    return matrix;
}

void calcmatrix(float**matrix, int rows, int columns){
    float tmp, nm;

    nm = rows*columns;

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            tmp = i*j;
            matrix[i][j] = tmp/nm;
        }
    }
}

void writef(float **matrix, int rows, int colums){
    char *filename = "matrx.txt";

    FILE *fp = fopen(filename, "w");

    fprintf(fp, "%d %d \n", rows, colums);
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < colums; j++){
            printf("%f ", matrix[i][j]);
            fprintf(fp, "%f ", matrix[i][j]);
        }
        fprintf(fp, "\n");
        printf("\n");
    }
    fclose(fp);
}

void freeMatrix(float **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main(){
    int n, m;

    printf("Введіть n та m: ");
    scanf("%d %d", &n, &m);

    float **A = createMatrix(n, m);

    calcmatrix(A, n, m);

    writef(A, n, m);

}