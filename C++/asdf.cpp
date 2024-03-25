#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    string s;
    cin >> s;
    vector<string> v = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
    
    int cnt = 0;
    for(int i=0; i<s.size(); i++){
        for(int j=0; j<v.size(); j++){
            if(s.substr(i, v[j].size()) == v[j]){
                cnt += v[j].size()-1;
                i += v[j].size()-1;
                break;
            }
        }
    }
    cout<<s.size()-cnt<<endl;
}