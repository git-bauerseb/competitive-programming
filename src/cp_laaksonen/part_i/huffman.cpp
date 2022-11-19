#include <bits/stdc++.h>

using namespace std;

struct Node {
    Node* m_left;
    Node* m_right;
    int m_key;
    char m_c;

    Node(int key, char c) : m_key{key}, m_c{c} {
        m_left = nullptr;
        m_right = nullptr;
    }

    ~Node() {
        if (m_left != nullptr) {delete m_left;}
        if (m_right != nullptr) {delete m_right;}
    }

    Node(int key, char c, Node* l, Node* r) 
        : m_c{c}, m_left{l}, m_right{r}, m_key{key} {}

    void print_code(string code);
};

void Node::print_code(string code) {
    if (m_left != nullptr) {m_left->print_code(code + '0');}
    if (m_right != nullptr) {m_right->print_code(code + '1');}

    if (m_left == nullptr && m_right == nullptr) {
        cout << m_c << "\t" << code << "\n";
    }
}

struct CustomCompare {
    bool operator()(const Node* l, const Node* r) {
        return l->m_key > r->m_key;
    }
};

void huffman_coding(vector<int> frequencies, vector<char> chars) {
    priority_queue<Node*, vector<Node*>, CustomCompare> pq;

    for (int i = 0; i < frequencies.size(); i++) {
        Node* n = new Node(frequencies[i], chars[i]);
        pq.push(n);
    }

    while (pq.size() > 1) {

        Node* f = pq.top();
        pq.pop();

        Node* s = pq.top();
        pq.pop();

        Node* combined = new Node(f->m_key + s->m_key, '.', f, s);
        pq.push(combined);
    }

    Node* top = pq.top();
    pq.pop();
    top->print_code("");

    delete top;
}

int main(int argc, char** argv) {
    //               A B C D
    vector<int> freq{5,1,2,1, 7};
    vector<char> chars{'A', 'B', 'C', 'D', 'E'};
    huffman_coding(freq, chars);

    return 0;
}