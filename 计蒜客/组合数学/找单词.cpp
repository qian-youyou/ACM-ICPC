#include<stdio.h>
int main()
{
    int n,i,j,k;
    scanf("%d",&n);
    while(n--)
    {
        int a[27] = {0}, b[100]= {0}, c[100] = {0};
        for(i = 1; i <= 26; ++i)
            scanf("%d", &a[i]);
        for(i = 1; i <= 26; i++)
        {
            if(a[i] != 0)
            {
                for(j = 0; i * j <= 50 && j <= a[i]; j++)
                    b[i*j]=1;
                break;
            }
        }
        for(i = i + 1; i <= 26; i++)
        {
            if(a[i] != 0)
            {
                for(k = 0; k <= 50; k++)
                {
                    if(b[k] != 0)
                    {
                        for(j = 0; j * i + k <= 50 && j <= a[i]; j++)
                        {
                            c[i * j + k] += b[k];
                        }
                    }
                }
                for(k = 0; k <= 50; k++)
                {
                    b[k] = c[k];
                    c[k] = 0;
                }
            }
        }
        int sum = 0;
        for(i = 1; i <= 50; i++)
        {
            sum += b[i];
        }
        printf("%d\n", sum);
    }
    return 0;
}
