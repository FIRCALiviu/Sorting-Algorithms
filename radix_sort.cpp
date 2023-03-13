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

int biggestPower0x(long long x){
    assert(x>=0);
    int counter=-1;
    for(;x;counter++,x>>=4);
    return counter;  
}
void countsort(std::vector<int>& v,int power){ // we perform a countsort each step on the i-th digit of the number in base 16
    std::vector<int> counting_table(16);
    std::vector<int> sorting_key;
    std::vector<int> copy_v=v;
    
    for(int i:v){
        i>>=power;
        i=i&15;
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

void radixsort_16(std::vector<int>& v)
{
    assert(v.size()>0);
    int biggest=max(v);
    int inter=biggestPower0x(biggest)*4;
    for(int power=0;power<=inter;power+=4){
        countsort(v,power);
    }
    
}

int main(){
    std::string filename;
    std::cin>>filename;
    std::vector<int> v;
    std::ifstream input_file(filename);
    input_file>>std::hex;
    int temp;
    while(input_file>>temp)v.push_back(temp);

    radixsort_16(v);
    std::ofstream output_file("test_set.out");
    output_file<<std::hex;
    for(int i:v)output_file<<i<<' ';

}