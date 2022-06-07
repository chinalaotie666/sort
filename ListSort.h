//
// Created by fire on 2022/6/2.
//

#ifndef SORT_LISTSORT_H
#define SORT_LISTSORT_H

#endif //SORT_LISTSORT_H
/**
 * 桶排序
 */
void listSort(vector<int> & a){
    vector<vector<int>> v;
    for(int i=0;i<10;i++){
        v.push_back(*new vector<int>);
    }
    //个位排序
    for(int k=0;k<3;k++){
        for(int i=0;i<a.size();i++){
            int z=a[i];
            int x;
            if(k==0){
                x=z%10;
            }
            else if(k==1){
                z=z/10;
                x=z%10;
            }
            else{
                z=z/100;
                x=z;
            }
            v[x].push_back(a[i]);
        }
        //第一次收集
        a.clear();
        for(int i=0;i<10;i++) {
            for (int j = 0; j < v[i].size(); j++) {
                a.push_back(v[i][j]);
            }
            v[i].clear();
        }
    }
    for(int &i:a){
        cout<<i<<endl;
    }


}
