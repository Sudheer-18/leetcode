class Node {
public:
    Node* link[26];
    bool flag = false;

    bool ContainKey(char ch) {
        return link[ch - 'a'] != nullptr;
    }    

    void Put(char ch, Node* node) {
        link[ch - 'a'] = node;
    }

    Node* Get(char ch) {
        return link[ch - 'a'];
    }

    void SetEnd() {
        flag = true;
    }

    bool IsEnd() {  
        return flag;
    }
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(char ch : word) {
            if(!node->ContainKey(ch)) {
                node->Put(ch, new Node());
            }
            node = node->Get(ch);
        }
        node->SetEnd();
    }
    
    bool search(string word) {
        Node* node = root;
        for(char ch : word) {
            if(!node->ContainKey(ch)) {
                return false;
            }
            node = node->Get(ch);
        }
        return node->IsEnd();  
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(char ch : prefix) {
            if(!node->ContainKey(ch)) {
                return false;
            }
            node = node->Get(ch);
        }        
        return true;
    }
};
