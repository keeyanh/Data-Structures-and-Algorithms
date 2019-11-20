#include <iostream>

template<class T>
class Queue {

private:
    int max, size;
    T *arr;

    void expand();

public:
    explicit Queue(int max) : max(max) {
        arr = new int[max];
    }

    void push(T val);

    T pop();

    void print();
};

template<class T>
void Queue<T>::push(T val) {
    if (size == max) {
        expand();
    }
    arr[size] = val;
    size++;
}

template<class T>
T Queue<T>::pop() {
    if (size == 0)
        return NULL;
    size--;
    return arr[0];
}

template<class T>
void Queue<T>::expand() {
    const int newSize = max * 2;
    auto *newArr = new int[newSize];
    for (int index = 0; index < max; index++) {
        newArr[index] = arr[index];
    }
    max = newSize;
    arr = newArr;
}

template<class T>
void Queue<T>::print() {
    for (int index = 0; index < size; index++) {
        printf("%d, ", arr[index]);
    }

    printf("\nArray size is %d and max is %d", size, max);
}

int main() {
    Queue<int> queue(1);

    queue.push(1);
    queue.push(2);
    queue.push(50);

    queue.print();
    return 0;
}