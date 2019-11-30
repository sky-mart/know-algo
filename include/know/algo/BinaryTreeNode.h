//
// Created by Vlad Agievich on 2019-07-07.
//

#ifndef KNOW_ALGO_BINARYTREENODE_H
#define KNOW_ALGO_BINARYTREENODE_H

#include <vector>
#include <list>

namespace know {
namespace algo {

template<class T>
struct BinaryTreeNode {
    BinaryTreeNode *p;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    T value;

    explicit BinaryTreeNode(const T& v) : p(nullptr), left(nullptr), right(nullptr), value(v) {}

    ~BinaryTreeNode() {
        delete left;
        delete right;
    }

    bool hasChildren() const {
        return left || right;
    }

    void preOrder(std::vector<T>& traversal) const {
        traversal.push_back(value);
        if (left) {
            left->preOrder(traversal);
        }
        if (right) {
            right->preOrder(traversal);
        }
    }

    void inOrder(std::vector<T>& traversal) const {
        if (left) {
            left->inOrder(traversal);
        }
        traversal.push_back(value);
        if (right) {
            right->inOrder(traversal);
        }
    }

    void postOrder(std::vector<T>& traversal) const {
        if (left) {
            left->postOrder(traversal);
        }
        if (right) {
            right->postOrder(traversal);
        }
        traversal.push_back(value);
    }

    size_t height() const {
        size_t leftHeight = 0, rightHeight = 0;
        if (left) {
            leftHeight = left->height() + 1;
        }
        if (right) {
            rightHeight = right->height() + 1;
        }
        return leftHeight > rightHeight
               ? leftHeight
               : rightHeight;
    }

    static std::vector<T> preOrderTraversal(BinaryTreeNode<T> *root) {
        std::vector<T> traversal;
        if (root) {
            root->preOrder(traversal);
        }
        return traversal;
    }

    static std::vector<T> inOrderTraversal(BinaryTreeNode<T> *root) {
        std::vector<T> traversal;
        if (root) {
            root->inOrder(traversal);
        }
        return traversal;
    }

    static std::vector<T> postOrderTraversal(BinaryTreeNode<T> *root) {
        std::vector<T> traversal;
        if (root) {
            root->postOrder(traversal);
        }
        return traversal;
    }

    static std::vector<T> levelOrderTraversal(BinaryTreeNode<T> *root) {
        std::vector<T> traversal;
        std::list<BinaryTreeNode<T> *> q;
        BinaryTreeNode<T> *x;

        if (root) {
            q.push_back(root);
            while (!q.empty()) {
                x = q.front();
                traversal.push_back(x->value);
                if (x->left) {
                    q.push_back(x->left);
                }
                if (x->right) {
                    q.push_back(x->right);
                }
                q.pop_front();
            }
        }
        return traversal;
    }
};

}
};

#endif //KNOW_ALGO_BINARYTREENODE_H
