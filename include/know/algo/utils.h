//
// Created by Vlad Agievich on 2019-07-10.
//

#ifndef KNOW_ALGO_UTILS_H
#define KNOW_ALGO_UTILS_H

#include "BinaryTreeNode.h"
#include <string>

std::string huffmanDecode(know::algo::BinaryTreeNode<char> *huffmanRoot, const std::string &s);

std::vector<std::vector<int>> swapNodes(std::vector<std::vector<int>> nodes, std::vector<int> swaps);

#endif //KNOW_ALGO_UTILS_H
