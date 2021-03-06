class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n!= 0 && m != 0){
            for(int i = 0; i < m; i++){
                if(nums1[i] > nums2[0]){
                   // cout << "i = " << i << "\n";
                    int tmp = nums1[i];
                    nums1[i] = nums2[0];
                    nums2[0] = tmp;
                    int ele = nums2[0];
                    for(int j = 1; j < n; j++){
                        if(ele > nums2[j]){
                            nums2[j-1] = nums2[j];
                             if(j == n-1) nums2[j] = ele;
                        } else{
                            nums2[j-1] = ele;
                            break;
                        }
                    }
                }
            }

            for(int i = m; i < m+n; i++){
                nums1[i] = nums2[i-m];
            }
        }else if(m == 0 && n != 0){
            for(int i = m; i < m+n; i++){
                nums1[i] = nums2[i-m];
            }
        }
    }
};


// Gap method: TC(O(logN)*O(N)) SC - O(1)

class Solution {
public:
    void print(vector<int> &ans){
        for(auto it : ans) cout << it << " ";
        cout << endl;
    }
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n!= 0 && m != 0){
            int gap = (n+m+1)/2;
            
            for(int i = gap; i >= 1; i = (i+1)/2){
                int low = 0;
                int high = low+i;
                while(high < m){
                    if(nums1[low] > nums1[high]){
                        swap(nums1[low], nums1[high]);
                    }
                    low++; high++;
                }
                while(high < m+n){
                    if(low < m && nums1[low] > nums2[high-m]){
                        swap(nums1[low], nums2[high-m]);
                    } else if(low >= m && nums2[low-m] > nums2[high-m]){
                        swap(nums2[low-m], nums2[high-m]);
                    }
                    low++; high++;
                }
                
                if(i == 1){
                   // print(nums1);
                   // print(nums2);
                    for(int i = m; i < m+n; i++){
                        nums1[i] = nums2[i-m];
                     }
                    return;
                }
                
            }
        }else if(m == 0 && n != 0){
            for(int i = m; i < m+n; i++){
                nums1[i] = nums2[i-m];
            }
        }
    }
};

