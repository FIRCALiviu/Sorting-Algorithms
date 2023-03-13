#include<fstream>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
// void insertSort_h(vector<int>& v,int h,int begin){// performs an insertion sort on elements that are h apart.
// for(int i=begin;i<v.size();i+=h){
// for(int j=i;j>=h and v[j]<v[j-h];j-=h){
//     swap(v[j],v[j-h]);
// }
// }
// }
// void shellsort(vector<int>& v){ //this algorithm is just slower than the other implementation
    // for(int h=v.size()/2;h>0;h/=2){
    //     for(int i=0;i<h;i++){
    //         insertSort_h(v,h,i);
    //     }
    // }
// }
inline vector<int> gen_gaps(const vector<int>& v){
vector<int> gaps;
int gap=1;
for(int i=1;gap<v.size();i++){
    gaps.push_back(gap);
    gap=(1<<(2*i))+3*(1<<i-1)+1; // consult the wikipedia link if you are confused https://oeis.org/A036562
}
reverse(gaps.begin(),gaps.end());
return gaps;
}
void shellsort(vector<int>&v){  // algorithm provided by https://en.wikipedia.org/wiki/Shellsort
for(int gap:gen_gaps(v)){
    for(int i=gap;i<v.size();i++){
        int j=i,swapper=v[i];
        while(j>=gap and v[j-gap]>swapper){
        v[j]=v[j-gap];
        j-=gap;
        
        }
        v[j]=swapper;
    }
}

}
int main(){
    ifstream inputf("test_set.in");

    vector<int> v;
    int temp;
    while(inputf>>temp)v.push_back(temp);
    shellsort(v);
    ofstream outputf("test_set.out");
    for(int i:v) outputf<<i<<",";
    
}