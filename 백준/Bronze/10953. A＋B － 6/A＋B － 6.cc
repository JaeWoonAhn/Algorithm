#include <iostream>
#include <string>
#include <vector>
#include <sstream>


using namespace std;
vector<string> split(string str, char Delimiter){
    istringstream iss(str);
    string buffer;
    
    vector<string> result;
    
    while(getline(iss, buffer, Delimiter)){
        result.push_back(buffer);
    }
    return result;
}
int main(){
    
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        
        vector<string> input = split(str,',');
        int a,b;
        a = stoi(input[0]);
        b = stoi(input[1]);
        
        cout << a+b << endl;
    }
    return 0;
}