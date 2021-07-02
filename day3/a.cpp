#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <utility>

using namespace std;

int main(){
    ifstream f;
    f.open("input.txt");
    if(!f){
        cerr<<"Bruh"<<endl;
        exit(0);
    }
    string line;
    int x=0;
    int y=0;
    getline(f, line);
    set<pair<int,int>> s;
    pair<int,int> temp;
    temp.first=x;
    temp.second=y;
    s.insert(temp);
    for (char const &c: line){
        if (c=='>'){
            x++;
            temp.first=x;
            s.insert(temp);
        }
        else if (c=='<'){
            x--;
            temp.first=x;
            s.insert(temp);
        }
        else if (c=='^'){
            y++;
            temp.second=y;
            s.insert(temp);
        }
        else if (c=='v'){
            y--;
            temp.second=y;
            s.insert(temp);
        }
    }
    cout<<s.size()<<endl;
}