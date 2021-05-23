#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
int cmpfunc (const void * a, const void * b) {
return ( *(int*)a - *(int*)b );
}
int main()
{
int size=(rand()%10000)+10000;
int value=10;
int flag;
int tid;
int A[size];for(int i=0;i<size;i++)
{
A[i]=rand()%10000;
}
double t1,t2;
printf("Total number of element: %d\n\n",size);
printf("\n1.Sequential Linear search:\n");
t1=omp_get_wtime();
flag=0;
for(int i=0;i<size;i++)
{
if(A[i]==value)
{
flag=1;
printf("Element found at pos %d\n",i+1);
}
}
if(flag==0)
{
printf("Element Not found\n");
}
t2=omp_get_wtime();
printf("Time taken %f s\n\n",t2-t1);
printf("\n2.Parallel Linear search:\n");
t1=omp_get_wtime();
int i;
#pragma omp parallel num_threads(4) private(i)
{
tid=omp_get_thread_num();
#pragma omp for
for(i=0;i<size;i++)
{
if(A[i]==value)
{
flag=1;
printf("Element found at pos %d by thread %d\n",i+1,tid);
}
}
}
t2=omp_get_wtime();printf("Time taken %f s\n\n",t2-t1);
qsort(A, size, sizeof(int), cmpfunc);
printf("Here we have sorted the given array to perform binary search.\n");
printf("\n3.Sequential Binary search:\n");
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
}
}
if(flag==0)
{
printf("Element not found\n");
}
t2=omp_get_wtime();
printf("Time taken %f s\n\n",t2-t1);
return 0;
}
