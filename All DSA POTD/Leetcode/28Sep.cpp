#include <bits/stdc++.h>
using namespace std;
class MyCircularDeque
{
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) : k(k), q(k), rear(k - 1) {}

    /** Adds an item at the front of Deque. Return true if the operation is
     * successful. */
    bool insertFront(int value)
    {
        if (isFull())
            return false;

        front = (--front + k) % k;
        q[front] = value;
        ++size;
        return true;
    }

    /** Adds an item at the rear of Deque. Return true if the operation is
     * successful. */
    bool insertLast(int value)
    {
        if (isFull())
            return false;

        rear = ++rear % k;
        q[rear] = value;
        ++size;
        return true;
    }

    /** Deletes an item from the front of Deque. Return true if the operation is
     * successful. */
    bool deleteFront()
    {
        if (isEmpty())
            return false;

        front = ++front % k;
        --size;
        return true;
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is
     * successful. */
    bool deleteLast()
    {
        if (isEmpty())
            return false;

        rear = (--rear + k) % k;
        --size;
        return true;
    }

    /** Get the front item from the deque. */
    int getFront()
    {
        return isEmpty() ? -1 : q[front];
    }

    /** Get the last item from the deque. */
    int getRear()
    {
        return isEmpty() ? -1 : q[rear];
    }

    /** Checks whether the circular deque is empty or not. */
    bool isEmpty()
    {
        return size == 0;
    }

    /** Checks whether the circular deque is full or not. */
    bool isFull()
    {
        return size == k;
    }

private:
    const int k;
    vector<int> q;
    int size = 0;
    int front = 0;
    int rear;
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */