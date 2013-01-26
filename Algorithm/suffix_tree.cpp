//
//  suffix_tree.cpp
//  Algorithm
//
//  Created by Shuai on 9/13/12.
//
//

#include <vector>
#include <string>
#include <cassert>
#include <iostream>
using namespace std;

class SuffixTreeNode
{
public:
    SuffixTreeNode()
    {
        memset(children, 0, sizeof(children));
        word = false;
    }
    
    SuffixTreeNode* children[26];
    bool word;
};

SuffixTreeNode* build_tree(vector<string>& strs)
{
    SuffixTreeNode* root = new SuffixTreeNode;
    
    for (int i=0; i<strs.size(); i++) {
        const string& current = strs[i];
        int n = 0;
        SuffixTreeNode* node = root;
        while (n < current.size()) {
            assert(current[n] >= 'a' && current[n] <= 'z');

            if (!node->children[current[n]-'a']) {
                node->children[current[n]-'a'] = new SuffixTreeNode;
            }
            node = node->children[current[n]-'a'];
            n++;
        }
        node->word = true;
    }
    return root;
}

void traverse_suffix_tree(SuffixTreeNode* root, string& path)
{
    if (root->word) {
        cout << path << endl;
    }
    
    for (int i=0; i<sizeof(root->children)/sizeof(*root->children); i++) {
        if (root->children[i]) {
            path.push_back('a' + i);
            traverse_suffix_tree(root->children[i], path);
            path.resize(path.size()-1);
        }
    }
}

void test_suffix_tree()
{
    const char* strs[] = {
        "test",
        "tes",
        "tt",
        "est",
        "esset",
        "talk",
        "estimate"
    };
    
    vector<string> strings;
    for (int i=0; i<sizeof(strs)/sizeof(*strs); i++) {
        strings.push_back(strs[i]);
    }
    
    SuffixTreeNode* tree = build_tree(strings);
    string dummy;
    traverse_suffix_tree(tree, dummy);
}
