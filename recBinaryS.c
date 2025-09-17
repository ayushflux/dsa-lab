#include <stdio.h>

int binarySearch(int arr[], int low, int high, int key){
        int mid = (low + high)/2;
        if(arr[mid]==key)return mid;
        else{
            if(arr[mid]>key)return binarySearch(arr,low,mid-1,key);
            else{
                   return binarySearch(arr, mid+1, high, key);
            }
        }
        return -1;
}

int main(){
    int i;
    printf(" Enter number of elements in arr");
    scanf("%d",&i);
    int arr[i];
    for(int j=0;j<i;j++){
        printf("Enter array element ");
        scanf("%d",&arr[j]);
    }
    char c= 'y';
    while(c=='y'){
        int key;
        printf("Enter key to search");
        scanf("%d", &key);
        printf("Element found @ %d\n", binarySearch(arr, 0, i, key));
        printf("Enter y to continue");
        scanf("%c",&c);
    }
    
}