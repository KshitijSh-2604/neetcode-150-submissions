/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
    if (!head)
    {
        return nullptr;
    }
    Node* cur = head;
    while (cur)
    {
        Node* copy = new Node(cur->val);
        copy->next = cur->next;
        cur->next = copy;
        cur = copy->next;
    }
    cur = head;
    while (cur)
    {
        if (cur->random)
        {
            cur->next->random = cur->random->next;
        }
        cur = cur->next->next;
    }
    Node* dummy = new Node(0);
    Node* copyCur = dummy;
    cur = head;
    while (cur)
    {
        Node* copy = cur->next;
        cur->next = copy->next;
        copyCur->next = copy;
        copyCur = copy;
        cur = cur->next;
    }
    return dummy->next;
}
};
