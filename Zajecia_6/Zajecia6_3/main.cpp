#include <iostream>
#include <functional>
using std::cout;
using std::endl;
using std::cerr;
using std::function;

struct Node {
    int data;
    Node* next;
};

void printList(const Node* head){
    if (head == nullptr) cout << "Empty list" << endl;

    while(head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void add(Node*& head, int data){
    Node* p = new Node;
    p->data = data;

    if(head == nullptr) {
        p->next = nullptr;
        head = p;
    }

    if(data < head->data) {
        p->next = head;
        head = p;
    }

    if(data > head->data) {
        Node* temp;
        Node* tmp;

        for (temp = head; temp->next != nullptr; temp = temp->next){
            if (temp->next->data > data){
                tmp = temp->next;
                temp->next = p;
                p->next = tmp;
                return;
            }
        }
        p->next = nullptr;
        temp->next = p;
    }
}

bool any(const Node* head, function<bool(int)> pred) {
    const Node* temp = head;
    while(temp->next != nullptr) {
        if (pred(temp->data))
            return true;
        temp = temp->next;
    }
    return false;
}

bool all(const Node* head, function<bool(int)> pred) {
    const Node* temp = head;
    while(temp->next != nullptr) {
        if (!pred(temp->data))
            return false;
        temp = temp->next;
    }
    return true;
}
void deleteList(Node*& head) {
    while (head != nullptr) {
        Node* tmp = head;
        head = head->next;
        std:: cout<< "Del: " << tmp->data << " ";
        delete tmp;
    }
    std::cout << std:: endl;
}

int main()
{
    Node* head = 0;
    add(head,3);
    add(head,6);
    add(head,2);
    add(head,8);
    add(head,5);
    printList(head);
    cout << std::boolalpha;
    cout << "less than 10 all "
         << all(head,[] (int i) -> bool {return i< 10;})
         << endl;
    cout << "is even all "
         << all(head,[] (int i) -> bool {return i%2 == 0;})
         << endl;
    cout << "is even any "
         << any(head,[] (int i) -> bool {return i%2 == 0;})
         << endl;
    deleteList(head);
}
