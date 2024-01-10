
# File Hash Calculator

## Introduction
This project provides utilities to calculate the hash values of files, implemented in both C and Python. Users can choose from SHA256, SHA512, and MD5 hash algorithms to compute the hash values of their files. The project is available in two versions:
- C Version: Located in the `C` directory.
- Python Version: Located in the `Python` directory.

## Recent Updates
- The Python version has been updated to support multiple hash algorithms, providing more flexibility.
- Added C language implementation for additional performance and efficiency.

## Requirements
### C Version
- Ensure that the OpenSSL library is installed on your system.

### Python Version
- Ensure that Python is installed on your system.

## Installation
### C Version
1. Clone or download the source code to your local system.
2. Navigate to the `C` directory and compile the program using the following command:
   ```
   gcc -o hash hash.c -lcrypto
   ```

### Python Version
1. Clone or download the `hash.py` file from the `Python` directory to your local system.

## Usage
### C Version
Run the compiled program as follows:
```
./hash [algorithm] [file path]
```
Example:
```
./hash SHA256 example.txt example2.txt example3.txt ...
```

### Python Version
Run the script as follows:
```
python hash.py [algorithm] [file path]
```
Example:
```
python hash.py SHA256 example.txt example2.txt example3.txt ...
```

## Supported Algorithms
- SHA256
- SHA512
- MD5

## License
[MIT License](LICENSE)
