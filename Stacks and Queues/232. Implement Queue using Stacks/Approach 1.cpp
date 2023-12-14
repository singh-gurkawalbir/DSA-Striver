#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

struct Queue //! Using two Stacks where push operation is O(N)
{
    stack<int> input, output;
    // Push elements in queue
    void Push(int data)
    {
        // Pop out all elements from the stack input
        while (!input.empty())
        {
            output.push(input.top());
            input.pop();
        }
        // Insert the desired element in the stack input
        input.push(data);
        // Pop out elements from the stack output and push them into the stack input
        while (!output.empty())
        {
            input.push(output.top());
            output.pop();
        }
    }
    // Pop the element from the Queue
    int Pop()
    {
        if (input.empty())
        {
            exit(0);
        }
        int val = input.top();
        input.pop();
        return val;
    }
    // Return the Topmost element from the Queue
    int Top()
    {
        if (input.empty())
        {
            exit(0);
        }
        return input.top();
    }
    int size()
    {
        return input.size();
    }
};