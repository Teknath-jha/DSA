
#include <bits/stdc++.h>
using namespace std;
const int ALPHABET_SIZE = 26;

struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;
};

//create a node with null initialization
TrieNode *getNode()
{
    TrieNode *pNode = new TrieNode;

    pNode->isEndOfWord = false;

    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;

    return pNode;
}

void insert(TrieNode *root, string key)
{
    TrieNode *pCrawl = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (pCrawl->children[index] == NULL)
            pCrawl->children[index] = getNode();

        pCrawl = pCrawl->children[index];
        
    }

    pCrawl->isEndOfWord = true;
}

bool isLeafNode(struct TrieNode* root) 
{ 
    return root->isEndOfWord != false; 
} 
  
// function to display the content of Trie 
void display(struct TrieNode* root, char str[], int level=0) 
{ 
    
    if (isLeafNode(root))  
    { 
        str[level] = '\0'; 
        cout << str << endl; 
    } 
  
    int i; 
    for (i = 0; i < ALPHABET_SIZE; i++)  
    { 
        if (root->children[i])  
        { 
            str[level] = i + 'a'; 
            display(root->children[i], str, level + 1); 
        } 
    } 
} 

signed main()
{
    TrieNode *root =  getNode();
    string key[]={
        "i","am","a","boy"
    };
    for(string x:key)
    insert(root, x);

    char wordArray[100];
    display(root, wordArray);
}


////

/*


// C++ implementation of search and insert 
// operations on Trie 
#include <bits/stdc++.h> 
using namespace std; 

const int ALPHABET_SIZE = 26; 

// trie node 
struct TrieNode 
{ 
	struct TrieNode *children[ALPHABET_SIZE]; 

	// isEndOfWord is true if the node represents 
	// end of a word 
	bool isEndOfWord; 
}; 

// Returns new trie node (initialized to NULLs) 
struct TrieNode *getNode(void) 
{ 
	struct TrieNode *pNode = new TrieNode; 

	pNode->isEndOfWord = false; 

	for (int i = 0; i < ALPHABET_SIZE; i++) 
		pNode->children[i] = NULL; 

	return pNode; 
} 

// If not present, inserts key into trie 
// If the key is prefix of trie node, just 
// marks leaf node 
void insert(struct TrieNode *root, string key) 
{ 
	struct TrieNode *pCrawl = root; 

	for (int i = 0; i < key.length(); i++) 
	{ 
		int index = key[i] - 'a'; 
		if (!pCrawl->children[index]) 
			pCrawl->children[index] = getNode(); 

		pCrawl = pCrawl->children[index]; 
	} 

	// mark last node as leaf 
	pCrawl->isEndOfWord = true; 
} 

// Returns true if key presents in trie, else 
// false 
bool search(struct TrieNode *root, string key) 
{ 
	struct TrieNode *pCrawl = root; 

	for (int i = 0; i < key.length(); i++) 
	{ 
		int index = key[i] - 'a'; 
		if (!pCrawl->children[index]) 
			return false; 

		pCrawl = pCrawl->children[index]; 
	} 

	return (pCrawl != NULL && pCrawl->isEndOfWord); 
} 

// Driver 
int main() 
{ 
	// Input keys (use only 'a' through 'z' 
	// and lower case) 
	string keys[] = {"the", "a", "there", 
					"answer", "any", "by", 
					"bye", "their" }; 
	int n = sizeof(keys)/sizeof(keys[0]); 

	struct TrieNode *root = getNode(); 

	// Construct trie 
	for (int i = 0; i < n; i++) 
		insert(root, keys[i]); 

	// Search for different keys 
	search(root, "the")? cout << "Yes\n" : 
						cout << "No\n"; 
	search(root, "these")? cout << "Yes\n" : 
						cout << "No\n"; 
	return 0; 
} 

*/