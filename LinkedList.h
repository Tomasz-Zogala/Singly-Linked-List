#ifndef PROJECTLINKEDLIST_LINKEDLIST_H
#define PROJECTLINKEDLIST_LINKEDLIST_H

/**
* @brief
* Generic type class - Single Node used in MyLinkedList class
*/
template<class T>
class Node {
public:
    /**
 * @brief
 * Generic type data - hold data in Node
 */
    T data;

    /**
 * @brief
 * Pointer of generic type Node - points to the next Node object in MyLinkedList class
 */
    Node<T>* next;

    /**
* @brief
* Default constructor of Node class
*/
    Node();

    /**
* @param data data in Node
* @brief
* Constructor of Node class with given data of generic type
*/
    Node(T data);
};

/**
* @brief
* Generic type class - MyLinkedList
*/
template<class T>
class MyLinkedList {
    /**
* @brief
* Pointer of generic type Node - points to head (first node of MyLinkedList)
*/
    Node<T>* head;

public:
    /**
* @brief
* Default constructor of MyLinkedList class
*/
    MyLinkedList();

    /**
* @param list MyLinkedList from which elements are copied
* @brief
* Copy constructor of MyLinkedList class
*/

    MyLinkedList(const MyLinkedList& list);

    /**
* @param list MyLinkedList from which elements are moved
* @brief
* Move constructor of MyLinkedList class
*/

    MyLinkedList(MyLinkedList&& list);

    /**
* @brief
* Destructor of MyLinkedList class
*/

    ~MyLinkedList();

    /**
* @param data given data
* @brief
* MyLinkedList method - insert node with given data at the end of MyLinkedList
*/

    void insertElementAtEnd(T data);

    /**
* @param data given data
* @brief
* MyLinkedList method - insert node with given data at the beginning of MyLinkedList
*/

    void insertElementAtBeginning(T data);

    /**
* @brief
* MyLinkedList method - print every data of nodes in MyLinkedList
*/

    void printMyLinkedList();

    /**
* @param nodeOfSet index of the node to be deleted
* @brief
* MyLinkedList method - delete node under given index in MyLinkedList
*/

    void deleteElement(int nodeOfSet);

    /**
* @param element element which is searched for in the MyLinkedList
* @brief
* MyLinkedList method - searching for the given element in the MyLinkedList
*/

    void searchForElement(T element);

    /**
* @param list list from which elements are copied
* @brief
* MyLinkedList overload of assign operator - copying elements from one MyLinkedList to another
*/

    void operator=(const MyLinkedList& list);

    /**
* @param list list from which elements are moved
* @brief
* MyLinkedList overload of assign operator - moving elements from one MyLinkedList to another
*/

    void operator=(MyLinkedList&& list);

    /**
* @brief
* MyLinkedList method - sorting elements in the MyLinkedList (ascending)
*/
    void sort();

    /**
* @param fileName name of the file into which the data are written
* @brief
* MyLinkedList method - saving the MyLinkedList data to a text file with the given name
*/

    void saveToFile(std::string fileName);

    /**
* @param fileName the name of the file from which data is loaded
* @brief
* MyLinkedList method - loading data from a file into a MyLinkedList
*/

    void fromFileToList(std::string fileName);

};

#endif PROJECTLINKEDLIST_LINKEDLIST_H