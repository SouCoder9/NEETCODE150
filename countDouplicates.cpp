#include<iostream>
#include<unordered_set>
#include<vector> 

using namespace std;

bool countDouplicate(vector<int>&nums){         
    unordered_set<int>freq;

    for(int num : nums){
        if(freq.contains(num)){
            return true;
        }
        freq.insert(num);
    }
    return false;
}

int main(){
    int n;
    cin >> n;
    int i = 0;
    while(n--){
        vector<int>nums;
        cin>> nums[i];
        i++;
        countDouplicate(nums);
    }
    return 0;
}