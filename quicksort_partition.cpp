#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<string>
using namespace std;

int partition(vector<int> &v, int left, int right){
int i=left-1,pivot=v[right];

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
    string filename;
    cin>>filename;
    std::ifstream input(filename);
    int temp;
    input>>hex;
    std::vector<int> v;
    while(input>>temp) v.push_back(temp);
    quicksort(v,0,v.size()-1);
    ofstream output("test_set.out");
    output<<hex;
    for (int x:v){
        output<<x<<' ';
    }
    
   
    
}