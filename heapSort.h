//
// Created by fire on 2022/6/3.
//

#ifndef SORT_HEAPSORT_H
#define SORT_HEAPSORT_H

#endif //SORT_HEAPSORT_H
#include <iostream>
#include <vector>
using namespace std;

/**
 * 调整数组变成最大堆
 * @param a 输入数组
 * @param begin 起点
 * @param end 终点
 */
void maxHeap(vector<int> &a,int begin,int end){
    int dad=begin;
    int son=dad*2+1;
    while(son<=end){
        if(son+1<=end){
            //如果有两个儿子
            if(a[son]<a[son+1]){
                //如果左儿子大于右儿子，选中右儿子
                son++;
            }
        }
        if(a[dad]>a[son]){
            //如果此节点形成最大堆，返回
            return;
        }
        else{
            //如果不成立，那么交换父子，进行下一次比较
            swap(a[son],a[dad]);
            //dad和son指向新的父子，进行下一次构建
            dad=son;
            son=dad*2+1;
        }

    }
}

/**
 * 把无序数组构建成最大堆
 * @param a 输入数组
 */
void buildAll(vector<int> &a){
    for(int i=a.size()/2-1;i>=0;i--){
        maxHeap(a,i,a.size()-1);
    }
}

void heapSort(vector<int> &a){
    //从后往前构建一次最大堆
    buildAll(a);
    //进行堆排序,共n-1次
    for(int i=a.size()-1;i>0;i--){
        swap(a[i],a[0]);
        maxHeap(a,0,i-1);
    }
}

/**
 * 由儿子得到父亲
 * @param son 儿子下标
 * @return //父亲下标
 */
int getDad(int son){
    //leftSon=dad*2+1,rightSon=dad*2+2
    if(son%2==0){
        //右儿子
        return (son/2)-1;
    }
    else{
        //左儿子
        return (son-1)/2;
    }
}

/**
 * 向堆中插入一个元素
 * @param a 堆数组
 * @param x 插入的元素
 */
void insert(vector<int> &a,int x){
    //x放在最后一个
    a.push_back(x);
    //从后往前扫描
    int son=a.size()-1;
    int dad=getDad(son);
    while(dad>=0){
        if(a[son]>a[dad]){
            swap(a[son],a[dad]);
            son=dad;
            dad=getDad(dad);
        }
        else{
            return;
        }
    }
}
