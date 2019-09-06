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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // add the last lsb
        // hold carry in a variable
        // if one of the list has reached its end process the other one
        // finally check if any carry exists

        ListNode *result,*ans = new ListNode(0);
        result = ans;
        int carry = 0;
        while (l1 && l2){
            ListNode* node = new ListNode(0);
            node->val = l1->val+l2->val+carry;
            carry = node->val / 10;
            node->val -= carry*10;
            ans->next = node;
            ans = node;
            l1 = l1->next;
            l2 = l2->next;
        }

        // if one of them reach null, check for other
        while (l1){
            ListNode* node = new ListNode(0);
            node->val = l1->val+carry;
            carry = node->val / 10;
            node->val -= carry*10;
            ans->next = node;
            ans = node;
            l1 = l1->next;
        }

        while (l2){
            ListNode* node = new ListNode(0);
            node->val = l2->val+carry;
            carry = node->val / 10;
            node->val -= carry*10;
            ans->next = node;
            ans = node;
            l2 = l2->next;
        }

        // if carry exist create new node
        if (carry > 0){
            ListNode* node = new ListNode(1);
            carry = 0;
            ans->next = node;
            ans = node;
        }
        ans = result;
        result = result->next;
        delete (ans);
        return result;
    }
};
