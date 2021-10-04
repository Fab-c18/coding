/* 739. Daily Temperatures 

Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is 
the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which 
this is possible, keep answer[i] == 0 instead.

 

Example 1:

Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
Example 2:

Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]
Example 3:

Input: temperatures = [30,60,90]
Output: [1,1,0]

*/


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) 
    {
        int n=temp.size();
        stack<int>st;
        vector<int>res(n,0);
        for(int i=0; i<temp.size(); i++)
        {
            while(!st.empty() && temp[i]>temp[st.top()])
            {
                res[st.top()]=abs(i-st.top());
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};
