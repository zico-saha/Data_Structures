#include "../header/UFDS.h"

using namespace std;

// Constructor to initialize the data structures
UFDS::UFDS(int n)
{
    this->nodeCount = n;
    this->rank.resize(n + 1, 0);
    this->size.resize(n + 1, 1);
    this->parent.resize(n + 1);

    for (int i = 0; i <= n; i++)
    {
        this->parent[i] = i;
    }
}

// Function to find the root parent of a node with path compression
int UFDS::findRootParent(int node)
{
    if (node < 0 || node >= this->parent.size())
    {
        throw out_of_range("Node index out of bounds");
    }
    return (this->parent[node] == node) ? node : (this->parent[node] = findRootParent(this->parent[node]));
}

// Function to union two sets by rank
void UFDS::unionByRank(int u, int v)
{
    int rootParent_u = findRootParent(u);
    int rootParent_v = findRootParent(v);

    if (rootParent_u == rootParent_v)
    {
        return;
    }

    if (this->rank[rootParent_u] < this->rank[rootParent_v])
    {
        this->parent[rootParent_u] = rootParent_v;
    }
    else if (this->rank[rootParent_u] > this->rank[rootParent_v])
    {
        this->parent[rootParent_v] = rootParent_u;
    }
    else
    {
        this->parent[rootParent_v] = rootParent_u;
        this->rank[rootParent_u]++;
    }
}

// Function to union two sets by size
void UFDS::unionBySize(int u, int v)
{
    int rootParent_u = findRootParent(u);
    int rootParent_v = findRootParent(v);

    if (rootParent_u == rootParent_v)
    {
        return;
    }

    if (this->size[rootParent_u] < this->size[rootParent_v])
    {
        this->parent[rootParent_u] = rootParent_v;
        this->size[rootParent_v] += this->size[rootParent_u];
    }
    else
    {
        this->parent[rootParent_v] = rootParent_u;
        this->size[rootParent_u] += this->size[rootParent_v];
    }
}

// Function to check if two nodes are connected
bool UFDS::isConnected(int node1, int node2)
{
    return findRootParent(node1) == findRootParent(node2);
}

// Function to get the size of the component containing a node
int UFDS::getComponentSize(int node)
{
    int root = findRootParent(node);
    return this->size[root];
}

// Function to count the number of unique components
int UFDS::countUniqueComponents()
{
    int uniqueComponents = 0;
    for (int i = 1; i <= this->nodeCount; i++)
    {
        if (this->parent[i] == i)
        {
            uniqueComponents++;
        }
    }
    return uniqueComponents;
}

// Function to list all components
vector<vector<int>> UFDS::listAllComponents()
{
    unordered_map<int, vector<int>> components;
    for (int i = 1; i <= this->nodeCount; i++)
    {
        int root = findRootParent(i);
        components[root].push_back(i);
    }

    vector<vector<int>> allComponents;
    for (auto &component : components)
    {
        allComponents.push_back(component.second);
    }
    return allComponents;
}

// Function to reset the UFDS
void UFDS::reset()
{
    for (int i = 0; i <= this->nodeCount; i++)
    {
        this->parent[i] = i;
        this->rank[i] = 0;
        this->size[i] = 1;
    }
}