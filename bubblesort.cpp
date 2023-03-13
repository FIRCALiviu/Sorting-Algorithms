#include<fstream>
#include<vector>
#include<algorithm>
void bubblesort(std::vector<int>& v){
  for(int i=0;i<v.size();i++){
    for(int j=0;j<v.size()-1;j++){
      if (v[j]>v[j+1]){
        std::swap(v[j],v[j+1]);
      }
    }
  }
}
int main(){
    std::ifstream input("test_set.in");
    int temp;
   
    std::vector<int> v;
    while(input>>temp) v.push_back(temp);
    bubblesort(v);
    input.close();
    std::ofstream of("bubble.out");
    for (int i:v){
        of<<i<<' ';
    }
}

