#include "../header/FenwickTree.h"

FenwickTree::FenwickTree(const vector<int> &arr)
{
    this->size = arr.size() + 1;
    this->tree.resize(this->size, 0);

    for (int i = 0; i < arr.size(); i++)
    {
        pointUpdate(i, arr[i]);
    }
}

void FenwickTree::pointUpdate(int index, int value)
{
    for (int i = (index + 1); i < this->size; i += (i & (-i)))
    {
        this->tree[i] += value;
    }
}

int FenwickTree::prefixSum(int index)
{
    int sum = 0;
    for (int i = (index + 1); i > 0; i -= (i & (-i)))
    {
        sum += this->tree[i];
    }
    return sum;
}

int FenwickTree::querySum(int left, int right)
{
    return (prefixSum(right) - prefixSum(left - 1));
}