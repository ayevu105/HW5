/* @file bst.h
 * @brief The following code gives the declarations of the bst class.
 *  This class is used to store movies.
 * @author Anthony Vu
 * @date 12/05/2022
 */

#ifndef _BST_H_
#define _BST_H_
#include <iostream>
#include <assert.h>

template <typename T>
class BST {
public:
    BST();

    ~BST();

    bool insert(T*);

    bool retrieve(const T&, T*&) const;

    void display() const;

    bool remove(const T&);

    void clear();

    bool isEmpty() const;

    int getTotalNode() const;

private:
    struct Node {
        T* data;
        Node* right;
        Node* left;
    };

    Node* root;

    int totalNode;

    bool insertHelper(T*, Node*&);

    bool retrieveHelper(Node*, const T&, T*&) const;

    void displayHelper(Node*) const;

    bool removeHelper(Node*& current, const T& key);

    void clearHelper(Node*&);
};

//bst constructor
template<typename T>
BST<T>::BST() {
    root = nullptr;
    totalNode = 0;
}

//destructor
template<typename T>
BST<T>::~BST() {
    clear();
}

/*insert calls insertHelper to traverse recursively through the tree 
 * and returns false if there are repititions
 */
template<typename T>
bool BST<T>::insert(T* newNode) {
    if (root == nullptr) {
        //create a new root, and assign left and right subtree null pointer
        root = new Node{ newNode, nullptr, nullptr };
        assert(root != nullptr); // out of memory
        totalNode++;
        return true;
    } else {
        if (insertHelper(newNode, root)) {
            totalNode++;
            return true;
        }
        return false;
    }
}

/*insertHelper recursively traverses the tree and adds the node
 */
 template<typename T>
bool BST<T>::insertHelper(T* newNode, Node*& current) {
    if (current == nullptr) {
        current = new Node{ newNode, nullptr, nullptr };
        assert(current != nullptr); // out of memory
        return true;
    } else if (*newNode < *current->data) {
        return insertHelper(newNode, current->left);
    } else if (*newNode > *current->data) {
        return insertHelper(newNode, current->right);
    } else {
        //if duplicate
        return false;
    }
}

/*retrieve calls retrieve helper and returns true if successfully retrieves
 */
template<typename T>
bool BST<T>::retrieve(const T& target, T*& retriever) const {
    return retrieveHelper(root, target, retriever);
}

/* retrieveHelper recursively traverses the tree and returns true if target is found
 */
template<typename T>
bool BST<T>::retrieveHelper(Node* current, const T& target, T*& retriever) const {
    if (current == nullptr) {
        retriever = nullptr;
        return false;
    }

    if (target < *current->data) {
        return retrieveHelper(current->left, target, retriever);
    } else if (target > *current->data) {
        return retrieveHelper(current->right, target, retriever);
    } else {
        retriever = current->data;
        return true;
    }
}

/* remove finds the target node and deletes it and returns true if successful
 */
template<typename T>
bool BST<T>::remove(const T& target) {
    if (this->root == nullptr) {
        return false;
    } else {
        if (removeHelper(root, target)) {
            totalNode--;
            return true;
        }
        return false;
    }
}

/* removeHelper recursively traverses the tree and retu8rns true if successuful
 */
template<typename T>
bool BST<T>::removeHelper(Node*& current, const T& target) {
    if (current == nullptr) {
        return false;
    }

    if (target < *current->data) {
        return removeHelper(current->left, target);
    } else if (target > * current->data) {
        return removeHelper(current->right, target);
    } else {
        if (current->left == nullptr && current->right == nullptr) 
        {
            delete current->data;
            delete current;
            current = nullptr;
            return true;
        } else if (current->left && current->right) {
            Node* temp = current->right;
            while (temp->left != nullptr) 
            {
                temp = temp->left;
            }
            *current->data = *temp->data;
            return removeHelper(current->right, *temp->data);
        } else {
            Node* child = (current->left) ? current->left : current->right;
            Node* temp = current;
            current = child;
            delete temp->data;
            delete temp;
            temp = nullptr;
            return true;
        }
    }
}

/* display displays the noeds of the tree from left to right
 */
template<typename T>
void BST<T>::display() const {
    displayHelper(root);
}

/* displayHelper traverse recursively through the tree
 */
template<typename T>
void BST<T>::displayHelper(Node* current) const {
    if (current == nullptr) {
        return;
    } else {
        displayHelper(current->left);
        std::cout << "  " << *current->data << std::endl;
        displayHelper(current->right);
    }
}

/* clear deletes all the nodes from the tree
 */
template<typename T>
void BST<T>::clear() 
{
    if (root == nullptr) {
        return;
    }

    clearHelper(root);
    root = nullptr;
}

/* clearHelper traverses recursively the tree and delete very nodes
 */
template<typename T>
void BST<T>::clearHelper(Node*& current) {
    if (current != nullptr) {
        clearHelper(current->left);        
        clearHelper(current->right);       
        if (current->data != nullptr) {
            delete current->data;          
        }
        delete current;                 
    }
}

/* isEmpty checks the tree to see if it is empty
 */
template<typename T>
bool BST<T>::isEmpty() const {
    return root == nullptr;
}

/*getTotalNode returns the total number of nodes
 */
template<typename T>
int BST<T>::getTotalNode() const {
    return totalNode;
}
#endif