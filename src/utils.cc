//
// Created by Vlad Agievich on 2019-07-10.
//

#include "know/algo/utils.h"
#include <unordered_set>

using namespace know::algo;
using namespace std;

string huffmanDecode(BinaryTreeNode<char> *huffmanRoot, const string &s) {
    auto curNode = huffmanRoot;
    string ans;

    for (char c : s) {
        curNode = c == '1' ? curNode->right : curNode->left;
        if (!curNode->hasChildren()) {
            ans += curNode->value;
            curNode = huffmanRoot;
        }
    }
    return ans;
}

// hackerrank problem. Contains loop inorder traversal
vector<vector<int>> swapNodes(vector<vector<int>> nodes, vector<int> swaps) {
    vector<vector<int>> traversals(swaps.size());

    if (nodes.empty()) {
        return traversals;
    }

    vector<int> parent(nodes.size());
    vector<vector<int>> nodesByLevel = {{1}};
    parent[0] = -1;
    int level = 0;

    while (true) {
        vector<int> newLevelIndices;
        for (int i : nodesByLevel[level]) {
            for (int child : nodes[i-1]) {
                if (child != -1) {
                    newLevelIndices.push_back(child);
                    parent[child-1] = i;
                }
            }
        }
        if (newLevelIndices.empty()) {
            break;
        }
        nodesByLevel.push_back(newLevelIndices);
        level++;
    }

    for (int q = 0; q < swaps.size(); q++) {
        int query = swaps[q];
        int levelToSwap = query;
        while (levelToSwap <= nodesByLevel.size()) {
            for (int i : nodesByLevel[levelToSwap-1]) {
                swap(nodes[i-1][0], nodes[i-1][1]);
            }
            levelToSwap += query;
        }

        // in order traversal
        vector<bool> visited(nodes.size(), false);
        int cur = 1;
        while (true) {
            if (visited[cur-1]) {
                if (parent[cur-1] == -1) {
                    break;
                }
                cur = parent[cur-1];
            }

            int left = nodes[cur-1][0];
            int right = nodes[cur-1][1];

            if (left != -1 && !visited[left-1]) {
                cur = left;
                continue;
            }
            if (!visited[cur-1]) {
                traversals[q].push_back(cur);
                visited[cur - 1] = true;
            }
            if (right != -1 && !visited[right-1]) {
                cur = right;
                continue;
            }
        }
    }
    return traversals;
}
