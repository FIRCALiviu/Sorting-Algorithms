#include<fstream>
#include<vector>
int max(const std::vector<int> & v){
    int m=v[0];
    for(int i:v){
        if (i>m) m=i;
    }
    return m;
}
void countsort(std::vector<int> & v){
int biggest_num=max(v);
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

}

int main(){
std::ifstream input("test_set.in");
int temp;
std::vector<int> v;
while(input>>temp) v.push_back(temp);
input.close();
countsort(v);
std::ofstream output("test_set.out");

for(int i:v)output<<i<<' '; 
output.close();
}