#include <iostream>

void display(int* arr,size_t n){
    for(int i = 0; i < n;++i){
        std::cout << arr[i] << " ";
    }
}

void insert_elements(int* arr,size_t n){
    std::cout << "Insert Elements" << '\n';
    for(int i = 0;i < n;++i){
        std::cin >> arr[i];
    }
}

void bubble_sort(int* arr,size_t n){
    for(int i = 0;i < n;++i){
        for(int j = 0;j < n;++j){
            if(arr[i] < arr[j]){
                 std::swap(arr[i],arr[j]);
            }
        }
    }
}

void selection_sotr(int* arr,size_t n){
    int min_idx = 0;

    for (int i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (int j = i+1; j < n; j++)
        if (arr[j] < arr[min_idx])
            min_idx = j;
 
        std::swap(arr[min_idx], arr[i]);
    }    
}

void insertion_sort(int* arr, size_t n){
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


int main(){
   size_t n;
   std::cout << "Enter the size of arr" << '\n';
   std::cin >> n;
   int arr[n];
   insert_elements(arr,n);
   std::cout << std::endl;

   //Bubble Sort
   bubble_sort(arr,n);
   std::cout << std::endl;
   display(arr,n);
   std::cout << std::endl;

   //Selection Sort
   selection_sotr(arr,n);
   std::cout << std::endl;
   display(arr,n);
   std::cout << std::endl;

   //Isertion Sort
   insertion_sort(arr,n);
   std::cout << std::endl;
   display(arr,n);
   std::cout << std::endl;
}