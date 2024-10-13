#include "../header/SegmentTree.h"

// Constructor: Initializes the segment tree with the input array
SegmentTree::SegmentTree(const vector<int> &arr)
{
    this->size = arr.size();
    this->tree.resize((4 * this->size), vector<int>(3));
    this->lazy.resize((4 * this->size), 0);

    this->build(1, 0, this->size - 1, arr);
}

// Builds the segment tree from the input array
void SegmentTree::build(int node, int start, int end, const vector<int> &arr)
{
    if (start == end)
    {
        this->tree[node] = {arr[start], arr[start], arr[start]};
        return;
    }

    int mid = (start + end) / 2;
    int child1 = (2 * node);
    int child2 = (2 * node) + 1;

    build(child1, start, mid, arr);
    build(child2, (mid + 1), end, arr);

    this->tree[node][0] = this->tree[child1][0] + this->tree[child2][0];
    this->tree[node][1] = max(this->tree[child1][1], this->tree[child2][1]);
    this->tree[node][2] = min(this->tree[child1][2], this->tree[child2][2]);
}

// Public method to update a specific index with a new value
void SegmentTree::pointUpdate(int index, int value)
{
    pointUpdate(1, 0, (this->size - 1), index, value);
}

// Updates a specific index with a new value
void SegmentTree::pointUpdate(int node, int start, int end, int index, int value)
{
    if (start == end)
    {
        if (start == index)
        {
            this->tree[node] = {value, value, value};
        }
        return;
    }

    int mid = (start + end) / 2;
    int child1 = (2 * node);
    int child2 = (2 * node) + 1;

    if (index <= mid)
    {
        pointUpdate(child1, start, mid, index, value);
    }
    else
    {
        pointUpdate(child2, (mid + 1), end, index, value);
    }

    this->tree[node][0] = this->tree[child1][0] + this->tree[child2][0];
    this->tree[node][1] = max(this->tree[child1][1], this->tree[child2][1]);
    this->tree[node][2] = min(this->tree[child1][2], this->tree[child2][2]);
}

// Public method to update all elements in the range [left, right] with a specific value
void SegmentTree::rangeUpdate(int left, int right, int value)
{
    rangeUpdate(1, 0, (this->size - 1), left, right, value);
}

// Updates all elements in a range [left, right] with a specific value using lazy propagation
void SegmentTree::rangeUpdate(int node, int start, int end, int left, int right, int value)
{
    propagate(node, start, end);

    if (left > end || right < start)
    {
        return;
    }

    if (left <= start && end <= right)
    {
        lazy[node] += value;
        propagate(node, start, end);
        return;
    }

    int mid = (start + end) / 2;
    int child1 = (2 * node);
    int child2 = (2 * node) + 1;

    rangeUpdate(child1, start, mid, left, right, value);
    rangeUpdate(child2, mid + 1, end, left, right, value);

    this->tree[node][0] = this->tree[child1][0] + this->tree[child2][0];
    this->tree[node][1] = max(this->tree[child1][1], this->tree[child2][1]);
    this->tree[node][2] = min(this->tree[child1][2], this->tree[child2][2]);
}

// Propagates lazy updates to the children of the current node
void SegmentTree::propagate(int node, int start, int end)
{
    if (lazy[node] != 0)
    {
        int addValue = lazy[node];

        this->tree[node][0] += (end - start + 1) * addValue;
        this->tree[node][1] += addValue;
        this->tree[node][2] += addValue;

        if (start != end)
        {
            int child1 = (2 * node);
            int child2 = (2 * node) + 1;

            lazy[child1] += addValue;
            lazy[child2] += addValue;
        }

        lazy[node] = 0;
    }
}

// Public method to query the sum in the range [left, right]
int SegmentTree::querySum(int left, int right)
{
    return querySum(1, 0, (this->size - 1), left, right);
}

// Queries the sum over a given range [left, right]
int SegmentTree::querySum(int node, int start, int end, int left, int right)
{
    propagate(node, start, end);

    if (left > end || right < start)
    {
        return 0;
    }
    if (left <= start && right >= end)
    {
        return this->tree[node][0];
    }

    int mid = (start + end) / 2;
    int child1 = (2 * node);
    int child2 = (2 * node) + 1;

    int sumLeft = querySum(child1, start, mid, left, right);
    int sumRight = querySum(child2, (mid + 1), end, left, right);

    return (sumLeft + sumRight);
}

// Public method to query the maximum value in the range [left, right]
int SegmentTree::queryMax(int left, int right)
{
    return queryMax(1, 0, (this->size - 1), left, right);
}

// Queries the maximum value over a given range [left, right]
int SegmentTree::queryMax(int node, int start, int end, int left, int right)
{
    propagate(node, start, end);

    if (left > end || right < start)
    {
        return INT_MIN;
    }
    if (left <= start && right >= end)
    {
        return this->tree[node][1];
    }

    int mid = (start + end) / 2;
    int child1 = (2 * node);
    int child2 = (2 * node) + 1;

    int maxLeft = queryMax(child1, start, mid, left, right);
    int maxRight = queryMax(child2, (mid + 1), end, left, right);

    return max(maxLeft, maxRight);
}

// Public method to query the minimum value in the range [left, right]
int SegmentTree::queryMin(int left, int right)
{
    return queryMin(1, 0, (this->size - 1), left, right);
}

// Queries the minimum value over a given range [left, right]
int SegmentTree::queryMin(int node, int start, int end, int left, int right)
{
    propagate(node, start, end);

    if (left > end || right < start)
    {
        return INT_MAX;
    }
    if (left <= start && right >= end)
    {
        return this->tree[node][2];
    }

    int mid = (start + end) / 2;
    int child1 = (2 * node);
    int child2 = (2 * node) + 1;

    int minLeft = queryMin(child1, start, mid, left, right);
    int minRight = queryMin(child2, (mid + 1), end, left, right);

    return min(minLeft, minRight);
}