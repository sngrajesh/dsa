// https://www.naukri.com/code360/problems/implement-a-phone-directory_1062666
#include<bits/stdc++.h>
using namespace std;


// TrieNode class represents a node in the Trie data structure
class TrieNode {
public:
    char data; // stores the character represented by the node
    TrieNode *children[26]; // array of pointers to child nodes (one for each letter of the alphabet)
    bool isTerminal; // flag to indicate if the node represents the end of a word

    // Constructor to initialize a TrieNode with a character
    TrieNode(char ch) {
        this->data = ch;
        // initialize all child pointers to NULL
        for (int i = 0; i < 26; i++) 
            children[i] = NULL;
        isTerminal = false; // initially not a terminal node
    }
};

// Trie class represents the Trie data structure
class Trie {
public:
    TrieNode *root; // root node of the Trie

    // Constructor to initialize an empty Trie
    Trie() {
        root = new TrieNode('\0'); // create a dummy root node with character '\0'
    }

    // Helper function to insert a word into the Trie recursively
    void insertUtil(TrieNode *root, string word) {
        // Base case: if the word is empty, mark the current node as terminal
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        // Calculate the index of the current character in the children array
        int index = word[0] - 'a';
        TrieNode *child;

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
    void insert(string word) {
        insertUtil(root, word);
    }

    // Helper function to print all words starting with the given prefix
    void printList(TrieNode *curr, vector<string> &temp, string prefix) {
        // If the current node is a terminal node, add the prefix to the output vector
        if (curr->isTerminal) {
            temp.push_back(prefix);
        }

        // Recursively traverse the Trie and append characters to the prefix
        for (char ch = 'a'; ch <= 'z'; ch++) {
            TrieNode *next = curr->children[ch - 'a'];
            if(next != NULL) {
                prefix.push_back(ch);
                printList(next, temp, prefix);
                prefix.pop_back(); // remove the last character from the prefix
            }
        }
    }

    // Function to get suggestions for the given query string
    vector<vector<string>> getSuggestions(string queryStr) {
        vector<vector<string>> output;
        TrieNode *prev = root;
        string prefix = "";

        // Traverse the Trie for each character in the query string
        for (int i = 0; i < queryStr.size(); i++) {
            char lastChar = queryStr[i];
            prefix.push_back(lastChar);
            TrieNode *curr = prev->children[lastChar - 'a'];

            // If the current character is not found in the Trie, break the loop
            if (curr == NULL) break;

            vector<string> temp;
            // Print all words starting with the current prefix
            printList(curr, temp, prefix);
            output.push_back(temp);
            temp.clear();
            prev = curr; // Update the previous node for the next iteration
        }

        return output;
    }
};

// Function to get phone directory suggestions for the given query string
vector<vector<string>> phoneDirectory(vector<string> &contactList, string &queryStr) {
    Trie *T = new Trie(); // create a new Trie

    // Insert all contact numbers into the Trie
    for (auto i : contactList)
        T->insert(i);

    // Get suggestions for the given query string
    return T->getSuggestions(queryStr);
}