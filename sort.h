//
// Created by fire on 2022/5/30.
//

#ifndef SORT_SORT_H
#define SORT_SORT_H

#endif //SORT_SORT_H

#include <iostream>
#include <vector>
using namespace std;










/**
 * 二分插入排序,其实效率上并没有优化
 * @param a 输入数组
 */
void sort4(int* a){
    cout<<"二分插入排序"<<endl;
    int length=a[0];
    for(int i=2;i<=length;i++){
        int tmp=a[i];
        int low=1;
        int high=i-1;
        int mid;
        int j=i;
        while(low<=high){
            mid=(low+high)/2;
            if(a[mid]>tmp){
                //如果中间值大于tmp，那么high往左走
                high=mid-1;
            }
            else{
                //如果中间值等于tmp或者小于tmp，那么low往右走
                low=mid+1;
            }
        }
        for(int j=i;j>=high+1;j--){
            a[j]=a[j-1];
        }
        a[high+1]=tmp;
    }
}

/**
 * 冒泡排序
 * @param a  输入数组
 */
void sort3(int *a){
    cout<<"冒泡排序结果"<<endl;
    int length=a[0];
    for(int i=1;i<length;i++){
        for(int j=1;j<length;j++){
            if(a[j]>a[j+1]){
                int tmp=a[j+1];
                a[j+1]=a[j];
                a[j]=tmp;
            }
        }
    }
}

/**
 * 选择排序
 * @param a 输入数组
 */
void sort2(int *a){
    cout<<"选择排序结果"<<endl;
    int length=a[0];
    int max;
    for(int i=length;i>1;i--){
        max=1;
        for(int j=2;j<=i;j++){
            if(a[j]>a[max]){
                max=j;
            }
        }
        int tmp=a[i];
        a[i]=a[max];
        a[max]=tmp;
    }
}

/**
 * 插入排序
 * @param a 输入数组
 * @return 输出数组
 */
void  sort1(int * a){
    cout<<"插入排序结果"<<endl;
    int length=a[0];
    for(int i=2;i<length+1;i++){
        int tmp=a[i];
        int j=i;
        while(j>0&&tmp<a[j-1]){
            a[j]=a[j-1];
            j--;
        }
        if(j!=i){
            a[j]=tmp;
        }
    }
}

/**
 * 建立数组
 * @param a 输入的空指针，
 */
void buildArr(int* &a){
    cout<<"请输入数组大小"<<endl;
    int length;
    cin>>length;
    a=new int[length+1];
    a[0]=length;
    for(int i=1;i<=length;i++){
        cout<<"请输入第"<<i<<"个值"<<endl;
        cin>>a[i];
    }
    cout<<"输入完毕"<<endl;
}

/**
 * 遍历数组
 * @param a 输入的数组
 */
void order(int* a){
    for(int i=1;i<=a[0];i++){
        cout<<"a["<<i<<"]="<<a[i]<<endl;
    }
}



struct Node {
    int data;
    Node *next;
};

void sort(Node * root) {
    Node* p=root->next;
    if(p->next==nullptr){
        return;
    }
    while(p->next!=nullptr){
        p=p->next;
    }
    Node* index=p;
    Node* p1;
    while(index!=root->next){
        p=root->next;
        p1=p;
        while(p1->next!=index){
            if(p1->data>p->data){
                p=p1;
            }
            p1=p1->next;
        }
        if(p1->data>p->data){
            p=p1;
        }
        if(index->data<p->data){
            int tmp=index->data;
            index->data=p->data;
            p->data=tmp;
        }
        index=p1;
    }
}

void linkSort() {
    Node *root = new Node;
    Node *rear = root;
    int a;
    cin >> a;
    while (a >= 0) {
        Node *p = new Node;
        p->data = a;
        rear->next = p;
        rear = p;
        cin >> a;
    }
    cout << "排序前" << endl;
    Node *p = root->next;
    while (p != nullptr) {
        cout << p->data << endl;
        p = p->next;
    }
    cout << "排序后:" << endl;
    sort(root);
    p = root->next;
    while (p != nullptr) {
        cout << p->data << endl;
        p = p->next;
    }
}

void doubleSort(int *a) {
    int low, high, flag, i;
    low = 1;
    high = a[0];
    while (low < high) {
        flag = 0;
        for (i = low; i < high; i++) {
            if (a[i] > a[i + 1]) {
                int tmp = a[i + 1];
                a[i + 1] = a[i];
                a[i] = tmp;
                flag = 1;
            }
        }
        if (!flag)
            break;
        high--;
        for (i = high; i > low; i--) {
            if (a[i] < a[i - 1]) {
                int tmp = a[i];
                a[i] = a[i - 1];
                a[i - 1] = tmp;
            }
        }
        low++;
    }
}