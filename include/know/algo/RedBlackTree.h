//
// Created by Vlad Agievich on 2019-07-21.
//

#ifndef KNOW_ALGO_REDBLACKTREE_H
#define KNOW_ALGO_REDBLACKTREE_H

#include "BinarySearchTree.h"

namespace know {
namespace algo {

template<class T>
struct RedBlackNode : public BinaryTreeNode<T> {
    enum Color {
        Red,
        Black
    };

    Color color;
};

template<class T>
class RedBlackTree : public BinarySearchTree<T> {
public:
private:
    RedBlackNode *nil;
};

}
};

#endif //KNOW_ALGO_REDBLACKTREE_H
