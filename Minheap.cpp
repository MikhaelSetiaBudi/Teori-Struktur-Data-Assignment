#include <iostream>
#include <vector>

using namespace std;

class MaxHeap{
private:
    vector<int> heap;
    
    void heapifyDown(int index){
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        if (static_cast < size_t > (left) < heap.size()&& heap[left] < heap[smallest]){
            smallest = left;
        }
        if (static_cast < size_t > (right) < heap.size() && heap[right] < heap[smallest]){
            smallest = right;
        }
        if (smallest != index){
            swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }
    void heapifyUp(int index){
        int parent = (index - 1) / 2;

        while (index > 0 && heap[parent] > heap[index]){
            swap(heap[index], heap[parent]);
            index = parent;
            parent = (parent - 1) / 2;
        }
    }
    public:
    MaxHeap() {}

    void insert(int value){
        heap.push_back(value);
        heapifyDown(heap.size() - 1);
    }
    int extractMax(){
        if (heap.empty()){
            return -1;
        }
        int min = heap[0];
        swap (heap[0], heap[heap.size() - 1]);
        heap.pop_back();
        heapifyDown(0);
        return min;
    }

    int peekMax(){
        if(heap.empty()){
            return -1;
        }
        return heap[0];
    }
    bool isEmpty(){
        return heap.empty();
    }

    void printHeap(){
        for (int value : heap){
            cout << value << " ";
        }
        cout << endl;
    }

};
    
    int main(){
        MaxHeap heap;

        heap.insert(10);
        heap.insert(5);
        heap.insert(15);
        heap.insert(3);
        heap.insert(2);

        cout << "Heap: ";
        heap.printHeap();

        cout << "Max Element: " << heap.extractMax() << endl;

        cout << "Heap After Extract: ";
        heap.printHeap();

        return 0;
    }