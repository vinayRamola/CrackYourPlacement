class Solution {
public:
    class TrieNode {
    public:
        char data;
        TrieNode* children[26];
        int childCount;
        bool isTerminal;

        TrieNode(char ch) {
            data = ch;
            for (int i = 0; i < 26; i++) {
                children[i] = NULL;
            }
            childCount = 0;
            isTerminal = false;
        }
    };

    class Trie {
    public:
        TrieNode* root;

        Trie(char ch) {
            root = new TrieNode(ch);
        }

        void insertUtil(TrieNode* root, string word) {
            if (word.length() == 0) {
                root->isTerminal = true;
                return;
            }

            int index = word[0] - 'a';
            TrieNode* child;

            // present
            if (root->children[index] != NULL) {
                child = root->children[index];
            } else {
                // absent
                child = new TrieNode(word[0]);
                root->childCount++;
                root->children[index] = child;
            }

            // recursion
            insertUtil(child, word.substr(1));
        }

        void insertWord(string word) {
            insertUtil(root, word);
        }

        void lcp(string str, string& ans) {
            TrieNode* node = root; // Start from the root of the Trie
            for (int i = 0; i < str.length(); i++) {
                char ch = str[i];

                if (node->childCount == 1) {
                    ans.push_back(ch);
                    int index = ch - 'a';
                    node = node->children[index];
                } else {
                    break;
                }

                if (node->isTerminal) {
                    break;
                }
            }
        }
    };

    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        Trie* t = new Trie('\0');

        for (const string& str : strs) {
            if (str.empty()) return "";
            t->insertWord(str);
        }

        string first = strs[0];
        string ans = "";

        t->lcp(first, ans);
        return ans;
    }
};

// space compelexity  O(n^2)

// class Solution {
// public:
//     string longestCommonPrefix(vector<string>& strs) {
//         if (strs.empty()) return "";
//         for(int i=0;i<strs[0].length();i++){
//             char currChar = strs[0][i];
//             for(int j=1;j<strs.size();j++){
//                 if(i>=strs[j].length() || strs[j][i] != currChar){
//                     return strs[0].substr(0, i);
//                 }
//             }
//         }
//         return strs[0];
//     }
// };