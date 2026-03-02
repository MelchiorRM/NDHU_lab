#include <iostream>
#include <queue>
#include <map>
#include <string>
using namespace std;

// ======================= NODE STRUCT =======================
struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = nullptr;
    }
};

// ======================= MIN-HEAP COMPARATOR =======================
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;   // smallest freq first
    }
};

// ======================= CHECK LEAF =======================
bool isLeaf(Node* root) {
    return root->left == nullptr && root->right == nullptr;
}



// ======================= GENERATE HUFFMAN CODES =======================
void generateCodes(Node* root, string code, map<char,string>& codes) {
    if (!root) return;

    if (isLeaf(root)) {
        codes[root->ch] = code;
        return;
    }
    generateCodes(root->left,  code + "0", codes);
    generateCodes(root->right, code + "1", codes);
}



// ======================= BUILD HUFFMAN TREE =======================
Node* buildHuffmanTree(const string& text) {
    if (text.empty()) return nullptr;

    // Count frequencies
    map<char,int> freq;
    for (char c : text) freq[c]++;

    // Create min-priority queue
    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Push leaf nodes
    for (auto p : freq) {
        pq.push(new Node(p.first, p.second));
    }

    // Merge until one tree remains
    while (pq.size() > 1) {
        Node* L = pq.top(); pq.pop();
        Node* R = pq.top(); pq.pop();

        Node* parent = new Node('$', L->freq + R->freq);
        parent->left = L;
        parent->right = R;

        pq.push(parent);
    }

    return pq.top();
}



// ======================= ENCODE TEXT =======================
string encode(const string& text, map<char,string>& codes) {
    string encoded = "";
    for (char c : text) encoded += codes[c];
    return encoded;
}



// ======================= DECODE BITSTRING =======================
string decode(const string& encoded, Node* root) {
    string result = "";
    Node* cur = root;

    for (char bit : encoded) {
        if (bit == '0') cur = cur->left;
        else            cur = cur->right;

        if (isLeaf(cur)) {
            result += cur->ch;
            cur = root;     // restart from root
        }
    }
    return result;
}



// ======================= FREE TREE (AVOID MEMORY LEAKS) =======================
void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}



// =========================================================
// ============================ MAIN ========================
// =========================================================
int main() {
    string text = "AAAAABBBCCD";

    cout << "Original Text: " << text << "\n\n";

    // Build Huffman Tree
    Node* root = buildHuffmanTree(text);

    // Generate Codes
    map<char,string> codes;
    generateCodes(root, "", codes);

    // Print Codes
    cout << "Huffman Codes:\n";
    for (auto p : codes) {
        cout << p.first << " : " << p.second << "\n";
    }
    cout << "\n";

    // Encode text
    string encoded = encode(text, codes);
    cout << "Encoded Bitstring:\n" << encoded << "\n\n";

    // Decode back
    string decoded = decode(encoded, root);
    cout << "Decoded Text:\n" << decoded << "\n\n";

    // Free memory
    freeTree(root);

    return 0;
}
