#include <iostream>
using namespace std;

class MinHeap {
	private:
	    int *heap; //array for surve element
	    int size; //size of heap
	    int capacity; //capacity for minheap tree

	public:
		//constructor 
	    MinHeap(int cap) {
	        capacity = cap;
	        size = 0;
	        heap = new int[capacity];
	    }
	    int parent(int i){ 
			return (i - 1) / 2;
		}
	    int leftChild(int i){
			return 2 * i + 1;
		}
	    int rightChild(int i){
			return 2 * i + 2;
		}
		void insert(int value) {
	    	if (size == capacity) {
	            cout << "Heap is full, cannot insert more elements\n";
	            return;
	        }
	        size++;
	        int i = size - 1;
	        heap[i] = value;
	       	while (i != 0 && heap[parent(i)] > heap[i]) {
	        	swap(heap[i], heap[parent(i)]);
	        	i = parent(i);
	    	}
	    }
	    void heapify(int i) {
	        int l = leftChild(i);
	    	int r = rightChild(i);
	    	int smallest = i;
	    	if (l < size && heap[l] < heap[i])
	        	smallest = l;
	    	if (r < size && heap[r] < heap[smallest])
	        	smallest = r;
	    	if (smallest != i) {
	        	swap(heap[i], heap[smallest]);
	        	heapify(smallest);
	    	}
	    }
	
		// delete  root node
	    void deleteMin(){
	    	if (size <= 0)
	        	return;
	    	if (size == 1) {
	        	size--;
	        	return;
	        }
	        //move last element to root
	        heap[0] = heap[size - 1];
	        size--;
	        // call heapify function
	        heapify(0);
		}
		//preorder
		void preorderTraversal(int index){
			if (index >= size)
	        	return;
	    	cout << heap[index] << " ";
	    	preorderTraversal(leftChild(index));
	    	preorderTraversal(rightChild(index));
		} 
	    void printHeap() {
	        for (int i = 0; i < size; i++)
	            cout << heap[i] << " ";
	        cout << endl;
	    }
};

int main() {
	MinHeap heap(10);
    heap.insert(10);
    heap.insert(20);
    heap.insert(15);
    heap.insert(30);
    heap.insert(40);
    heap.insert(50);
    heap.insert(100);
    heap.insert(25);
    heap.insert(45);
    heap.insert(5);
    cout << "Preorder traversal of min heap:\n";
    heap.preorderTraversal(0);
    cout << "\nDeleting the minimum element (root)\n";
    heap.deleteMin();
    cout << "Preorder traversal after deletion:\n";
    heap.preorderTraversal(0);
	return 0;
}
