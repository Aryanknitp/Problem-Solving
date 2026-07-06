
class Solution {
public:
    void reverse(ListNode* head) {
        ListNode* cur = head;
        ListNode* pre = NULL;
        while (cur != NULL) {
            ListNode* nex = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nex;
        }
    }

    ListNode* kthNode(ListNode* head, int k) {
        k -= 1;
        while (head != NULL && k > 0) {
            k--;
            head = head->next;
        }
        return head;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* pre = NULL;
        while (temp != NULL) {
            ListNode* kth = kthNode(temp, k);
            if (kth == NULL) {
                if (pre)
                    pre->next = temp;
                break;
            }
            ListNode* nex = kth->next;
            kth->next = NULL;
            reverse(temp);
            if (temp == head) {
                head = kth;
            } else {
                pre->next = kth;
            }
            pre = temp;
            temp = nex;
        }
        return head;
    }
};