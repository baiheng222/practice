#! /bin/bash
if [ -e a.out ]; then 
   echo "a.out exist"
elif [ -e hello.cpp ]; then
   echo "hello.cpp exist , a.out not exist"
else
   echo "fuck!"
fi
