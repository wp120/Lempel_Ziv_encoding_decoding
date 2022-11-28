// lz decoding

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int binary_to_int(string s){
    
    int ans1=0;
    
    for(int j=s.length()-1;j>=0;j--){
        if(s[j]=='1'){
            ans1+=pow(2,(s.length()-j-1));
        }
    }
    
    return ans1;
}

int main() {
	
	string s;
	cin>>s;
	
	vector<string> posbit;
	posbit.push_back("0");
	posbit.push_back("1");
	
	for(int i=0;i<=s.length()-4;i+=4){
	    string temp=s.substr(i,4);
	    
	    int pos1=binary_to_int(temp.substr(0,3));
	    
	    posbit.push_back(to_string(pos1)+temp[3]);
	}
	
	int n=posbit.size();
	
	for(int i=2;i<n;i++){
	    
	    int t1=posbit[i][0]-'0';
	    t1--;
	    
	    posbit[i]=posbit[t1]+posbit[i][1];
	    cout<<posbit[i];
	}
	cout<<endl;
	
	
	return 0;
}
