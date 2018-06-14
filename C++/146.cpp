struct Node {
    int key, value;
    Node *pre, *next;

    Node() {}

    Node(int _key, int _value, Node *_pre, Node *_next) : key(_key), value(_value), pre(_pre), next(_next) {}
};

// Hash table + 双向链表思想
class LRUCache {
private:
    int cap, size = 0;
    Node *head, *tail;
    unordered_map<int, Node *> linkMap;

    void moveToHead(Node *node) {
        node->pre->next = node->next;
        node->next->pre = node->pre;
        node->next = head->next;
        node->pre = head;
        head->next->pre = node;
        head->next = node;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(0, 0, nullptr, nullptr);
        tail = new Node(0, 0, nullptr, nullptr);
        head->next = tail;
        tail->pre = head;
    }

    int get(int key) {
        auto iter = linkMap.find(key);
        if (iter == linkMap.end()) {
            return -1;
        }
        moveToHead((*iter).second);
        return head->next->value;
    }

    void put(int key, int value) {
        auto iter = linkMap.find(key);
        if (iter == linkMap.end()) {
            Node *node = new Node(key, value, head, head->next);
            head->next->pre = node;
            head->next = node;
            linkMap[key] = node;
            if (++size > cap) {
                node = tail->pre;
                linkMap.erase(tail->pre->key);
                node->pre->next = tail;
                tail->pre = node->pre;
                delete node;
                size--;
            }
        } else {
            (*iter).second->value = value;
            moveToHead((*iter).second);
        }
    }
};