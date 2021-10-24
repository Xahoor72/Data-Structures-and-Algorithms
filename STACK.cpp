//IMPLEMENT STACK USING ARRAY
void MyStack :: push(int x)
{
    arr[++top]=x;
    // Your Code
}
int MyStack :: pop()
{
    if(top==-1){
        return -1;
    }
    int x=arr[top];
    top=top-1;
    return x;
    // Your Code       
}
//IMPLEMENT STACK USING LINKED LIST
void MyStack ::push(int x) 
{
    StackNode*new_node=new StackNode(x);
    new_node->next=top;
    top=new_node;
}
int MyStack ::pop() 
{
   if(top==NULL){
       return -1;
   } 
   int result=top->data;
   top=top->next;
   return result;
    // Your Code
}
//Queue Reversal 
queue<int> rev(queue<int> q)
{
    stack<int>s;
    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }
     while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    return q;
}
/*
Evaluation of Postfix Expression 
Easy Accuracy: 53.28% Submissions: 24951 Points: 2
Given string S representing a postfix expression, the task is to evaluate the expression and find the final value. 
Operators will only include the basic arithmetic operators like *, /, + and -.
Example 1:
Input: S = "231*+9-"
Output: -4
Explanation:
After solving the given expression, 
we have -4 as result.
*/
int evaluatePostfix(string S)
    {
        stack<int>s;
        for(int i=0;i<S.size();i++){
            if(S[i]>='0' && S[i]<='9' ){
                s.push(S[i]-48);
            }
            else{
                int res=0;
                int x=s.top();
                s.pop();
                int y=s.top();
                s.pop();
                if(S[i]=='*'){
                    res=x*y;
                }
                else if(S[i]=='+'){
                    res=x+y;
                }
              else if(S[i]=='/'){
                    res=y/x;
                }  else if(S[i]=='-'){
                    res=y-x;
                }
            s.push(res);
            }
        }
        return s.top();    
    }
//sort a stack
void insert(stack<int>&s,int temp){
    if(s.empty()|| temp>=s.top()){
         s.push(temp);
    }
    else{
        int ptr=s.top();
        s.pop();
        insert(s,temp);
        s.push(ptr);
    }
    
}
void SortedStack :: sort()
{
    if(s.empty()){
        return;
    }
    else{
        int temp=s.top();
        s.pop();
        sort();
        insert(s,temp);
    }
 
}
//Delete middle element of a stack 
 void solve(stack<int>&s,int mid){
        if(mid==1){
            s.pop();
            return;
        }
           int temp=s.top();
       s.pop();
       solve(s,mid-1);
       s.push(temp);
    }
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
       int mid=sizeOfStack/2+1;
       solve(s,mid);      
    }
//Implement two stacks in an array 
    This method efficiently utilizes the available space. It doesn't cause an overflow if there is space available in arr[].
    The idea is to start two stacks from two extreme corners of arr[]. stack1 starts from the leftmost element, the first element in stack1 is pushed at index 0.
    The stack2 starts from the rightmost corner, the first element in stack2 is pushed at index (n-1). Both stacks grow (or shrink) in opposite direction. 
    To check for overflow, all we need to check is for space between top elements of both stacks. 
    This check is highlighted in the below code. 
     void twoStacks :: push1(int x)
{
    ++top1;
    
    arr[top1]=x;

}
   
//Function to push an integer into the stack2.
void twoStacks ::push2(int x)
{
 --top2;
    
    arr[top2]=x;
}
   
//Function to remove an element from top of the stack1.
int twoStacks ::pop1()
{
    if(top1==-1){
        return -1;
    }
    int res=arr[top1];
    top1=top1-1;
return res;
}

//Function to remove an element from top of the stack2.
int twoStacks :: pop2()
{
    if(top2==size){
        return -1;
    }
    int res=arr[top2];
    top2=top2+1;
    return res;
}   
/*
Parenthesis Checker 
Easy Accuracy: 49.12% Submissions: 96928 Points: 2
Given an expression string x. Examine whether the pairs and the orders of “{“,”}”,”(“,”)”,”[“,”]” are correct in exp.
For example, the function should return 'true' for exp = “[()]{}{[()()]()}” and 'false' for exp = “[(])”.

Example 1:

Input:
{([])}
Output: 
true
Explanation: 
{ ( [ ] ) }. Same colored brackets can form 
balaced pairs, with 0 number of 
unbalanced bracket.

*/
bool ispar(string x)
    {
        stack<char>s;
        for(int i=0;i<x.size();i++){
        char c=x[i];
        
        if(c=='{' || c=='(' || c=='['){
            s.push(c);
        }
        else if(c=='}'){
            if(!s.empty() && s.top()=='{'){
                s.pop();
            }
            else{
                return false;
            }
        }
         else if(c==')'){
            if(!s.empty() && s.top()=='('){
                s.pop();
            }
            else{
                return false;
            }
        } else if(c==']'){
            if(!s.empty() && s.top()=='['){
                s.pop();
            }
            else{
                return false;
            }
        }
    }
   return  s.size()==0?true:false;
        
    }
