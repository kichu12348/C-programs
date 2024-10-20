// sparse matrix representation

#include <stdio.h>



void inputSpareMatrix(int matrix[][10], int row, int col){
    printf("Enter the elements of the matrix\n");
    for(int i=0;i<row;i++){
        printf("Enter the elements of row %d\n",i+1);
        for(int j=0;j<col;j++){
            scanf("%d",&matrix[i][j]);
        }
    }
}


int getIndx(int matrix[][10], int r, int c,int row[],int col[],int val[]){
    int k=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(matrix[i][j]!=0){
                row[k]=i;
                col[k]=j;
                val[k]=matrix[i][j];
                k++;
            }
        }
    }
    return k;
}


void printSparseMatrix(int row[],int col[],int val[],int k){
    printf("\n");
    printf("Row:    ");
    for(int i=0;i<k;i++){
        printf("%d ",row[i]);
    }
    printf("\n");
    printf("Column: ");
    for(int i=0;i<k;i++){
        printf("%d ",col[i]);
    }
    printf("\n");
    printf("Value:  ");
    for(int i=0;i<k;i++){
        printf("%d ",val[i]);
    }
    printf("\n");
}



void main(){
    int matrix[10][10],row,col;
    printf("Enter the number of rows and columns of the matrix\n");
    scanf("%d %d",&row,&col);
    inputSpareMatrix(matrix,row,col);
    int rowArr[100],colArr[100],valArr[100];
    int k = getIndx(matrix,row,col,rowArr,colArr,valArr);
    printSparseMatrix(rowArr,colArr,valArr,k);
}
