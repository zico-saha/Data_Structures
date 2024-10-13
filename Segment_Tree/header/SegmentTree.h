#pragma once

#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class SegmentTree
{
private:
    int size = 0;             // Size of the input array
    vector<vector<int>> tree; // Segment tree to store sum, max, and min in each node
    vector<int> lazy;         // Lazy propagation array for deferred updates

    // Builds the segment tree from the input array
    // Time Complexity: O(n)
    void build(int node, int start, int end, const vector<int> &arr);

    // Queries the sum over a given range [left, right]
    // Time Complexity: O(log n)
    int querySum(int node, int start, int end, int left, int right);

    // Queries the maximum value over a given range [left, right]
    // Time Complexity: O(log n)
    int queryMax(int node, int start, int end, int left, int right);

    // Queries the minimum value over a given range [left, right]
    // Time Complexity: O(log n)
    int queryMin(int node, int start, int end, int left, int right);

    // Updates a specific index with a new value
    // Time Complexity: O(log n)
    void pointUpdate(int node, int start, int end, int index, int value);

    // Updates all elements in a range [left, right] with a specific value using lazy propagation
    // Time Complexity: O(log n)
    void rangeUpdate(int node, int start, int end, int left, int right, int value);

    // Propagates lazy updates to the children of the current node
    // Time Complexity: O(1) per node (total complexity depends on how many nodes are affected)
    void propagate(int node, int start, int end);

public:
    // Constructor: Initializes the segment tree with the input array
    // Time Complexity: O(n)
    SegmentTree(const vector<int> &arr);

    // Public method to query the sum in the range [left, right]
    // Time Complexity: O(log n)
    int querySum(int left, int right);

    // Public method to query the maximum value in the range [left, right]
    // Time Complexity: O(log n)
    int queryMax(int left, int right);

    // Public method to query the minimum value in the range [left, right]
    // Time Complexity: O(log n)
    int queryMin(int left, int right);

    // Public method to update a specific index with a new value
    // Time Complexity: O(log n)
    void pointUpdate(int index, int value);

    // Public method to update all elements in the range [left, right] with a specific value
    // Uses lazy propagation for efficient range updates
    // Time Complexity: O(log n)
    void rangeUpdate(int left, int right, int value);
};