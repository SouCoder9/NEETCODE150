#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

string generate(string s){
    int arr[26];
    for(int i : s){
        arr[i - 'a'];
    }
    string new_word = "";
    for(int i = 0; i < 26; i++){
        int freq = arr[i];
        if(freq > 0){
            new_word += string(freq,i + 'a');
        }
    }
    return new_word;
}

vector<vector<string>> groupAnagram(vector<string>& strs){
    vector<vector<string>>result;
    int n = strs.size();
    unordered_map<string,vector<string>> mpp;
    for(int i = 0; i < n; i++){
        string words = strs[i];
        string new_word = generate(words);
        mpp[new_word].push_back(words); 
    }

    for(auto it : mpp){
        result.push_back(it.second);
    }

}
int main(){
   
}