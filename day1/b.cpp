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
    getline(f, x);
    for (int i=0; i<x.length(); i++){
        if (count==-1){
            cout<<i<<endl;
            break;
        }
        
        if (x[i]=='('){
            count++;
        }
        else if (x[i]==')'){
            count--;
        }
    }
    cout<<count<<endl;
    return 0;
}