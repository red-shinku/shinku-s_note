from collections import deque

# 带yield的生成器函数：
# 运行该函数返回一个生成器对象，里面保存了函数体、局部变量、状态
# 之后通过对该对象显式或隐式调用next()，每次返回yield之后的内容
# 能暂停的函数。

def search(lines,pattern,history=5):
    previous_lines = deque(maxlen=history)
    for line in lines:
        if pattern in line:
            yield line, previous_lines
        previous_lines.append(line)

if __name__ == '__main__':
    with open('file/somefile.txt') as f:
        for line, prevlines in search(f, 'python', 5):
            for pline in prevlines:
                print(pline, end='')
            print(line, end='')
            print('-'*20)