#---------------------------------------------------------------

from collections import Counter # 序列中元素出现的次数

names = ["shinku", "shinku", "shinku", "kotori", "kotori", "kotori", "kotori", "komari", "komari", 
        "setsumi", "setsumi", "shizuru", "lucia", "chihaya", "taichi", "kutarou"]

name_counts = Counter(names)
print(f'名字频率最高 { name_counts.most_common(3) }', end= '\n')
# Counter()返回的对象可以做数学运算

#---------------------------------------------------------------

 # 切片与其重命名
items = [0, 1, 2, 3, 4, 5, 6, 7, 8]
print(f'使用切片[2:4] { items[2: 4] }', end='\n')
a = slice(2, 4)
print(f'使用切片名a { items[a] }', end='\n')

#---------------------------------------------------------------

from collections import namedtuple # 为元组内每个元素命名

# 该函数返回具有命名字段的元组子类对象
Student = namedtuple('Student', ['name', 'clas', 'id'])
stu = Student('Maek', 5, 529)
print(f'{ stu.name } 他在 { stu.clas } 班', end='\n')
stu = [ Student('romeo', 3, 342), Student('julia', 3, 341)]


#---------------------------------------------------------------

# 从任意长度的可迭代对象中分解元素
# *表达式，这里提取出中间的元素们
def drop_first_last(grades):
    first, *middle, last = grades
    return avg(middle)

def avg(datas):
    return sum(datas) / len(datas)

print("输入成绩们求平均：")
userinput = input()

#---------------------------------------------------------------

numbers = [1, 2, 3, 2, 4, 5, 6, 7 ,5 ,7, 2, 4, 0]

#列表推导式
grades = [ int(x) for x in userinput.split(',') ]
print(drop_first_last(grades))

#生成器表达式
gen_num = ( x for x in numbers if x > 5) #返回生成器对象，每次next输出大于5的数
print('循环使用生成器输出： ')
for x in gen_num:
    print(x, end='  ')

#---------------------------------------------------------------