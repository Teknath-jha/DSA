#include<bits/stdc++.h>
using namespace std;

void code(){
    #ifndef ONLINE_JUDGE
    freopen("T:\\C++\\input.txt", "r", stdin);
    freopen("T:\\C++\\output.txt", "w", stdout);
    #endif
}

int getLeftBound(vector<int>& v, int target){
    int n = v.size();
    int low=0;
    int high=n-1;

    while(low<=high){

        int mid = (low+high)/2;

        if(v[mid]==target){
            if(mid==0)
                return 0;
            else{
                if(v[mid-1]!=target)
                    return mid;
                else 
                    high=mid-1;
            }
            continue;
        }

        if(v[mid]<target)
            low=mid+1;
        else 
            high=mid-1;

    }
    return -1;
}


int getRightBound(vector<int>& v, int target){
    int n = v.size();
    int low=0;
    int high=n-1;

    while(low<=high){

        int mid = (low+high)/2;

        if(v[mid]==target){
            if(mid==(n-1))
                return (n-1);
            else{
                if(v[mid+1]!=target)
                    return mid;
                else 
                    low=mid+1;
            }
            continue;
        }

        if(v[mid]<target)
            low=mid+1;
        else high=mid-1;

    }
    return -1;
}


int main(){

    code();

    int n;
    int target;

    cin>>n>>target;
    vector<int> v(n);

    for(int i=0; i<n; i++)
        cin>>v[i];

    v.resize(n);

    int  leftBound  =  getLeftBound(v,target);
    int  rightBound = getRightBound(v,target);

    cout<<"leftBound: "<<leftBound<<endl;
    cout<<"rightBound: "<<rightBound<<endl;

}