
//prefix and postfix expression evaluation
//Shinde Dipashri
#include<iostream>
#include<stack>
using namespace std;
int postfixevaluation(string s){
	stack<int>st;
	int r;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0' && s[i]<='9'){
			st.push(s[i]-'0');//char to integer
		}
		else{
		    int op2=st.top();
			st.pop();
			int op1=st.top();
			st.pop();
			if(s[i]=='+'){
			   	r=op1+op2;
			}
			else if(s[i]=='-'){
				r=op1-op2;	
			}
			else if(s[i]=='*'){
				r=op1*op2;
			}
			else if(s[i]=='/'){
				r=op1/op2;
			}
			else{
				r=op1^op2;
			}
			st.push(r);	
		}
	}
	return r;
	st.pop();
	
}
int prefixevaluation(string s){
	stack<int>st;
	int re;
	for(int i=s.length()-1;i>=0;i--){
	/*
	    #include<algorithm>            we travese the string reversely(Right to left) or first reverse it & then traverse it left to right 
	    reverse(s.begin(),s.end()) 
	    for(int i=0;i<s.length();i++)
	*/            
		if(s[i]>='0' && s[i]<='9'){
			st.push(s[i]-'0');//char to integer
		}
		else{
		    int op1=st.top();
			st.pop();
			int op2=st.top();
			st.pop();
			if(s[i]=='+'){
			   	re=op1+op2;
			}
			else if(s[i]=='-'){
				re=op1-op2;	
			}
			else if(s[i]=='*'){
				re=op1*op2;
			}
			else if(s[i]=='/'){
				re=op1/op2;
			}
			else{
				re=op1^op2;
			}
			st.push(re);	
		}
	}
	return re;
	st.pop();
}
int main(){
	
	string str;
	cout<<"enter postfix expression"<<endl;
	cin>>str;
	cout<<postfixevaluation(str)<<endl;
	cout<<"enter prefix expression"<<endl;
	cin>>str;
	cout<<prefixevaluation(str)<<endl;
}

