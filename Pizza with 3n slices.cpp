#include<iostream>
using namespace std;
class Solution {
public:
    int solve(int start,int end,vector<int> &slices,int n){
        if(n == 0 || start > end) return 0;

        int incl = slices[start] + solve(start+2,end,slices,n-1);
        int excl = 0 + solve(start+1,end,slices,n);

        return max(incl,excl);
    }
    int maxSizeSlices(vector<int>& slices) {
        int k = slices.size();
        int case1 = solve(0,k-2,slices,k/3);
        int case2 = solve(1,k-1,slices,k/3);
        return max(case1,case2);
    }
};

