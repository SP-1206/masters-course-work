#include<stdio.h>
void main()
{
int c=10,j=12,i;
int a[14][14];
a[0]=4;
a[1]=6;
a[2]=8;
for(i=3;i<j-3;i++)
{
a[0][i]=7;
a[1][i]=10;

}

a[j-1]=4;
a[j-2]=6;
a[j-3]=8;

for(i=0;i<12;i++)
printf("%d ",a[i]);
printf("\n");
}


					 // {{3, 4, 5, 7, 5, 4, 3}, 
                                          //{4, 6, 8, 10, 8, 6, 4},
                                          //{5, 8, 11, 13, 11, 8, 5}, 
                                          //{5, 8, 11, 13, 11, 8, 5},
                                          //{4, 6, 8, 10, 8, 6, 4},
                                          //{3, 4, 5, 7, 5, 4, 3}};