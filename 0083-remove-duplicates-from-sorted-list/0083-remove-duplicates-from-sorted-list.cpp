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
    ListNode* deleteDuplicates(ListNode* head) {
          if (head == nullptr) {
            return head;
        }

        ListNode* current = head;
        ListNode* prev = nullptr;

        unordered_set<int> seen;

        while (current != nullptr) {

            if (seen.find(current->val) != seen.end()) {

                // Duplicate node
                prev->next = current->next;

                delete current;

                current = prev->next;
            }
            else {

                // First occurrence
                seen.insert(current->val);

                prev = current;
                current = current->next;
            }
        }

        return head;
    }
};