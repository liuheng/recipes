#include <queue>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <vector>
#include <cstring>
#include <ctime>

using namespace std;

#define MAX_SIZE 1024
#define left(x) (2 * (x) + 1)
#define right(x) (2 * (x) + 2)
#define parent(x) ((x - 1) / 2)

void heapify_down(int arr[], size_t N, int index) {
    int newindex = index;
    int val = arr[index];
    if (left(index) < N && val < arr[left(index)]) {
        newindex = left(index);
        val = arr[left(index)];
    }
    if (right(index) < N && val < arr[right(index)]) {
        newindex = right(index);
    }
    if (index == newindex) return;
    else {
        swap(arr[index], arr[newindex]);
        heapify_down(arr, N, newindex);
    }
}
void make_heap(int arr[], size_t N) {
    for(int i=parent(N); i>=0; --i) {
        heapify_down(arr, N, i);
    }
}

void heap_sort(int arr[], size_t N) {
    make_heap(arr, N);
    for (int i=N-1; i>=0; --i) {
        swap(arr[i], arr[0]);
        heapify_down(arr, i, 0);
    }
}

class MinHeap {
    public:
        MinHeap() {
            memset(_arr, 0, MAX_SIZE * sizeof(int));
        }
        inline bool empty() { return _size == 0; }
        inline bool full() { return _size == MAX_SIZE; }
        void print_heap() {
            for (int i=0; i< _size; ++i)
                printf("%d ", _arr[i]);
            printf("\n");
        }
        void push(int v) {
            if (!full()) {
                _arr[_size++] = v;
                heapify_up(_size-1);
            }
        }
        int top() {
            if (!empty()) {
                return _arr[0];
            } else {
                return -1;
            }
        }
        int pop() {
            swap(_arr[0], _arr[--_size]);
            heapify_down(0);
        }
        void heapify_down(int index) {
            int newindex = index;
            int val = _arr[index];
            if (left(index) < _size && val > _arr[left(index)]) {
                newindex = left(index);
                val = _arr[left(index)];
            }
            if (right(index) < _size && val > _arr[right(index)]) {
                newindex = right(index);
            }
            if (index == newindex) return;
            else {
                swap(_arr[index], _arr[newindex]);
                heapify_down(newindex);
            }
        }
        void heapify_up(int index) {
            if (0 == index) return;
            if (_arr[parent(index)] <= _arr[index]) return;
            else {
                swap(_arr[parent(index)], _arr[index]);
                heapify_up(parent(index));
            }
        }
    private:
        size_t _size;
        int _arr[MAX_SIZE];
};

int main() {
    priority_queue<int, vector<int>, greater<int> > Q;
    Q.push(5);
    Q.push(4);
    Q.push(7);
    while (!Q.empty()) {
        printf("%d ", Q.top());
        Q.pop();
    }
    printf("\n");

    srand(time(NULL));
    MinHeap H;
    for (int i=0; i<10; ++i) {
        H.push(rand() % 100);
    }
    H.print_heap();
    while (!H.empty()) {
        printf("%d ", H.top());
        H.pop();
    }
    printf("\n");

    int arr[20] = {0};
    for (int i=0; i<20; ++i) {
        arr[i] = rand() % 100;
    }
    heap_sort(arr, 20);
    for (int i=0; i<20; ++i) {printf("%d ", arr[i]);}
    printf("\n");
    return 0;
}
