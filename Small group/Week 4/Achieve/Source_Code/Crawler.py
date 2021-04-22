from bs4 import BeautifulSoup  # 网页解析：获取数据       数据拆分
import re  # 正则表达式：文字匹配      数据提炼
import urllib.request, urllib.error  # 指定URL，获取网页数据   爬数据
#import xlwt  # 进行Excel操作
import sqlite3  # 进行SQL数据库操作


def main():
    #找到所需网页地址
    baseurl = "https://movie.douban.com/top250?start="
    # 爬取网页并解析数据
    #askURL("https://movie.douban.com/top250?start=")
    datalist = getData(baseurl)
    # 保存数据
    #savepath = "D:\douban\doubanTOP250.xlsx"  # 保存的路径，定义的名称应和参数名保持一致
    #saveData(datalist, savepath)
    dbpath = "Douban_movie250_third.db"
    saveDataDB(datalist,dbpath)


# 影片详情链接的规则
findLink = re.compile(r'<a href="(.*?)">')  # 正则表达式对象，表示规则，字符串模式   快速锁定到某一部分的规则  r:忽视所有特殊符号的意思
# (.*?)表示有一堆字符 .表示字符  *表示多个

# 影片图片的连接
findImgSrc = re.compile(r'<img.*src="(.*?)" width="100"/>')

# 影片片名
findTitle = re.compile(r'<span class="title">(.*)</span>')

# 找到导演
#findDirector = re.compile(r'导演:(.*)主演:', re.S)  # re.S:忽视换行符

# 找到导演和演员
findDirector = re.compile(r'''<p class="">
                            导演:(.*)<br/>''', re.S)

# 找到年份
findYear = re.compile(r'''<br/>
                            (.*) / .* / .*''', re.S)

# 影片评分
findScore = re.compile(r'<span class="rating_num" property="v:average">(.*)</span>')

# 评价人数
findJudge = re.compile(r'<span>(\d*)人评价</span>')  # (\d*)表示数字

# 找到概况
findInq = re.compile(r'<span class="inq">(.*)</span>')

# 找到国家
findNation = re.compile(r'''<br/>
                            \d* / (.*) / .*
                        </p>''')

# 找到类型
findType = re.compile(r'''<br/>
                            \d* / .* / (.*)
                        </p>''')



def getData(baseurl):
    datalist = []

    # 此处需要获取250个的数据，10页，所以写一个for循环
    for i in range(0, 10):  # 调用获取页面信息的函数：调用10次
        url = baseurl + str(i * 25)
        html = askURL(url)  # 保存获取到的网页源码

        # 开始逐一解析（获得一个网页就解析一次）
        soup = BeautifulSoup(html, "html.parser")  # 用BeautifulSoup解析html这个对象，使用的工具是html.parser

        for item in soup.find_all('div', class_="item"):  # 查找符合要求的字符串，形成列表
            #print(item)
            data = []  # 保存一部电影的所有信息
            item = str(item)  # 变成字符串
            #print(item)
            #break
            # 获取影片详情的连接
            link = re.findall(findLink, item)[0]  # re库用来通过正则表达式查找指定的字符串  [0]表示，找到多个，只要第一个
            #print(link)
            data.append(link)  # 添加链接

            image = re.findall(findImgSrc, item)[0]
            data.append(image)  # 添加图片

            titles = re.findall(findTitle, item)
            if len(titles) == 2:
                Ctitle = titles[0]
                data.append(Ctitle)
                Ftitle = titles[1].replace(" / ","")
                data.append(Ftitle)
            else:
                data.append(titles[0])
                data.append(' ')  #添加片名

            score = re.findall(findScore, item)[0]
            data.append(score)  # 添加分数

            judgenum = re.findall(findJudge, item)[0]
            data.append(judgenum)  # 添加评价人数

            inq = re.findall(findInq, item)
            if len(inq) != 0:
                inq = inq[0]
                data.append(inq)  # 添加概述
            else:
                data.append(' ')

            director = re.findall(findDirector, item)[0].replace(" ","")
            data.append(director)  # 添加导演和演员

            year = re.findall(findYear, item)[0]
            data.append(year)  # 添加年份

            nation = re.findall(findNation, item)
            data.append(nation)  #添加国家

            type = re.findall(findType, item)
            data.append(type)  #添加类型

            datalist.append(data)  #data导入datalist
    #print(datalist)

    return datalist


#  得到指定url的页面内容
def askURL(url):
    # 模拟浏览器头部信息，“骗过”豆瓣向其服务器发出请求
    head = {
        "User-Agent": "Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/75.0.3770.100 Safari/537.36"
    }  #用户代理，告诉豆瓣服务器我们是什么类型的机器——浏览器（实质上是告诉服务器我们能接收什么水平的文件内容）

    request = urllib.request.Request(url, headers = head)
    html = ""

    try:
        response = urllib.request.urlopen(request)  #接收
        html = response.read().decode("utf-8")  #读取（utf-8形式）
        #print(html)
    except urllib.error.URLError as e:
        # 遇到404（浏览器出问题，比如ip被限制）
        if hasattr(e, "code"):
            print(e.code)
        if hasattr(e, "reason"):
            print(e.reason)
    return html


def saveDataDB(datalist,dbpath):
    init_db(dbpath)
    con = sqlite3.connect(dbpath)  # 连接
    cur = con.cursor()  # 获取游标

    for data in datalist:
        for index in range(len(data)):
            data[index] = '"' + str(data[index]) + '"'
        sql = '''
                insert into movie250_third(
                information_link, picture_link, China_name, Foreign_name, score, raters_number, information, director_and_performer, years, nation, type)
                values(%s) ''' %",".join(data)   # 插入数据
        #print(sql)
        cur.execute(sql)  # 执行sql
        con.commit()  # 提交
    cur.close()
    con.close()  # 关闭


def init_db(dbpath):
    sql = '''
        create table movie250_third (
        id integer primary key autoincrement,
        information_link text,
        picture_link text,
        China_name varchar,
        Foreign_name varchar,
        score numeric,
        raters_number numeric,
        information text,        
        years numeric,
        director_and_performer text,
        nation text,
        type text
        )
    '''
    #创建列表
    #print(sql)
    con = sqlite3.connect(dbpath)  # 连接
    cur = con.cursor()  # 获取游标
    cur.execute(sql)  # 执行sql
    con.commit()  # 提交
    con.close()  # 关闭


if __name__ == '__main__':
    main()
    #init_db("Douban_movie250_first.db")
    print("\n\nsuccess!")