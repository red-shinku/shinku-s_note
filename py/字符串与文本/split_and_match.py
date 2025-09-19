import re # 匹配、搜索、替换
import unicodedata # 处理unicode字符
import os

sentence = 'I saw the sea today.   I am not afraid anymore.'

# ----------------------------------------------------------------

# 以空格、句号、多个空格分离
senlist = re.split(r'[.\s]\s*', sentence)  
print(senlist)

# ----------------------------------------------------------------

path = '../../cpp'
for fname in os.listdir(path):
    if fname.endswith(('.md', '.h')): # 匹配开头或结尾，返回布尔值
        print(f'{fname}', end='  ')
print(end='\n')

text = 'ShInkU, shinku, SHINKU, oksHiNkU, kotori, KkoTori, SHINku'

text = re.sub('shinku', 'shinku', text, flags=re.IGNORECASE) # 无视大小写匹配，并替换成小写
print(f'{text}', end='\n')

# ----------------------------------------------------------------

chaos_str = 'he\rll\ro\twor\rld\n'
print(f'混乱的字符：{chaos_str}', end='\n')

# 字符转换表 
remap = {
    ord('\t'): ' ',
    ord('\f'): ' ',
    ord('\r'): None
}
clean_str = chaos_str.translate(remap)
print(f'过滤后的字符：{clean_str}', end='\n')



