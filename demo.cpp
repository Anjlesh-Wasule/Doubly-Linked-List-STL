#include "doubly_linked_list.h"

int main() {
    DoublyLinkedList<int> dll;

    dll.insertFront(10);
    dll.insertFront(20);
    dll.insertBack(30);
    dll.insertBack(40);

    std::cout << "List forward: ";
    dll.displayForward();

    std::cout << "List backward: ";
    dll.displayBackward();

    dll.deleteNode(20);
    std::cout << "List after deleting 20: ";
    dll.displayForward();

    dll.deleteNode(40);
    std::cout << "List after deleting 40: ";
    dll.displayForward();

    return 0;
}