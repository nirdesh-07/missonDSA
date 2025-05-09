class Node:
    def __init__(self, info): 
        self.info = info  
        self.left = None  
        self.right = None 
        self.level = None 

    def __str__(self):
        return str(self.info) 

class BinarySearchTree:
    def __init__(self): 
        self.root = None

    def create(self, val):  
        if self.root == None:
            self.root = Node(val)
        else:
            current = self.root
         
            while True:
                if val < current.info:
                    if current.left:
                        current = current.left
                    else:
                        current.left = Node(val)
                        break
                elif val > current.info:
                    if current.right:
                        current = current.right
                    else:
                        current.right = Node(val)
                        break
                else:
                    break

"""
Node is defined as
self.left (the left child of the node)
self.right (the right child of the node)
self.info (the value of the node)
"""
def topView(root, side=0):
    #Write your code here
    # Initialize the level
    this_level = [(root, 0)]
    scores = {}
    while this_level:
        # Basically iterate over the nodes on a single level
        for _ in range(len(this_level)):
            node, score = this_level.pop(0)
            # Skip empty nodes
            if not node:
                continue
            # Store the score if it's a new one!
            if score not in scores:
                scores[score] = node.info
            # Add the node children to the next level
            this_level.extend(
                [(node.left, score - 1),
                (node.right, score + 1)])

    # Sort the scores and print their values 
    # (By default the sort is on the tuple first element: the score)
    for _, value in sorted(list(scores.items())):
        print(value, end=' ')



tree = BinarySearchTree()
t = int(input())

arr = list(map(int, input().split()))

for i in range(t):
    tree.create(arr[i])

topView(tree.root)