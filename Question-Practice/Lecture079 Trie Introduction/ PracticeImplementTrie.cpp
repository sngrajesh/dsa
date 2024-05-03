// https://www.naukri.com/code360/problems/implement-trie_631356

#include<bits/stdc++.h>
using namespace std;


/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

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


class Trie {

public:

    /** Initialize your data structure here. */
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
        int index = word[0] - 'a';
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
    /** Inserts a word into the trie. */
    void insert(string word) { insertUtil(root, word); }

    bool searchUtil(TrieNode* root, string word) {
        // Base case: if the word is empty, check if the current node is
        // terminal
        if (word.length() == 0) {
            return root->isTerminal;
        }

        // Calculate the index of the current character in the children array
        int index = word[0] - 'a';

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
    /** Returns if the word is in the trie. */  
    bool search(string word) { return searchUtil(root, word); }

    bool startsWithUtil(TrieNode* root, string word) {
        // Base case: if the word is empty, check if the current node is
        // terminal
        if (word.length() == 0) {
            return true;
        }

        // Calculate the index of the current character in the children array
        int index = word[0] - 'a';

        // If the child node exists, recursively search for the remaining part
        // of the word
        if (root->children[index] != NULL) {
            return startsWithUtil(root->children[index], word.substr(1));
        }
        // Otherwise, the word is not present in the Trie
        else {
            return false;
        }
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return startsWithUtil(root, prefix);
    }
};