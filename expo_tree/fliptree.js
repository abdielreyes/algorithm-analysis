class Node {
  constructor(data) {
    this.data = data;
    this.left = this.right = null;
  }
}

function flipBinaryTree(root) {
  if (root == null) return root;
  if (root.left == null && root.right == null) return root;

  let flippedRoot = flipBinaryTree(root.left);

  root.left.left = root.right;
  root.left.right = root;
  root.left = root.right = null;
  return flippedRoot;
}

function printInOrder(root) {
  if (root == null) return;

  let q = [];
  q.push(root);
  while (true) {
    let nodeCount = q.length;
    if (nodeCount == 0) break;

    while (nodeCount > 0) {
      let node = q.shift();
      console.log(node.data + " ");
      if (node.left != null) q.push(node.left);
      if (node.right != null) q.push(node.right);
      nodeCount--;
    }
  }
}

let root = new Node(1);
root.left = new Node(2);
root.right = new Node(3);
root.right.left = new Node(4);
root.right.right = new Node(5);
console.log("In order");
printInOrder(root);
root = flipBinaryTree(root);
console.log("Flippped in order")
printInOrder(root);
