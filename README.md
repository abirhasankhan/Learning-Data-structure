# Learning-Data-structure

This project showcases various data structure implementations I have completed while learning about data structures.

## Splay Tree Implementation in C++

This project is a C++ implementation of a **Splay Tree**, which is a type of self-balancing binary search tree. Splay Trees are designed to keep frequently accessed nodes near the root of the tree, optimizing the time complexity for operations based on usage patterns.

### Features

- **Insert**: Adds a new node to the tree and splays it to the root.
- **Delete**: Removes a node by first splaying it to the root.
- **Traversals**:
  - **Preorder**: Visits nodes in the order: root, left subtree, right subtree.
  - **Inorder**: Visits nodes in the order: left subtree, root, right subtree.
- **Rotations**: Implements left and right rotations to maintain tree balance during splay operations.

### Code Structure

#### Node Class
The `node` class represents each node in the Splay Tree, containing:
- `data`: The value of the node.
- `lchild`: Pointer to the left child.
- `rchild`: Pointer to the right child.
- `next`: Pointer for potential extensions (currently unused).

```cpp
class node {
public:
    int data;
    node* lchild;
    node* rchild;
    node* next;
};
