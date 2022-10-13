
class Node:
    def __init__(self, parent, number = 0) -> None:
        self.parent = parent
        self.number = number
        self.children = []
    
class k_ary_tree:
    def __init__(self, k: int, d: int) -> None:
        self.c = 0
        self.head = Node(None, self.c)
        self.c += 1
        self.create_children(self.head, d, k)
        
    def create_children(self, current, counter, k):
        if counter >= 0:
            for j in range (k):
                
                current.children.append(Node(current, self.c))
                self.c += 1
            for j in current.children:
                counter -= 1
                self.create_children(j, counter, k)

    def list_representation(self) -> list:
        arr = []
        self.insert_node(arr, self.head)
        return arr
        
    def insert_node(self, arr, node):
        arr.ap
        for ch in node.children:
            arr.append(ch.number)

        for ch in node.children:
            self.insert_node(arr, ch)


tree = k_ary_tree(2, 2)
print(tree.list_representation())
