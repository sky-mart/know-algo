//
// Created by Vlad Agievich on 2019-03-03.
//

#ifndef KNOW_ALGO_BINARYSEARCHTREE_H
#define KNOW_ALGO_BINARYSEARCHTREE_H

#include "BinaryTreeNode.h"
#include <vector>
#include <list>

namespace know {
namespace algo {

template<class T>
class BinarySearchTree {
public:
    BinarySearchTree() : root(nullptr) {}

    BinarySearchTree(std::initializer_list<T> ilist) : root(nullptr) {
        for (const T& x : ilist) {
            insert(x);
        }
    }

    ~BinarySearchTree() {
        delete root;
    }

    BinaryTreeNode<T> *find(const T& v) const {
        return find(root, v);
    }

    void insert(const T& v) {
        BinaryTreeNode<T> *x = root, *y = nullptr;
        auto *z = new BinaryTreeNode<T>(v);

        while (x) {
            y = x;
            if (z->value < x->value) {
                x = x->left;
            } else {
                x = x->right;
            }
        }
        z->p = y;

        if (y == nullptr) {
            root = z;
        } else if (z->value < y->value) {
            y->left = z;
        } else {
            y->right = z;
        }
    }

    void remove(const T& v) {
        // TODO: check if node memory is freed
        BinaryTreeNode<T> *y, *z = find(root, v);
        if (z == nullptr) {
            return;
        }

        if (z->left == nullptr) {
            transplant(z, z->right);
        } else if (z->right == nullptr) {
            transplant(z, z->left);
        } else {
            y = minimum(z->right);
            if (y->p != z) {
                transplant(y, y->right);
                y->right = z->right;
                y->right->p = y;
            }
            transplant(z, y);
            y->left = z->left;
            y->left->p = z;
        }
    }

    std::vector<T> preOrderTraversal() const {
        return BinaryTreeNode<T>::preOrderTraversal(root);
    }

    std::vector<T> inOrderTraversal() const {
        return BinaryTreeNode<T>::inOrderTraversal(root);
    }

    std::vector<T> postOrderTraversal() const {
        return BinaryTreeNode<T>::postOrderTraversal(root);
    }

    std::vector<T> levelOrderTraversal() const {
        return BinaryTreeNode<T>::levelOrderTraversal(root);
    }

    size_t height() const {
        if (root) {
            return root->height();
        }
        return 0;
    }

    std::list<T> topView() const {
        std::list<std::pair<BinaryTreeNode<T> *, int>> q;
        std::list<T> top;
        BinaryTreeNode<T> *x;
        int minHor = 1, maxHor = 0, hor;

        if (root) {
            q.push_back(std::make_pair(root, 0));
            while (!q.empty()) {
                auto p = q.front();
                x = p.first;
                hor = p.second;

                if (hor < minHor) {
                    top.push_front(x->value);
                    minHor = hor;
                } else if (hor > maxHor) {
                    top.push_back(x->value);
                    maxHor = hor;
                }
                if (x->left) {
                    q.push_back(std::make_pair(x->left, hor - 1));
                }
                if (x->right) {
                    q.push_back(std::make_pair(x->right, hor + 1));
                }
                q.pop_front();
            }
        }
        return top;
    }

    T lowestCommonAncestor(const T& u, const T& v) {
        auto uPath = std::move(findPath(root, u));
        auto vPath = std::move(findPath(root, v));
        auto i = uPath.begin();
        auto j = vPath.begin();

        while ((i != uPath.end()) &&
               (j != vPath.end()) &&
               (*i == *j)) {
            ++i;
            ++j;
        }
        return (*(--i))->value;
    }

    static bool isBinarySearchTree(BinaryTreeNode<T> *root) {
        auto t = BinaryTreeNode<T>::inOrderTraversal(root);
        for (int i = 1; i < t.size(); ++i) {
            if (t[i] <= t[i - 1]) {
                return false;
            }
        }
        return true;
    }

protected:
    static BinaryTreeNode<T> *find(BinaryTreeNode<T> *root, const T& v) {
        BinaryTreeNode<T> *x = root;
        while (x != nullptr && v != x->value) {
            if (v < x->value) {
                x = x->left;
            } else {
                x = x->right;
            }
        }
        return x;
    }

    static std::vector<BinaryTreeNode<T> *> findPath(BinaryTreeNode<T> *root, const T& v) {
        std::vector<BinaryTreeNode<T> *> path;
        BinaryTreeNode<T> *x = root;
        while (true) {
            if (!x) {
                return std::vector<BinaryTreeNode<T> *>();
            }
            path.push_back(x);
            if (v == x->value) {
                return path;
            }
            if (v < x->value) {
                x = x->left;
            } else {
                x = x->right;
            }
        }
    }

    // transplant node v to the place of node u
    void transplant(BinaryTreeNode<T> *u, BinaryTreeNode<T> *v) {
        if (u->p == nullptr) {
            root = v;
        } else if (u == u->p->left) {
            u->p->left = v;
        } else {
            u->p->right = v;
        }
        if (v) {
            v->p = u->p;
        }
    }

    void leftRotate(BinaryTreeNode<T> *x) {
        BinaryTreeNode<T> *y = x->right;

        x->right = y->left;
        if (y->left != nullptr) {
            y->left->p = x;
        }

        y->p = x->p;
        if (x->p == nullptr) {
            root = y;
        } else if (x == x->p->left) {
            x->p->left = y;
        } else {
            x->p->right = y;
        }

        y->left = x;
        x->p = y;
    }

    void rightRotate(BinaryTreeNode<T> *y) {
        BinaryTreeNode<T> *x = y->left;

        y->left = x->right;
        if (x->right != nullptr) {
            x->right->p = y;
        }

        x->p = y->p;
        if (y->p == nullptr) {
            root = x;
        } else if (y == y->p->left) {
            y->p->left = x;
        } else {
            y->p->right = x;
        }

        x->right = y;
        y->p = x;
    }

    static BinaryTreeNode<T> *minimum(BinaryTreeNode<T> *root) {
        BinaryTreeNode<T> *x = root;
        while (x->left) {
            x = x->left;
        }
        return x;
    }

    static BinaryTreeNode<T> *maximum(BinaryTreeNode<T> *root) {
        BinaryTreeNode<T> *x = root;
        while (x->right) {
            x = x->right;
        }
        return x;
    }

    static BinaryTreeNode<T> *successor(BinaryTreeNode<T> *root) {
        BinaryTreeNode<T> *x = root, *y;
        if (x->right) {
            return minimum(x->rigth);
        }
        y = x->p;
        while (y && x == y->right) {
            x = y;
            y = y->p;
        }
        return y;
    }

    static BinaryTreeNode<T> *predecessor(BinaryTreeNode<T> *root) {
        BinaryTreeNode<T> *x = root, *y;
        if (x->left) {
            return maximum(x->left);
        }
        y = x->p;
        while (y && x == y->left) {
            x = y;
            y = y->p;
        }
        return y;
    }

    BinaryTreeNode<T> *root;
};

}
};

#endif //KNOW_ALGO_BINARYSEARCHTREE_H