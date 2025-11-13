#include<bits/stdc++.h>

using namespace std;
using namespace std::chrono;

void helper(int i,vector<int> &arr, vector<int> &subset, int target) {
    if(target==0) {
        for(int i=0;i<subset.size();i++) {
            cout<<subset[i];
        }
        cout<<endl;
        return;
    }
    if(i == arr.size()) {
        return;
    }
    helper(i+1,arr,subset,target);
    if(arr[i] <= target) {
        subset.push_back(arr[i]);
        helper(i+1,arr,subset,target-arr[i]);
        subset.pop_back();
    }
}

int main() {
    int n;

    cout<<"Enter the number of elements: "<<endl;
    cin>>n;

    vector<int> arr(n,0);

    for(int i=0;i<n;i++) {
        cout<<"Enter element "<<i+1<<" :";
        cin>>arr[i];
    }

    cout<<"Enter the expected sum: "<<endl;
    int m;
    cin>>m;

    vector<int> subset;

    auto start = high_resolution_clock::now();

    helper(0,arr,subset,m);

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(stop - start);

    cout << "\nTime taken: " << duration.count() << " ms" << endl;

    return 0;


}