#include <iostream>
#include <fstream>
#include "LinkedList.h"

template<class T>
Node<T>::Node() {
    this->data = 0;
    this->next = nullptr;
}

template<class T>
Node<T>::Node(T data) {
    this->data = data;
    this->next = nullptr;
}

template<class T>
MyLinkedList<T>::MyLinkedList() {
    this->head = nullptr;
}

template<class T>
MyLinkedList<T>::MyLinkedList(const MyLinkedList &list) {
    this->head = nullptr;
    if (list.head == nullptr) {
        return;
    }

    Node<T> *temp = list.head;
    Node<T> *last = nullptr;

    while (temp != nullptr) {
        Node<T> *newNode = new Node(temp->data);

        if (this->head == nullptr) {
            this->head = newNode;
        }

        if (last != nullptr) {
            last->next = newNode;
        }

        last = newNode;
        temp = temp->next;
    }
}

template<class T>
MyLinkedList<T>::MyLinkedList(MyLinkedList &&list) {
    this->head = list.head;
    list.head = nullptr;
}

template<class T>
MyLinkedList<T>::~MyLinkedList() {
    Node<T> *current = this->head;

    while (current != nullptr) {
        Node<T> *temp = current;
        current = current->next;
        delete temp;
    }
}

template<class T>
void MyLinkedList<T>::insertElementAtEnd(T data) {
    Node<T> *newNode = new Node<T>(data);

    if (this->head == nullptr) {
        this->head = newNode;
        return;
    }

    Node<T> *temp = this->head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
}

template<class T>
void MyLinkedList<T>::insertElementAtBeginning(T data) {
    Node<T> *newNode = new Node<T>(data);

    if (this->head == nullptr) {
        this->head = newNode;
        return;
    }

    newNode->next = this->head;
    this->head = newNode;
}

