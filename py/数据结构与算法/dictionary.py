from collections import defaultdict
from collections import OrderedDict # 有序字典

#创建一个基于表或集合的字典，实现一键多值
#使用defaultdict，自动添加键
dic = defaultdict(set)
dic['key'].add('Little Buster!')
dic['key'].add('Clannad')
dic['key'].add('Rewrite')
dic['key'].add('Summer Pocket')

gamescore = defaultdict(list)
gamescore['Cross Channel'].append(100)
gamescore['Rewrite'].append(95)
gamescore['AIR'].append(86)
gamescore['your diary+'].append(72)
gamescore['Baldr sky Dive'].append(89)

#字典上常见的数据操作只会处理键
#zip()方法反转字典中的键和值
print('-'*20)
print('use zip()')
high = max(zip( gamescore.values(), gamescore.keys() ))
low = min(zip( gamescore.values(), gamescore.keys() ))
print(f'最高分为 {high[1]}  {high[0][0]}分')
print(f'最低分为 {low[1]}  {low[0][0]}分')
print('-'*20)

# key= 参数，在很多依赖比较、排序的函数都支持。其作用在比较前调用key=后的函数，将返回值作为比较依据 
print('use lambda')
high_game = max(gamescore, key= lambda k: gamescore[k])
low_game = min(gamescore, key= lambda k: gamescore[k])
print(f"最高分为 {high_game}  {gamescore[high_game][0]}分")
print(f"最低分为 {low_game}  {gamescore[low_game][0]}分")
print('-'*20)

# OrderDict内部维护了双向链表，保持添加顺序
orderdic = OrderedDict()
orderdic[1] = 'hi'
orderdic[2] = '你好'
orderdic[3] = 'ciao'

#---------------------------------------------------------------

# 查找字典相同点
dicA = { 'x': 1, 'y': 2, 'z': 3, 'j': 3}
dicB = { 'j': 3, 'x': 7, 'y': 1}

    # 只需用keys()，values(), items()方法 进行集合运算 (values方法需要先转化为集合才能运算)
print(f'输出A,B字典相同的键 { dicA.keys() & dicB.keys() }', end="\n")
print(f'输出A,B字典相同的值 { set(dicA.values()) & set(dicB.values()) }', end='\n')
print(f'输出A,B字典相同的内容 { dicA.items() & dicB.items() }', end="\n\n")

    # 这三个方法返回动态视图对象，他是动态更新的
see = dicA.keys()
print(f'更新A字典前：{ see }', end= '\n')
dicA['b'] = 15
print(f'更新A字典后：{ see }', end= '\n')

print('-'*20)