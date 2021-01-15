"""
class Stack(list):
    push = list.append
    pop = list.pop

    def is_empty(self):
        if not self:
            return True
        else:
            return False
"""
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None # 자신과 연결된 다음 Node를 가르킴

class Stack:
    def __init__(self):
        self.head = None

    def init(self):
            self.head = None
    
    def is_empty(self):
        if not self.head:
            return True
        else:
            return False
    
    def push(self, data):
        node = Node(data)
        node.next = self.head # head는 나중에 들어온 node가 된다.
        self.head = node
    
    def pop(self):
        if self.is_empty():
            return None
        result = self.head.data # 현재 head의 data를 반환
        self.head = self.head.next # head를 바꿔줍니다.
        return result
    
    
stack = Stack()#객체 생성
b=0
c=[]
T = int(input())
for j in range(T):
    stack.push(str(input()))
for p in range(T):
    a = stack.pop()
    b = 0
    for i in range(len(a)):
        if a[i] == '(':
                b = b+1
        elif a[i] == ')':
            if b == 0:
                b = b+50
            else:
                b = b-1
    if b == 0:
        c.append(1)
    else:
        c.append(0)
c.reverse()
for i in c:
    if i == 1:
        print("YES")
    else:
        print("NO")
