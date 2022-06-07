//
// Created by fire on 2022/6/2.
//

#ifndef SORT_SHELLSORT_H
#define SORT_SHELLSORT_H

#endif //SORT_SHELLSORT_H
/**
 * 希尔排序
 * @param a 输入数组
 */
void sort5(int *a){
    for(int d=a[0]/2;d>0;d/=2){
        for(int i=d+1;i<=a[0];i++){
            int tmp=a[i];
            int j=i-d;
            while(j>0&&tmp<a[j]){
                a[j+d]=a[j];
                j-=d;
            }
            a[j+d]=tmp;
        }
    }
}