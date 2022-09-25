class MyCircularQueue {
public:
    MyCircularQueue(const int& k) :cap(k), left(0), right(-1), count(0), queue(new int[k]) {
        
    }
    
	~MyCircularQueue() { delete[] queue; } // destructor
	
    bool enQueue(const int& value) {
        if (isFull())
            return false;
        
        ++right;
        right %= cap;
        queue[right] = value;
        
        ++count;
        
        return true;
    }
    
    bool deQueue() {
        if (isEmpty())
            return false;
        
        ++left;
        left %= cap;
        
        --count;
        
        return true;
    }
    
    int Front() const {
        return count == 0 ? -1 : queue[left];
    }
    
    int Rear() const {
        return count == 0 ? -1 : queue[right];
    }
    
    bool isEmpty() const {
        return count == 0;
    }
    
    bool isFull() const {
        return count == cap;
    }
    
private:
    int* queue;
    int left, right, count;
    const int cap;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */