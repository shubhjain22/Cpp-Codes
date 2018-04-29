#include <stdio.h>
int sumtria(int a[][100],int n,int p,int q);

int max(int a,int b);

int main() { int n,t,a[100][100],cost,i,j;

scanf("%d",&t);

while(t--)
{
   scanf("%d",&n);

   for(i=0;i<n;i++)

   for(j=0;j<=i;j++)

   scanf("%d",&a[i][j]);

   cost=sumtria(a,n,0,0);

   printf("%d",cost);

   printf("\n");
}
return 0;
} int sumtria(int a[][100],int n,int p,int q) { int cost;

if(p==n-1)

return a[p][q];

else

cost=a[p][q]+(max((sumtria(a,n,p+1,q)),(sumtria(a,n,p+1,q+1))));

return cost;
}

int max(int d,int b)

{ if(d>b)

return d;

else

return b;
}

