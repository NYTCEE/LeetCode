class MyCircularQueue {
private:
    int front;     //佇列頭部元素的索引
    int size;     //佇列中元素的數量
    int capacity;     //佇列的最大容量
    vector<int> q;     //q儲存佇列中的元素

public:
    MyCircularQueue(int k) {
        capacity = k;
        q = vector<int>(k);     //q被初始化為一個大小為k的向量
        front = size = 0;
    }

    //入佇列
    bool enQueue(int value) {     
        if (isFull()) return false;     //檢查佇列是否已滿
        int idx = (front + size) % capacity;     
        //計算新元素要插入的位置索引idx
        //CircularQueue的公式
        q[idx] = value;     //將值value儲存到q的索引idx處
        ++size;
        return true;     //回傳true表示入佇列操作成功
    }

    //出佇列
    bool deQueue() {     //檢查佇列是否為空
        if (isEmpty()) return false;
        front = (front + 1) % capacity;     //更新front(指向下一個元素)
        --size;
        return true;     //回傳true表示入佇列操作成功
    }

    int Front() {
        if (isEmpty()) return -1;     //如果佇列為空，返回-1
        return q[front];
    }

    int Rear() {
        if (isEmpty()) return -1;     //如果佇列為空，返回-1
        int idx = (front + size - 1) % capacity;
        //計算尾部元素的索引idx
        //公式為(front + size - 1)取餘數
        return q[idx];
    }

    bool isEmpty() {    
        return size == 0;
        //檢查佇列是否為空(判斷size是否為0)
    }

    bool isFull() {     
        return size == capacity;
        //檢查佇列是否已滿(判斷size是否等於最大容量)
    }
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