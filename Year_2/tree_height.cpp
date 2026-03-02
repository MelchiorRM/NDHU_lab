#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct Node {
    int id;
    vector<Node*> children;
};

Node* createNode(int id) {
    Node* newNode = new Node();
    newNode->id = id;
    return newNode;
}

int getHeight(Node* root) {
    if (root == nullptr) return -1;
    if (root->children.empty()) return 0;

    int maxChildHeight = -1;
    for (Node* child : root->children) {
        maxChildHeight = max(maxChildHeight, getHeight(child));
    }

    return 1 + maxChildHeight;
}

int main() {
    int N;
    cin >> N;

    unordered_map<int, Node*> nodeMap;
    Node* root = nullptr;

    for (int i = 0; i < N - 1; ++i) {
        int parentId, childId;
        cin >> parentId >> childId;

        if (nodeMap.find(parentId) == nodeMap.end()) {
            nodeMap[parentId] = createNode(parentId);
            if (root == nullptr) root = nodeMap[parentId];
        }
        
        if (nodeMap.find(childId) == nodeMap.end()) {
            nodeMap[childId] = createNode(childId);
        }
        
        nodeMap[parentId]->children.push_back(nodeMap[childId]);
    }
    
    cout << getHeight(root) << endl;

    // Clean up memory
    for (auto& pair : nodeMap) {
        delete pair.second;
    }

    return 0;
}
