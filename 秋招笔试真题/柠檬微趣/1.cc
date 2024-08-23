#include <bits/stdc++.h>
using ll = long long;
using namespace std;

struct Node {
    Node(int v = -1) : val(v) {}
    int val;
    Node* next{nullptr};
};

Node* merge(Node *l, Node *r) {
    Node dump(-1);
    Node* cur = &dump;
    while (l && r) {
        if (l->val < r->val) {
            cur->next = l;
            l = l->next;
        } else {
            cur->next = r;
            r = r->next;
        }
        cur = cur->next;
    }
    if (l) cur->next = l;
    else cur->next = r;
    return dump.next;
}

Node *sortList(Node *head) {
    if (head == nullptr || head->next == nullptr) return head;
    Node *slow = head, *fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    fast = slow->next;
    slow->next = nullptr;
    return merge(sortList(head), sortList(fast));
}

// 排序链表
int main() {

    string str;
    getline(cin, str);
    istringstream iss(str);
    int n;
    Node dump(-1);
    Node* cur = &dump;
    while (iss >> n) {
        Node *node = new Node(n);
        cur->next = node;
        cur = cur->next;
    }
    dump.next = sortList(dump.next);
    cur = dump.next;
    if (cur) {
        cout << cur->val;
        cur = cur->next;
    }
    while (cur) {
        cout << " " << cur->val;
        cur = cur->next;
    }

    return 0;
}