#include <iostream>
#include <vector>

using namespace std;

struct GNode {
    int id;
    vector<GNode*> children;
};

struct BNode {
    int id;
    BNode* left = nullptr;
    BNode* right = nullptr;
};

BNode* convert(GNode* root) {
    if (!root) return nullptr;
    BNode* bRoot = new BNode{root->id};

    if (!root->children.empty()) {
        bRoot->left = convert(root->children[0]);
        BNode* current = bRoot->left;
        for (size_t i = 1; i < root->children.size(); ++i) {
            current->right = convert(root->children[i]);
            current = current->right;
        }
    }
    return bRoot;
}

void preOrderTraversal(BNode* root) {
    if (!root) return;
    cout << root->id << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<GNode*> nodes(N + 1, nullptr);
    for (int i = 1; i <= N; ++i) {
        nodes[i] = new GNode{i};
    }

    for (int i = 0; i < M; ++i) {
        int parent, child;
        cin >> parent >> child;
        nodes[parent]->children.push_back(nodes[child]);
    }

    BNode* binaryRoot = convert(nodes[1]);
    preOrderTraversal(binaryRoot);
    cout << endl;

    return 0;
}
