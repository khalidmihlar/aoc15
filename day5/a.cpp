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
    int vowel=0;
    bool a=false, b=false, c=true;
    for (int i=0; i<input.size(); i++){
        for (int j=0; j<input[i].length(); j++){
            if (input[i][j]=='a' || input[i][j]=='e' || input[i][j]=='i' || input[i][j]=='o' || input[i][j]=='u'){
                vowel++;
                if (vowel==3){
                    a=true;
                }
            }
            if (input[i][j] == input[i][j+1]){
                b=true;
            }
            if (a && b){
                j=input[i].length();
            }
        }
        size_t found = input[i].find("ab"), found2=input[i].find("cd"), found3=input[i].find("pq"), found4=input[i].find("xy");
        if (found==found2 && found==found3 && found==found4){
            c=true;
        }
        else{
            c=false;
        }
        if (a && b && c){
            nice++;
        }
        a=false;
        b=false;
        vowel=0;
    }
    cout<<nice<<endl;
}