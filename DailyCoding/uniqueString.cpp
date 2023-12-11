#include<bits/stdc++.h>
using namespace std;


int n=3;
vector<string> v;
void allString(string s){

    if(s.length()==n)
    {
            v.push_back(s);
            s="";
            return;
    }

    allString(s+"0");
    allString(s+"1");
}

int main(){

    allString("");

    for(auto x:v)
        cout<<x<<endl;
    
}