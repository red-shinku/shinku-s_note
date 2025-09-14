# 从任意长度的可迭代对象中分解元素
# *表达式，这里提取出中间的元素们
def drop_first_last(grades):
    first, *middle, last = grades
    return avg(middle)

def avg(datas):
    return sum(datas) / len(datas)

userinput = input()

#列表推导式
grades = [ int(x) for x in userinput.split(',') ]
print(drop_first_last(grades))


