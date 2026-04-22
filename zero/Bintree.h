#ifndef ED2_BINTREE_H
#define ED2_BINTREE_H

#include <stdbool.h>

typedef struct arvre Arvore;
typedef struct no TNO;

/**
 * Allocates memory for a new TNO structure, initializes its attributes,
 * and sets its index.
 *
 * @param x A double pointer to a TNO structure. The function allocates and
 *          assigns a newly created TNO to the memory location pointed
 *          to by this parameter.
 * @param y An integer value used to initialize the index attribute of the
 *          newly created TNO structure.
 * @return A boolean value indicating whether the operation was successful.
 *         Returns true (1) if memory allocation succeeds, and false (0)
 *         otherwise.
 */
bool no_createnfill(TNO** x, int y);

/**
 * Creates a new binary tree by allocating memory for an Arvore structure
 * and initializing its attributes.
 *
 * @return A pointer to the newly created Arvore structure if memory
 *         allocation succeeds. Returns NULL if memory allocation fails.
 */
Arvore* tree_create();

/**
 * Performs a left rotation on the binary tree node pointed to by the given pointer,
 * updating the structure to ensure proper balancing when a right-heavy imbalance is detected.
 *
 * @param x A double pointer to the root node of the tree or subtree to be rotated.
 *          The function modifies this pointer to point to the new root node after
 *          the rotation is completed.
 * @param h A pointer to a boolean flag indicating whether the height of the tree
 *          may have changed. If not NULL, the function sets this value to false
 *          if a height change does not occur.
 */
void case1_giroesquerda(TNO** x, bool* h);

/**
 * Performs a right rotation on a binary tree's node to adjust its balance
 * and structure.
 *
 * @param x A double pointer to the node (TNO) where the rotation will occur.
 *          The pointer is used to modify the structure of the tree during
 *          the rotation process.
 * @param h An integer value representing additional contextual information
 *          that may influence the operation; its purpose depends on the
 *          specific implementation logic.
 */
void case2_girodireita(TNO** x, int h);

/**
 * Searches for a node with the specified value in the binary tree and prints its details.
 * If the value is not found or the tree is null, appropriate messages are displayed.
 *
 * @param x A pointer to the binary tree (of type Arvore) where the search will be performed.
 *          This parameter represents the root structure of the binary tree.
 * @param y An integer value to be searched for within the binary tree.
 *          The function locates the node with this index and prints its details.
 */
void printspecificno(Arvore* x, int y);

/**
 * Performs an in-order traversal of a binary tree, printing the nodes
 * in the specified order.
 *
 * @param x A pointer to an `Arvore` structure representing the binary
 *          tree to be traversed. If the pointer is NULL, the function
 *          returns immediately without performing any operations.
 */
void printtreeinorder(Arvore* x);

/**
 * Prints the nodes of a binary tree in post-order traversal.
 *
 * This function traverses the binary tree associated with the given Arvore
 * structure in post-order (left subtree, right subtree, root) and prints
 * the nodes in that order. The printing of each node is performed by an
 * internal helper function that handles individual node formatting and output.
 *
 * @param x A pointer to an Arvore structure representing the binary tree
 *          to be traversed and printed. If the tree is NULL, the function
 *          performs no operation.
 */
void printtreeposorder(Arvore* x);

/**
 * Prints the elements of a binary tree in pre-order traversal.
 *
 * This function initiates a pre-order traversal of the binary tree
 * represented by the given `Arvore` structure, starting from its root node.
 * It internally uses a helper function to recursively traverse and print
 * the tree nodes in the pre-order sequence (root, left, right).
 *
 * @param x A pointer to an `Arvore` structure representing the binary tree
 *          to be traversed. If the pointer is `NULL`, the function performs
 *          no operation.
 */
void printtreepreorder(Arvore* x);

/**
 * Converts a character representing a digit into its corresponding integer value.
 *
 * @param c The character to be converted. It is expected to be a character
 *          between '0' and '9'.
 * @return The integer value of the input character, obtained by subtracting
 *         the ASCII value of '0' from the ASCII value of the input character.
 */
int chartoint(char c);

/**
 * Builds a binary tree from a string representation and returns the root node.
 * The string should follow a specific format where nodes are enclosed
 * in parentheses, and child nodes are recursively nested.
 * Empty nodes are represented by `()` in the string.
 *
 * @param x A character pointer to the input string, which contains the
 *          serialized representation of the tree.
 * @param atual A pointer to an integer that tracks the current position
 *              in the input string as the tree is being built. This value
 *              is updated throughout the function's execution.
 * @return A pointer to the root node of the constructed binary tree.
 *         Returns NULL if memory allocation fails or the input string
 *         does not represent a valid tree structure.
 */
TNO* stringtotree(char *x, int *atual);

/**
 * Traverses the tree in level-order (breadth-first) and prints the values
 * of its nodes.
 *
 * @param x A pointer to the tree structure whose nodes will be traversed
 *          and printed. The traversal begins from the root node of the tree.
 */
void arvorepornivel(Arvore* x);

/**
 * Creates a new tree structure, constructs its root node from a string,
 * and initializes the tree.
 *
 * @param buffer A pointer to a character array containing serialized data
 *               that will be converted into the tree structure.
 * @param atual A pointer to an integer that tracks the current position
 *              within the buffer during the tree construction process.
 *              This value is updated as the tree is built.
 * @return A pointer to the newly created tree (Arvore), or NULL if memory
 *         allocation for the tree fails.
 */
Arvore* createnfillstringtotree(char *buffer, int *atual);

/**
 * Calculates the height of a binary tree rooted at the given node.
 *
 * @param x A pointer to the root node of the binary tree. If the pointer
 *          is NULL, the height of the tree is considered zero. Otherwise,
 *          the function recursively computes the height based on the
 *          structure of the left and right subtrees.
 * @return An integer representing the height of the binary tree. The height
 *         is the number of nodes along the longest path from the given node
 *         to a leaf.
 */
int alturano(TNO* x);

/**
 * Finds and prints the Lowest Common Ancestor (LCA) of two nodes in a binary tree.
 *
 * @param x A pointer to a tree structure representing the binary tree.
 *          The function operates on the root of this tree.
 * @param p An integer representing the value of the first node for which
 *          the LCA is to be determined.
 * @param q An integer representing the value of the second node for which
 *          the LCA is to be determined.
 */
void printlca(Arvore* x, int p, int q);

/**
 * Calculates the sum of values within a specified interval [p, q] in a binary tree.
 *
 * @param x A pointer to the binary tree structure containing the tree nodes.
 * @param p An integer representing the lower bound of the interval.
 * @param q An integer representing the upper bound of the interval.
 * @return The sum of the values within the interval [p, q] present in the tree.
 */
int somadeintervaloarvoe(Arvore* x, int p, int q);

#endif
