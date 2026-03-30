#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

// ===== Struktur for tre =====
struct BST {
    int value;
    BST* left;
    BST* right;
};

// Lager ny node
BST* GetNyNode(int value) {
    BST* NyNode = new BST();
    NyNode->value = value;
    NyNode->left = NyNode->right = NULL;
    return NyNode;
}

// Setter inn verdi i treet
BST* Insert(BST* root, int value) {
    if (root == NULL) {
        return GetNyNode(value);
    }
    else if (value <= root->value) {
        root->left = Insert(root->left, value);
    }
    else {
        root->right = Insert(root->right, value);
    }
    return root;
}

// Legger alle verdier i en liste
void LeggTilVerdier(BST* root, std::vector<int>& values) {
    if (root == NULL) return;

    values.push_back(root->value);
    LeggTilVerdier(root->left, values);
    LeggTilVerdier(root->right, values);
}

// ===== Main =====
int main() {

    BST* root = NULL;

    // Lager treet
    root = Insert(root, 8);
    root = Insert(root, 3);
    root = Insert(root, 1);
    root = Insert(root, 6);
    root = Insert(root, 4);
    root = Insert(root, 7);
    root = Insert(root, 10);
    root = Insert(root, 14);
    root = Insert(root, 13);

    // Lager liste med verdier fra treet
    std::vector<int> values;
    LeggTilVerdier(root, values);

    // Gjør random klar
    srand(time(0));

    // Velger tilfeldig tall fra treet
    int secret = values[rand() % values.size()];

    int guess;

    std::cout << "Gjett et tall fra treet!\n";

    // Spill-løkke
    while (true) {
        std::cin >> guess;

        if (guess == secret) {
            std::cout << "Riktig!\n";
            break;
        }
        else if (guess < secret) {
            std::cout << "Større\n";
        }
        else {
            std::cout << "Mindre\n";
        }
    }

    return 0;
}
