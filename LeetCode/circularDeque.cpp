class MyCircularDeque {
private:
    vector<int> dq;
    int front, rear, size, capacity;

public:
    MyCircularDeque(int k) {
        dq.resize(k);
        capacity = k;
        front = 0;
        rear = -1;
        size = 0;
    }
    
    bool insertFront(int value) {
        if (isFull()) return false;
        front = (front - 1 + capacity) % capacity;
        dq[front] = value;
        size++;
        if (size == 1) rear = front; 
        return true;
    }
    
    bool insertLast(int value) {
        if (isFull()) return false;
        rear = (rear + 1) % capacity;
        dq[rear] = value;
        size++;
        if (size == 1) front = rear; 
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty()) return false;
        front = (front + 1) % capacity;
        size--;
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty()) return false;
        rear = (rear - 1 + capacity) % capacity;
        size--;
        return true;
    }
    
    int getFront() {
        if (isEmpty()) return -1;
        return dq[front];
    }
    
    int getRear() {
        if (isEmpty()) return -1;
        return dq[rear];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == capacity;
    }
};
