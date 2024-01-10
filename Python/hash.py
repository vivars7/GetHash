import hashlib
import sys

def getHash(input_file, algorithm):
    try:
        with open(input_file, 'rb') as f:
            data = f.read()

        if algorithm == "SHA256":
            hash_result = hashlib.sha256(data).hexdigest().upper()
        elif algorithm == "SHA512":
            hash_result = hashlib.sha512(data).hexdigest().upper()
        elif algorithm == "MD5":
            hash_result = hashlib.md5(data).hexdigest().upper()
        else:
            raise ValueError("Unsupported algorithm")

        return hash_result
    except Exception as e:
        return f"Error: {e}"

def getHashs(args):
    algorithm = args[1]
    files = args[2:]

    print("-----------------------------------------------------------------------------")
    for file in files:
        print("File path : " + file)
        print(getHash(file, algorithm))
        print("-----------------------------------------------------------------------------")

if __name__ == '__main__':
    if len(sys.argv) < 3:
        print("Invalid arguments. Usage : hash.py [algorithm] [target file path] [target file path]...")
    else:
        getHashs(sys.argv)