#include<vector>
#include<fstream>
#include<algorithm>
#include<string>
using namespace std;
int main(int argc,char ** argv){
    string filename(argv[1]);
    ifstream input(filename);
    int temp;
    vector<int> v;
    input>>hex;
    while(input>>temp) v.push_back(temp);
    input.close();
    sort(v.begin(),v.end());
    ofstream output("test_set.out");
    output<<hex;
    for( int i:v) output<<i<<' ';

    }