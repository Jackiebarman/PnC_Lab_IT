#include<bits/stdc++.h>
using namespace std;
bool is_valid(string &s,long long int &val)
{
    int cnt=0,start=0;
    bool y=true;
    for(int i=start;i<s.size();i++)
    {
        if(s[i]=='.')
            cnt++;
        else
        {
            if(cnt)
                continue;
            if(s[i]>='0'&&s[i]<='9')
                val=val*10+s[i]-'0';
            else
                return false;
        }
    }
    return cnt<=1 && val>=75 && val<=85;
}
int main(int argc,char* argv[])
{
    string T = "1",s,text;
    long long int r,n,x,y,val=0;
    cout<<"Enter radius:";
    cin>>s; 
    cout<<endl;
    vector<pair<int,int>>ans;
    bool condition=is_valid(s,val);
    if(condition)
    {
        r=val;
        for(x=0;x<r;x++)
        {
            for(y=0;y<r;y++)
            {
                if(x*x+y*y<r*r)
                {
                    cout<<-x<<","<<y<<endl;
                    ans.push_back({-x,y});
                }
            }
        }
    }
    else
        cout<<"Invalid Input\n";
    if(argc>1)
        T=argv[1];
    string outputfile = "181IT211_IT302_P1_Output_TC"+T+".txt";
    freopen(outputfile.c_str(),"w+",stdout);
    if(condition)
    {
        for(auto x:ans)
            cout<<"{x , y} = { "<<x.first<<" , "<<x.second<<" }"<<endl;
    }
    else
        cout<<"Invalid input\n";
}