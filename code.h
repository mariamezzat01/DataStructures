#ifndef MY_TREE_H
#define MY_TREE_H
#include <iostream>
#include <cassert>
#include <vector>
#include <stack>
#include "queue"
#include<algorithm>
using namespace std;
template <class T>
class MyTree {

private:

    struct node {
        T item;
        node* left;
        node* right;
    };



public:
    node* root;
    int size;

    MyTree(int SSize) {
        root = NULL;
        size = SSize ;
    }

    MyTree(int SSize,vector<T> elements) {
        size = SSize ;
        root = NULL;
        sort(elements.begin(), elements.end());
        root = insertvector(elements, 0, elements.size() - 1);
    }

    node* insertvector(vector<T> v, int start, int end) {
        {
            if (start > end)
                return NULL;
            int mid = (start + end) / 2;
            node* p = newnode(v[mid]);
            p->left = insertvector(v, start, mid - 1);
            p->right = insertvector(v, mid + 1, end);
            return p;
        }

    }

    node* newnode(T key) {
        node* t = new node();
        t->item = key;
        t->left = NULL;
            t->right = NULL;
        return t;

    }

    bool search(T key) {
        node* p = root;
        if (p == NULL) return false;

        while (p != NULL) {
            if (key == p->item)
                return true;
            if (key > p->item) {
                p = p->right;
            }
            else
                p = p->left;
        }
        return false;
    }

    void insert(T key) {
        node* current;
        node* trailCurrent;
        node* newNode;

        newNode = new node;
        assert(newNode != NULL);
        newNode->item = key;
        newNode->right = NULL;
        newNode->left = NULL;

        if (root == NULL) {
            root = newNode;
            size++;
        }
        else {

            current = root;
            while (current != NULL) {
                trailCurrent = current;

                if (key > current->item) {
                    current = current->right;
                }
                else current = current->left;
            }
            if (key > trailCurrent->item) {
                trailCurrent->right = newNode;
                size++;
            }
            else {
                trailCurrent->left = newNode;
                size++;
            }
        }
    }

    void inorder_rec() { inorder(root); }
    void inorder(node* node)
    {
        if (node == NULL)
            return;

        inorder(node->left);
        cout << node->item << " ";
        inorder(node->right);
    }


    void preorder_rec() { preorder(root); }
    void preorder(node* node) {
        if (node == NULL)
            return;
        cout << node->item << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder_rec() { postorder_rec(root); }
    void postorder_rec(node* node) {
        if (node == NULL)
            return;
        postorder_rec(node->left);
        postorder_rec(node->right);
        cout << node->item << " ";
    }

    void inorder_it() {
        stack<node*> s;
        node* curr = root;

        while (curr != NULL || s.empty() == false)
        {
            while (curr != NULL)
            {
                s.push(curr);
                curr = curr->left;
            }

            curr = s.top();
            s.pop();

            cout << curr->item << " ";
            curr = curr->right;

        }
    }

    void preorder_it()
    {
        node* p = root;
        if (p == NULL)
            return;

        stack<node*> nodeStack;
        nodeStack.push(p);

        while (nodeStack.empty() == false) {
            struct node* node = nodeStack.top();
            cout << node->item << " ";
            nodeStack.pop();


            if (node->right)
                nodeStack.push(node->right);
            if (node->left)
                nodeStack.push(node->left);
        }
    }

    void postorder_it() {
        node* p = root;
        if (p == NULL)
            return;
        stack<node*> s1, s2;

        s1.push(root);
        node* node;

        while (!s1.empty()) {

            node = s1.top();
            s1.pop();
            s2.push(node);

            if (node->left)
                s1.push(node->left);
            if (node->right)
                s1.push(node->right);
        }

        while (!s2.empty()) {
            node = s2.top();
            s2.pop();
            cout << node->item << " ";
        }


    }

    void breadth_traversal() {
        node* p = root;
        if (p == NULL)
            return;
        queue<node*> q;
        q.push(p);
        while (q.empty() == false) {
            node* temp = q.front();
            cout << temp->item << " ";
            q.pop();

            if (temp->left != NULL)
                q.push(temp->left);

            if (temp->right != NULL)
                q.push(temp->right);
        }

    }

    int Size() {
        return size;
    }
};


#endif 
