
class TrieNode {
public:
    TrieNode* children[26] = {nullptr}; 
    int prefixCount = 0; 
};
class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    void insert(string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (!node->children[ch - 'a']) {
                node->children[ch - 'a'] = new TrieNode();
            }
            node = node->children[ch - 'a'];
            node->prefixCount++; 
        }
    }
    int getPrefixScore(string& word) {
        TrieNode* node = root;
        int score = 0;
        for (char ch : word) {
            node = node->children[ch - 'a'];
            score += node->prefixCount;
        }
        return score;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie trie;
        for (string word : words) {
            trie.insert(word);
        }
        vector<int> result;
        for (string word : words) {
            result.push_back(trie.getPrefixScore(word));
        }
        
        return result;
    }
};

