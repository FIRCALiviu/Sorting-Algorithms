#include<fstream>
#include<vector>
#include<string>
#include<iostream>
int max(const std::vector<int> & v){
    int m=v[0];
    for(int i:v){
        if (i>m) m=i;
    }
    return m;
}
int countsort(std::vector<int> & v){
int biggest_num=max(v);
if(biggest_num>500000000){
    return -1;
}
std::vector<int> count_table(biggest_num+1);
for(int i:v) count_table[i]++;
for(int i=1;i<count_table.size();i++){
count_table[i]+=count_table[i-1];
}
for(int i=biggest_num;i>-1;i--){
    count_table[i]=count_table[i-1];// the index where each individual value should be at
}
count_table[0]=0;
std::vector<int> copy=v;
for(int i:copy){
    v[count_table[i]]=i;
    count_table[i]++;
}
return 0;
}

int main(int argc, char* argv[]){
    std::string filename(argv[1]);
    std::ifstream input(filename);
    input>>std::hex;
    int temp;
    std::vector<int> v;
    while(input>>temp) v.push_back(temp);
    input.close();
    int failure=countsort(v);
    if(failure==-1){
        return EXIT_FAILURE;
    }
    std::ofstream output("test_set.out");
    output<<std::hex;
    for(int i:v) output<<i<<' '; 
    output.close();
    return EXIT_SUCCESS;
}