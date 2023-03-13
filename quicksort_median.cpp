#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;

int median3(vector<int> &v,int left, int right){ // algorithm provided by https://en.wikipedia.org/wiki/Quicksort#Choice_of_pivot
    
    int middle = (left+right)/2;
    if (v[middle]<v[left]) swap(v[middle],v[left]);
    if (v[right]<v[left]) swap(v[left],v[right]);
    if (v[middle]<v[right]) swap(v[middle],v[right]);
    return v[right];

}


int partition(vector<int> &v, int left, int right){
int i=left-1,pivot=median3(v,left,right);

for ( int j=left;j<right;j++){ 
if (v[j]<pivot){ 
i++;
swap(v[j],v[i]);
}
}
i++;
swap(v[i],v[right]);
return i;
}


void quicksort(vector<int> &v,int left, int right){
    if (left<right){
    int p=partition(v,left,right);
    quicksort(v,left,p-1); 
    quicksort(v,p+1,right);
    }

}
int main(){
    std::ifstream input("test_set.in");
    int temp;
    bool sorted=false;
    std::vector<int> v;
    while(input>>temp) v.push_back(temp);
    quicksort(v,0,v.size()-1);
    ofstream output("test_set.out");
    for (int x:v){
        output<<x<<' ';
    }
    cout<<"finished";
   
    
}