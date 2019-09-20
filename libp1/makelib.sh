#!/bin/bash
g++ -fPIC -c CP1.cpp
g++ -shared -o libp1.so CP1.o