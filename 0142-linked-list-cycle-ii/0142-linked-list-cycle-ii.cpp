/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (head == NULL)
            return NULL;

        ListNode *hare = head;
        ListNode *tortoise = head;

        do
        {
            if (hare == NULL|| hare->next==NULL)
                return NULL;
                else if(hare->next->next==NULL)
                return NULL;
            
        
            hare = hare->next->next;
            tortoise = tortoise->next;

        } while (hare != tortoise);
        tortoise = head;

        while (tortoise != hare)
        {
            tortoise = tortoise->next;
            hare = hare->next;
        }
        return tortoise;
    }
};