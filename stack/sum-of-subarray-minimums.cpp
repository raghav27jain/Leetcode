class Solution {
public:
    vector<int> findPSEE(vector<int>& arr) {
        int n = arr.size();
        vector<int> psee(n);
        stack<int> st;
        for(int i = 0; i <= n-1; i++) {
            while(!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            psee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return psee; 
    }

    vector<int> findNSE(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n);
        stack<int> st;
        for(int i = n-1; i >=0; i--) {
            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> psee = findPSEE(arr);
        vector<int> nse = findNSE(arr);
        int total = 0;
        int mod = (int)(1e9 + 7);

        for(int i = 0; i <= n-1; i++) {
            long long left = i - psee[i];
            long long right = nse[i] - i;
            total = (total + (left * right * 1ll * arr[i]) % mod) % mod;
        }
        return total;
    }
};