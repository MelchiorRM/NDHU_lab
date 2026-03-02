#include <bits/stdc++.h>
using namespace std;
// ------------------ GENERAL TREE STRUCT ------------------
struct GeneralNode {
 int id;
 vector<GeneralNode*> children;
};
// ------------------ BINARY TREE STRUCT -------------------
struct BinaryNode {
 int id;
 BinaryNode *left; // first child
 BinaryNode *right; // next sibling
 BinaryNode(int v) : id(v), left(nullptr), right(nullptr) {}
};
// ------------------ CONVERSION FUNCTION ------------------
BinaryNode* convert(GeneralNode* gRoot) {
 if (!gRoot) return nullptr;
 BinaryNode* bRoot = new BinaryNode(gRoot->id);
 if (!gRoot->children.empty()) {
 // First child -> left
 bRoot->left = convert(gRoot->children[0]);
 // Siblings -> chain on the right
 BinaryNode* current = bRoot->left;
 for (size_t i = 1; i < gRoot->children.size(); i++) {
 current->right = convert(gRoot->children[i]);
 current = current->right;
 }
 }
 return bRoot;
}
// ------------------ PRINT BINARY TREE ---------------------
void printBinary(BinaryNode* root, int depth = 0) {
 if (!root) return;
 // Simple preorder print with indentation
 for (int i = 0; i < depth; i++) cout << " ";
 cout << root->id << "\n";
 printBinary(root->left, depth + 1); // first child
 printBinary(root->right, depth); // next sibling (same depth)
}
// ------------------ MAIN PROGRAM -------------------------
int main() {
 int N, rootID;
 cout << "Enter number of nodes: ";
 cin >> N;
 cout << "Enter root id: ";
 cin >> rootID;
 // Create all nodes first
 unordered_map<int, GeneralNode*> nodes;
 for (int i = 1; i <= N; i++) {
 nodes[i] = new GeneralNode{i, {}};
 }
 cout << "Enter " << N - 1 << " edges (parent child):\n";
 for (int i = 0; i < N - 1; i++) {
 int p, c;
 cin >> p >> c;
 nodes[p]->children.push_back(nodes[c]);
 }
 // Build general tree root
 GeneralNode* gRoot = nodes[rootID];
 // Convert to binary tree
 BinaryNode* bRoot = convert(gRoot);
 cout << "\nConverted Binary Tree (Left-Child Right-Sibling Representation):\n";
 printBinary(bRoot);
 return 0;
}