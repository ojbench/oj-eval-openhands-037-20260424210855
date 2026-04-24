
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

namespace DoubleLinkList {

struct NODE {
    int data;
    NODE *next;
    NODE *pre;
    NODE() : data(0), next(nullptr), pre(nullptr) {}
    NODE(int val) : data(val), next(nullptr), pre(nullptr) {}
};

NODE *head = nullptr, *tail = nullptr;
int len = 0;

void Pre() {
    head = new NODE();
    tail = new NODE();
    head->pre = NULL;
    tail->next = NULL;
    head->next = tail;
    tail->pre = head;
    len = 0;
}

NODE *move(int i) {
    NODE *cur = head;
    for (int j = 0; j <= i; j++) {
        cur = cur->next;
    }
    return cur;
}

void insert(int i, int x) {
    NODE *pos = move(i);
    NODE *newNode = new NODE(x);
    newNode->next = pos;
    newNode->pre = pos->pre;
    pos->pre->next = newNode;
    pos->pre = newNode;
    len++;
}

void remove(int i) {
    if (i < 0 || i >= len) return;
    NODE *pos = move(i);
    pos->pre->next = pos->next;
    pos->next->pre = pos->pre;
    delete pos;
    len--;
}

int Get_length() {
    return len;
}

int Query(int i) {
    if (i < 0 || i >= len) return -1;
    NODE *pos = move(i);
    return pos->data;
}

void Print() {
    if (len == 0) {
        cout << -1 << endl;
        return;
    }
    NODE *cur = head->next;
    while (cur != tail) {
        cout << cur->data << (cur->next == tail ? "" : " ");
        cur = cur->next;
    }
    cout << endl;
}

void Clear() {
    NODE *cur = head;
    while (cur != nullptr) {
        NODE *next = cur->next;
        delete cur;
        cur = next;
    }
    head = tail = nullptr;
    len = 0;
}

} // namespace DoubleLinkList

int main() {
    int n;
    if (!(cin >> n)) return 0;
    int op, x, p, ans;
    DoubleLinkList::Pre();
    for (int _ = 0; _ < n; ++_) {
        if (!(cin >> op)) break;
        switch (op) {
        case 0:
            ans = DoubleLinkList::Get_length();
            cout << ans << endl;
            break;
        case 1:
            cin >> p >> x;
            DoubleLinkList::insert(p, x);
            break;
        case 2:
            cin >> p;
            ans = DoubleLinkList::Query(p);
            cout << ans << endl;
            break;
        case 3:
            cin >> p;
            DoubleLinkList::remove(p);
            break;
        case 4:
            DoubleLinkList::Print();
            break;
        }
    }
    DoubleLinkList::Clear();
    return 0;
}
