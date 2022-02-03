import hashlib
import sys

def getHash(input_file):
    try:
        f = open(input_file, 'rb')
        data = f.read()
        f.close()
        return hashlib.sha256(data).hexdigest().upper()
    except Exception as e:
        print("Target file is invalid.", e)

def getHashs(args):
    del args[0]
    print("-----------------------------------------------------------------------------")
    for arg in args:
        print("File path : " + arg)
        print(getHash(str(arg)))
        print("-----------------------------------------------------------------------------")

if __name__ == '__main__':
    if len(sys.argv) < 2:
        print("Invalid arguments. Usage : hash [target file path] [target file path]...")
    getHashs(sys.argv)