class DynamicArray {
private:
    int* arr;
    int size;
    int capacity;

public:
    // constructor to initialize the dynamic array
    DynamicArray(int capacity) : capacity(capacity), size(0) {
        arr = new int[capacity];
    }

    int get(int i) {
        return  arr[i];
    }

    void set(int i, int n) {
        arr[i] = n;
    }

    void pushback(int n) {
        if(size == capacity) {
            resize();
        }
        arr[size] = n;
        size++;
    }

    int popback() {
        int last = arr[size - 1];
        size--;
        return last;
    }

    void resize() {
        capacity = capacity * 2;
        int* newArr = new int[capacity];
        for (int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return capacity;
    }
};
