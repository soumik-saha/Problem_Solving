#include <stack>
#include <vector>

class CustomStack {
public:
    stack<int> stk;
    vector<int> increments;
    int maxSize;

    CustomStack(int maxSize) {
        this->maxSize = maxSize;
        increments.resize(maxSize, 0);
    }
    
    void push(int x) {
        if (stk.size() < maxSize) {
            stk.push(x);
            increments[stk.size() - 1] = 0;
        }
    }
    
    int pop() {
        if (stk.empty()) return -1;

        int index = stk.size() - 1;
        int ele = stk.top() + increments[index]; 
        stk.pop();

        if (!stk.empty()) {
            increments[stk.size() - 1] += increments[index]; 
        }

        return ele;
    }
    
    void increment(int k, int val) {
        if (stk.empty()) return;

        if (k > stk.size()) k = stk.size(); 
        increments[k - 1] += val; 
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
