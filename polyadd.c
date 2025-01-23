#include <stdio.h>

typedef struct poly
{
    int coeff;
    int exp;
} poly;

poly p1[100];
int n, m;

int add()
{
    int i = 0;
    int j = n;
    int k = m + n;

    while (i < n && j < m + n)
    {
        if (p1[i].exp > p1[j].exp)
        { 
            p1[k].exp = p1[i].exp;
            p1[k++].coeff = p1[i++].coeff;
        }
        else if (p1[i].exp < p1[j].exp)
        {
            p1[k].exp = p1[j].exp;
            p1[k++].coeff = p1[j++].coeff;
        }
        else
        {
            p1[k].exp = p1[i].exp;
            p1[k++].coeff = p1[i++].coeff + p1[j++].coeff;
        }
    }

    while (i < n)
    {
        p1[k].exp = p1[i].exp;
        p1[k++].coeff = p1[i++].coeff;
    }
    while (j < m + n)
    {
        p1[k].exp = p1[j].exp;
        p1[k++].coeff = p1[j++].coeff;
    }

    return k;
}

void inputpoly()
{
    int c, e;
    printf("\nEnter the size of the first polynomial: ");
    scanf("%d", &n);
    printf("Enter coefficients and exponents for the first polynomial:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &c, &e);
        p1[i].exp = e;
        p1[i].coeff = c;
    }
    printf("\nEnter the size of the second polynomial: ");
    scanf("%d", &m);
    printf("Enter coefficients and exponents for the second polynomial:\n");
    for (int i = n; i < m + n; i++)
    {
        scanf("%d %d", &c, &e);
        p1[i].exp = e;
        p1[i].coeff = c;
    }
}

void display(int k)
{
    printf("\nAdded polynomial is: ");
    for (int i = m + n; i < k; i++)
    {
        printf("%dx^%d", p1[i].coeff, p1[i].exp);
        if (i < k - 1)
        {
            printf(" + ");
        }
    }
    printf("\n");
}

int main()
{
    inputpoly();
    int k = add();
    display(k);
    return 0;
}
