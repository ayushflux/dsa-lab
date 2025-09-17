#include <stdio.h>

int power(int a, int b){
    int result=1;
    while(b>=1){
        result*=a;
        b--;
    }
    return result;
}

void counting(int *copy, int n, int c){
    int iter[n];
    int num[10];
    for(int j=0;j<10;j++){
        num[j]=0;
    }
    for(int j=0;j<n;j++){
        int k=(copy[j]%power(10,c))/power(10,c-1);
        num[k]++;
    }
    for(int j=1;j<10;j++){
        num[j]+=num[j-1];
    }
    for(int j=n-1;j>=0;j--){
        int k=(copy[j]%power(10,c))/power(10,c-1);
        iter[num[k]-1]=copy[j];
        num[k]--;
    }
    for(int j=0;j<n;j++){
        copy[j]=iter[j];
    }
    printf("\n");
    for(int i=0;i<n;i++){
        printf("%d ",copy[i]);
    }
        printf("\n");
}
void radix(int *arr, int n){
    int max=arr[0];
    for(int i=1;i<n;i++)max=arr[i]>max?arr[i]:max;
    int i=0;
    while(max!=0){
        i+=1;
        max/=10;
    }
    int c=0;
    int copy[n];
    for(int j=0;j<n;j++)copy[j]=arr[j];
    while(i--){
        c+=1;
        counting(copy,n,c);
    }
    for(int i=0;i<n;i++)arr[i]=copy[i];
}

int main(){
    int i;
    printf(" Enter number of elements in arr");
    scanf("%d",&i);
    int arr[i];
    for(int j=0;j<i;j++){
        printf("Enter array element ");
        scanf("%d",&arr[j]);
        printf("\n");
    }   
    radix(arr,i);
    printf("Sorted Array: ");
    for(int n=0;n<i;n++){
        printf("%d ",arr[n]);
    }
}