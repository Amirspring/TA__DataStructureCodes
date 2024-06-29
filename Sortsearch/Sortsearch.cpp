// Amirhossien hatamikhah 4001406118

#include <iostream>
using namespace std;
// Function to perform bubble sort on an array
void BubbleSort(int array[], int size) {
	//Loop through each element of the array
    for (int i = 0; i < size; i++) {
       for (int j = 0; j < size - 1; j++) {
            if (array[j] > array[j + 1]) 
                swap(array[j],array[j+1]);
        }
    }
}
// Function to perform insertion sort on an array
void InsertionSort(int a[], int n){
    for (int i = 1; i < n; i++){
        int k = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > k){
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = k;
    }
}

void merge(int arr[], int front, int middle, int rear) {
    int n1 = middle - front + 1;
    int n2 = rear - middle;
    int L[n1], M[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[front + i];
    for (int j = 0; j < n2; j++)
	    M[j] = arr[middle + 1 + j];
    int i, j, k;
    i = 0;
    j = 0;
    k = front;

    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            arr[k] = L[i];
            i++;
        } 
		else {
            arr[k] = M[j];
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
        arr[k] = M[j];
        j++;
        k++;
    }
}
/*Function to perform merge sort on an array
f = front
m = middle
r = reat
*/
void mergeSort(int arr[], int f, int r) {
    if (f < r) {
        int m = (f + r) / 2;
        mergeSort(arr, f, m);
        mergeSort(arr, m + 1, r);
        merge(arr,f,m,r);
    }
}
// Function to perform selection sort on an array
void selectionSort(int arr[], int n) {
    // Loop through each element of the array except the last one
    for (int i = 0; i < n-1; i++) {
        // Assume the first unsorted element is the minimum
        int minIndex = i;
        // Compare this element with the rest of the unsorted portion of the array to find the true minimum
        for (int j = i+1; j < n; j++) {
            // If a smaller element is found, update minIndex with the new minimum element's index
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        // Swap the found minimum element with the first unsorted element
        swap(arr[i], arr[minIndex]);
    }
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++)
        cout <<"  "<<array[i];
    cout << "\n";
}
//Function to swap element
void swap(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1; //if element not find 
}

// An iterative binary search function.
int binarySearch(int arr[], int low, int high, int x){
    while (low <= high) {
        int mid = low + (high - low) / 2;
        // Check if x is present at mid
        if (arr[mid] == x)
            return mid;
        // If x greater, ignore left half
        if (arr[mid] < x)
            low = mid + 1;
        // If x is smaller, ignore right half
        else
            high = mid - 1;
    }
    // If we reach here, then element was not present
    return -1;
}

int main() {
	// Initialize array with unsorted elements
    int data[] = {-2,0,11,-9,1};
    // Calculate number of elements in the array
    int size = sizeof(data) / sizeof(data[0]);
    cout <<"Unsorted Array:\t";
    printArray(data, size);
    
    // Call Bubblesort function to sort the array
    BubbleSort(data, size);
    cout <<"Bubblesort:\t";
    printArray(data, size);
    
    // Call Insertionsort function to sort the array
    InsertionSort(data, size);
    cout <<"Insertionsort:\t";
    printArray(data,size);
    
    // Call mergeort function to sort the array
    mergeSort(data, 0, size - 1);
    cout <<"Mergesort:\t";
    printArray(data, size);
    
    // Call selectionSort function to sort the array
    selectionSort(data,size);
    cout <<"Selectionsort:\t";
    printArray(data,size);
    

    cout << "Please enter your key then find with linear search function\n";
    int key;
    cin >> key;
    //LS = Linearsearch
    //Call linearsearch function
    int resultLS = linearSearch(data,size, key);
    if (resultLS == -1)
        cout << "Not find index of element" << endl;
    else
        cout << "Index of element is: " << resultLS << endl;
    
    cout << "Please enter your value then find with binary search\n";
    int value;
    cin >> value;
    //BS = Binarysearch
    //Call binarysearch function
    int resultBS = binarySearch(data, 0, size - 1, value);
    if (resultBS == -1)
        cout << "Not find index of element" << endl;
    else
        cout << "Index of element is: " << resultBS << endl;
    
    return 0;
}

