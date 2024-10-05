#include <stdio.h>

int k3 = 0;

void readmat(int a[][10], int m, int n)
{
    printf("Enter the matrix:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}

void sparseConversion(int a[][10], int b[][3], int m, int n)
{
    int k1 = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] != 0)
            {
                b[k1][0] = i;
                b[k1][1] = j;
                b[k1][2] = a[i][j];
                k1++;
            }
        }
    }
}

void sparseAdd(int s1[][3], int s2[][3], int s3[][3], int nonZero1, int nonZero2)
{
    k3 = 0;
    int i = 0, j = 0;
    while (i < nonZero1 && j < nonZero2)
    {
        if (s1[i][0] < s2[j][0] || (s1[i][0] == s2[j][0] && s1[i][1] < s2[j][1]))
        {
            s3[k3][0] = s1[i][0];
            s3[k3][1] = s1[i][1];
            s3[k3][2] = s1[i][2];
            i++;
        }
        else if (s1[i][0] > s2[j][0] || (s1[i][0] == s2[j][0] && s1[i][1] > s2[j][1]))
        {
            s3[k3][0] = s2[j][0];
            s3[k3][1] = s2[j][1];
            s3[k3][2] = s2[j][2];
            j++;
        }
        else
        {
            s3[k3][0] = s1[i][0];
            s3[k3][1] = s1[i][1];
            s3[k3][2] = s1[i][2] + s2[j][2];
            i++;
            j++;
        }
        k3++;
    }

    while (i < nonZero1)
    {
        s3[k3][0] = s1[i][0];
        s3[k3][1] = s1[i][1];
        s3[k3][2] = s1[i][2];
        i++;
        k3++;
    }

    while (j < nonZero2)
    {
        s3[k3][0] = s2[j][0];
        s3[k3][1] = s2[j][1];
        s3[k3][2] = s2[j][2];
        j++;
        k3++;
    }
}

void printSparse(int s3[][3], int n)
{
    printf("Row   Col   Value\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d     %d     %d\n", s3[i][0], s3[i][1], s3[i][2]);
    }
}

int main()
{
    int row1, col1, row2, col2;
    int nonZero1 = 0, nonZero2 = 0;
    printf("Enter the number of rows for the first matrix: ");
    scanf("%d", &row1);
    printf("Enter the number of columns for the first matrix: ");
    scanf("%d", &col1);

    printf("Enter the number of rows for the second matrix: ");
    scanf("%d", &row2);
    printf("Enter the number of columns for the second matrix: ");
    scanf("%d", &col2);

    if (row1 != row2 || col1 != col2)
    {
        printf("Matrices must have the same dimensions for addition.\n");
        return 0;
    }

    int mat1[10][10], mat2[10][10];
    printf("Enter elements of the first matrix:\n");
    readmat(mat1, row1, col1);
    printf("Enter elements of the second matrix:\n");
    readmat(mat2, row2, col2);

    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++)
        {
            if (mat1[i][j] != 0)
                nonZero1++;
        }
    }
    for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            if (mat2[i][j] != 0)
                nonZero2++;
        }
    }

    int sparse1[nonZero1][3], sparse2[nonZero2][3], sparse3[nonZero1 + nonZero2][3];

    sparseConversion(mat1, sparse1, row1, col1);
    sparseConversion(mat2, sparse2, row2, col2);
    sparseAdd(sparse1, sparse2, sparse3, nonZero1, nonZero2);
    printf("The result of sparse matrix addition is:\n");
    printSparse(sparse3, k3);

    return 0;
}
