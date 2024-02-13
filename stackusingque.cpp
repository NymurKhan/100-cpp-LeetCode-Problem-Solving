#include <iostream>
#include <queue>

using namespace std;

class MyStack {
    queue<int> q;
    int topele;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        topele = x;
    }
    
    int pop() {
        int size = q.size();
        while(size>1){
            this->push(q.front());
            q.pop();
            size--;
        }
        int x = q.front();
        q.pop();
        return x;
    }
    
    int top() {
        return this->topele;
    }
    
    bool empty() {
        return q.empty();
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

int main() {
    MyStack* obj = new MyStack();
    obj->push(1);
    obj->push(2);
    cout << obj->top() << endl;   // Output: 2
    cout << obj->pop() << endl;   // Output: 2
    cout << obj->top() << endl;   // Output: 1
    cout << obj->empty() << endl; // Output: 0 (false)
    return 0;
}
