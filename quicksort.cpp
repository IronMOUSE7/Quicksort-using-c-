#include<iostream>

using namespace std;

void quicksort(int arr[],int low,int high);
int partition(int arr[],int low,int high);
void swap(int arr[],int i,int j);

void swap(int arr[],int i,int j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

void quicksort(int arr[],int low,int high){
    if(low<high){
        int pidx=partition(arr,low,high);
        
        quicksort(arr,low,pidx-1);
        quicksort(arr,pidx+1,high);
    }
}

int partition(int arr[],int low, int high){
    int pivot=arr[high];
    int i=low-1;
    
    for(int j=low;j<high;j++){
        if(arr[j]<pivot){
            i++;
            //swap
            swap(arr,i,j);
        }
    }
    swap(arr,i+1,high);
    return i+1;
}

int main(){
    
    int arr[100],n;
    
    cout<<"enter the size of the array = ";
    cin>>n;
    
    cout<<"enter the elements = ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
        
    }

    
    quicksort(arr,0,n-1);
    
    
    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    

    
    return 0;
    
}