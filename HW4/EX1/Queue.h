#include <stdio.h>

#define NMAX 100

using namespace std;

template<typename T> class Queue {
    private:
        T queueArray[NMAX];
        int head, tail, size;
    public:
        void enqueue(T x) {
            if (size == NMAX) {
                fprintf(stderr, "Error 102 - The queue is empty!\n");
                return;
            }
            queueArray[tail] = x;
            tail = (tail + 1) % NMAX;
            size++;
        }

        T dequeue() {
            if (isEmpty()) {
                fprintf(stderr, "Error 102 - The queue is empty!\n");
                T x;
                return x;
            }
            T x = queueArray[head];
            head = (head + 1) % NMAX;
            size--;
            return x;
    }
    T peek() {
                if (isEmpty()) {
                    fprintf(stderr, "Error 103 - The queue is empty!\n");
                    T x;
                    return x;
                }
                return queueArray[head];
            }

    int isEmpty() {
                return (size == 0);
    }

        Queue() {
            head = tail = size = 0;
        }
    int getSize()
    {
        return size;
    }
};
