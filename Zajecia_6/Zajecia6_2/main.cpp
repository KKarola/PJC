#include <iostream>

struct Node {
    int   data;
    Node* next;
};

Node* arrayToList(const int arr[], size_t size) {
    Node* head = nullptr;
    for(int i = size-1; i >= 0; i--){
        Node *p = new Node;
        p->data = arr[i];
        p->next = head;
        head = p;
    }
    return head;
}

Node* removeOdd(Node* head) {

    if(head != nullptr) {
        Node* temp;
        Node* tmp;
        Node* lista;
        while(head->data % 2 != 0) {
            temp = head;
            head = temp->next;
            std::cout << "DEL:" << temp->data << " ";
            delete temp;
            if(head->next == nullptr) return nullptr;
        }
        lista = head;
        while(lista->next != nullptr){
            temp = lista->next;
            if(temp->data % 2 != 0) {
                lista->next = temp->next;
                std::cout << "DEL:" << temp->data << " ";
                delete temp;
            } else  {
                lista = lista->next;
            }
        }
        std::cout << std::endl;
    }
    return head;
}

void showList(const Node* head) {
    if(head == nullptr)
        std::cout << "Empty list"<< std:: endl;

    while(head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }

    std::cout << std::endl;
}

void deleteList(Node*& head) {
    while (head != nullptr) {
        Node* tmp = head;
        head = head->next;
        std:: cout<< "del:" << tmp->data << " ";
        delete tmp;
    }
    std::cout << std:: endl;
}

int main() {
    int arr[] = {1,2,3,4,5,6};
    size_t size = sizeof(arr)/sizeof(*arr);
    Node* head = arrayToList(arr,size);
    showList(head);
    head = removeOdd(head);
    showList(head);
    deleteList(head);
    showList(head);
}
