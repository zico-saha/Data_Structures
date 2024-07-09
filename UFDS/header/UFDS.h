#pragma once

#include <vector>
#include <unordered_map>
#include <stdexcept>

using namespace std;

class UFDS
{
private:
    int nodeCount = 0;
    vector<int> parent;
    vector<int> rank;
    vector<int> size;

public:
    // Constructor: Initializes the data structures
    // Time Complexity: O(n)
    UFDS(int n);

    // Find the root parent of a node with path compression
    // Amortized Time Complexity: O(α(n))
    int findRootParent(int node);

    // Union two sets by rank
    // Amortized Time Complexity: O(α(n))
    void unionByRank(int node1, int node2);

    // Union two sets by size
    // Amortized Time Complexity: O(α(n))
    void unionBySize(int node1, int node2);

    // Check if two nodes are connected
    // Amortized Time Complexity: O(α(n))
    bool isConnected(int node1, int node2);

    // Get the size of the component containing a node
    // Amortized Time Complexity: O(α(n))
    int getComponentSize(int node);

    // Count the number of unique components
    // Time Complexity: O(n)
    int countUniqueComponents();

    // List all components as sets of nodes
    // Time Complexity: O(n)
    vector<vector<int>> listAllComponents();

    // Reset the UFDS
    // Time Complexity: O(n)
    void reset();
};