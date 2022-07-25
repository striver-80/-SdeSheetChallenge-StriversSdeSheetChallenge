#include<bits/stdc++.h>
int largestRectangle(vector < int > & h) {
   // Write your code here.
     int n = h.size();
     stack<int> st;
     int leftsmall[n], rightsmall[n];
     for (int i = 0; i < n; i++) {
        while (!st.empty() && h[st.top()] >= h[i]) {
          st.pop();
        }
        if (st.empty()) leftsmall[i] = 0;
        else leftsmall[i] = st.top() + 1;
        st.push(i);
      }
     
     while (!st.empty()) st.pop();

      for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && h[st.top()] >= h[i]) st.pop();
        if (st.empty())  rightsmall[i] = n - 1;
        else rightsmall[i] = st.top() - 1;
        st.push(i);
      }
      int maxi = 0;
      for (int i = 0; i < n; i++) {
        maxi = max(maxi, h[i] * (rightsmall[i] - leftsmall[i] + 1));
      }
      return maxi;
 }
