/*Implement a multiplayer game system that uses an AVL tree data structure to organize and
manage player data efficiently. The multiplayer game supports multiple players participating
simultaneously, and the AVL tree is used to store player information such as player_id and
scores (key, value pair). The system should provide following operation:
1. Player Registration(ADD NODE IN AVL)
2. Leaderboard Display(DISPLAY NODES)
3. Remove player from game(DELETE NODE)*/

#include<iostream>
using namespace std;

class Node
{
    public:
        int player_id,score,height;
        Node* left;
        Node* right;

        Node(int value,int sc){
            player_id=value;
            left=nullptr;
            right=nullptr;
            score=sc;
            height=1;
            }
};

int getheight(Node* node) 
{
    return (node == nullptr) ? 0 : node->height;
}

int balancefactor(Node* node)
{
    return (node == nullptr)  ? 0 : getheight(node->left)-getheight(node->right);
}

Node* RightRotation(Node* y) 
{
    Node* x = y->left;
    Node* T2 = x->right;

    
    x->right = y;
    y->left = T2;

  
    y->height = max(getheight(y->left), getheight(y->right)) + 1;
    x->height = max(getheight(x->left), getheight(x->right)) + 1;

    
    return x;
}


Node* LeftRotation(Node* x) 
{
    Node* y = x->right;
    Node* T2 = y->left;

    
    y->left = x;
    x->right = T2;

    
    x->height = max(getheight(x->left), getheight(x->right)) + 1;
    y->height = max(getheight(y->left), getheight(y->right)) + 1;

    
    return y;
}

Node* insert(Node* node,int player_id,int score)
{
    if(node == nullptr)
    {
        return new Node(player_id,score);
    }
    if(player_id < node->player_id)
    {
        node->left= insert(node->left,player_id,score);
    }
    else if(player_id > node->player_id)
    {
        node->right = insert(node->right,player_id,score);
    }
    else 
    {
        return node;
    }

    node->height = 1 + max(getheight(node->left), getheight(node->right));
    int balance = balancefactor(node);

    //checking the balance factor and rotations
    if (balance >1 && player_id < node->left->player_id)
    {
        return RightRotation(node);
    }
     if (balance <-1 && player_id > node->right->player_id)
    {
        return LeftRotation(node);
    }
     if (balance >1 && player_id < node->left->player_id)
    {
        node->left=LeftRotation(node->left);
        return RightRotation(node);
    }
     if (balance <-1 && player_id > node->right->player_id)
    {
        node->right=RightRotation(node->right);
        return LeftRotation(node);
    }
    return node;
}

void inorder(Node* root) 
{
    if (root != nullptr) 
    {
        inorder(root->left);
        cout << "Player ID :" << root->player_id << " " << "Score :" << root->score << endl;
        inorder(root->right);
    }
}

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current;
}

Node* deleteNode(Node* root, int player_id) {
    if (root == nullptr) {
        return root;
    }

    if (player_id < root->player_id) {
        root->left = deleteNode(root->left, player_id);
    }
    
    else if (player_id > root->player_id) {
        root->right = deleteNode(root->right, player_id);
    }
    
    else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = minValueNode(root->right);

        root->player_id = temp->player_id;
        root->score = temp->score;

        root->right = deleteNode(root->right, temp->player_id);
    }

    
    root->height = 1 + max(getheight(root->left), getheight(root->right));  
    int balance = balancefactor(root); 

    // LL
    if (balance > 1 && balancefactor(root->left) >= 0) {
        return RightRotation(root);
    }

   // RR
    if (balance < -1 && balancefactor(root->right) <= 0) {
        return LeftRotation(root);
    }

   // LR
    if (balance > 1 && balancefactor(root->left) < 0) {
        root->left = LeftRotation(root->left);
        return RightRotation(root);
    }

   // RL
    if (balance < -1 && balancefactor(root->right) > 0) {
        root->right = RightRotation(root->right);
        return LeftRotation(root);
    }

    return root;
}

int main() {
    Node* root = nullptr;

    /* Here Are The Total Players */
    root = insert(root, 1, 100);
    root = insert(root, 2, 200);
    root = insert(root, 3, 50);
    root = insert(root, 4, 150);

    // Display Leaderboard
    cout << "Leaderboard:\n";
    inorder(root);
    
    // Perform Deletion
     root = deleteNode(root, 3);

    // After Deletion 
    cout << "\nUpdated leaderboard:\n";
    inorder(root);

    return 0;
}