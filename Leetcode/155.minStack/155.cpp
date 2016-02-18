//use a stack to store the all the element ,s1
//the other to store the minimum element in current situation
//before s1.top();

class MinStack {
private:
	stack<int> stk1;
	stack<int> stk2;
public:
    void push(int x) {
        stk1.push(x);
        if (stk2.empty() || stk1.top() <= stk2.top())
        	stk2.push(x);
    }

    void pop() {
    	if (stk2.top() == stk1.top())
       		stk2.pop();
       	stk1.pop();
    }

    int top() {
      return stk1.top();  
    }

    int getMin() {
      return stk2.top();  
    }
};
