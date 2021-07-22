#include<stdlib.h>
#include<stdio.h>

typedef struct Node {
	int num;
	struct Node* l_ptr;
	struct Node* r_ptr;
} Node;

Node initTree() {
	Node* root = (Node*) malloc(sizeof(Node)) ;
	return *root;
}

int root(Node* nd) {
	return nd->num == -1;
}

Node createNode(int elem, Node* left, Node* right) {
	Node nd;
	nd.num = elem;
	if(left == NULL || right == NULL) {
		nd.l_ptr = (Node*) malloc(sizeof(Node));
		nd.r_ptr = (Node*) malloc(sizeof(Node));
	} else if (right == NULL) {
		nd.r_ptr = (Node*) malloc(sizeof(Node));
		nd.l_ptr = left;
	} else if (left == NULL) {
		nd.r_ptr = right;
		nd.l_ptr = (Node*) malloc(sizeof(Node));
	} else {
		nd.l_ptr = left;
		nd.r_ptr = right;
	}
	return nd;
}

int leafNode(Node* node) {
	return node->l_ptr == NULL && node->r_ptr == NULL;
}

void inOrderTraversal(Node* tree, int** elements) {
	if (!leafNode(tree)) {
		inOrderTraversal(tree->r_ptr, elements);
		printf("%d\n", tree->num);
		*(elements++) = &tree->num;
		inOrderTraversal(tree->l_ptr, elements);
	}
}

Node* search(Node* tree, int elem) {
	if (leafNode(tree) || tree->num == elem) {
		return tree;
	} else if(tree->l_ptr->num < elem) {
		return search(tree->r_ptr, elem);
	} else {
		return search(tree->l_ptr, elem);
	}
}

Node* minimum(Node* tree) {
	if (!leafNode(tree)) {
		return minimum(tree->l_ptr);
	}
	return tree;
}

Node* maximum(Node* tree) {
	if (tree->r_ptr != NULL) {
		return maximum(tree->r_ptr);
	}
	return tree;
}

void insert(Node* tree, Node* new) {
	if (leafNode(tree)) {
		*tree = *new;
	} else if (tree->num < new->num) {
		insert(tree->r_ptr, new);
	} else if (tree->num > new->num) {
		insert(tree->l_ptr, new);
	}
}

void transplant(Node* tree, Node* subtree1, Node* subtree2) {
	if (leafNode(subtree1)) {
		tree = subtree2;
	} else if (subtree1 == tree->l_ptr) {
		tree->l_ptr = subtree2;
	} else {
		tree->r_ptr = subtree2;
	}
}

/* TODO implement deletion procedure
 * void delete(Node* tree, Node* node) {
	if (node->l_ptr == NULL) {
		transplant(tree, node, node->r_ptr);
	} else if(node->r_ptr == NULL) {
		transplant(tree, node, node->l_ptr);
	} else {
		Node* min = minimum(node->r_ptr);

		if (min != node->r_ptr) {
			transplant(tree, min, min->right);
			Node minCopy = *min;
			min->right = node->right;
			min->
		}

		transplant(tree, node, min);
		min */

Node createTree(int elements[], int elementCount) {
	Node rootNode = initTree();
	for(int i = 0; i < elementCount; i++) {
		Node newNode = createNode(elements[i], NULL, NULL);
		insert(&rootNode, &newNode);
	}
	return rootNode;
}

/* int main(void) {
	int elements[] = {17,62,5,3,8,4,9};
	int** traversed = (int**) malloc(sizeof(int*));
	Node myTree = createTree(elements, 7);
	inOrderTraversal(&myTree, traversed);
	return 0;
} */
