#include<iostream>
#include<unordered_set>
#include<vector>
#include<string>

using namespace std;

bool isAnagram(string s, string t){
    if(s.size() != t.size()) return false;
    int count[26] = {0};
    for (int i = 0; i < s.size(); i++)
    {
        count[s[i] - 'a']++;
        count[t[i] - 'a']--;
    }
    for(int cnt : count){
        if(cnt != 0){
            return false;
        }
   }
   return true;
}

int main(){
    // Test cases
    string s1 = "anagram", t1 = "nagaram";
    string s2 = "rat", t2 = "car";
    string s3 = "listen", t3 = "silent";
    string s4 = "hello", t4 = "world";
    
    cout << "Testing anagram checker:\n";
    cout << "\"" << s1 << "\" and \"" << t1 << "\": " << (isAnagram(s1, t1) ? "Yes" : "No") << endl;
    cout << "\"" << s2 << "\" and \"" << t2 << "\": " << (isAnagram(s2, t2) ? "Yes" : "No") << endl;
    cout << "\"" << s3 << "\" and \"" << t3 << "\": " << (isAnagram(s3, t3) ? "Yes" : "No") << endl;
    cout << "\"" << s4 << "\" and \"" << t4 << "\": " << (isAnagram(s4, t4) ? "Yes" : "No") << endl;

    return 0;
}