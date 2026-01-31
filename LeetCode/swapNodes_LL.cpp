class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* first = head;
        ListNode* second = head;
        ListNode* curr = head;

        for(int i = 1; i < k; i++){
            first = first->next;
        }

        curr = first;
        while(curr->next != nullptr){
            curr = curr->next;
            second = second->next;
        }

        int temp = first->val;
        first->val = second->val;
        second->val = temp;

        return head;
    }
};
