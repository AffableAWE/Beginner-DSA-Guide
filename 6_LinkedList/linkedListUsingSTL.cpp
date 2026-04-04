#include<list>
#include<forward_list>
#include<iostream>

using namespace std;

int main() {
    list<int> dList = {1, 2, 3};
    forward_list<int> sList = {4, 5, 6};

    // Insert element at the end (list)
    dList.push_back(10);
    
    // Insert element at the front (forward_list)
    sList.push_front(0);

    // Print elements of a Doubly linked list
    for (list<int> ::iterator i = dList.begin(); i != dList.end(); i++) {
         cout<< *i << " ";
    }
    cout<< endl;
    
    //Print elements of singly linked list
    for (forward_list<int> ::iterator i = sList.begin(); i != sList.end(); i++) {
         cout<< *i << " ";
    }
    cout<<endl;
}

