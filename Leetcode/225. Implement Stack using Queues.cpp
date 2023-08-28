class MyStack {
    queue<int> q1, q2;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q2.push(x);

        while(!q1.empty()) {
            int ele = q1.front();
            q1.pop();
            q2.push(ele);
        }

        queue<int> temp;
        temp = q1;
        q1 = q2;
        q2 = temp;
    }
    
    int pop() {
        if(q1.empty())
            return -1;
        int ele = q1.front();
        q1.pop();
        return ele;
    }
    
    int top() {
        if(q1.empty())
            return -1;
        return q1.front();
    }
    
    bool empty() {
        if(q1.empty())
            return true;
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
