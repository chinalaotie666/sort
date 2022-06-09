#include <iostream>
#include <vector>
#include "MergeSort.h"
using namespace std;

int main() {
    vector<int>a;
    int x;
    srand(unsigned(time(nullptr)));
    for(int i=0;i<10;i++){
        a.push_back(rand()%50);
    }
    for(int &i:a){
        cout<<i<<endl;
    }
    cout<<endl;
    mergeSort(a);
    for(int &i:a){
        cout<<i<<endl;
    }
}
