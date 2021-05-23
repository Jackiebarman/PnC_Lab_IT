#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
int key=10;
int cmpfunc (const void * a, const void * b) {
return ( *(int*)a - *(int*)b );
}
int binary_search(int arr[],int l,int r){
if(l>=r)return -1;
int mid=(l+r)/2;
if(arr[mid]==key)return mid;
int a = -1,b = -1;
if((r-l)>10000){
#pragma omp task shared(a)
{
a=binary_search(arr,mid+1,r);
}
#pragma omp task shared(b)
{
b=binary_search(arr,l,mid);
}
#pragma omp taskwait
return a>b?a:b;
}
else
{
a=binary_search(arr,mid+1,r);
b=binary_search(arr,l,mid);return a>b?a:b;
}
}
int main()
{
int size=(rand()%10000)+10000;
int value=key;
int flag,index;
int tid;
int A[size];
for(int i=0;i<size;i++)
{
A[i]=rand()%10000;
}
double t1,t2;
printf("Total number of element: %d\n\n",size);
qsort(A, size, sizeof(int), cmpfunc);
printf("\n1.Sequential Binary search:\n");
t1=omp_get_wtime();
int beg=0,last=size-1,mid;
while(beg<=last)
{
mid=beg+(last-beg)/2;
if(A[mid]==value)
{
flag=1;
printf("Element found at pos %d\n",mid+1);
break;
}
else if(A[mid]>value)
{
last=mid-1;
}
else
{
beg=mid+1;
}}
if(flag==0)
{
printf("Element not found\n");
}
t2=omp_get_wtime();
printf("Time taken %f s\n\n",t2-t1);
printf("\n2.parallel Binary search:\n");
t1=omp_get_wtime();
#pragma omp parallel
{
#pragma omp master
{
index=binary_search(A,0,size-1);
}
}
printf("Element found at pos %d\n",mid+1);
t2=omp_get_wtime();
printf("Time taken %f s\n\n",t2-t1);
return 0;
}
