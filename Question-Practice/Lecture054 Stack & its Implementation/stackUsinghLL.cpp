#include <iostream>
using namespace std;

class Node {
   public:
    int data;
    Node *next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node() {
        cout << "Deleted : " << this->data << endl;
        if (this->next != NULL) {
            delete next;
            this->next = NULL;
        }
    }
};

class stackUsinghLL {
   public:
    Node *top;
    int length;
    stackUsinghLL() {
        top = NULL;
        length = 0;
    }

    void push(int data) {
        Node *temp = new Node(data);
        if (top == NULL) {
            top = temp;
        } else {
            temp->next = top;
            top = temp;
        }
        length++;
    }
    int pop() {
        if (top == NULL) {
            cout << "Stack Undeflow" << endl;
            return -1;
        }
        Node *temp = top;
        top = top->next;
        int val = temp->data;
        temp->next = NULL;
        delete temp;
        length--;
        return val;
    }
    int peek() {
        if (top != NULL) return top->data;
        cout << "Stack is empty" << endl;
        return -1;
    }
    int size() { return length; }
    bool isEmpty() { return top == NULL; }

    void print() {
        Node *temp = top;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~stackUsinghLL() {
        if (top != NULL) delete top;
    }
};

int main() {
    stackUsinghLL st;
    st.push(1);
    st.push(2);
    cout << st.peek() << endl;
    st.push(3);
    st.push(4);
    st.push(5);
    st.pop();
    cout << st.size() << endl;

    st.print();

    st.isEmpty() ? cout << "Empty" << endl : cout << "Not Empty" << endl;

    return 0;
}
