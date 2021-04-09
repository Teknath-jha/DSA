#include<bits/stdc++.h>
using namespace std;

#define MAX 100005
int parent[MAX];
int n;

int find(int a)
{
    while(parent[a]>0)
    a=parent[a];

    return a;
}

void Union(int a,int b)
{
    parent[a]+=parent[b];
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

    memset(parent,-1,sizeof(parent));

    for(int i=1;i<=m;i++)
    {
        int a,b;cin>>a>>b;
        a=find(a);b=find(b);

        if( a!=b )
        Union(a,b);
        else cout<<"In same set \n";
        print();
    }


    while(1)
    {
        int a,b;cin>>a>>b;

        if(a==0 && b==0)break;

        a=find(a);b=find(b);

        if(a!=b)
        Union(a,b);
        print();


    }
print();

    return 0;
}