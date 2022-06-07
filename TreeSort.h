//
// Created by fire on 2022/6/2.
//

#ifndef SORT_TREESORT_H
#define SORT_TREESORT_H

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
#endif //SORT_TREESORT_H
int const m = 1000000;


void TreeSort(vector<int> &a) {
    int len = a.size();// 数组长度
    int nodeSize = len * 2 - 1; // 对一个满二叉树，节点总数 = 叶子节点数*2-1
    int* tree = new int[nodeSize + 1]; // 这里将用数组表示二叉树的存储结构
    /* 填充叶子节点 */
    for (int i = len - 1, j = 0; i >= 0; i--, j++) {
        tree[nodeSize - j] = a[i];
    }
    /* 填充其他节点 */
    for (int i = nodeSize - len; i > 0; i--) {
        tree[i] = tree[i * 2] < tree[i * 2 + 1] ? tree[i * 2] : tree[i * 2 + 1];
    }
    /* 将每次找出的最小元素移走 */
    int index = 0;// 数组a的索引
    int minIndex = 0;// 最小值的索引
    while (index < len) {
        int min = tree[1]; // 这是tree的根节点，也是最小元素
        a[index++] = tree[1]; // 将tree中最小的元素取到a[0]中
        minIndex = nodeSize;
        /* 从最后的叶子节点开始，直到找到最小值的索引 */
        while (tree[minIndex] != min) {
            minIndex--;
        }
        tree[minIndex] = m; // 将这个最小元素置为最大
        /* 如果这个节点还有父节点，那么就将它的兄弟节点升到父亲节点位置 */
        while (minIndex > 1) {// 根结点的索引是1
            if (minIndex % 2 == 0) {// 这个节点是左节点
                tree[minIndex / 2] = tree[minIndex] < tree[minIndex + 1] ? tree[minIndex] : tree[minIndex + 1];
                minIndex = minIndex / 2;
            } else {// 这个节点是右节点
                tree[minIndex / 2] = tree[minIndex] < tree[minIndex - 1] ? tree[minIndex] : tree[minIndex - 1];
                minIndex = minIndex / 2;
            }
        }
    }
}
