#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<char> attendance(n);
    for(int i=0;i<n;i++){
        cin>>attendance[i];
    }
    unordered_map<int,int> seen;
    int sum=0;
    int maxLen=0;
    seen[0]=-1;
    for(int i=0;i<n;i++){
        if(attendance[i]=='P'){
            sum+=1;
        }else{
            sum-=1;
        }
        if(seen.find(sum)!=seen.end()){
            int len=i-seen[sum];
            maxLen=max(maxLen,len);
        }else{
            seen[sum]=i;
        }
    }
    cout<<maxLen<<endl;
    return 0; 
}