template<class T>
void MyLinkedList<T>::printMyLinkedList() {
    Node<T> *temp = this->head;

    if (this->head == nullptr) {
        std::cout << "EMPTY LIST" << std::endl;
        return;
    }

    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

template<class T>
void MyLinkedList<T>::deleteElement(int nodeOfSet) {
    Node<T> *temp1 = this->head;
    Node<T> *temp2 = nullptr;

    int ListLen = 0;

    if (this->head == nullptr) {
        std::cout << "EMPTY LIST" << std::endl;
        return;
    }

    while (temp1 != nullptr) {
        temp1 = temp1->next;
        ListLen++;
    }

    if (ListLen < nodeOfSet) {
        std::cout << "Index out of range" << std::endl;
        return;
    }

    temp1 = this->head;

    if (nodeOfSet == 1) {
        this->head = this->head->next;
        delete temp1;
        return;
    }

    while (nodeOfSet > 1) {
        nodeOfSet--;
        temp2 = temp1;
        temp1 = temp1->next;
    }

    temp2->next = temp1->next;

    delete temp1;
}

template<class T>
void MyLinkedList<T>::searchForElement(T element) {
    int position = 1;
    Node<T> *temp1 = this->head;

    while (temp1 != nullptr) {
        if (temp1->data == element) {
            std::cout << element << " has been found in: " << position << " node." << std::endl;
            return;
        }
        temp1 = temp1->next;
        position++;
    }
    std::cout << element << " has not been found." << std::endl;
}

template<class T>
void MyLinkedList<T>::operator=(const MyLinkedList &list) {
    this->head = nullptr;
    if (list.head == nullptr) {
        return;
    }

    Node<T> *temp = list.head;
    Node<T> *last = nullptr;

    while (temp != nullptr) {
        Node<T> *newNode = new Node(temp->data);

        if (this->head == nullptr) {
            this->head = newNode;
        }

        if (last != nullptr) {
            last->next = newNode;
        }

        last = newNode;
        temp = temp->next;
    }
}

template<class T>
void MyLinkedList<T>::operator=(MyLinkedList &&list) {
    if (&list != this) {
        Node<T> *current = this->head;

        while (current != nullptr) {
            Node<T> *temp = current;
            current = current->next;
            delete temp;
        }

        this->head = list.head;
        list.head = nullptr;
    }
}

template<class T>
void MyLinkedList<T>::sort() {
    Node<T> *sorted = nullptr;

    if (this->head == nullptr) {
        std::cout << "EMPTY LIST" << std::endl;
        return;
    }

    while (this->head != nullptr) {
        Node<T> *temp = this->head;
        Node<T> *min = this->head;

        while (temp != nullptr) {
            if (min->data > temp->data) {
                min = temp;
            }
            temp = temp->next;
        }

        if(min == this->head){
            this->head = this->head->next;
        } else {
            Node<T> *temp2 = this->head;
            while (temp2->next != min) {
                temp2 = temp2->next;
            }
            temp2->next = min->next;
        }
        min->next = nullptr;

        if (sorted == nullptr) {
            sorted = min;
        } else {
            Node<T> *temp3 = sorted;
            while (temp3->next != nullptr) {
                temp3 = temp3->next;
            }
            temp3->next = min;
        }
    }
    this->head = sorted;

}

template<class T>
void MyLinkedList<T>::saveToFile(std::string fileName) {
    std::ofstream file;
    file.open(fileName, std::ofstream::out | std::ofstream::trunc);

    Node<T> *temp = this->head;

    if (this->head == nullptr) {
        std::cout << "EMPTY LIST" << std::endl;
        return;
    }

    bool firstItr = true;
    while (temp != nullptr) {
        if (firstItr) {
            firstItr = false;
        } else {
            file << std::endl;
        }
        file << temp->data;
        temp = temp->next;
    }
    file.close();
}

template<class T>
void MyLinkedList<T>::fromFileToList(std::string fileName) {
    Node<T> *current = this->head;

    while (current != nullptr) {
        Node<T> *temp = current;
        current = current->next;
        delete temp;
    }

    this->head = nullptr;
    std::fstream file(fileName);

    while (!file.eof()) {
        T myText;
        file >> myText;
        this->insertElementAtEnd(myText);
    }
    file.close();
}

void test1() {
    //Creating singly linked list using default constructor - list1
    MyLinkedList<int> list1;

    //Inserting element 10 at the end of list1
    list1.insertElementAtEnd(10);

    //Inserting element 150 at the beginning of list1
    list1.insertElementAtBeginning(150);

    //Printing on console elements of list1
    //Expectations: 150 10
    std::cout << "Expectations: 150 10" << std::endl;
    list1.printMyLinkedList();

    //Searching list1 to find 30 element
    //Expectations: 30 has not been found.
    std::cout << "Expectations: 30 has not been found." << std::endl;
    list1.searchForElement(30);

    //Searching list1 to find 150 element
    //Expectations: 150 has been found in: 1 node.
    std::cout << "Expectations: 150 has been found in: 1 node." << std::endl;
    list1.searchForElement(150);

    //Inserting element 35 at the end of list1
    list1.insertElementAtEnd(35);

    //Deleting element in 2 node of list1
    list1.deleteElement(2);

    //Printing on console elements of list1
    //Expectations: 150 35
    std::cout << "Expectations: 150 35" << std::endl;
    list1.printMyLinkedList();

    //Creating singly linked list using copy constructor - list2 (copy elements from list1)
    MyLinkedList<int> list2(list1);

    //Printing on console elements of list1
    //Expectations: 150 35
    std::cout << "Expectations: 150 35" << std::endl;
    list1.printMyLinkedList();

    //Printing on console elements of list2
    //Expectations: 150 35
    std::cout << "Expectations: 150 35" << std::endl;
    list2.printMyLinkedList();

    //Creating singly linked list using move constructor - list3 (move elements from list1)
    MyLinkedList<int> list3 = std::move(list1);

    //Printing on console elements of list1
    //Expectations: EMPTY LIST
    std::cout << "Expectations: EMPTY LIST" << std::endl;
    list1.printMyLinkedList();

    //Printing on console elements of list3
    //Expectations: 150 35
    std::cout << "Expectations: 150 35" << std::endl;
    list3.printMyLinkedList();

    //Inserting element 70 at the end of list2
    list2.insertElementAtEnd(70);

    //Using assignment operator - list1 have list2 elements
    list1 = list2;

    //Printing on console elements of list1
    //Expectations: 150 35 70
    std::cout << "Expectations: 150 35 70" << std::endl;
    list1.printMyLinkedList();

    //Printing on console elements of list2
    //Expectations: 150 35 70
    std::cout << "Expectations: 150 35 70" << std::endl;
    list2.printMyLinkedList();

    //Creating singly linked list using default constructor - list4
    MyLinkedList<int> list4;

    //Using move operator - list1 move elements to list4
    list4 = std::move(list1);

    //Printing on console elements of list1
    //Expectations: EMPTY LIST
    std::cout << "Expectations: EMPTY LIST" << std::endl;
    list1.printMyLinkedList();

    //Printing on console elements of list4
    //Expectations: 150 35 70
    std::cout << "Expectations: 150 35 70" << std::endl;
    list4.printMyLinkedList();

    //Saving list2 to file test1.txt
    list2.saveToFile("test1.txt");

    //Printing on console elements of list1
    //Expectations: EMPTY LIST
    std::cout << "Expectations: EMPTY LIST" << std::endl;
    list1.printMyLinkedList();

    //Reading from file "test1.txt" and writing it to list1
    //Expectations: 150 35 70
    std::cout << "Expectations: 150 35 70" << std::endl;
    list1.fromFileToList("test1.txt");
    list1.printMyLinkedList();

    //Inserting element 35 at the beginning of list1
    list1.insertElementAtBeginning(35);

    //Inserting element 1 at the end of list1
    list1.insertElementAtEnd(1);

    //Printing on console elements of list1
    //Expectations: 35 150 35 70 1
    std::cout << "Expectations: 35 150 35 70 1" << std::endl;
    list1.printMyLinkedList();

    //Sorting list1
    list1.sort();
    //Expectations: 1 35 35 70 150
    std::cout << "Expectations: 1 35 35 70 150" << std::endl;
    list1.printMyLinkedList();

}

void test2() {
    //Creating singly linked list using default constructor - list1
    MyLinkedList<std::string> list1;

    //Inserting element "Monkey" at the end of list1
    list1.insertElementAtEnd("Monkey");

    //Inserting element "Elephant" at the beginning of list1
    list1.insertElementAtBeginning("Elephant");

    //Printing on console elements of list1
    //Expectations: Monkey Elephant
    std::cout << "Expectations: Monkey Elephant" << std::endl;
    list1.printMyLinkedList();

    //Searching list1 to find "Eagle" element
    //Expectations: Eagle has not been found.
    std::cout << "Expectations: Eagle has not been found." << std::endl;
    list1.searchForElement("Eagle");

    //Searching list1 to find "Elephant" element
    //Expectations: Elephant has been found in: 1 node.
    std::cout << "Expectations: Elephant has been found in: 1 node." << std::endl;
    list1.searchForElement("Elephant");

    //Inserting element "Lion" at the end of list1
    list1.insertElementAtEnd("Lion");

    //Deleting element in 2 node of list1
    list1.deleteElement(2);

    //Printing on console elements of list1
    //Expectations: Elephant Lion
    std::cout << "Expectations: Elephant Lion" << std::endl;
    list1.printMyLinkedList();

    //Creating singly linked list using copy constructor - list2 (copy elements from list1)
    MyLinkedList<std::string> list2(list1);

    //Printing on console elements of list1
    //Expectations: Elephant Lion
    std::cout << "Expectations: Elephant Lion" << std::endl;
    list1.printMyLinkedList();

    //Printing on console elements of list2
    //Expectations: Elephant Lion
    std::cout << "Expectations: Elephant Lion" << std::endl;
    list2.printMyLinkedList();

    //Creating singly linked list using move constructor - list3 (move elements from list1)
    MyLinkedList<std::string> list3 = std::move(list1);

    //Printing on console elements of list1
    //Expectations: EMPTY LIST
    std::cout << "Expectations: EMPTY LIST" << std::endl;
    list1.printMyLinkedList();

    //Printing on console elements of list3
    //Expectations: Elephant Lion
    std::cout << "Expectations: Elephant Lion" << std::endl;
    list3.printMyLinkedList();

    //Inserting element "Snake" at the end of list2
    list2.insertElementAtEnd("Snake");

    //Using assignment operator - list1 have list2 elements
    list1 = list2;

    //Printing on console elements of list1
    //Expectations: Elephant Lion Snake
    std::cout << "Expectations: Elephant Lion Snake" << std::endl;
    list1.printMyLinkedList();

    //Printing on console elements of list2
    //Expectations: Elephant Lion Snake
    std::cout << "Expectations: Elephant Lion Snake" << std::endl;
    list2.printMyLinkedList();

    //Creating singly linked list using default constructor - list4
    MyLinkedList<std::string> list4;

    //Using move operator - list1 move elements to list4
    list4 = std::move(list1);

    //Printing on console elements of list1
    //Expectations: EMPTY LIST
    std::cout << "Expectations: EMPTY LIST" << std::endl;
    list1.printMyLinkedList();

    //Printing on console elements of list4
    //Expectations: Elephant Lion Snake
    std::cout << "Expectations: Elephant Lion Snake" << std::endl;
    list4.printMyLinkedList();

    //Saving list2 to file test2.txt
    list2.saveToFile("test2.txt");

    //Printing on console elements of list1
    //Expectations: EMPTY LIST
    std::cout << "Expectations: EMPTY LIST" << std::endl;
    list1.printMyLinkedList();

    //Reading from file "test2.txt" and writing it to list1
    //Expectations: Elephant Lion Snake
    std::cout << "Expectations: Elephant Lion Snake" << std::endl;
    list1.fromFileToList("test2.txt");
    list1.printMyLinkedList();


    //Inserting element "Monkey" at the beginning of list1
    list1.insertElementAtBeginning("Monkey");

    //Inserting element "Bear" at the end of list1
    list1.insertElementAtEnd("Bear");

    //Printing on console elements of list1
    //Expectations: Monkey Elephant Lion Snake Bear
    std::cout << "Expectations: Monkey Elephant Lion Snake Bear" << std::endl;
    list1.printMyLinkedList();

    //Sorting list1
    list1.sort();
    //Expectations:
    std::cout << "Expectations: Bear Elephant Lion Monkey Snake " << std::endl;
    list1.printMyLinkedList();
}


int main() {
    test1();
    test2();

    return 0;
}