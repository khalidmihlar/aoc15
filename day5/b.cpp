#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main(){
    long long int x=0;
    ifstream f;
    f.open("input.txt");
    if(!f){
        cerr<<"Bruh"<<endl;
        exit(0);
    }
    vector <string> input;
    string line;
    while (getline(f, line)){
        input.push_back(line);
    }
    int nice=0;
    bool a=false, b=false;
    size_t found;
    for (int i=0; i<input.size(); i++){
        for (int j=0; j<input[i].length()-2; j++){
            found = input[i].substr(j+2, input[i].size()-j-2).find(input[i].substr(j,2));
            if (found!=string::npos){
                a=true;
            }
            if (input[i][j] == input[i][j+2]){
                b=true;
            }
            if (a && b){
                nice++;
                j=input[i].length();
            }
        }
        a=false;
        b=false;
    }
    cout<<nice<<endl;
}