#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>

// Node structure for the doubly linked list
template<typename T>
struct Node {
    T data;
    Node<T>* next;
    Node<T>* prev;

    // Constructor: Initializes data with value, next and prev with nullptr
    Node(T value) : data(value), next(nullptr), prev(nullptr) {}
};

// Doubly linked list class
template<typename T>
class DoublyLinkedList {
    private:
        Node<T>* head; // Pointer to the head of the list
        Node<T>* tail; // Pointer to the tail of the list

    public:
        // Constructor to initialize an empty list
        DoublyLinkedList();

        // Destructor to clean up allocated memory
        ~DoublyLinkedList();

        // Insert a node at the front of the list
        void insertFront(T value);

        // Insert a node at the back of the list
        void insertBack(T value);

        // Delete a node with the specified value
        void deleteNode(T value);

        // Display the list from head to tail
        void displayForward() const;

        // Display the list from tail to head
        void displayBackward() const;
};

// Constructor to initialize an empty list
template<typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr) {}

// Destructor to clean up allocated memory
template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    Node<T>* current = head;
    Node<T>* nextNode = nullptr;
    while (current) {
        nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

// Insert a node at the front of the list
template<typename T>
void DoublyLinkedList<T>::insertFront(T value) {
    Node<T>* newNode = new Node<T>(value);
    if (!head) {
        head = tail = newNode; // List is empty
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

// Insert a node at the back of the list
template<typename T>
void DoublyLinkedList<T>::insertBack(T value) {
    Node<T>* newNode = new Node<T>(value);
    if (!tail) {
        head = tail = newNode; // List is empty
    } else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

// Delete a node with the specified value
template<typename T>
void DoublyLinkedList<T>::deleteNode(T value) {
    Node<T>* current = head;
    while (current) {
        if (current->data == value) {
            if (current->prev) {
                current->prev->next = current->next;
            } else {
                head = current->next; // Deleting the head node
            }
            if (current->next) {
                current->next->prev = current->prev;
            } else {
                tail = current->prev; // Deleting the tail node
            }
            delete current;
            return;
        }
        current = current->next;
    }
}

// Display the list from head to tail
template<typename T>
void DoublyLinkedList<T>::displayForward() const {
    Node<T>* current = head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

// Display the list from tail to head
template<typename T>
void DoublyLinkedList<T>::displayBackward() const {
    Node<T>* current = tail;
    while (current) {
        std::cout << current->data << " ";
        current = current->prev;
    }
    std::cout << std::endl;
}

#endif // DOUBLY_LINKED_LIST_H