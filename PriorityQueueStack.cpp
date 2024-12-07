#include <iostream>
#include <stack>
#include <string>
using namespace std;

class PriorityQueueStack {
private:
    stack<int> mainStack;

    
    void printStack(stack<int> s) {
        stack<int> temp;
        while (!s.empty()) {
            temp.push(s.top());
            s.pop();
        }
        while (!temp.empty()) {
            cout << temp.top() << " ";
            s.push(temp.top());
            temp.pop();
        }
    }

public:
    void push(int priority) {
        cout << "\nPushing " << priority << "...\n";
        stack<int> tempStack;

        
        cout << "Main stack before rearranging: ";
        printStack(mainStack);
        cout << "\n";

        while (!mainStack.empty() && mainStack.top() <= priority) {
            tempStack.push(mainStack.top());
            mainStack.pop();
        }

        cout << "Temp stack after moving elements: ";
        printStack(tempStack);
        cout << "\n";

        
        mainStack.push(priority);
        cout << "Main stack after adding " << priority << ": ";
        printStack(mainStack);
        cout << "\n";

        
        while (!tempStack.empty()) {
            mainStack.push(tempStack.top());
            tempStack.pop();
        }

        cout << "Main stack after rearranging: ";
        printStack(mainStack);
        cout << "\n";
    }

    int pop() {
        if (mainStack.empty()) {
            throw runtime_error("Priority queue is empty!");
        }
        int topElement = mainStack.top();
        cout << "\nPopping " << topElement << "...\n";
        mainStack.pop();
        cout << "Main stack after popping: ";
        printStack(mainStack);
        cout << "\n";
        return topElement;
    }

    bool isEmpty() {
        return mainStack.empty();
    }
};

int main() {
    PriorityQueueStack pq;

    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int priority;

        cout << "Enter priority for element " << (i + 1) << ": ";
        cin >> priority;

        pq.push(priority);
    }

    cout << "\nElements will be popped in priority order:\n";

    while (!pq.isEmpty()) {
        cout << "Popped: " << pq.pop() << endl;
    }

    return 0;
}
