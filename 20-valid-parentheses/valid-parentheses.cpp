class Solution {
public:
    stack<char> s;
    bool isValid(string str) {
       
        for(int i=0;i<str.length();i++){
            char ch = str[i];
            if(ch=='('||ch=='['||ch=='{'){
                s.push(ch);
            }
            else{
                if(!s.empty()){
                    char topE = s.top();
                    if(ch==')' && topE=='('){
                        s.pop();
                    }
                    else if(ch==']' && topE=='['){
                        s.pop();
                    }
                    else if(ch=='}' && topE=='{') s.pop();
                    else return false;
                }
                else return false;
            }
            
        }
        if(s.empty()) return true;
        else return false;
    }
};