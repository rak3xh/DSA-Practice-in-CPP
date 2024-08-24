#include <bits/stdc++.h>
using namespace std;

class NQueue
{

public:
    int *arr;

    int *front;

    int *rear;

    int *next;

    int freespot;

    // Initialize your data structure.

    NQueue(int n, int s)
    {

        arr = new int[s];

        front = new int[n];

        rear = new int[n];

        for (int i = 0; i < n; i++)
        {

            front[i] = rear[i] = -1;
        }

        next = new int[s];

        for (int i = 0; i < s; i++)
        {

            next[i] = i + 1;
        }

        next[s - 1] = -1;

        freespot = 0;
    }

    // Enqueues 'X' into the Mth queue. Returns true if it gets pushed into the queue, and false otherwise.

    bool enqueue(int x, int m)
    {

        if (freespot == -1)
        {

            return false;
        }

        else
        {

            int index = freespot;

            // updating freespot;

            freespot = next[index];

            // check if we adding 1st no

            if (front[m - 1] == -1)
            {

                front[m - 1] = index;
            }

            else
            {

                // link the prev rear to curr element

                next[rear[m - 1]] = index;
            }

            // update the next

            next[index] = -1;

            // update the rear

            rear[m - 1] = index;

            // store the element in the arr

            arr[index] = x;

            return true;
        }
    }

    // Dequeues top element from Mth queue. Returns -1 if the queue is empty, otherwise returns the popped element.

    int dequeue(int m)
    {

        if (front[m - 1] == -1)
        {

            return -1;
        }

        else
        {

            int index = front[m - 1];

            // update front

            front[m - 1] = next[index];

            // update the freespace

            next[index] = freespot;

            freespot = index;

            return arr[index];
        }
    }
};
