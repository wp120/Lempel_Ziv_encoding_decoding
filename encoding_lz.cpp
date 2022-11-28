// Lempel-Ziv_encoding 

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

string int_to_bin(int n){
    
    int p=int(log2(n))+1;
    string ans2="";
    
    while(p!=0){
        if(n>=pow(2,p-1)){
            n-=(pow(2,p-1));
            ans2=ans2+"1";
        }
        else{
            ans2=ans2+"0";
        }
        p--;
    }
    
    while(ans2.length()<3){
        ans2="0"+ans2;
    }
    
    return ans2;
}

int main() {
	
	string s;
	cin>>s;
	
	map <string,int> mp;
	mp["0"]=1;
	mp["1"]=2;
	
	vector<string> v;
	v.push_back("0");
	v.push_back("1");
	
	string temp="";
	int pos=2;
	
	
	for(int i=0;i<s.length();i++){
	    
	    temp=temp+s[i];
	    if(mp[temp]==0){
	        pos++;
	        mp[temp]=pos;
	        v.push_back(temp);
	        temp="";
	    }
	}
	
	int n=v.size();
	
	for(int i=2;i<n;i++){
	    
	    string t5="";
	    int sn=v[i].size();
	    t5=(v[i].substr(0,sn-1));
	   
	    cout<<int_to_bin(mp[t5])<<v[i][v[i].length()-1];
	    
	}
	cout<<endl;
	
	return 0;
}
