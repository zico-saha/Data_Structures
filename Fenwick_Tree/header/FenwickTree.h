#pragma once

#include <vector>

using namespace std;

class FenwickTree
{
private:
    int size = 0;     // Size of the tree (size + 1 for 1-based indexing)
    vector<int> tree; // Fenwick Tree (BIT) representation

public:
    // Constructor: Builds the tree based on the input array
    FenwickTree(const vector<int> &arr);

    // Point update: Adds value to the element at index
    // Time Complexity: O(log n)
    void pointUpdate(int index, int value);

    // Returns the prefix sum up to the given index
    // Time Complexity: O(log n)
    int prefixSum(int index);

    // Returns the sum over the range [left, right]
    // Time Complexity: O(log n)
    int querySum(int left, int right);
};