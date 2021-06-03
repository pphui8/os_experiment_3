#!/bin/bash
g++ -o clib.so -shared -fPIC start.cpp
python3 -u start.py
