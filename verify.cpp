#include<iostream>
#include<fstream>

using namespace std;
int main(){
    ifstream verify("test_set.out");
    int right,left,temp;
    verify>>std::hex;
    verify>>right;
    bool sorted;
    while(verify>>left){
        if(right>left){
            
            return EXIT_FAILURE;
        }
        right=left;
    }
    
    return EXIT_SUCCESS;
}