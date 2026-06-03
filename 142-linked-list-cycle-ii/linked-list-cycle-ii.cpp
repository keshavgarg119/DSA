/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast!=nullptr && fast->next!=nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            
            ListNode* temp = head;

            if(slow == fast) {
                
                while(slow!=temp) {
                    slow = slow->next;
                    temp = temp->next;
                }
                return temp;
            }
            
            
        }

        return nullptr;
    }
};