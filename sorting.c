#include<stdio.h>
#include<stdlib.h>
#define size 20
void swap(int *a,int *b){
	*b=*a+*b-(*a=*b);
}
void bubble_sort(int arr[],int n){
	int i,j;
	for(i=0;i<n-1;i++)
		for(j=0;j<n-i-1;j++)
			if(arr[j]>arr[j+1])
				swap(&arr[j],&arr[j+1]);
}
void selection_sort(int arr[],int n){
	int i,j;
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if(arr[j]<arr[i])
				swap(&arr[j],&arr[i]);
}
void insetion_sort(int arr[],int n){
	int i,j,temp;
	for(i=1;i<n;i++){
		temp=arr[i];
		for(j=i-1;j>=0&&arr[j]>temp;j--)
			arr[j+1]=arr[j];
		arr[j+1]=temp;
	}
}

void merge1(int arr[],int left,int mid,int right){
	//int s=right-left+1;
	//int *temp_arr=(int*)calloc(s,sizeof(int));
	int temp_arr[size];
	int l=left;
	int r=mid+1;
	int t=left;
	int i;

	while(l<=mid && r<=right){
		if(arr[l]<=arr[r])
			temp_arr[t++]=arr[l++];
		else
			temp_arr[t++]=arr[r++];
	}
	while(l<=mid)
		temp_arr[t++]=arr[l++];
	while(r<=right)
		temp_arr[t++]=arr[r++];
	for(i=left;i<=right;i++)
		arr[i]=temp_arr[i];
}
void merge_sort(int arr[],int left,int right){
	int mid;
	if(left>=right)
		return;
	mid=(right+left)/2;
	merge_sort(arr,left,mid);
	merge_sort(arr,mid+1,right);
	merge1(arr,left,mid,right);
}

int partition(int arr[],int left,int right){
	int pivot,i,l;
	pivot=arr[right];
	idx=left;
	for(i=left;i<right;i++)
		if(pivot>arr[i])
			swap(&arr[i],&arr[idx++]);
	swap(&arr[idx],&arr[right]);
	return idx;
}
void quick_sort(int arr[],int left,int right){
	if(left>=right)
		return;
	int p=partition(arr,left,right);
	quick_sort(arr,left,p-1);
	quick_sort(arr,p+1,right);
}
int main(){
	int arr[size];
	int i,n,ch;
	printf("Enter the size of array = ");
	scanf("%d",&n);
	printf("Enter the %d element of array:\n",n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("1.Bubble Sort\n2.Selction Sort\n3.Insertion Sort\n4.Merge Sort\n5.Quick Sort\n");
	printf("Enter your choise = ");
	scanf("%d",&ch);
	printf("Before the sorting\n");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	switch(ch){
		case 1:
			bubble_sort(arr,n);
			break;
		case 2:
			selection_sort(arr,n);
			break;
		case 3:
			insetion_sort(arr,n);
			break;
		case 4:
			merge_sort(arr,0,n-1);
			break;
		case 5:
			quick_sort(arr,0,n-1);
			break;
		default:
			printf("Invalid Input!");
			break;
	}
	printf("\nAfter the sorting\n");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
}
