#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int x[20],count=0;
int place(int k,int i)
{
    int j;
    for(j=1;j<=k-1;j++)
    {
        if((x[j]==i) || (abs(x[j]-i)==abs(j-k)))
        {
            return 0;
        }
    }
    return 1;
}
void nqueens(int k,int n)
{
    int i;
    for(i=1;i<=n;i++)
    {
        if(place(k,i))
        {
            x[k]=i;
            if(k==n)
            {
                count++;
                printf("\n\nSolution %d:\n",count);
                for(i=1;i<=n;i++)
                {
                    for(int j=1;j<=n;j++)
                    {
                        if(x[i]==j)
                        {
                            printf("Q\t");
                        }
                        else
                        {
                            printf("*\t");
                        }
                    }
                    printf("\n");
                }
            }
            else
            {
                nqueens(k+1,n);
            }
        }
    }
}
int main()
{
    int n;
    printf("Enter the number of queens: ");
    scanf("%d",&n);
    nqueens(1,n);
    printf("\n\nTotal solutions: %d",count);
    return 0;
}