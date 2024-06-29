#include <iostream>
using namespace std;
class Node {
	public:
    	int key;
    	Node* left;
    	Node* right;
    	int height;
};
// A utility function to get the height of the tree 
int height(Node *node) {
    if (node == NULL)
        return 0;
    return node->height;
}

// A utility function to get maximum of two integers 
int max(int a, int b) {
    return (a > b) ? a : b;
}

/*
Helper function that allocates a new node with the given key and 
NULL left and right pointers.
*/
Node *newNode(int key) {
    Node *node = new Node();
    node->key = key;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1;  // new node is initially added at leaf 
    return node;
}

// A utility function to right rotate subtree rooted with y See the diagram given above. 
Node *rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;
    // Perform rotation 
    x->right = y;
    y->left = T2;
    // Update heights 
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    // return new node
    return x;
}

//A utility function to left rotate subtree rooted with x See the diagram given above. 
Node *leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;
    // Perform rotation 
    y->left = x;
    x->right = T2;
    // Update heights 
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    // return new node
    return y;
}

// Get Balance of node 
int getBalance(Node *node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

/* 
Recursive function to insert a key in the subtree rooted 
with node and returns the new root of the subtree.
*/ 
Node *insert(Node *node, int key) {
    if (node == NULL)
        return (newNode(key));
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    // Equal keys are not allowed in BST 
    else
        return node;
    // Update height
    node->height = 1 + max(height(node->left), height(node->right));
	//Get the balance of this node to check this node became unbalanced
    int balance = getBalance(node);
	// If this node becomes unbalanced, then there are 4 cases
	 
	// Left Left Case 
    if (balance > 1 && key < node->left->key) 
		return rightRotate(node); 

   	// Right Right Case 
	if (balance < -1 && key > node->right->key) 
		return leftRotate(node); 

    // Left Right Case 
	if (balance > 1 && key > node->left->key) { 
		node->left = leftRotate(node->left); 
		return rightRotate(node); 
	} 
	// Right Left Case 
	if (balance < -1 && key < node->right->key) { 
		node->right = rightRotate(node->right); 
		return leftRotate(node); 
	} 
	//return the (unchanged) node pointer
    return node;
}

/*
return the node with minimum key value found in that tree. 
Note that the entire tree does not need to be searched.
*/
Node *min(Node *node) { 
	Node* current = node; 
	//loop down to find the leftmost leaf
	while (current->left != NULL) 
		current = current->left; 
	return current;
}

/* 
Recursive function to delete a node with given key from subtree with 
given root. It returns root of the modified subtree. 
*/
Node *deleteNode(Node *root, int key) {  
	if (root == NULL) 
		return root; 

	// If the key to be deleted is smaller than the root's key, then it lies in left subtree 
	if ( key < root->key ) 
		root->left = deleteNode(root->left, key); 

	// If the key to be deleted is greater than the root's key, then it lies in right subtree 
	else if( key > root->key ) 
		root->right = deleteNode(root->right, key); 
		
	// if key is same as root's key, then This is the node to be deleted 
	else{ 
		// node with only one child or no child 
		if( (root->left == nullptr) ||(root->right == nullptr) ) { 
			Node *temp = root->left ? root->left : root->right; 
			// No child case 
			if (temp == nullptr) { 
				temp = root; 
				root = nullptr; 
			} 
			else // One child case 
			*root = *temp; // Copy the contents of the non-empty child 
			free(temp); 
		} 
		else{ 
			// node with two children: Get the inorder successor (smallest in the right subtree) 
			Node *temp = min(root->right); 

			// Copy the inorder successor's data to this node 
			root->key = temp->key; 

			// Delete the inorder successor 
			root->right = deleteNode(root->right, temp->key); 
		} 
	} 

	// If the tree had only one node then return 
	if (root == nullptr) 
		return root; 

	// Update height of the current node 
	root->height = 1 + max(height(root->left), height(root->right)); 

    //Get the balance of this node to check this node became unbalanced
    int balance = getBalance(root);
	// If this node becomes unbalanced, then there are 4 cases 

	// Left Left Case 
	if (balance > 1 && getBalance(root->left) >= 0) 
		return rightRotate(root); 

	// Left Right Case 
	if (balance > 1 && 	getBalance(root->left) < 0) { 
		root->left = leftRotate(root->left); 
		return rightRotate(root); 
	} 

	// Right Right Case 
	if (balance < -1 && getBalance(root->right) <= 0) 
		return leftRotate(root); 

	// Right Left Case 
	if (balance < -1 && getBalance(root->right) > 0) { 
		root->right = rightRotate(root->right); 
		return leftRotate(root); 
	} 
	return root; 
} 

Node *Search(Node *root,int key){
	if(root == nullptr || root->key == key)
		return root;
	if(key < root->key)
		return Search(root->left,key);
	else
		return Search(root->right,key);
}

// Function to print in-order traversal of the tree
void Inorder(Node* root) {
    if (root != nullptr) {
        Inorder(root->left);
        cout << root->key << " ";
        Inorder(root->right);
    }
}

int main() {
    Node* root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);
    /*
    		 30 
			/ \ 
		   20 40 
		   / \ \ 
		  10 25 50 
	*/
    cout << "Inorder traversal of  the AVL tree is \n";
    Inorder(root);
    root = deleteNode(root,40);
    cout << "\nInorder traversal after delete of 40 \n"; 
	Inorder(root); 
	
	Node *result = Search(root,21);
	if(result != nullptr)
		cout << "\nKey found in the AVL tree" << endl;
	else
		cout << "\nKey not found in AVL tree" << endl;
    return 0;
}