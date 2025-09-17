#include <stdio.h>

typedef struct{
	int row;
	int clm;
	int value;
}Triple;
void cpy(Triple *b, Triple *a){
	b->clm=a->clm;
	b->row=a->row;
	b->value=a->value;
}
void cpy2(Triple *b, Triple *a){
	b->clm=a->row;
	b->row=a->clm;
	b->value=a->value;
}
void fast_tr(Triple arr[]){
	int n=arr[0].value;
	Triple copy[n+1];
	int max=arr[1].clm;
	int rows=arr[0].row;
	int clms=arr[0].clm;
	arr[0].clm=rows;
	arr[0].row=clms;
	arr[0].value=n;
	for(int i=1;i<=n;i++){
		cpy(&copy[i],&arr[i]);
		max=(arr[i].clm>max)?(arr[i].clm):max;
	}
	int twop[max+1];
	for(int i=0;i<=max;i++){
		twop[i]=0;
	}
	for(int i=1;i<=n;i++){
		twop[arr[i].clm]+=1;
	}
	for(int i=1;i<=max;i++){
		twop[i]+=twop[i-1];
	}
	for(int i=n;i>=1;i--){
		cpy2(&arr[twop[copy[i].clm]],&copy[i]);
		twop[copy[i].clm]--;
	}
	
}

int main(){
	int n;
	printf("Enter number of elements: ");
	scanf("%d",&n);
	printf("\n");
	Triple arr[n];
	for(int i=0;i<n;i++){
		printf("Enter row: ");
		scanf("%d",&(arr[i].row));
		printf("Enter clm: ");
		scanf("%d",&(arr[i].clm));
		printf("Enter value: ");
		scanf("%d",&(arr[i].value));
	}
	printf("Input:\n");
	for(int i=0;i<n; i++){
		printf("%d  %d  %d\n",arr[i].row, arr[i].clm, arr[i].value);
	}
	fast_tr(arr);
	printf("Output:\n");	
	for(int i=0;i<n; i++){
		printf("%d  %d  %d\n",arr[i].row, arr[i].clm, arr[i].value);
	}


}
