#include <bits/stdc++.h>
using namespace std;

// creating a struct "Node" for Trie
struct Node{
    char data;
    Node* children[26];
    bool isTerminal;

    Node(char ch){
        data = ch;
        for(int i=0; i<26; i++) children[i] = NULL;
        isTerminal = false;
    }
};

// Creating class "Trie" with insertion, deletion and search 
class Trie{
private:
    void insertUtil(Node* root, string word){
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        };

        int idx = word[0] - 'A';
        Node* child;

        if(root->children[idx]) child = root->children[idx];
        else{
            child = new Node(word[0]);
            root->children[idx] = child;
        }

        insertUtil(child, word.substr(1));
    }

    bool searchUtil(Node* root, string word){
        if(word.length() == 0){
            return root->isTerminal;
        }

        int idx = word[0] - 'A';
        Node* child;

        if(root->children[idx]) child = root->children[idx];
        else return false;

        return searchUtil(child, word.substr(1));
    }

    void deleteUtil(Node* root, string word){
        if(word.length() == 0){
            root->isTerminal = false;
            return;
        }

        int idx = word[0] - 'A';
        Node* child = root->children[idx];

        deleteUtil(child, word.substr(1));
    }

public:
    Node* root;

    Trie(){
        root = new Node('\0');
    }

    void insertWord(string word){
        insertUtil(root, word);
    }

    bool searchWord(string word){
        return searchUtil(root, word);
    }

    void deleteWord(string word){
        deleteUtil(root, word);
    }
};

// Phone directory
class PhoneDirectory{
private:
    void printSuggestions(Node* curr, vector<string> &ans, string &prefixStr){
        if(curr->isTerminal) ans.push_back(prefixStr);

        for(char ch='A'; ch<='Z'; ch++){
            Node* next = curr->children[ch-'A'];

            if(next){
                prefixStr.push_back(ch);
                printSuggestions(next, ans, prefixStr);
                prefixStr.pop_back();
            }
        }
    }

    vector<string> getSuggestion(string queryStr, Trie* trie){
        Node* curr = trie->root;
        vector<string> ans;
        string prefixStr = "";

        for(char ch : queryStr){
            prefixStr.push_back(ch);

            Node* next = curr->children[ch - 'A'];
            if(!next) return ans;
            curr = next;
        }

        printSuggestions(curr, ans, prefixStr);
        return ans;
    }

public:
    vector<string> phoneDirectory(vector<string> contactList, string queryStr){
        Trie *trie = new Trie();
        for(string contact : contactList) trie->insertWord(contact);

        return getSuggestion(queryStr, trie);
    }
};
