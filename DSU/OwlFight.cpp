

//here instead of no. of nodes in a set 
//we store maximum no. in set who would win
//read question for more





#include<bits/stdc++.h>
using namespace std;

#define MAX 100005
#define mod 1000000007
int parent[MAX];
int n;

int find(int a)
{
    
    vector<int> v;
    while(parent[a]>0)
    {
        v.push_back(a);
        a=parent[a];
    }
    
    for(int x:v)
    parent[x]=a;
    

    return a;
}

void Union(int a,int b)
{
    parent[a]=min(parent[a],parent[b]);
    parent[b]=a;
    
}

//For debugging 
void print()
{
    for(int i=1;i<=n;i++)
    cout<<i<<" ";

    cout<<endl;

    for(int i=1;i<=n;i++)
    cout<<parent[i]<<" ";
    cout<<endl;
}

int main()
{

    int m;
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    parent[i]=-i;

    for(int i=1;i<=m;i++)
    {
        int a,b;cin>>a>>b;
        a=find(a);b=find(b);

        if( a!=b )
        Union(a,b);
    
    }
    
int q;cin>>q;
while(q--)
{
int a,b;cin>>a>>b;

 int  x=find(a);
  int y=find(b);
  
  if(parent[x]==parent[y])
  cout<<"TIE\n";
  else if(parent[x] > parent[y])
  cout<<b<<'\n';
  else cout<<a<<'\n';

}


    return 0;
}