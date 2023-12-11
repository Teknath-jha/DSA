#include<bits/stdc++.h>
using namespace std;

map<char,string> mp;

void generateAllPossibleValues(string s,string ans, int n,int i)
{
    if(ans.length()==n){
        cout<<ans<<endl; 
        return;
    }

    for(;i<n;i++){

        for(int j=0;j<mp[s[i]].length();j++){

            generateAllPossibleValues(s,ans+mp[s[i]][j],n,i+1);

        }

    }
}

int main(){

mp['2'] = "abc";
mp['3'] = "def";
mp['4'] = "ghi";
mp['5'] = "jkl";
mp['6'] = "mno";
mp['7'] = "pqrs";
mp['8'] = "tuv";
mp['9'] = "wxyz";
string s="23";
int n = s.length();
generateAllPossibleValues(s,"",n,0);

}