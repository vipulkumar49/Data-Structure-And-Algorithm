// { Driver Code Starts
//Initial Template for C

#include <stdio.h>
#include <stdbool.h>


 // } Driver Code Ends
//User function Template for C

// Function to find majority element in the array
// a: input array
// size: size of input array
int majorityElement(int a[], int size) {
    int index = 0, cnt = 1;
    int n = size;
    for(int i = 1; i < n; i++) {
        if(a[i] == a[index]) 
            cnt++;
        else 
            cnt--;
        if(cnt == 0) {
            index = i;
            cnt = 1;
        }
    }
    int max_cnt = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] == a[index]) 
            max_cnt++;
    }
    if(max_cnt > n / 2) return a[index];
    else return -1;
}

// { Driver Code Starts.

int main(){

    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);
        int arr[n];
        
        for(int i = 0;i<n;i++){
            scanf("%d", &arr[i]);
        }
        printf("%d\n", majorityElement(arr, n));
    }

    return 0;
}
  // } Driver Code Ends