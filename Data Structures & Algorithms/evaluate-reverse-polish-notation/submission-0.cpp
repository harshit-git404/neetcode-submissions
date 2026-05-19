class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string c:tokens){
            if(!(c=="+"||c=="-"||c=="*"||c=="/")){
                int num=stoi(c);
                st.push(num);
            }
            else{
                int num2=st.top(); st.pop(); //pop returns void
                int num1=st.top(); st.pop();
                if(c=="+") st.push(num1+num2);
                else if(c=="-") st.push(num1-num2);
                else if(c=="*") st.push(num1*num2);
                else st.push(num1/num2);
            }
        }
        return st.top();
    }
};