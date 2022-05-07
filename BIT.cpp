#include<bits/stdc++.h>
using namespace std;
void update(vector<int>& BIT, int index, int val){
    index++;
    while(index < BIT.size()){
        BIT[index] += val;
        index += index & (-index);
    }

}

int getSum(vector<int>& BIT, int index){
    int sum = 0;
    index++;
    while(index > 0){
        sum += BIT[index];
        index -= index & (-index);
    }
    return sum;
}

int main()
{
    vector<int>nums={1,2,3,4,5};
    int n = nums.size();
    vector<int>BIT(n+1, 0);
    for(int i = 0; i < nums.size();i++)
        update(BIT, i, nums[i]);
    
    cout << getSum(BIT, 3) << endl;
    return 0;
}
