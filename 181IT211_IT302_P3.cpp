#include<bits/stdc++.h>
using namespace std;
#define loop(i,k,n)  for(int i=k;i<n;i++)
#define ll long long int
// check if no is a positive integer
bool is_valid(string &s,int  &val)
{

    int start=0;
    bool y=true;
    while(start<s.size()&&s[start]==' ')            // if input is number but space are ahead of it
        start++;
    if(start<s.size()&&s[start]=='-')
        return false;
    for(int i=start;i<s.size();i++)
    {
        if(s[i]=='.')                           
            return false;
        else
        {
            if(s[i]>='0'&&s[i]<='9')
                val=val*10+s[i]-'0';
            else
                return false;
        }
    }
  return true;            // also check for null input
}
//
int fact(int val)
{
  if(val==0 || val==1)
    return 1;
  else
  {
    return val*fact(val-1);
  }
}

int findCombination(int n,int r)
{
  ll x=fact(n);
  ll y=fact(n-r);
  ll z=fact(r);
  //z=z*y;
  return x/(y*z);
}

int main(int argc,char* argv[])
{
  //discrete so n must be int pos
  // a must be positive int
  // c pos/neg ??
  // can m be neg/pos deci?
    //double m;
    string r,m,n;
    string find_name,input,T="1";
    cout<<"\nEnter the values of r, m and n:";
    cin>>r>>m>>n;
    int val_n=0,val_r=0,val_m=0;
    double  sum=0.0,val_c,sum2=0.0;
    bool condition =false;
    if(is_valid(r,val_r) && is_valid(n,val_n) && is_valid(m,val_m))    //m ??
    {
      //cout<<val_n<<endl;
      //cout<<val_r<<endl;
      //cout<<val_m<<endl;
      condition=true;
      for(int i=0;i<=val_n;i++)  
      {
           if(val_r<=i && val_m-i<=val_m)
           {
             sum+=findCombination(i,val_r)*findCombination(val_m,val_m-i);
             //cout<<sum<<endl;
           }
      }  
      cout<<"\nIntermediate Results: ";
      cout<<"\nValue of sum:"<<sum;
      val_c=1.0/sum;      
      cout<<"\n\nValue of c:"<<val_c;
      double res=0.0;
      for(int i=0;i<=val_n;i++)
      { 
        if(val_r<=i && val_m-i<=val_m)
        {
        res=val_c*(findCombination(i,val_r)*findCombination(val_m,val_m-i));
        cout<<"\nValue for x:"<<i<<" =>"<<res;   
        }
        else
        {
          cout<<"\nValue for x:"<<i<<" is not possible, invalid combination";
        }     
      }
    }
    else
    {
      cout<<"\nInvalid input";
    }
    cout<<"\n";
//////////////////////////////////////////////////////////////////////////////////////
//                                      For file                                    //
/////////////////////////////////////////////////////////////////////////////////////

    if(argc>1)
        T=argv[1];      // i.e ./a.out 2    so T=2 ,implying second test case
    string outputfile = "181IT211_IT302_P3_Output_TC"+T+".txt"; 
    freopen(outputfile.c_str(),"w+",stdout);
    if(condition)
    {

      cout<<"\nIntermediate Results";
      cout<<"\nValue of sum:"<<sum;
      val_c=1.0/sum;      
      cout<<"\nValue of c:"<<val_c;
      double res=0.0;
      for(int i=0;i<=val_n;i++)
      { 
        if(val_r<=i && val_m-i<=val_m)
        {
        res=val_c*(findCombination(i,val_r)*findCombination(val_m,val_m-i));
        cout<<"\nValue for x:"<<i<<" =>"<<res;   
        }
        else
        {
          cout<<"\nValue for x is not possible, invalid combination";
        }      
      }
    }
    else
        cout<<"Invaid input";
}