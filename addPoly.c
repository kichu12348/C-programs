#include <stdio.h>

typedef struct
{
    int coeff;
    int exp;
} Term;

void inputPoly(Term arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("enter coeff and power for term %d: ", (i + 1));
        scanf("%d%d", &arr[i].coeff, &arr[i].exp);
    }
}

int addPoly(Term poly1[], Term poly2[], Term res[], int s1, int s2)
{
    int size = 0, i = 0, j = 0;
    for (i; i < s1; i++)
    {
        Term temp = poly1[i];
        for (j = 0; j < s2; j++)
        {
            if (poly1[i].exp == poly2[j].exp)
            {
                temp.coeff = poly1[i].coeff + poly2[j].coeff;
                break;
            }
        }
        res[size++] = temp;
    }

    for (i = 0; i < s2; i++)
    {
        int isThere = 0;
        for (j = 0; j < size; j++)
        {
            if (res[j].exp == poly2[i].exp)
            {
                isThere = 1;
                break;
            }
        }

        if (!isThere)
        {
            res[size++] = poly2[i];
        }
    }

    return size;
}

void display(Term poly[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%dx^%d", poly[i].coeff, poly[i].exp);
        if (i != n - 1)
            printf("+");
    }
    printf("\n");
}

int main()
{

    int s1, s2, s3;
    printf("enter size of poly1: ");
    scanf("%d", &s1);
    printf("enter poly1 \n");
    Term poly1[s1];
    inputPoly(poly1, s1);

    printf("enter size of poly2: ");
    scanf("%d", &s2);
    printf("enter poly2 \n");
    Term poly2[s2];
    inputPoly(poly2, s2);

    Term res[100];

    s3 = addPoly(poly1, poly2, res, s1, s2);

    display(res, s3);

    return 0;
}
