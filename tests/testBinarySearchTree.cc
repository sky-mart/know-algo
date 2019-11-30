//
// Created by Vlad Agievich on 2019-07-07.
//

#include "know/algo/BinarySearchTree.h"
#include <gtest/gtest.h>

using namespace know::algo;
using namespace std;

TEST(BinarySearchTree, insert) {
    BinarySearchTree<int> bst;
    bst.insert(15);
    bst.insert(6);
    bst.insert(3);
    bst.insert(2);
    bst.insert(4);
    bst.insert(7);
    bst.insert(13);
    bst.insert(9);
    bst.insert(18);
    bst.insert(17);
    bst.insert(20);

    ASSERT_EQ(bst.find(1), nullptr);
    ASSERT_EQ(bst.find(21), nullptr);
    ASSERT_NE(bst.find(3), nullptr);
    ASSERT_NE(bst.find(20), nullptr);
}

TEST(BinarySearchTree, remove) {
    BinarySearchTree<int> bst = {15, 6, 3, 2, 4, 7, 13, 9, 18, 17, 20};

    ASSERT_NE(bst.find(20), nullptr);
    bst.remove(20);
    ASSERT_EQ(bst.find(20), nullptr);
}

TEST(BinarySearchTree, traversal) {
    BinarySearchTree<int> bst = {1, 2, 5, 6, 3, 4};

    ASSERT_EQ(bst.preOrderTraversal(), vector<int>({1, 2, 5, 3, 4, 6}));
    ASSERT_EQ(bst.inOrderTraversal(), vector<int>({1, 2, 3, 4, 5, 6}));
    ASSERT_EQ(bst.postOrderTraversal(), vector<int>({4, 3, 6, 5, 2, 1}));
    ASSERT_EQ(bst.levelOrderTraversal(), vector<int>({1, 2, 5, 3, 6, 4}));
}

TEST(BinarySearchTree, height) {
    BinarySearchTree<int> bst = {3, 2, 5, 1, 4, 6, 7};

    ASSERT_EQ(bst.height(), 3);
}

TEST(BinarySearchTree, topView) {
    BinarySearchTree<int> bst = {1, 2, 5, 3, 6, 4};
    ASSERT_EQ(bst.topView(), list<int>({1, 2, 5, 6}));

    BinarySearchTree<int> bst2 = {
            37, 23, 108, 59, 86, 64, 94, 14,
            105, 17, 111, 65, 55, 31, 79, 97,
            78, 25, 50, 22, 66, 46, 104, 98,
            81, 90, 68, 40, 103, 77, 74, 18,
            69, 82, 41, 4, 48, 83, 67, 6,
            2, 95, 54, 100, 99, 84, 34, 88,
            27, 72, 32, 62, 9, 56, 109, 115,
            33, 15, 91, 29, 85, 114, 112, 20,
            26, 30, 93, 96, 87, 42, 38, 60,
            7, 73, 35, 12, 10, 57, 80, 13,
            52, 44, 16, 70, 8, 39, 107, 106,
            63, 24, 92, 45, 75, 116, 5, 61,
            49, 101, 71, 11, 53, 43, 102, 110,
            1, 58, 36, 28, 76, 47, 113, 21,
            89, 51, 19, 3
    };
    ASSERT_EQ(bst2.topView(), list<int>({1, 2, 4, 14, 23, 37, 108, 111, 115, 116, 83, 84, 85}));
}

TEST(BinarySearchTree, lowestCommonAncestor) {
    BinarySearchTree<int> bst = {4, 2, 3, 1, 7, 6};

    ASSERT_EQ(bst.lowestCommonAncestor(1, 7), 4);
}

TEST(BinarySearchTree, isBinarySearchTree) {
    auto n1 = new BinaryTreeNode<int>(3);
    auto n2 = new BinaryTreeNode<int>(5);
    n1->left = n2;
    auto n3 = new BinaryTreeNode<int>(2);
    n1->right = n3;
    auto n4 = new BinaryTreeNode<int>(1);
    n2->left = n4;
    auto n5 = new BinaryTreeNode<int>(4);
    n2->right = n5;
    auto n6 = new BinaryTreeNode<int>(6);
    n3->left = n6;

    ASSERT_EQ(BinarySearchTree<int>::isBinarySearchTree(n1), false);
}

