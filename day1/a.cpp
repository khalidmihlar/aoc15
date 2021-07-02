#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    ifstream f;
    f.open("input.txt");
    if(!f){
        cerr<<"Bruh"<<endl;
        exit(0);
    }
    string x;
    int count=0;
    cout<<count<<endl;
    getline(f, x);
    for (char const &c: x){
        if (c=='('){
            count++;
        }
        else if (c==')'){
            count--;
        }
    }
    cout<<count<<endl;
    return 0;
}