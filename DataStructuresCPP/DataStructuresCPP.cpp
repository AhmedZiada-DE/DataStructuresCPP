#include "Vector.h"
#include "vector"

//SLLs don't have push back like we designed it
#include "SingleLinkedList.h"
#include "forward_list"

#include "DoubleLinkedList.h"

#include "Stack.h"
#include "Queue.h"
#include "BST.h"

//Display Stack
template <typename T>
void displayStack(Stack<T> stack) {
    while (!stack.isEmpty()) {
        cout << stack.top() << " ";
        stack.pop();
    }
    cout << endl;
}
//Display Queue
template <typename T>
void displayQueue(Queue<T> que) {
    while (!que.isEmpty()) {
        cout << que.front() << " ";
        que.pop();
    }
    cout << endl;
}

int main()
{
    cout << "================Vector===============" << endl;
    vector<int> realV;
    Vector<int> v;
    v.push_back(15);
    v.push_back(25);
    v.push_back(35);
    v.push_back(45);

    Vector<int> v2(v);
    for (int i = 0; i < v.getSize(); i++) {
        cout << v2[i] << " ";
    }
    cout << endl;


    cout << "================SingleLinkedList===============" << endl;
    SingleLinkedList<int> sll;
    sll.push_back(1);
    sll.push_back(2);
    sll.push_back(3);
    sll.push_front(0);
    sll.pop_back();
    SingleLinkedList<int>::Iterator it;
    for (it = sll.begin(); it != sll.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "================DoubleLinkedList===============" << endl;
    DoubleLinkedList<int> dl;
    dl.push_back(10);
    //dl.push_front(0);
    //dl.push_back(20);
    dl.push_front(1);
    dl.pop_front();
    dl.pop_back();
    DoubleLinkedList<int>::Iterator Dit;
    for (Dit = dl.begin(); Dit != dl.end(); Dit++) {
        cout << *Dit << " ";
    }
    cout << endl;

    cout << "================Stack===============" << endl;
    Stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.pop();
    displayStack(st);
    st.reverse();
    cout << "reversed stack: " << endl;
    displayStack(st);

    cout << "================Queue===============" << endl;
    Queue<int> que;
    que.push(10);
    que.push(20);
    que.push(30);
    que.push(40);
    que.pop();
    displayQueue(que);
    que.reverse();
    displayQueue(que);

    cout << "================BST===============" << endl;
    BST<int> bst;
    bst.insert(20).displayOutput();
    bst.insert(10).displayOutput();
    bst.insert(30).displayOutput();
    bst.insert(5).displayOutput();
    bst.insert(15).displayOutput();
    bst.insert(45).displayOutput();
    bst.insert(35).displayOutput();
    bst.insert(1).displayOutput();
    cout << "search" << endl;
    bst.search(1).displayOutput();
    bst.search(155).displayOutput();
}

