#include<stdio.h>
#include<limits.h>

int mss(int a[], int n){
    int maxSum = INT_MIN;
    for(int i=0; i<n; i++){
        int sum =0;
        for(int j=i; j<n; j++){
            sum += a[j];
            if(sum>maxSum){
                maxSum = sum;
            }
        }
    }
    return maxSum;
}

int main(int argc,char **argv){
    int a[] = {-3,1,-8,12,0,-3,5,-9,4};
    int n = sizeof(a)/sizeof(a[0]);
    int maxSum = mss(a,n);

    printf("\n Maximum Subarray sum is %d", maxSum);
}