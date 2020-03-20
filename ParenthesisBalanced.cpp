#include<bits/stdc++.h>  //includes every standard library, stack declared in this library
using namespace std; 
  

bool is_Balanced(string syntex) 
{ 
    stack<char> s;  //s is a stack 
    char x; 
    //string opening = "({[";
	//string closing = ")}]";
  
    int len = syntex.size();
    for (int i = 0; i < len; i++) 
    { 
        
    	if (syntex[i]!='[' && syntex[i]!='(' && syntex[i]!='{' && syntex[i]!=']' && syntex[i]!=')' && syntex[i]!='}' )
    	{
    		continue;
    	}

        if (syntex[i]=='[' || syntex[i]=='(' || syntex[i]=='{')
        {  
            s.push(syntex[i]); 
            continue; 
        } 
  
        
        
        if(s.empty())
        {
        	//cout<<"e"<<s.empty()<<endl;
        	return false;
        }
  		

        switch (syntex[i]) 
        { 
        case ']': 
  
            x = s.top(); //(
            if (x=='(' || x=='}') 
                return false;

            s.pop(); 
            break; 
  
        case ')': 
  
            x = s.top();  
            if (x=='{' || x=='[') 
                return false;

            s.pop(); 
            break; 
  
        case '}': 
  
            x = s.top(); 
            if (x =='(' || x == '[') 
                return false; 
            
            s.pop();
            break; 
        } 
    } 
  
    //cout<<(s.empty())<<endl;
    return(s.empty());
    //return true;


} 
  

int main()
{	
	string syntex;
	cout<<"Enter an expression to check:"<<endl;
	cin>>syntex;
	//string syntex = "4{2(4+5)}[]"; 
	if(is_Balanced(syntex))
	{
	 cout<<"\nValid expression - Balanced"<<endl;
    }

    else
    {
       cout<<"\nInvalid expression - Not a Balanced"<<endl;
    }
 
     return 0; 

}