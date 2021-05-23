#include <bits/stdc++.h> 
using namespace std; 
  
// Function to find the nCr 
long long printNcR(int n, int r) 
{ 
    long long p = 1, k = 1; 
    if (n - r < r) 
        r = n - r; 
  
    if (r != 0) { 
        while (r) { 
            p *= n; 
            k *= r; 
  
            // gcd of p, k 
            long long m = __gcd(p, k); 
            p /= m; 
            k /= m; 
  
            n--; 
            r--; 
        } 
    } 
  
    else
        p = 1; 
    return p;
} 
int main() 
{ 
	string s1,s2,s3;
	int n,m;
    double p;
	cout<<"Enter the probability that a patient recovers from a rare blood disease(p):";
	cin>>s1;
	for(int i=0;i<s1.size();i++)
	{
		if((s1[i]<'0' || s1[i]>'9')&&(s1[i]!='.') )
		{
			cout<<"Sorry!!! Enter valid input(double)."<<endl;
			exit(0);
		}
	}
    p=stod(s1);
    if(p>1)
    {
    	cout<<"Sorry!!! Enter valid input(0<=p<=1)."<<endl;
			exit(0);
    }
	//cin>>p;
    cout<<"Enter total number of people who are known to have contracted this disease(N):";
	cin>>s2;
	for(int i=0;i<s2.size();i++)
	{
		if(s2[i]<'0' || s2[i]>'9')
		{
			cout<<"Sorry!!! Enter valid input(integer)."<<endl;
			exit(0);
		}
	}
	n=stoi(s2);
	//cin>>n;
	cout<<"Enter the number M, to find the probability that exactly M survive:";
	cin>>s3;
	for(int i=0;i<s3.size();i++)
	{
		if(s3[i]<'0' || s3[i]>'9')
		{
			cout<<"Sorry!!! Enter valid input(integer)."<<endl;
			exit(0);
		}
	}
	m=stoi(s3);

	if(n<m)
	{
		cout<<"Sorry!!! Enter valid input(n should be greater than m in nCm)."<<endl;
		exit(0);
	}
    //cin>>p>>n>>m; 
     ////x,n,p
    double res1,res2;
    long long ncm=printNcR(n, m); 
    res1=pow(p,m);
    res2=pow(1-p,n-m);
    ///
    // cout<<"\nPower(p,m):"<<res1<<endl;
    // cout<<"Power(1-p,n-m):"<<res2<<endl;
    // cout<<"Combination(nCm):"<<ncm<<endl;
    ///Final Output b(m,n,p)===b((nCm)*pow(p,m)*pow(1-p,n-m))
    cout<<endl;
    cout<<"Final OUTPUT:"<<ncm*res1*res2<<endl;
    return 0; 
} 