#include <iostream>
#include <queue>
#include <stack>

/* 力扣234题 */
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head)
        {
            return false;
        }
 
        std::queue<int> my_queue;
        std::stack<int> my_stack;
        int list_length = 0;
        for (ListNode* travel = head; travel != NULL; travel = travel->next)
        {
            my_queue.push(travel->val);
            my_stack.push(travel->val);
            list_length++;
        }

        for (int idx = 0; idx < list_length; idx++)
        {
            if (my_queue.front() != my_stack.top())
            {
                return false;
            }
            my_queue.pop();
            my_stack.pop();
        }
        return true;
    }
};