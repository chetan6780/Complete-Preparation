# [Implement Trie](https://www.codingninjas.com/codestudio/problems/implement-trie_631356?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos&leftPanelTab=0) 🌟🌟🌟

-   Lecture-1 of striver's Trie series.
-   Implemented Trie in c++.
-   Implemented insert, search and startsWith in c++.
-   The below code is self-explanatory.
-   For reference here is [Striver's video](https://www.youtube.com/watch?v=dBGUmUQhjaM).

### Code

```cpp
/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
*/

struct Node{
    Node *links[26]; // 26 size array
    bool flag = false;

    bool containsKey(char ch){
        // if the char is null or not
        return (links[ch-'a']!=NULL);
    }
    Node* get(char ch){
        // Get the character
        return links[ch-'a'];
    }
    void put(char ch, Node* node){
        // Create new reference node
        links[ch-'a'] = node;
    }
    void setEnd(){
        // if end then set flag=true
        flag = true;
    }
    bool isEnd(){
        // if end, flag=true else flag=false
        return flag;
    }
};

class Trie {

private: Node* root; // root node

public:

    /** Initialize your data structure here. */
    Trie() {
        // initialize new root node
		root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
		Node *node = root; // start with root
        for(int i=0;i<word.size();i++){ // traverse the trie
            if(!node->containsKey(word[i])){ // if node not contain current char
                node->put(word[i],new Node()); // create new trie node
            }
            // if node contains current char get it's reference node
            node = node->get(word[i]);
        }
        // after the last char setEnd(),i.e. set fl=true;
        node->setEnd();
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
		Node* node = root;
        for(int i=0;i<word.size();i++){ // traverse the trie
            if(!node->containsKey(word[i])){ // if node not contain current char
				return false;
            }
            // if node contains current char get it's reference node
            node = node->get(word[i]);
        }
        // if word present isEnd()=true else isEnd()=false
        return node->isEnd();
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
		Node *node = root;
        for(int i=0;i<prefix.size();i++){
            if(!node->containsKey(prefix[i])){ // if node not contain current char
				return false;
            }
            node = node->get(prefix[i]); // get reference node of prefix[i]
        }
        // if it reaches to end, it means prefix exist, return true.
        return true;
    }
};
```
