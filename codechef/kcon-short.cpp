#include<bits/stdc++.h>
using namespace std;

long long kadane(int list[], int n){
    long long max_so_far = INT_MIN;
    long long max_till_here = 0;

    for(int i=0;i<2*n;i++){ 
            max_till_here = max_till_here + list[i%n];
            if (max_so_far < max_till_here)
                max_so_far = max_till_here;
            if (max_till_here < 0)
                max_till_here = 0;
        }
    return max_so_far;
}

long long doStuff(int list[], int k, int n){
    long long sum = 0;
    long long kadane_val = kadane(list, n);

    for (int i=0;i<n;i++){
        sum+=list[i];
    }
    if (sum > 0)
        return kadane_val + sum*(k-2);
    else 
        return kadane_val;
}

int main(){
    int number;
    int k,n;
    
    cin>>number;
    // input loop
    for(int i=0;i<number;i++){
        cin>>n>>k;

        int list[n];
        // array A input and check for all positive case
        for(int i=0;i<n;i++){
            cin>>list[i];
        }
        cout<<doStuff(list, k, n)<<endl;
    }
    return 0;
}