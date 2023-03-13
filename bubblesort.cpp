#include<fstream>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
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
    std::string filename;
    std::cin>>filename;
    std::ifstream input(filename);
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

