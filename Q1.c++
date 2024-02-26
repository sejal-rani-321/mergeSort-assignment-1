#include<iostream>
#include<vector>
using namespace std;

void merge( vector<int>& a, vector<int>& b, vector<int> & res){
    int i = 0, j = 0, k = 0;

    while (i < a.size() && j < b.size()){
        if (b[j] > a[i])  {res[k++]  =  b[j++];}        // small change
        else   {res[k++] = a[i++];}   // small change
    }

    if(j==b.size()) {while (i<a.size()){ res[k++] = a[i++];}}
    if(i==a.size()) {while (j<b.size()){ res[k++] = b[j++];}}    
}

void mergeSort( vector<int>& v){
    int n = v.size();
    if(n==1) {return; } 
    int n1 = n/2, n2 = n - n/2;
    vector<int> a(n1), b(n2);
    // Copy pasting element
    for (int i = 0; i < n1; i++){
        a[i] = v[i];
    }
    for (int i = 0; i < n2; i++){
        b[i] = v[i+n1];
    }

    //magia aka recursion
    mergeSort(a);
    mergeSort(b);
   
    //merge
    merge(a,b,v);
    // delelting small sorted subarrays
    a.clear();
    b.clear();
}

int main(){
    int arr[] = {5,1,3,0,4,9,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> v(arr,arr+n);

    for (int i = 0; i < v.size(); i++){
        cout << v[i]<<" ";
    }cout << endl;

     mergeSort(v); 
    
    for (int i = 0; i < v.size(); i++){
        cout << v[i]<<" ";
    }cout << endl;
    // merge(a,b,res);
}
