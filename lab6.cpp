#include<bits/stdc++.h>
#include<omp.h>
using namespace std;
int main()
{
ifstream ptr;
int R,G,B,i;
double Gray;
ptr.open("KittenRGB.txt");
double t1,t2;
vector<vector<int>> v;
vector<int> m;
int size=300*300;
vector<double>Y(size,0),I(size,0),Q(size,0),Gr(size,0);
for(int i=0;i<size;i++)
{
m.clear();
ptr>>R;
ptr>>G;
ptr>>B;
m.push_back(R);
m.push_back(G);
m.push_back(B);
v.push_back(m);
}
ptr.close();
printf("1.serial execution\n");
t1=omp_get_wtime();
for(i=0;i<size;i++)
{
Gr[i]=(v[i][0]*0.21+v[i][1]*0.72+v[i][2]*0.07);
Y[i]=(0.299*v[i][0]+0.587*v[i][1] + 0.114*v[i][2]);
I[i]=(0.596*v[i][0]-0.275*v[i][1]-0.321*v[i][2]);
Q[i]=(0.212*v[i][0]-0.523*v[i][1]+0.311*v[i][2]);
}
t2=omp_get_wtime();
printf("Time taken =%lf s\n\n",t2-t1);printf("2.parallel execution with 2 thread\n");
t1=omp_get_wtime();
#pragma omp parallel num_threads(2)
#pragma omp for private(i) schedule(guided,100)
for(i=0;i<size;i++)
{
Gr[i]=(v[i][0]*0.21+v[i][1]*0.72+v[i][2]*0.07);
Y[i]=(0.299*v[i][0]+0.587*v[i][1] + 0.114*v[i][2]);
I[i]=(0.596*v[i][0]-0.275*v[i][1]-0.321*v[i][2]);
Q[i]=(0.212*v[i][0]-0.523*v[i][1]+0.311*v[i][2]);
}
t2=omp_get_wtime();
printf("Time taken =%lf s\n\n",t2-t1);
printf("3.parallel execution with 4 thread\n");
t1=omp_get_wtime();
#pragma omp parallel num_threads(4)
#pragma omp for private(i) schedule(guided,100)
for(i=0;i<size;i++)
{
Gr[i]=(v[i][0]*0.21+v[i][1]*0.72+v[i][2]*0.07);
Y[i]=(0.299*v[i][0]+0.587*v[i][1] + 0.114*v[i][2]);
I[i]=(0.596*v[i][0]-0.275*v[i][1]-0.321*v[i][2]);
Q[i]=(0.212*v[i][0]-0.523*v[i][1]+0.311*v[i][2]);
}
t2=omp_get_wtime();
printf("Time taken =%lf s\n\n",t2-t1);
printf("4.parallel execution with 8 thread\n");
t1=omp_get_wtime();
#pragma omp parallel num_threads(8)
#pragma omp for private(i) schedule(guided,100)
for(i=0;i<size;i++)
{
Gr[i]=(v[i][0]*0.21+v[i][1]*0.72+v[i][2]*0.07);
Y[i]=(0.299*v[i][0]+0.587*v[i][1] + 0.114*v[i][2]);
I[i]=(0.596*v[i][0]-0.275*v[i][1]-0.321*v[i][2]);Q[i]=(0.212*v[i][0]-0.523*v[i][1]+0.311*v[i][2]);
}
t2=omp_get_wtime();
printf("Time taken =%lf s\n\n",t2-t1);
printf("5.parallel execution with 16 thread\n");
t1=omp_get_wtime();
#pragma omp parallel num_threads(16)
#pragma omp for private(i) schedule(guided,100)
for(i=0;i<size;i++)
{
Gr[i]=(v[i][0]*0.21+v[i][1]*0.72+v[i][2]*0.07);
Y[i]=(0.299*v[i][0]+0.587*v[i][1] + 0.114*v[i][2]);
I[i]=(0.596*v[i][0]-0.275*v[i][1]-0.321*v[i][2]);
Q[i]=(0.212*v[i][0]-0.523*v[i][1]+0.311*v[i][2]);
}
t2=omp_get_wtime();
printf("Time taken =%lf s\n\n",t2-t1);
return 0;
}
