#include <unordered_map>
#include <cstdio>
#include <cassert>

using namespace std;

struct DNode {
    DNode *next;
    DNode *prev;
    int key;
    int value;
};

class LRUCache{
public:
    LRUCache(int capacity)
     : capacity(capacity)
     , size(0) {
        head = new DNode();
        head->next = head;
        head->prev = head;
        head->key = -1;
        head->value = -1;
    }

    void make_latest(DNode *cur, bool old=true) {
        if (old) {
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
        }
        cur->next = head->next;
        cur->prev = head;
        head->next->prev = cur;
        head->next = cur;
    }

    int get(int key) {
        if (ht.find(key) != ht.end()) {
            DNode *cur = ht[key];
            make_latest(cur);
            return cur->value;
        }
        else return -1;
    }

    void set(int key, int value) {
        if (ht.find(key) != ht.end()) {
            DNode *cur = ht[key];
            cur->key = key;
            cur->value = value;
            make_latest(cur);
            return;
        }
        if (size == capacity) {
            DNode *old = head->prev;
            old->prev->next = old->next;
            old->next->prev = old->prev;
            ht.erase(old->key);
            delete old;
            --size;
        }
        DNode *cur = new DNode();
        cur->key = key;
        cur->value = value;
        make_latest(cur, false);
        ht[key] = cur;
        ++size;
    }

private:
    DNode *head;
    unordered_map<int, DNode*> ht;
    int capacity;
    int size;
};

int main() {
    LRUCache lru(3);
    assert(-1 == lru.get(1));
    lru.set(1, 11);
    lru.set(2, 22);
    lru.set(3, 33);
    assert(11 == lru.get(1));
    assert(33 == lru.get(3));
    lru.set(4, 44);
    assert(-1 == lru.get(2));
    lru.set(5, 55);
    assert(-1 == lru.get(1));
    assert(44 == lru.get(4));
    return 0;
}
