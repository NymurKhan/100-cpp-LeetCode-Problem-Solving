#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    struct TrieNode {
        TrieNode* child[26];
        bool flag = false;
        bool Inserted = false;
        string str;
        
        bool containChar(char character) {
            return (child[character - 'a'] != NULL);
        }
        
        void putNode(char nxtchar, TrieNode* node) {
            child[nxtchar - 'a'] = node;
        }
        
        TrieNode* getNode(char character) {
            return child[character - 'a'];
        }
        
        void setEnd() {
            flag = true;
        }
        
        bool isEnd() {
            return flag;
        }
        
        bool didInsert() {
            return Inserted;
        }
        
        void setdidInsert() {
            Inserted = true;
        }
    };
    
    TrieNode* root = new TrieNode();
    
    void insertWord(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (node->containChar(word[i]) == false) {
                node->putNode(word[i], new TrieNode());
            }
            node = node->getNode(word[i]);
        }
        node->setEnd();
        node->str = word;
    }
    
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node, vector<string>& ans, vector<vector<bool>>& visited) {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) {
            return;
        }
        if (visited[i][j]) {
            return;
        }
        node = node->getNode(board[i][j]);
        if (node == NULL) {
            return;
        }
        if (node->isEnd() && !(node->Inserted)) {
            ans.push_back(node->str);
            node->Inserted = true;
        }
        visited[i][j] = true;
        dfs(board, i + 1, j, node, ans, visited);
        dfs(board, i, j + 1, node, ans, visited);
        dfs(board, i - 1, j, node, ans, visited);
        dfs(board, i, j - 1, node, ans, visited);
        visited[i][j] = false;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        for (string word : words) {
            insertWord(word);
        }
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                dfs(board, i, j, root, ans, visited);
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<char>> board = {{'o', 'a', 'a', 'n'}, {'e', 't', 'a', 'e'}, {'i', 'h', 'k', 'r'}, {'i', 'f', 'l', 'v'}};
    vector<string> words = {"oath", "pea", "eat", "rain"};
    vector<string> result = sol.findWords(board, words);
    for (string word : result) {
        cout << word << " ";
    }
    cout << endl;
    return 0;
}
