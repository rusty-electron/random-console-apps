#include<bits/stdc++.h>
using namespace std;

long long kadane(int list[], int n){
    long long max_so_far = INT_MIN;
    long long max_till_here = 0;

    for(int i=0;i<n;i++){ 
            max_till_here = max_till_here + list[i];
            if (max_so_far < max_till_here)
                max_so_far = max_till_here;
            if (max_till_here < 0)
                max_till_here = 0;
        }
    return max_so_far;
}

long long doStuff(int list[], int k, int n){
    long long kadane_val = kadane(list, n);
    if(k == 1){
        return kadane_val;
    }

    long long prefix_sum = 0, suffix_sum = 0;
    long long max_prefix = INT_MIN, max_suffix = INT_MIN;

    for(int i=0;i<n;i++){
		prefix_sum = prefix_sum +list[i];
		max_prefix = max(prefix_sum,max_prefix);
	}
	long long sum = prefix_sum;
	for(int i=n-1;i>=0;i--){
		suffix_sum = suffix_sum +list[i];
		max_suffix = max(max_suffix, suffix_sum);
	}

    if (sum > 0)
        return max((max_suffix + max_prefix + sum*(k-2)), kadane_val);
    else 
        return max((max_suffix + max_prefix), kadane_val);
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