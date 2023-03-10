#include<vector>
#include <assert.h>
#include<string>
#include<iostream>
#include<fstream>
int max(const std::vector<int> & v){
    int k=v[0];
    for(int i:v){
        if (i>k) k=i;
    }
    return k;

}

int biggestPower_65536(long long x){
    assert(x>=0);
    int counter=-1;
    for(;x;counter++,x>>=16);
    return counter;  
}
void countsort(std::vector<int>& v,int power){ // we perform a countsort each step on the i-th digit of the number in base 2^16
    std::vector<int> counting_table(65536);
    std::vector<int> sorting_key;
    std::vector<int> copy_v=v;
    
    for(int i:v){
        i>>=power;
        i=i&65535;
        sorting_key.push_back(i);
        counting_table[i]++;
    }
    for(int i=1;i<counting_table.size();i++){
        counting_table[i]+=counting_table[i-1]; 
    }
    for(int i=counting_table.size()-1;i>0;i--){
        counting_table[i]=counting_table[i-1];// represents the index where the value will be written
    }
    counting_table[0]=0;
    for(int i=0;i<sorting_key.size();i++){
        copy_v[counting_table[sorting_key[i]]]=v[i];
        counting_table[sorting_key[i]]++;
    }
    v=std::move(copy_v);
}

void radixsort_65536(std::vector<int>& v)
{
    assert(v.size()>0);//just in case something terrible happens
    int biggest=max(v);
    int inter=biggestPower_65536(biggest)*16;
    for(int power=0;power<=inter;power+=16){
        countsort(v,power);
    }
    
}

int main(int argc, char* argv[]){
    std::string filename(argv[1]);
    std::ifstream input(filename);
    std::vector<int> v;
    std::ifstream input_file(filename);
    input_file>>std::hex;
    int temp;
    while(input_file>>temp)v.push_back(temp);

    radixsort_65536(v);
    std::ofstream output_file("test_set.out");
    output_file<<std::hex;
    for(int i:v)output_file<<i<<' ';
}
