#include<iostream>
#include<vector>
using namespace std;


median(vector<int>& v){
    int n = v.size();
    int s = 0;
    int e = n-1;
    int mid = s +(e-s)/2;
    while (s<=e){
        // int case even
        if(n%2==0){return v[mid];}
        else{return (v[mid]+v[mid+1])/2.0;}
    }
    


}
void merge(vector<int> & num1,vector<int>& num2, vector<int>& v ){
    int i = 0,j = 0,k = 0;
     while ( i< num1.size() && j<num2.size()){
        if(num1[i] < num2[j]) {v[k++] = num1[i++];}
        else{v[k++] = num2[j++];}
     }
    if(j==num2.size()) {while (i<num1.size()){ v[k++] = num1[i++];}}
    if(i==num1.size()) {while (j<num2.size()){ v[k++] = num2[j++];}}
}


int main(){
    int a[] = {1,3};
    int n = sizeof(a)/sizeof(a[0]);
    int b[] = {7,1};
    int m = sizeof(b)/sizeof(b[0]);
    vector<int> num1(a, a+n);
    vector<int> num2(b, b+m);
    vector<int> v(n+m);

    merge(num1,num2,v);
    for (int i = 0; i < v.size(); i++){
        cout<< v[i] << " ";
    }cout << endl;
    float ans =  median(v);
    cout << ans;
}