#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	ofstream f;
	f.open("a.txt");
	int r;
	cout<<"Enter radius as input: ";
	cin>>r;
	cout<<endl;
	if(r>=75 && r<=85)
	{
		for(int i=0;i<=r;i++)
		{
			for(int j=0;j<=r;j++)
			{
				if((i*i+j*j)<(r*r))
				{
					cout<<"("<<-i<<","<<j<<")"<<",";
					f<<"("<<-i<<","<<j<<")"<<endl;
				}
			}
		}

	}
	else
	{
		cout<<"Error in input";
		f<<"Error in input";
	}
	f.close();
}