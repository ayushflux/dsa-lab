//{4,5,9,1,2,3}

#include <stdio.h>

int binarySearch(int arr[], int n, int key){
    int low=0;
    int high=n-1;
    int mid;
    while(low<=high){
        mid=(low+high)/2;
        if(arr[mid]==key){
            return mid;
        }else{
            if(arr[mid]>=arr[low]){   //here the sorted part is in focus i.e. between low and mid
                if(key>=arr[low]&&key<=arr[mid]){
                    high=mid-1;
                }else{
                    low=mid+1;
                }
                }else{ //here the unsorted part is in focus i.e. between low and mid
                    if(key>=arr[mid]&&key<=arr[high]){
                        low=mid+1;
                    }else{
                        high = mid-1;
                    }
                }
            }
        }
    return -1;
    }


int main(){
    int a[]={4,5,4,4,4,4};
    printf("%d",binarySearch(a,6,5));
}