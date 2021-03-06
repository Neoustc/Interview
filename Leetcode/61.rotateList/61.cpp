class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return NULL;
        int len = listLength(head);
        k %= len;
        ListNode* fast = head;
        for (int i = 0; i < k; i++)
            fast = fast -> next;
        ListNode* slow = head;
        while (fast -> next) {
            slow = slow -> next;
            fast = fast -> next;
        }
        fast -> next = head;
        head = slow -> next;
        slow -> next = NULL;
        return head;
    }
private:
    int listLength(ListNode* head) {
        int len = 0;
        while (head) {
            len++;
            head = head -> next;
        }
        return len;
    }
};
