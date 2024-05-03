#include<bits/stdc++.h>
using namespace std;

// https://www.naukri.com/code360/problems/longest-common-prefix_2090383


/*
    Time Complexity: O(N*M)
    Space Complexity: O(1)

    where N is the number of strings in the array and M is the length of the shortest string present in the array.
*/

string longestCommonPrefixIterative(vector<string> &arr, int n)
{
    // A String to store the longest common prefix
    string longestPrefix = "";

    for(int idx = 0; idx < arr[0].size(); ++idx)
    {
        // The variable ch is the character to be searched
        char ch = arr[0][idx];
        
        // A boolean value to check whether is it possible to insert ch in longest prefix or not.
        bool matched = true;

        for(int index = 1; index < n; ++index) 
        {   
            // Check if arr[index][idx] is equal to ch
            if (arr[index].size() < idx or arr[index][idx] != ch)
            {
                matched = false;
                break;
            }
        }

        // If matched is true,insert the character ch into longestPrefix
        if (matched)
        {
            longestPrefix += ch;
        }
        else
        {
            break;
        }
    }

    return longestPrefix;
}



/***************************************Using Trie**************************************/





// TrieNode class represents a node in the Trie data structure
class TrieNode {
public:
    char data; // stores the character represented by the node
    TrieNode *children[26]; // array of pointers to child nodes (one for each letter of the alphabet)
    bool isTerminal; // flag to indicate if the node represents the end of a word
    int childCount; // count of valid children nodes
    
    // Constructor to initialize a TrieNode with a character
    TrieNode(char ch) {
        this->data = ch;
        for (int i = 0; i < 26; i++) 
            children[i] = NULL; // initialize all child pointers to NULL
        isTerminal = false; // initially not a terminal node
        childCount = 0; // initially no children
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
            root->childCount++; // update the child count
        }
        
        // Recursively insert the remaining part of the word
        insertUtil(child, word.substr(1));
    }
    
    // Function to insert a word into the Trie
    void insert(string word) {
        insertUtil(root, word);
    }
    
    // Function to find the longest common prefix among all strings
    string longestCommonPrefix(vector<string> &arr, int n) {
        string ans = "";
        TrieNode *curr = root;
        
        // Iterate through the characters of the first string
        for (char ch : arr[0]) {
            int index = ch - 'a';
            // Check if the current node has only one child and it's not a terminal node
            if (curr->childCount == 1 && !curr->isTerminal) {
                ans.push_back(ch);
                curr = curr->children[index];
            } else {
                break;
            }
        }
        
        return ans;
    }
};

string longestCommonPrefix(vector<string> &arr, int n) {
    Trie *t = new Trie();
    for (int i = 0; i < n; i++) 
        t->insert(arr[i]);
    return t->longestCommonPrefix(arr, n);
}

