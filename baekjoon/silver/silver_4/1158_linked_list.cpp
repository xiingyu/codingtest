#include <iostream>
using namespace std;

struct node {
    int Id;
    node* prev;
    node* next;
};

void appendNode(node*& head, int data) {
    node* newNode = new node{data, head->prev, head};
    node* tail = head->prev;
    tail->next = newNode;
    head->prev = newNode;
}

node* popNode(node*& head, int index) {
    int temp;
    node* target = head;
    for(int i = 0; i < index; ++i) {
        target = target->next;
    }
    temp = target->Id;

    target->prev->next = target->next;
    target->next->prev = target->prev;
    return target;

}

int main() {
    int n, k, temp;
    cin >> n >> k;
    node* head = new node{1, nullptr, nullptr};
    head->next = head;
    head->prev = head;
    for(int i = 2; i <= n; ++i) {
        appendNode(head,i);
    }

    cout << "<";
    node* curNode = head;
    for(int i = 1; i <= n; ++i) {
        if(i==1) curNode = popNode(curNode, k-1);
        else curNode = popNode(curNode, k);

        if (i == n) cout << curNode->Id;
        else cout << curNode->Id << ", ";
        delete curNode;
    }
    
    cout << ">";
}
