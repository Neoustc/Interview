// test case:
// push push top top.
// so we need to reorganize the queue when push the element into queue. shouldn't in the top() operation
class Stack {
private: queue<int> que;
public:
    // Push element x onto stack.
    void push(int x) {
       que.push(x);
        int n = que.size();
        for (int i = 0; i < que.size() - 1; ++i){
            que.push(que.front());
            que.pop();
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        que.pop();
    }

    // Get the top element.
    int top() {
        return que.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return que.empty();
    }
};
