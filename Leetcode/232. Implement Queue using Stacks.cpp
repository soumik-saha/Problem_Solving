class MyQueue {
public:
    private :
    stack<int> s1,s2;
    
    public:
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(s2.empty())
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int temp = s2.top();
        s2.pop();
        return temp;
    }
    
    int peek() {
        if(!s2.empty())
        {
            int top = s2.top();
            return top;
        }
        else
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    
    bool empty() {
        if(s1.empty() and s2.empty())
            return true;
        
        return false;
    }
};
