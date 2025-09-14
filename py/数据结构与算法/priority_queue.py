# heapq模块提供了堆队列算法（是最小堆）
# heapq.heappush(heap, item) item加入heap
# heapq.heappop(heap) 弹出最小元素
# heapq.heapify(x) 将列表x转成堆
# heap.heappushpop(heap, item) 添加后弹出，更高效
# heap.heapreplace(heap, item) 弹出后添加

import heapq

# 利用元组的比较规则实现自定义优先级队列
class PriorityQueue:

    def __init__(self):
        self._queue = []
        self._index = 0

    def push(self, item, priority):
        heapq.heappush(self._queue, (-priority, self._index, item))
        self._index += 1

    def pop(self):
        return heapq.heappop(self._queue)[-1]

# -priority处理优先级，_index处理优先级相同时的次序

class Item:

    def __init__(self,name):
        self.name = name
    
    def __repr__(self):
        return 'Item({!r})'.format(self.name)
    
object1 = Item('magic_crystal')
object2 = Item('space_stone')
object3 = Item('book')

q = PriorityQueue()
q.push(object1,7)
q.push(object2,6)
q.push(object3,5)

print(q.pop())
print(q.pop())
print(q.pop())
