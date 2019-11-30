//
// Created by Vlad Agievich on 2019-09-28.
//

#include "know/algo/BinaryTreeNode.h"
#include "know/algo/utils.h"
#include <gtest/gtest.h>

using namespace know::algo;
using namespace std;

TEST(utils, huffmanDecode) {
    auto f5 = new BinaryTreeNode<char>('\0');
    auto f2 = new BinaryTreeNode<char>('\0');
    f5->left = f2;
    auto a3 = new BinaryTreeNode<char>('a');
    f5->right = a3;
    auto b1 = new BinaryTreeNode<char>('b');
    f2->left = b1;
    auto c1 = new BinaryTreeNode<char>('c');
    f2->right = c1;

    ASSERT_EQ(huffmanDecode(f5, "1001011"), "abaca");
}

TEST(utils, swapNodes) {
    vector<vector<int>> res1 = swapNodes({
                                                 {2, 3},
                                                 {-1, -1},
                                                 {-1, -1}}, {1, 1});
    ASSERT_EQ(res1, vector<vector<int>>({
    {3, 1, 2},
    {2, 1, 3}
    }));

    vector<vector<int>> res2 = swapNodes({
                                                 {2, 3},
                                                 {-1, 4},
                                                 {-1, 5},
                                                 {-1, -1},
                                                 {-1, -1}}, {2});
    ASSERT_EQ(res2, vector<vector<int>>({{4, 2, 1, 5, 3}}));

    vector<vector<int>> res3 = swapNodes({
                                                 {2, 3},
                                                 {4, -1},
                                                 {5, -1},
                                                 {6, -1},
                                                 {7, 8},
                                                 {-1, 9},
                                                 {-1, -1},
                                                 {10, 11},
                                                 {-1, -1},
                                                 {-1, -1},
                                                 {-1, -1}}, {2, 4});
    ASSERT_EQ(res3, vector<vector<int>>({
    {2, 9, 6, 4, 1, 3, 7, 5, 11, 8, 10},
    {2, 6, 9, 4, 1, 3, 7, 5, 10, 8, 11}
    }));
}

