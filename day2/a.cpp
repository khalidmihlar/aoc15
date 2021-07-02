#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

long int getArea (string str){
    string temp="";
    int count=0;
    int w,l,h;
    for (int i=0; i<str.length(); i++){
        if (i==str.length()-1){
            temp=temp+str[i];
            h=stoi(temp);
            temp="";
        }
        else if (str[i]!='x'){
            temp=temp+str[i];
        }
        else {
            if (count==0){
                w=stoi(temp);
                temp="";
                count++;
            }
            else if (count==1){
                l=stoi(temp);
                temp="";
                count++;
            }
        }
    }
    cout<<w<<" "<<l<<" "<<h<<endl;
    int ans = (2*w*l)+(2*w*h)+(2*l*h);
    if (w<=h && l<=h){
        ans+=w*l;
    }
    else if (w<=l && h<=l){
        ans+=w*h;
    }
    else if (l<=w && h<=w){
        ans+=h*l;
    }
    return ans;
}

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
    for (string const &f: input){
        x+=getArea(f);
    }
    cout<<x<<endl;
    return 0;
}