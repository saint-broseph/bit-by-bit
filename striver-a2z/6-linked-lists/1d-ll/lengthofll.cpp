/*
  Given the head of a linked list, print the length of the linked list.
*/

#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};
class Solution {
public:
    int lengthOfLinkedList(Node* head) {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};

int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    Solution obj;
    cout << "Length of Linked List: "
         << obj.lengthOfLinkedList(head) << endl;

    return 0;
}
