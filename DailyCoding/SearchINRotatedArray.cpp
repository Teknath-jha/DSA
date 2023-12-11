#include<bits/stdc++.h>
using namespace std;

void code(){
    #ifndef ONLINE_JUDGE
    freopen("T:\\C++\\input.txt", "r", stdin);
    freopen("T:\\C++\\output.txt", "w", stdout);
    #endif
}

int searchInRotatedSortedArrray(vector<int> &v , int target){
    int n = v.size();
    int low = 0;
    int high = n-1;

    while(low <= high){

        int mid = (high + low)/2;

        if(v[mid]== target)
            return mid;

        //left half
        if(v[low]<=v[mid]){
            if(target>=v[low] and target <=v[mid])
                high=mid-1;
            else
                low = mid+1;
        }
        //means right half is sorted As Either left or right will always be sorted 
        else{
            if(target>= v[mid] and target <=v[high])
                low=mid+1;
            else
                high = mid-1;
        }
    }
    return -1;
}

int main(){

    code();
    int n; //array size
    int target; //target
    cin>>n>>target;
    vector<int> v(n);
    for(int i=0; i<n; i++)
        cin>>v[i];
    
    v.resize(n);

    int result = searchInRotatedSortedArrray(v,target);

    cout<<"Element at : "<<result;

}