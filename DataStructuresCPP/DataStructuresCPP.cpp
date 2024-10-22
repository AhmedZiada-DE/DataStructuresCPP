#include "Vector.h"
#include "vector"

//SLLs don't have push back like we designed it
#include "SingleLinkedList.h"
#include "forward_list" //SLL standard lib

#include "DoubleLinkedList.h"
#include <list> //DDL standard lib

#include "Stack.h"
#include "Queue.h"
#include "BST.h"
//These use Hash table
#include <unordered_set>
#include <unordered_map>

//These use BST
#include <set>
#include <map>

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
    /*
    
                20
        10              30
    5       15                  45
1                            35

    DFS : 20 10 5 1 15 30 45 35
    BFS : 20 10 30 5 15 45 1 35
    */
    //cout << "search" << endl;
    //bst.search(1).displayOutput();
    //bst.search(155).displayOutput();
    bst.displayDFS();
    bst.BFS();
    BST<int> copiedBST = bst;
    copiedBST.displayDFS();
    copiedBST = bst;
    copiedBST.BFS();
    bst.erase(20).displayOutput();

    cout << "================unordered_set===============" << endl;
    //unordered set take unique values only so there is no duplication inside it
    unordered_set<int> set;
    cout << set.insert(1002).second << endl;
    cout << set.insert(1005).second << endl;
    cout << set.insert(1012).second << endl;
    cout << set.insert(1027).second << endl;
    cout << set.insert(1037).second << endl;
    cout << set.insert(1049).second << endl;
    cout << set.insert(1039).second << endl;
    cout << set.insert(1039).second << endl;

    cout << "================unordered_map===============" << endl;
    //It consists of keys and values so values can be duplicated
    // but the keys are unique
    unordered_map<int, string> map;
    cout << map.insert({1002, "A"}).second << endl;
    cout << map.insert({1002, "A"}).second << endl; //Duplicate key so val won't be inserted
    cout << map.insert({1003, "B"}).second << endl;
    cout << map.insert({1004, "V"}).second << endl;
    cout << map.insert({1005, "D"}).second << endl;
    cout << map.insert({1006, "E"}).second << endl;
    cout << map.insert({1007, "Q"}).second << endl;
    cout << map.insert({1008, "A"}).second << endl;

    /*
    both unordered set and map return a pair first and second
    first returns an iterator 
    second returns whether the insert happened or not
    */

    cout << "================Graph===============" << endl;
    /*
    Let's Model a graph
    */

    /*
    1       3
    1       5
    2       4
    2       5
    3       2
    4       5
    5       3
    
    */
    cout << "Enter nodes and edges" << endl;
    int nodes, edges;
    cin >> nodes >> edges;
    vector<vector<int>> graph(nodes + 1);
    for (int i = 1; i <= edges; i++) {
        int parent, child;
        cin >> parent >> child;
        graph[parent].push_back(child);
    }

    for (int i = 1; i <= nodes; i++) {
        cout << "Parent: " << i << "--> ";
        for (int j = 0; j < graph[i].size(); j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

}

