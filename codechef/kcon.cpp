#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
    int number;
    bool allpos = true, allneg = true;
    long sum = 0;

    cin>>number;
    for(int i=0;i<number;i++){
        int k, n;
        cin>>n>>k;
        int list[n];
        // array A input and check for all positive case
        for(int j=0;j<n;j++){
            cin>>list[j];
            if (list[j] < 0) {
                allpos = false;
            }
            if (list[j] > 0){
                allneg = false;
            }
        }
        // check for cases
        if (allpos == true){
            // all elements are positive so simply compute total sum of all elements
            for(int j=0;j<n;j++){
                sum +=list[j];
            }
            sum*=k;
        }else if (allneg == true){ // all elements are negative so simply print out the least negative value
            int max= list[0];
            for(int j=1;j<n;j++){
                if(list[j] > max){
                    max = list[j];
                }
            }
            sum = max;
        }else{
            int new_bin = 0;
            int big_bin = 0;

            int big_list[2*n];
            for(int i=0;i<2*n;i++){ // concatenate two A arrays
                if(i<n)
                    big_list[i] = list[i];
                else
                    big_list[i] = list[i-n];
            }

            for (int i=0;i<2*n;i++){ //left bound
                if(big_list[i] < 0){
                    for (int j=i+1;j<2*n;j++){ //right bound
                        if(big_list[j] < 0){
                            for(int k=i+1;k<j;k++){ // calculating bin total
                                new_bin += big_list[k];
                            }
                            if (new_bin > big_bin){
                                big_bin = new_bin;   
                            }new_bin=0;
                        }
                    }
                }
            } 
            sum = big_bin;
        }

    cout<<sum<<endl;
    }
    return 0;
}