#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class MyStack
{
public:
    /** Initialize your data structure here. */
    queue<int> q1;
    MyStack()
    {
    }

    /** Push element x onto stack. */
    void push(int x)
    {
        int sz = q1.size();
        q1.push(x);
        while (sz--)
        {
            q1.push(q1.front());
            q1.pop();
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop()
    {
        int result = top();
        q1.pop();
        return result;
    }

    /** Get the top element. */
    int top()
    {
        return q1.front();
    }

    /** Returns whether the stack is empty. */
    bool empty()
    {
        return q1.empty();
    }
};