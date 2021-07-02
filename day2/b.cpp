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
    int ans=0;
    if (w<=h && l<=h){
        ans+=w+w+l+l;
    }
    else if (w<=l && h<=l){
        ans+=w+w+h+h;
    }
    else if (l<=w && h<=w){
        ans+=h+h+l+l;
    }
    ans+=w*l*h;
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