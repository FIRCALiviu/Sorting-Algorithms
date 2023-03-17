#include<fstream>
#include<vector>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;

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
int main(int argc, char* argv[]){
    string filename(argv[1]);
    std::ifstream input(filename);
    ifstream inputf(filename);
    inputf>>hex;
    vector<int> v;
    int temp;
    while(inputf>>temp)v.push_back(temp);
    shellsort(v);
    ofstream outputf("test_set.out");
    outputf<<hex;
    for(int i:v) outputf<<i<<' ';
    
}