#include<stdio.h>
void swap(int *a,int *b)
{ 
	int t= *a;
	*a=*b;
	*b=t;
} 
int lomuto_partition(int *a,int L,int R)
{ 
	int pivot =a[R];
	int i=L-1,j=L;
	for(;j<R;j++)
	{
		if(a[j]<pivot)
		{
			i+=1;
			swap(&a[i],&a[j]);
		}
	}
	swap(&a[i+1],&a[R]);
	return i+1;
} 
void quick_sort(int *a,int L,int R)
{ 
	if(R>L)
	{
		int p=lomuto_partition(a,L,R);
		quick_sort(a,L,p-1);
		quick_sort(a,p+1,R);
	}
} 
int main()
{ 
	int n;
	scanf("%d",&n);
	int a[n],i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	quick_sort(a,0,n-1);
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
} 
