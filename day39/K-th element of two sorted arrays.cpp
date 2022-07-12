// brute force approach:
int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
       int cnt = 0;
       int i = 0, j = 0;
       while(i < n and j < m){
           if(arr1[i] <= arr2[j]){
               cnt++;
               if(cnt == k) return arr1[i];
               i++;
           } else{
               cnt++;
               if(cnt == k) return arr2[j];
               j++;
           }
       }
       while(i < n){
            cnt++;
               if(cnt == k) return arr1[i];
               i++;
       }
       while(j < m){
           cnt++;
               if(cnt == k) return arr2[j];
               j++;
       }
       return 0;
        
    }


/// Optimized aproach:
int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
       if(m < n) return kthElement(arr2, arr1, m ,n, k);
        
        int low = max(0, k-m), high = min(k, n);
        while(low <= high){
            int cut1 = (low+high) >> 1;
            int cut2 = k - cut1;
            
            
            int left1 = cut1 == 0? INT_MIN : arr1[cut1-1];
            int left2 = cut2 == 0? INT_MIN : arr2[cut2-1];
            
            int right1 = cut1 >= n? INT_MAX : arr1[cut1];
            int right2 = cut2 >= m? INT_MAX : arr2[cut2];
            
            if(left1 <= right2 and left2 <= right1){
               return max(left1, left2);
            }
            else if(left1 > right2) high = cut1-1;
            else low = cut1+1;
        }
        return 0;
        
    }
