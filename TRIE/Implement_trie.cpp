#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *nodes[26];
    bool fl = false;

    bool containKey(char c)
    {
        return (nodes[c - 'a'] != NULL);
    }

    void put(char c, Node *node)
    {
        nodes[c - 'a'] = node;
    }

    Node *get(char c)
    {
        return nodes[c - 'a'];
    }

    void setEnd() { fl = true; }
    bool isEnd() { return fl; }
};

class TRIE
{
private:
    Node *root;

public:
    TRIE() { root = new Node(); }

    void insert(string s)
    {
        Node *node = root;
        for (char c : s)
        {
            if (!root->containKey(c))
            {
                node->put(c, node);
            }
            node = node->get(c);
        }
        node->setEnd();
    }

    bool search(string s)
    {
        Node *node = root;
        for (char c : s)
        {
            if (!root->containKey(c))
                return false;
            node = node->get(c);
        }
        return node->isEnd();
    }

    bool startWith(string s)
    {
        Node *node = root;
        for (char c : s)
        {
            if (!root->containKey(c))
                return false;
            node = node->get(c);
        }
        return true;
    }
};

int main()
{
    int q;
    cout << "Enter your Query no: \n";
    cin >> q;
    TRIE t1;
    cout << "Enter your Query: a number followd by a string seperated by a space.\n"
         << "Number 1 is to insert... 1 string\n"
         << "Number 2 is to search word starts with a pattern... 2 pattern\n"
         << "Number 3 is to search word exists... 3 word\n\n";
    while (q--)
    {
        int n;
        string a;
        cin >> n >> a;

        if (n == 1)
        {
            cout << "Inserting " << a;
            t1.insert(a);
            cout << endl;
        }
        if (n == 2)
        {
            cout << "Existance of word starts with " << a << " is: " <<( t1.startWith(a) ? "true\n" : "False\n");
        }
        if (n == 3)
            cout << "Existance of word " << a << " is: " << (t1.search(a) ? "true\n" : "False\n");
    }
}