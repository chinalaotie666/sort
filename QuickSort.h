//
// Created by fire on 2022/6/2.
//

#ifndef SORT_QUICKSORT_H
#define SORT_QUICKSORT_H

#endif //SORT_QUICKSORT_H


void swap(int &a,int &b){
    int tmp=b;
    b=a;
    a=tmp;
}


/**
 * 快速排序
 * @param a
 * @param left
 * @param right
 */
void quickSort(int* a,int left,int right){
    if(left<right){
        int i=left,j=right;
        while(i<j){
            while(i<j&&a[i]<a[j]){
                j--;
            }
            if(i<j){
                swap(a[i],a[j]);
                i++;
            }
            while(i<j&&a[i]<a[j]){
                i++;
            }
            if(i<j){
                swap(a[i],a[j]);
                j--;
            }
        }
        quickSort(a,left,i-1);
        quickSort(a,i+1,right);
    }
}