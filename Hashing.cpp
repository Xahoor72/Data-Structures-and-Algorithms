/*
Check if a string is Isogram or not 
Basic Accuracy: 55.24% Submissions: 23754 Points: 1
Given a string S of lowercase alphabets, check if it is isogram or not. An Isogram is a string in which no letter occurs more than once.

Example 1:

Input:
S = machine
Output: 1
Explanation: machine is an isogram
as no letter has appeared twice. Hence
we print 1.
*/
  bool isIsogram(string s)
    {
      int hash[256];
        memset(hash, 0, sizeof(hash));
      for(int i=0;i<s.size();i++){
          hash[s[i]]++;
      }
      for(int i=0;i<256;i++){
          if(hash[i]>1){
              return false;
          }
      }
      return true;
       
    }
/*
Uncommon characters 
Basic Accuracy: 37.25% Submissions: 7863 Points: 1
Given two strings A and B. Find the characters that are not common in the two strings. 

Example 1:

Input:
A = geeksforgeeks
B = geeksquiz
Output: fioqruz
Explanation: 
The characters 'f', 'i', 'o', 'q', 'r', 'u','z' 
are either present in A or B, but not in both.
*/
int hash[256]={0};
        int hash2[256]={0};
        for(int i=0;i<A.size();i++){
            hash[A[i]]++;
        }
        for(int i=0;i<B.size();i++){
            hash2[B[i]]++;
        }
        string res;
        for(int i=0;i<256;i++){
            if(hash[i]!=0 && hash2[i]==0){
                res+=i;
            }
            else if(hash[i]==0 && hash2[i]!=0){
                res+=i;
            }
        }
         return res.size() == 0 ? "-1" : res;
            // code here
        }
/*
Anagram Palindrome 
Given a string S, Check if characters of the given string can be rearranged to form a palindrome. 

Example 1:

Input:
S = "geeksogeeks"
Output: Yes
Explanation: The string can be converted
into a palindrome: geeksoskeeg
*/
int isPossible (string S)
{
    int hash[256]={0};
    int count=1;
    for(int i=0;i<S.size();i++){
        hash[S[i]]++;
    }
    for(int i=0;i<256;i++){
    if(count==1 &&hash[i]%2==1){
        count++;
    }
           else if(count>1 &&hash[i]%2==1)
        return 0;
        
    }
    
    return 1;
    // your code here
}
/*
Subarray with 0 sum 
Easy Accuracy: 49.91% Submissions: 71355 Points: 2
Given an array of positive and negative numbers. Find if there is a subarray (of size at-least one) with 0 sum.

Example 1:

Input:
5
4 2 -3 1 6

Output: 
Yes

Explanation: 
2, -3, 1 is the subarray 
with sum 0.
*/
//Your code here
bool subArrayExists(int arr[], int n)
    {
        
        int sum=0;
        unordered_map<int ,int>mp;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            mp[sum]++;
        }
        for(auto x:mp){
            if(x.second>1 || x.first==0){
                return 1;
            }
        }
        return 0;
    }
Substrings with similar first and last characters 
Basic Accuracy: 68.4% Submissions: 1801 Points: 1
Given string s, the task is to find the count of all substrings which have the same character at the beginning and end.

Example 1:

Input: s = "abcab"
Output: 7
Explanation: a, abca, b, bcab, 
c, a and b
/
*/
// Your code goes here
	int countSubstringWithEqualEnds(string s)
	{
	   
	    int hash[256]={0};
	    int res=0;
	    for(int i=0;i<s.size();i++){
	        hash[s[i]]++;
	    }
	    for(int i=0;i<256;i++){
	        res+=(hash[i]*(hash[i]+1))/2;
	    }
	    return res;
	}
/*
String Reversal 
Basic Accuracy: 69.01% Submissions: 1313 Points: 1
Given a string, say S, print it in reverse manner eliminating the repeated characters and spaces.

Example 1:

Input: S = "GEEKS FOR GEEKS"
Output: "SKEGROF"
*/
string reverseString(string s)
{
    //code here.
  int hash[256]={0};
  string str;
  for(int i=0;i<s.size()-1;i++){
      if(s[i]!=' ')
      hash[s[i]]++; 
  }
    for(int i=s.size()-1;i>=0;i--){
          if(hash[s[i]]>=1){
             str+=s[i];
             hash[s[i]]=-1;
          }
      }
 
  return str;
    
}

