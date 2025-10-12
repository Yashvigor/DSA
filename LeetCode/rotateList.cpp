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
    ListNode* rotateRight(ListNode* head, int k) {
         if (!head || !head->next || k == 0) return head;
        
        // Step 1: find the length
        int length = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            length++;
        }
        
        // Step 2: modulo to avoid extra rotations
        k = k % length;
        if (k == 0) return head;
        
        // Step 3: find the new tail (length - k - 1)
        ListNode* newTail = head;
        for (int i = 0; i < length - k - 1; i++) {
            newTail = newTail->next;
        }
        
        // Step 4: set new head
        ListNode* newHead = newTail->next;
        
        // Step 5: rotate
        newTail->next = nullptr;
        tail->next = head;
        
        return newHead;
    }
};
