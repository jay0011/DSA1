#include<stdio.h>
#define MAX 20
void Bsort(int arr[],int n){
	int i,j,temp;
	for(i=0;i<n-1;i++)
		for(j=0;j<n-i-1;j++)
			if(arr[j]>arr[j+1]){
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
}
void binary_search(int arr[],int n,int key){
	int left=0;
	int right=n-1;
	int mid,i,flag=1,ct=0;
	while(left<=right){
		ct++;
		mid=(left+right)/2;
		if(arr[mid]==key){
			printf("Sorted array:\n");
			for(i=0;i<n;i++)
				printf("%d ",arr[i]);
			printf("\n");
			printf("The searching value found in %d position of sorted array.\n",mid+1);
			printf("Number of iterations for binary search = %d\n",ct);
			flag=0;
			return;
		}
		else if(key<arr[mid])
			right=mid-1;
		else
			left=mid+1;
	}
	if(flag)
		printf("The searching value not found!\n");
}
void interpolation_search(int arr[],int n,int key){
	int left=0;
	int right=n-1;
	int mid,i,flag=1,ct=0;
	while(left<=right){
		ct++;
		mid=left+(((double)(right-left)/(arr[right]-arr[left]))*(key-arr[left]));
		if(arr[mid]==key){
			printf("Sorted array:\n");
			for(i=0;i<n;i++)
				printf("%d ",arr[i]);
			printf("\n");
			printf("The searching value found in %d position of sorted array.\n",mid+1);
			printf("Number of iterations for interpolation search = %d\n",ct);
			flag=0;
			return;
		}
		else if(key<arr[mid])
			right=mid-1;
		else
			left=mid+1;
	}
	if(flag)
		printf("The searching value not found!\n");
}
int main(){
	int i,n,key;
	int arr[MAX];
	printf("Enter the nummber of elements = ");
	scanf("%d",&n);
	printf("Enter the elements of array:\n");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("Enter the searching value = ");
	scanf("%d",&key);
	printf("Given array:\n");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
	Bsort(arr,n);
	binary_search(arr,n,key);
	interpolation_search(arr,n,key);
}
