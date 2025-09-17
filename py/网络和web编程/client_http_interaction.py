from urllib import request, parse
import json

url = 'http://httpbin.org/get'

# 请求参数
parms = { 
    'name1': 'value1',
    'name2': 'value2'
}

# 转成url查询字符串格式
querystring = parse.urlencode(parms)
u = request.urlopen(url + '?' + querystring)

# 返回字节数据
resp = u.read()

print(resp)