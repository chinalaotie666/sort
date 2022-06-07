//
// Created by fire on 2022/6/2.
//

#ifndef SORT_MERGESORT_H
#define SORT_MERGESORT_H

#endif //SORT_MERGESORT_H
/**
 *
 * @param a 输入数组
 * @param tmp 临时数组
 * @param leftPos 左起点
 * @param rightPos 右起点
 * @param rightEnd  右终点
 */
void merge(int* a,int* tmp,int leftPos,int rightPos,int rightEnd){
    int leftEnd=rightPos-1;
    int tmpPos=leftPos;
    int numElements=rightEnd-leftPos+1;

    //将左右两边分别装进临时数组里面
    while(leftPos<=leftEnd&&rightPos<=rightEnd){
        //从小到大依次进入临时数组
        if(a[leftPos]>=a[rightPos]){
            //左边的大于右边的
            tmp[tmpPos++]=a[rightPos++];
        }
        else{
            //右边大于左边的
            tmp[tmpPos++]=a[leftPos++];
        }
    }

    //清理剩余的数
    while(leftPos<=leftEnd){
        tmp[tmpPos++]=a[leftPos++];
    }
    while(rightPos<=rightEnd){
        tmp[tmpPos++]=a[rightPos++];
    }

    //复制到数组a中去
    for(int i=1;i<tmpPos;i++){
        a[i]=tmp[i];
    }
}

/**
 * 递归调用的归并排序函数
 * @param a 输入数组
 * @param tmp 临时数组
 * @param left 左边界
 * @param right 右边界
 */
void mergeSort(int* a,int* tmp,int left,int right){
    if(left<right){
        int center=(left+right)/2;
        mergeSort(a,tmp,left,center);
        mergeSort(a,tmp,center+1,right);
        merge(a,tmp,left,center+1,right);
    }
}

/**
 * 归并排序
 * @param a 输入数组
 */
void mergeSort(int *a){
    //a[0]表示数组的长度
    int* tmp=new int[a[0]+1];
    tmp[0]=a[0];
    mergeSort(a,tmp,1,a[0]);
}

