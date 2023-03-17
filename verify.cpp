#include<iostream>
#include<fstream>

using namespace std;
int main(){
    ifstream verify("test_set.out");
    int right,left,temp;
    verify>>std::hex;
    verify>>right;
    bool sorted;
    while(verify>>left){ // we assume the algorithm preserved all the numbers of the vector and has outputed all of it in the file
                         // the algoritms were manually checked for such behaviour   
        if(right>left){
            
            return EXIT_FAILURE;
        }
        right=left;
    }
    
    return EXIT_SUCCESS;
}