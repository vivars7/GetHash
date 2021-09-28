import hashlib
import sys

def getHash(input_file):
    try:
        f = open(input_file, 'rb')
        data = f.read()
        f.close()
        return hashlib.sha256(data).hexdigest().upper()
    except Exception as e:
        print("대상 파일이 잘못되었습니다.", e)

def getHashs(args):
    del args[0]
    print("-----------------------------------------------------------------------------")
    for arg in args:
        print("TARGET FILE PATH : " + arg)
        print(getHash(str(arg)))
        print("-----------------------------------------------------------------------------")

if __name__ == '__main__':
    if len(sys.argv) < 2:
        print("매개변수가 부족합니다. 사용방법 : hash [대상파일명] [대상파일명]...")
    getHashs(sys.argv)