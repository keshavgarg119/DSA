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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while(list1!=nullptr && list2!=nullptr) {
            if(list1->val <= list2->val) {
                temp->next = list1;
                list1 = list1->next;
            }
            else {
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }

        if(list1) {
            temp->next = list1;
            list1 = list1->next;
            temp = temp->next;
        }

        if(list2) {
            temp->next = list2;
            list2 = list2->next;
            temp = temp->next;
        }

        return dummy->next;
    }
    ListNode* solve(vector<ListNode*>& lists, int left, int right) {
        if(left==right) {
            return lists[left];
        }

        int mid = left + (right-left)/2;

        ListNode* l1 = solve(lists, left, mid);
        ListNode* l2 = solve(lists, mid+1, right);

        return mergeTwoLists(l1,l2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return nullptr;

        return solve(lists, 0, lists.size()-1);
    }
};