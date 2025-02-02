#include<stdio.h>
#include<stdlib.h>
#define MAXI 100

typedef struct term{
    int row;
    int col;
    int value;
}term;

term a[MAXI];
term b[MAXI];
term c[MAXI];

void simpleTranpose()
{
    b[0].col = a[0].row;
    b[0].row = a[0].col;
    b[0].value = a[0].value;

    if(b[0].value>1)
    {
        int current=1;
        for(int i=0;i<a[0].col;i++)
        {   
            for(int j=1;j<=a[0].value;j++)
            {
                if(a[j].col==i)
                {
                    b[current].col = a[j].row;
                    b[current].row = a[j].col;
                    b[current].value = a[j].value;
                    current++;
                }
            }
        }   
    }
}

void fastTranspose()
{
    int startingpos[MAXI],rowTerms[MAXI];
    int col = a[0].col, terms = a[0].value;

    c[0].value = a[0].value;
    c[0].row = a[0].col;
    c[0].col  = a[0].row;

    for(int i=0;i<col;i++) rowTerms[i] = 0;
    for(int i=1;i<=terms;i++) rowTerms[a[i].col]++;

    startingpos[0]=1;

    for(int i=1;i<col;i++) startingpos[i] = startingpos[i-1] + rowTerms[i-1];
    for(int i=1;i<=terms;i++)
    {
        int index = startingpos[a[i].col]++;
         c[index].row = a[i].col;
        c[index].col = a[i].row;
        c[index].value = a[i].value;
    }
}
void display(term d[])
{
    for(int i=1;i<=b[0].value;i++)
    {
        printf("%d %d %d\n",d[i].row,d[i].col,d[i].value);
    }
}

void main()
{
    int i;
    printf("Enter the number of rows and columns:\n");
    scanf("%d%d",&a[0].row,&a[0].col);

    printf("Enter the number of values:\n");
    scanf("%d",&a[0].value);

  
    for(int i=1;i<=a[0].value;i++)
    {
          printf("Enter the %dth row,column and value:\n",i);
        scanf("%d%d%d",&a[i].row,&a[i].col,&a[i].value);
    }

    printf("Original Matrix:\n");
    for(int i=1;i<=a[0].value;i++)
    {
    printf("%d\t%d\t%d\n",a[i].row,a[i].col,a[i].value);
    }

    simpleTranpose();
    printf("Simple transpose output:\n");
    display(b);
    fastTranspose();
    printf("Fast Transpose output:\n");
    display(c);
}