/*Subarray with 0 sum 
Easy Accuracy: 49.91% Submissions: 71355 Points: 2
Given an array of positive and negative numbers. Find if there is a subarray (of size at-least one) with 0 sum.

Example 1:

Input:
5
4 2 -3 1 6

Output: 
Yes

Explanation: 
2, -3, 1 is the subarray 
with sum 0.
//Your code here*/
bool subArrayExists(int arr[], int n)
    {
        
        int sum=0;
        unordered_map<int ,int>mp;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            mp[sum]++;
        }
        for(auto x:mp){
            if(x.second>1 || x.first==0){
                return 1;
            }
        }
        return 0;
    }
 bool subArrayExists(int arr[], int n)
    {
        unordered_set<int>s;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(s.find(sum)!=s.end() || arr[i]==0||sum==0 )return true;
            s.insert(sum);
        }
        return false;
        //Your code here
    }
/*
Max distance between same elements 
Easy Accuracy: 50.34% Submissions: 26427 Points: 2
Given an array with repeated elements, the task is to find the maximum distance between two occurrences of an element.

Example 1:

Input
n= 6
arr = {1, 1, 2, 2, 2, 1}

Output
5

Explanation
arr[] = {1, 1, 2, 2, 2, 1}
Max Distance: 5
Distance for 1 is: 5-0 = 5
Distance for 2 is : 4-2 = 2
Max Distance 5
*/
 int maxDistance(int arr[], int n)
    {
        int maxi=-1;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            if(mp.find(arr[i])==mp.end())
            mp[arr[i]]=i;
            maxi=max(maxi,i-mp[arr[i]]);
            
        }
        return maxi;
    //Code here
    }
/*Winner of an election 
Easy Accuracy: 49.75% Submissions: 19414 Points: 2
Given an array of names (consisting of lowercase characters) of candidates in an election. A candidate name in array represents a vote casted to the candidate. Print the name of candidate that received Max votes. If there is tie, print lexicographically smaller name.

Example 1:

Input:
n = 13
Votes[] = {john,johnny,jackie,johnny,john 
jackie,jamie,jamie,john,johnny,jamie,
johnny,john}
Output: john 4
Explanation: john has 4 votes casted for 
him, but so does johny. john is 
lexicographically smaller, so we print 
john and the votes he received.
*/
 vector<string> winner(string arr[],int n)
    {
        vector<string>s;
        string res;
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        int count=0;
        for(auto x:mp){
            count=max(count,x.second);
            
        }
        for(auto x:mp){
            if(x.second==count){
            string ans=x.first;
            if(res.size()==0 || ans<res){
                res=ans;
            }
            }
            
        }
             return{res,to_string(count)};
        
    }

//Largest subarray with 0 sum
int maxLen(vector<int>&A, int n)
    {   
        // Your code here
     unordered_map<int,int>mp;
        int maxLen=0;
        int sum=0; 
// to consider corner case if sum of elements from 0 to i is zero then length would be i-(-1)=i+1.
        mp[0]=-1; 
        for(int i=0;i<n;i++){
            sum+=A[i];
        if(mp.find(sum)!=mp.end())maxLen=max(maxLen,i-mp[sum]);
            else mp[sum]=i;
        }
        return maxLen;
    }
/*

Count distinct elements in every window 
Easy Accuracy: 44.16% Submissions: 70051 Points: 2
Given an array of integers and a number K. Find the count of distinct elements in every window of size K in the array.

Example 1:

Input:
N = 7, K = 4
A[] = {1,2,1,3,4,2,3}
Output: 3 4 4 3
Explanation: Window 1 of size k = 4 is
1 2 1 3. Number of distinct elements in
this window are 3. 
Window 2 of size k = 4 is 2 1 3 4. Number
of distinct elements in this window are 4.
Window 3 of size k = 4 is 1 3 4 2. Number
of distinct elements in this window are 4.
Window 4 of size k = 4 is 3 4 2 3. Number
of distinct elements in this window are 3.*/
   vector <int> countDistinct (int A[], int n, int k)
    { 
        vector<int>v;
            unordered_map<int,int>s;
        for(int i=0;i<k;i++){
        
            s[A[i]]++;
        }
        v.push_back(s.size());
        int j=0;
        for(int i=k;i<n;i++){
        s[A[j]]--;
        if(s[A[j]]==0){
            s.erase(A[j]);
        }
        s[A[i]]++;
        v.push_back(s.size());
        j++;
        
        }
        return v;
        //code here.
    }
