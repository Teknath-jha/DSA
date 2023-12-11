#include<bits/stdc++.h>
using namespace std;

void code(){
    #ifndef ONLINE_JUDGE
    freopen("T:\\C++\\input.txt", "r", stdin);
    freopen("T:\\C++\\output.txt", "w", stdout);
    #endif
}


int getInsertPosition(vector<int> &v, int target){

    int n=v.size();

    int low =0;
    int high =n-1;

    while(low<=high){
        int mid = (low+high)/2;

        if(v[mid]==target)
            return mid;

        if(v[mid]<target)
            low= mid+1;
        else
            high = mid-1;

    }
    return low;
}


int main(){

    code();

    int n,target;
    cin>>n>>target;

    vector<int> v(n);

    for(int i=0;i<n;i++)
        cin>>v[i];

    int result  =  getInsertPosition(v,target);

    cout<<result<<endl;

}