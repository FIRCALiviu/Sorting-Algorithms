#include<iostream>
#include<fstream>

using namespace std;
int main(){
    ifstream verify("result.out");
    int right,left,temp;
    verify>>std::hex;
    verify>>right;
    bool sorted;
    while(verify>>left){
        if(right>left){
            
            cout<<"error\n";
            return 0;
        }
        right=left;
    }
    
    cout<<"sorted\n";
}