#include <iostream>
#include <string>

using namespace std;

// TrieNode class represents a node in the Trie data structure
class TrieNode {
   public:
    char data;               // stores the character represented by the node
    TrieNode* children[26];  // array of pointers to child nodes (one for each
                             // letter of the alphabet)
    bool isTerminal;  // flag to indicate if the node represents the end of a
                      // word

    // Constructor to initialize a TrieNode with a character
    TrieNode(char ch) {
        this->data = ch;
        for (int i = 0; i < 26; i++)
            children[i] = NULL;  // initialize all child pointers to NULL
        isTerminal = false;      // initially not a terminal node
    }
};

// Trie class represents the Trie data structure
class Trie {
   public:
    TrieNode* root;  // root node of the Trie

    // Constructor to initialize an empty Trie
    Trie() {
        root =
            new TrieNode('\0');  // create a dummy root node with character '\0'
    }

    // Helper function to insert a word into the Trie recursively
    void insertUtil(TrieNode* root, string word) {
        // Base case: if the word is empty, mark the current node as terminal
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        // Calculate the index of the current character in the children array
        int index = word[0] - 'A';
        TrieNode* child;

        // If the child node exists, move to the child node
        if (root->children[index] != NULL) {
            child = root->children[index];
        }
        // Otherwise, create a new child node and assign it to the current index
        else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursively insert the remaining part of the word
        insertUtil(child, word.substr(1));
    }

    // Function to insert a word into the Trie
    void insert(string word) { insertUtil(root, word); }

    // Helper function to search for a word in the Trie recursively
    bool searchUtil(TrieNode* root, string word) {
        // Base case: if the word is empty, check if the current node is
        // terminal
        if (word.length() == 0) {
            return root->isTerminal;
        }

        // Calculate the index of the current character in the children array
        int index = word[0] - 'A';

        // If the child node exists, recursively search for the remaining part
        // of the word
        if (root->children[index] != NULL) {
            return searchUtil(root->children[index], word.substr(1));
        }
        // Otherwise, the word is not present in the Trie
        else {
            return false;
        }
    }

    // Function to search for a word in the Trie
    bool search(string word) { return searchUtil(root, word); }

    // Helper function to remove a word from the Trie recursively
    // Helper function to check if a node has any non-null children
    bool hasChildren(TrieNode* node) {
        for (int i = 0; i < 26; i++) {
            if (node->children[i] != NULL) {
                return true;
            }
        }
        return false;
    }

    bool removeUtil(TrieNode* root, string word, int depth = 0) {
        // If the word is empty, check if the current node is terminal
        if (word.length() == 0) {
            // If the node is terminal, mark it as non-terminal and return true
            if (root->isTerminal) {
                root->isTerminal = false;
                return true;
            }
            // If the node is not terminal, return false (word not found)
            else {
                return false;
            }
        }

        // Calculate the index of the current character in the children array
        int index = word[0] - 'A';
        TrieNode* child = root->children[index];

        // If the child node doesn't exist, return false (word not found)
        if (child == NULL) {
            return false;
        }

        // Recursively remove the remaining part of the word
        bool shouldDeleteChild = removeUtil(child, word.substr(1), depth + 1);

        // If the child node should be deleted (no more words passing through it)
        if (shouldDeleteChild) {
            // If the current node is not root and has no children
            if (depth > 0 && child->isTerminal == false) {
                delete child;
                root->children[index] = NULL;
            }
            // If the current node is root and has no children
            else if (depth == 0) {
                // Don't delete the root node, just clear its children
                for (int i = 0; i < 26; i++) {
                    if (root->children[i] != NULL) {
                        delete root->children[i];
                    }
                    root->children[i] = NULL;
                }
            }
            return (root->isTerminal == false && !hasChildren(root));
        }

        // If the child node should not be deleted, return false
        return false;
    }

    // Function to remove a word from the Trie
    bool remove(string word) { return removeUtil(root, word); }
};

int main() {
    Trie* T = new Trie();  // create a new Trie

    // insert the words into the Trie
    T->insert("rajesh");
    T->insert("munna");
    T->insert("ayush");

    // search for "rajesh" and print the result
    cout << "Search for rajesh: " << T->search("rajesh") << endl;  // 1
    cout << "Remove for rajesh: " << T->remove("rajesh") << endl;  // 1
    cout << "Search for rajesh: " << T->search("rajesh") << endl;  // 0
    cout << "Search for rajesh: " << T->search("rajesh") << endl;  // 0

    cout << endl;
    return 0;
}