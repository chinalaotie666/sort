#include <iostream>
#include <vector>
#include "heapSort.h"
using namespace std;

int main() {
    vector<int> a;
    srand(unsigned(time(nullptr)));
    for(int i=0;i<10;i++){
        int x=rand()%100;
        a.push_back(x);
    }
    buildAll(a);
    cout<<"第一次建堆"<<endl;
    for(int &i:a){
        cout<<i<<endl;
    }
    int x;
    cout<<"请输入要插入的值"<<endl;
    cin>>x;
    insert(a,x);
    cout<<"第二次建堆"<<endl;
    for(int &i:a){
        cout<<i<<endl;
    }
}
