class Solution{
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
        {
            ListNode* res = new ListNode();
            ListNode* cur_ptr = res;
            int in_mind = 0;

            while(l1 != nullptr || l2 != nullptr || in_mind != 0)
            {
                int v1, v2;
                if (l1 == nullptr)
                    v1 = 0;
                else
                {
                    v1 = l1->val;
                    l1 = l1->next;
                }
                
                if (l2 == nullptr)
                    v2 = 0;
                else
                {
                    v2 = l2->val;
                    l2 = l2->next;
                }

                int sum = v1 + v2 + in_mind;
                in_mind = sum / 10;
                ListNode* node = new ListNode(sum % 10);
                cur_ptr->next = node;
                cur_ptr = node;
            }
            return res->next;
        }
};