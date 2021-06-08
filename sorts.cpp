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
        if (arr[j] < arr[min_idx]){
            min_idx = j;
        }
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

void merge(int arr[], int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;
 
    int L[n1], R[n2];
 
    
    for (int i = 0; i < n1; i++){ L[i] = arr[l + i];}
    for (int j = 0; j < n2; j++){ R[j] = arr[m + 1 + j];}
    
    int i = 0;

    int j = 0;
 
    int k = l;
 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int* arr,size_t l,size_t r){
if(l>=r){
        return;
    }
    int m =l+ (r-l)/2;
    merge_sort(arr,l,m);
    merge_sort(arr,m+1,r);
    merge(arr,l,m,r);
}

int partation(int* arr,size_t l,size_t r){
    int base = arr[r];
    int i = l-1;

    for (size_t j = 0; j <= r-1 ; i++)
    {
        if(arr[j] < base){
            ++i;
            std::swap(arr[i],arr[j]);   
        }
    }
    std::swap(arr[i+1],arr[r]);
    return i+1;
}

void quick_sort(int* arr,size_t l,size_t r){
    if(l<r){
        int b = partation(arr,l,r);

        quick_sort(arr,l,b-1);
        quick_sort(arr,l+b,r);
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

   //Merge Sort
   merge_sort(arr,0,n);
   std::cout << std::endl;
   display(arr,n);
   std::cout << std::endl;

   //Quick Sort
   quick_sort(arr,0,n-1);
   std::cout << std::endl;
   display(arr,n);
   std::cout << std::endl;
}
