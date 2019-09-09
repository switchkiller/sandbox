/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct mycompare{
    bool operator() (ListNode *a, ListNode *b){
        return a->val > b->val;
    }
};

class Solution {
public:

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *result,*dummy;
        priority_queue<ListNode*, vector<ListNode*>, mycompare> pq;

        dummy = new ListNode(0);
        result = dummy;

        for (auto it : lists)
            if (it)
                pq.push(it);

        while (!pq.empty()){
            dummy->next = pq.top();
            dummy = dummy->next;
            ListNode *temp = pq.top();
            pq.pop();
            if (temp->next)
                pq.push(temp->next);
        }

        dummy->next = NULL;
        dummy = result;
        result = result->next;
        delete dummy;
        return result;
    }
};
