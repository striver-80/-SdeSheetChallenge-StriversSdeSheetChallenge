/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL or k == 1) return head;
        ListNode* dummy = new ListNode(0, head);
        dummy->next = head;
        ListNode *cur = dummy, *nex = dummy, *pre =dummy;
        int count = 0;
        while(cur->next){
            count++;
            cur = cur->next;
        }
        
        while(count >= k){
            cur = pre->next;
            nex = cur->next;
            //cout << cur->next->val << " " << nex->next->val << "\n";
            for(int i = 1; i < k; i++){
                cur->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = cur->next;
            }
            pre = cur;
            count -= k;
        }
        return dummy->next;
    }
};