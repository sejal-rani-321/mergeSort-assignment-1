#include<iostream>
#include<vector>
using namespace std;

int pairCount = 0;
void reverse_pair(vector<int>& nums,int low,int mid,int high){
        int total=0;
        int i=low;
        int j=mid+1;
        while(i<=mid && j<=high){ 
          if ((long long)nums[i]>(long long)2*nums[j])
            {
             total+=mid -i +1;
                j++;
            }
            else  i++;
        }        
        vector<int> temp;
        i=low, j=mid+1;
        while(i<=mid && j<=high){
            if(nums[i]<nums[j]){
                temp.push_back(nums[i++]);
            }else{
                temp.push_back(nums[j++]);
            }
        }
        // for(int it=low;it<=high;it++){
        //     nums[it]=temp[it-low];
        // }
        pairCount+=total;
    }

final(vector<int>& nums,int s,int e){
    // int count = 0;
    if(s<=e){
    int mid = s+(e-s)/2;
    final(nums,s,mid);
    final(nums,mid+1,e);
    reverse_pair(nums,s,mid,e);
    }
 return pairCount;
}    

int main(){
    int arr[] = {1,3,2,3,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> nums(arr, arr+n);
    for (int i = 0; i < n; i++){
        cout<< nums[i]<<" ";
    }cout << endl;
    
    cout<< final(nums,0,n);
    
}