//Queue using two Stacks 
void StackQueue :: push(int x)
{
    s1.push(x);
    // Your Code
}

//Function to pop an element from queue by using 2 stacks.
int StackQueue :: pop()
{
    if(s1.empty()){
        return -1;
    }
    while(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
    }
    int x= s2.top();
      s2.pop();
    while(!s2.empty()) {s1.push(s2.top()); s2.pop();}
    return x;
        
}
//Stack using two queues 
void QueueStack :: push(int x)
{
    q1.push(x);
        // Your Code
}

//Function to pop an element from stack using two queues. 
int QueueStack :: pop()
{
    if(q1.empty()){
        return -1;
    }
    while(q1.size()!=1){
        q2.push(q1.front());
        q1.pop();
    }
    int x=q1.front();
    q1.pop();
    while(!q2.empty()){
        q1.push(q2.front());
        q2.pop();
    }
    return x;             
}

//INFIX TO POSTFIX
    int priority(char c)
    {
        if(c=='^') return 3;
        if(c=='*' or c=='/') return 2;
        if(c=='+' or c=='-') return 1;
        if(c=='(') return 0;
    }
    //Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s)
    {
        stack<char> st;
        string ans="";
        for(auto c : s)
        {
            if(isalpha(c)) ans+=c;
            else if(c=='(') st.push(c);
            else 
            {
                if(c==')')
                {
                    while(st.top()!='(')
                    {
                        ans+=st.top();
                        st.pop();
                    }
                    st.pop();
                }
                else if(st.empty() or priority(c)>priority(st.top()))
                {
                    st.push(c);
                }
                else
                {
                    while(!st.empty() and priority(c)<=priority(st.top()))
                    {
                        ans+=st.top();
                        st.pop();
                    }
                    st.push(c);
                }
            }
            
        }
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
//REVERSE A STACKL
void insertAtBottom(int item) {  
    if (isEmpty()) {  
        push(item);  
    } else {  
       int top = pop();  
        insertAtBottom(item);  
        push(top);  
    }  
}  
void reverse() {  
    if (!isEmpty()) {  
         int top = pop();  
        reverse();  
        insertAtBottom(top);  
    }  
}  
/*
Stock span problem 
Medium Accuracy: 49.89% Submissions: 46736 Points: 4
The stock span problem is a financial problem where we have a series of n daily price quotes for a stock and we need to calculate the span of stock’s price for all n days. 
The span Si of the stock’s price on a given day i is defined as the maximum number of consecutive days just before the given day, for which the price of the stock on the current day is less than or equal to its price on the given day.
For example, if an array of 7 days prices is given as {100, 80, 60, 70, 60, 75, 85}, then the span values for corresponding 7 days are {1, 1, 1, 2, 1, 4, 6}.

Example 1:

Input: 
N = 7, price[] = [100 80 60 70 60 75 85]
Output:
1 1 1 2 1 4 6
Explanation:
Traversing the given input span for 100 
will be 1, 80 is smaller than 100 so the 
span is 1, 60 is smaller than 80 so the 
span is 1, 70 is greater than 60 so the 
span is 2 and so on. Hence the output will 
be 1 1 1 2 1 4 6.
*/
 vector<int>calculateSpan(int arr[], int n)
    {
        stack<int>s;
        vector<int>v;
     for(int i=0;i<n;i++){
         while(!s.empty()&& arr[s.top()]<=arr[i] ){
             s.pop();
         }
         
         if(s.empty()){
             v.push_back(i+1);
         }
         else{
           v.push_back(i-s.top());    
         }
        
          s.push(i);
     }
     return v;
       // Your code here
    }
/*
Next Greater Element 
Medium Accuracy: 48.92% Submissions: 67358 Points: 4
Given an array arr[ ] of size N having distinct elements, the task is to find the next greater element for each element of the array in order of their appearance in the array.
Next greater element of an element in the array is the nearest element on the right which is greater than the current element.
If there does not exist next greater of current element, then next greater element for current element is -1. For example, next greater of the last element is always -1.

Example 1:

Input: 
N = 4, arr[] = [1 3 2 4]
Output:
3 4 4 -1
Explanation:
In the array, the next larger element 
to 1 is 3 , 3 is 4 , 2 is 4 and for 4 ? 
since it doesn't exist, it is -1.

*/
 vector<long long> nextLargerElement(vector<long long> arr, int n){
        stack<long long>s;
        vector<long long >v;
        for(long long i= n-1;i>=0;i--){
            if(s.empty()){
                v.push_back(-1);
            }
            else if(!s.empty() && s.top()>arr[i]){
                v.push_back(s.top());
            }
            else {
                while(!s.empty() && s.top()<=arr[i]){
                    s.pop();
                }
                if(s.empty()){
                    v.push_back(-1);
                }
                else{
                    v.push_back(s.top());
                }
            }
            s.push(arr[i]);
        }
        reverse(v.begin(),v.end());
        return v;
        // Your code here
    }