#include <iostream>
#include <string>

using namespace std;

const int MAX_NODES = 100;
const int MAX_CHILDREN = 100;

// Node structure using fixed-size array
struct Node {
    string name;
    bool isFolder;
    int children[MAX_CHILDREN];
    int childCount;
};

// Tree represented as an array
Node tree[MAX_NODES];
int nodeCount = 0;

// Function to add a node
int addNode(string name, bool isFolder) {
    if (nodeCount >= MAX_NODES) {
        cout << "Tree is full!" << endl;
        return -1;
    }
    tree[nodeCount] = {name, isFolder, {}, 0};
    return nodeCount++;
}

// Function to add a child to a parent node
void addChild(int parentIndex, int childIndex) {
        tree[parentIndex].children[tree[parentIndex].childCount++] = childIndex;

}

// Recursive function to display the hierarchy
void displayHierarchy(int index, string prefix = "") {
    cout << prefix << "|- " << (tree[index].isFolder ? "[Folder] " : "[File] ") << tree[index].name << endl;
    for (int i = 0; i < tree[index].childCount; ++i) {
        displayHierarchy(tree[index].children[i], prefix + "   ");
    }
}

int main() {
    // Create root folder
    int root = addNode("Root", true);

    // Add folders and files
    int docs = addNode("Documents", true);
    int pics = addNode("Pictures", true);
    int file1 = addNode("Resume.docx", false);
    int file2 = addNode("Photo.jpg", false);

    // Build hierarchy
    addChild(root, docs);
    addChild(root, pics);
    addChild(docs, file1);
    addChild(pics, file2);

    // Display the hierarchy
    cout << "Disk Hierarchy:\n";
    displayHierarchy(root);

    return 0;
}
