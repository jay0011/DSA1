#include<bits/stdc++.h>
using namespace std;
void swap(int &a,int &b){
	b=a+b-(a=b);
}
class Heap{
	public:
	int MAX;
	int idx;
	int *arr;
	Heap(int x){
		MAX=x;
		idx=0;
		arr=new int[x];
	}

	int parent(int i){	return ((i-1)/2);	}
	int left(int i){	return (2*i+1);		}
	int right(int i){	return (2*i+2);		}

	void insert_heap(int data){
		if(idx==MAX){
			printf("Overflow Condition!");
			return;
		}
		int i=idx;
		arr[i]=data;

		while(i>0 && (arr[parent(i)]>arr[i])){
			swap(arr[parent(i)],arr[i]);
			i=parent(i);
		}
		idx++;
	}

	void print_heap(){
		for(int i=0;i<idx;i++)
			cout<<arr[i]<<" ";
		cout<<endl;
	}

	int index_search(int key){
		for(int i=0;i<idx;i++)
			if(arr[i]==key)
				return i;
		return -1;
	}
	void heapify(int idx,int index){
		int i=index;
		int l=left(i);
		int r=right(i);

		if(l<idx && arr[i]>arr[l])	i=l;
		if(r<idx && arr[i]>arr[r])	i=r;

		if(i!=index){
			swap(arr[i],arr[index]);
			heapify(idx,i);
		}
	}
	int extract_root(){
		if(idx<=0)	return INT_MAX;
		if(idx==1)	return arr[--idx];

		int root=arr[0];
		arr[0]=arr[--idx];
		heapify(idx,0);
		return root;
	}
	void delete_heap(int key){
		int i=index_search(key);
		arr[i]=INT_MIN;
		while(i>0 && (arr[parent(i)]>arr[i])){
			swap(arr[parent(i)],arr[i]);
			i=parent(i);
		}
		extract_root();
	}
	void heap_sort(){
		// int *temp=(int*)calloc(idx,sizeof(int));
		// for(int i=0;i<idx;i++){
		// 	temp[i]=extract_root();
		// 	cout<<temp[i]<<" ";
		// }
		//For heap sorting two arguments is mandatory for heapify function  
		int i=idx-1;
		while(i>0){
			swap(arr[i],arr[0]);
			i--;
			heapify(i,0);
		}
	}
	int height(){
		return ceil(log2(idx + 1)) - 1;
	}
	int get_root(){
		return arr[0];
	}
};
int main(){
	int s;
  	cout << "Enter Size of Min Heap" << endl;
  	cin >> s;
	Heap obj(s);
	int option, val;

  	do {
    	cout << "1. Insert Key/Node" << endl;
    	cout << "2. Search Key/Node" << endl;
    	cout << "3. Delete Key/Node" << endl;
    	cout << "4. Get Min" << endl;
    	cout << "5. Extract Min" << endl;
    	cout << "6. Height of Heap" << endl;
    	cout << "7. Print/Traversal Heap values" << endl;
    	cout << "8. Clear Screen" << endl;
    	cout << "0. Exit Program" << endl;
    	cin >> option;

    switch (option) {
    	case 0:
    	  break;
    	case 1:
    	  cout << "INSERT Operation -" << endl;
    	  cout << "Enter VALUE to INSERT in HEAP: ";
    	  cin >> val;
    	  obj.insert_heap(val);
    	  cout << endl;
    	  break;
    	case 2:
    	  cout << "SEARCH Operation -" << endl;
    	  cout << "Enter VALUE to SEARCH in HEAP: ";
    	  cin >> val;
    	  cout << "Found at index = " << obj.index_search(val)+1 << endl;
    	  break;
    	case 3:
    	  cout << "DELETE Operation -" << endl;
    	  cout << "Enter INDEX of Heap Array to DELETE: ";
    	  cin >> val;
    	  obj.delete_heap(val);
    	  break;
    	case 4:
    	  cout << "GET Min value : " << obj.get_root();
    	  cout << endl;
    	  break;
    	case 5:
    	  cout << "EXTRACT Min value : " << obj.extract_root();
    	  cout << endl;
    	  break;
    	case 6:
    	  cout << "HEAP TREE HEIGHT : " << obj.height() << endl;
    	  break;
	
    	case 7:
    	  cout << "PRINT Heap Array : " << endl;
    	  obj.print_heap();
    	  cout << endl;
    	  break;
	
    	case 8:
    	  system("cls");
    	  break;
	
    	default:
    	  cout << "Enter Proper Option number " << endl;
    	}
	
  	} while (option != 0);
  	cout << "Heap Sorted Array :" << endl;
  	obj.heap_sort();
//   	for(int i=0;i<idx;i++)
//   		cout << arr[i] <<" ";
//   	cout<<endl;
  	obj.print_heap();
	}
