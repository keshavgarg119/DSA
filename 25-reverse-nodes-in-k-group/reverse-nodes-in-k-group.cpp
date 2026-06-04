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
    ListNode* reverse(ListNode* head) {
        if(head==nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* newHead = reverse(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = nullptr;

        return newHead;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr || k==1) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* groupPrev = dummy; //exactly behind the start of prev group

        while(true) {
            ListNode* kth = groupPrev;

            for(int i=0; i<k; i++) {
                kth = kth->next;

                if(kth==nullptr) {
                    return dummy->next;
                }
            }

            ListNode* groupNext = kth->next; //starting point of the next group
            ListNode* groupStart = groupPrev->next; // starting point of the current group
            
            kth->next = nullptr;
            ListNode* newHead = reverse(groupStart); //reverse the curr group
            
            groupPrev->next = newHead; //join the dummy with reversed group
            groupStart->next = groupNext; //Move to starting point of the next group
            groupPrev = groupStart; //one node befire the start
        }

        return dummy->next;
    }
};