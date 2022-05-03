# cpp_datastructures
Python module with a collection of datastructures written in c++

REQURIEMENTS
Python3.10 or higher

INSTALLATION
Copy the cstruct.so file to the python lib folder
In examples python3.10 is used, however "3.10" can be replaced with any later version
For linux: /usr/lib/python3.10
Windows: C:\Program Files\Python3.10\Lib\site packages
Mac: /Library/Python/3.10/site-packages
If none of the paths worked run path_identify.py

BUILDING LIBRARY FOR EARLIER VERSIONS (Linux)
The build commands in the Makefile can be rewritten to use an earlier version of python
Several c++ libraries have to be installed prior to recompilation: boost.python, gmp, ssl, and crypto
To change the version of python simply change the PYTHON_VIRSION tag in the Makefile and execute "make" command in the directory of the project
