#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // if head is NULL OR just having a single node, then no need to change anything 
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
            
        ListNode* temp; // temporary pointer to store head->next
        temp = head->next; // give temp what he wants
        
        head->next = swapPairs(head->next->next); // changing links
        temp->next = head; // put temp->next to head
        
        return temp; // now after changing links, temp acts as our head
    }
};

// Utility function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Example linked list
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    Solution sol;
    ListNode* swappedList = sol.swapPairs(head);

    cout << "Swapped linked list: ";
    printList(swappedList);

    return 0;
}
