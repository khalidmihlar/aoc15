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
    int z=0;
    int a=0;
    getline(f, line);
    set<pair<int,int>> s;
    pair<int,int> temp;
    pair<int,int> rtemp;
    temp.first=x;
    temp.second=y;
    rtemp.first=z;
    rtemp.second=a;
    s.insert(temp);
    for (int i=0; i<line.length(); i++){
        if (i%2==0){
            if (line[i]=='>'){
                x++;
                temp.first=x;
                s.insert(temp);
            }
            else if (line[i]=='<'){
                x--;
                temp.first=x;
                s.insert(temp);
            }
            else if (line[i]=='^'){
                y++;
                temp.second=y;
                s.insert(temp);
            }
            else if (line[i]=='v'){
                y--;
                temp.second=y;
                s.insert(temp);
            }
        }
        else{
            if (line[i]=='>'){
                z++;
                rtemp.first=z;
                s.insert(rtemp);
            }
            else if (line[i]=='<'){
                z--;
                rtemp.first=z;
                s.insert(rtemp);
            }
            else if (line[i]=='^'){
                a++;
                rtemp.second=a;
                s.insert(rtemp);
            }
            else if (line[i]=='v'){
                a--;
                rtemp.second=a;
                s.insert(rtemp);
            }

        }
    }
    cout<<s.size()<<endl;
}