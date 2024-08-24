#include <stack>
#include <bits/stdc++.h>
using namespace std;
class Stack
{

public:
    int size;

    stack<int> st;

    Stack(int capacity)
    {

        size = capacity;
    }

    void push(int num)
    {

        if (st.size() != size)

            st.push(num);
    }

    int pop()
    {

        if (st.size() > 0)
        {

            int ans = st.top();

            st.pop();

            return ans;
        }

        return -1;
    }

    int top()
    {

        if (st.size() > 0)
        {

            return st.top();
        }

        return -1;
    }

    int isEmpty()
    {

        return st.empty();
    }

    int isFull()
    {

        return (st.size() == size);
    }
};