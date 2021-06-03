from ctypes import cdll
import os

p = os.getcwd() + '/clib.so'
f = cdll.LoadLibrary(p)
f.run_()
