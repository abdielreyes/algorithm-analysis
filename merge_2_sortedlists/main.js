class Node {
  constructor(d) {
    this.data = d;
    this.next = null;
  }
}

class LinkedList {
  constructor() {
    this.head = null;
  }

  addToTheLast(node) {
    if (this.head == null) {
      this.head = node;
    } else {
      let temp = this.head;
      while (temp.next != null) temp = temp.next;
      temp.next = node;
    }
  }

  printList() {
    let temp = this.head;
    while (temp != null) {
      console.log(temp.data + "")
      temp = temp.next;
    }
    
  }
}

function sortedMerge(headA, headB) {
  let fakeNode = new Node(0);

  let tail = fakeNode;
  while (true) {
    if (headA == null) {
      tail.next = headB;
      break;
    }
    if (headB == null) {
      tail.next = headA;
      break;
    }

    if (headA.data <= headB.data) {
      tail.next = headA;
      headA = headA.next;
    } else {
      tail.next = headB;
      headB = headB.next;
    }

    tail = tail.next;
  }
  return fakeNode.next;
}

let llist1 = new LinkedList();
let llist2 = new LinkedList();

llist1.addToTheLast(new Node(5));
llist1.addToTheLast(new Node(10));
llist1.addToTheLast(new Node(15));

llist2.addToTheLast(new Node(2));
llist2.addToTheLast(new Node(3));
llist2.addToTheLast(new Node(20));

console.log("List 1: ")
llist1.printList();
console.log("List 2: ")
llist2.printList();

llist1.head = sortedMerge(llist1.head, llist2.head);
console.log("Merged Linked List is:");
llist1.printList();
