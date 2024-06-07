# Doubly-Linked-List-STL
A Doubly Linked List STL provides a seamless creation of  Doubly Linked list at your finger tips, with the best part that it support different datatypes too.
A simple implementation of a doubly linked list in C++. This library provides basic operations such as insertion, deletion, and traversal for a doubly linked list.

## Features
- Insertion at Front: Add elements to the front of the list.
- Insertion at Back: Add elements to the end of the list.
- Deletion: Remove elements from the list.
- Traversal: Display elements from head to tail and tail to head.

## Prerequisites
To use this header file, you need a C++ compiler that supports C++11 or later.

# Usage
Here is an example of how to use the DoublyLinkedList class:

```cpp
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
```
