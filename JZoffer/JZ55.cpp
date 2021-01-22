class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        ListNode* slow=pHead,*quick=pHead;
        while(quick!=nullptr && quick->next!=nullptr){
            slow=slow->next;
            quick=quick->next->next;
            if(slow==quick){
                ListNode* q=pHead;
                while(q!=slow){
                    q=q->next;slow=slow->next;
                }
                return q;
            }
        }
        return nullptr;
    }
};
