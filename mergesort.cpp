#include<fstream>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
void merge(vector<int> &v,int right, int  separator, int left){ // for merging arr[right ... separator] and arr[separator+1 ... left]
vector<int> v1(v.begin()+right,v.begin()+separator+1),v2(v.begin()+separator+1,v.begin()+left+1);
int i=0,j=0,index=right;
while(i<v1.size() and j<v2.size()){
if(v2[j]>=v1[i]){
    v[index]=v1[i];
    i++;
    index++;
}
else{
    v[index]=v2[j];
    j++;
    index++;
}
}
while(i<v1.size()){
    v[index]=v1[i];
    i++;
    index++;
}
while(j<v2.size()){
    v[index]=v2[j];
    j++;
    index++;
}
return ;
}


void mergesort(vector<int>& v,int left, int right){
    if (right>left){
        int middle=(right+left)/2;
        mergesort(v,left,middle);
        mergesort(v,middle+1,right);
        merge(v,left,middle, right);
        return;
    }
}

int main(int argc, char* argv[]){
    string filename(argv[1]);
   
    ifstream input(filename);
    input>>hex;
    vector<int> v;
    int temp;
    while(input>>temp) v.push_back(temp);
    input.close();
    mergesort(v,0,v.size()-1);
    ofstream output("test_set.out");
    output<<hex;
    for(int i:v) output<<i<<' ';
    output.close();
}