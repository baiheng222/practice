cmake_minimum_required(VERSION 2.6)
project (LINKLIST)
set (SRC_LIST linklist.c)
include_directories (../lib)
link_directories("/home/baiheng222/study/practice/datastruct/The_Classic_Algorithm_Fundamental_of_C_C++/chapter2/lib/")
#link_libraries("/home/baiheng222/study/practice/datastruct/The_Classic_Algorithm_Fundamental_of_C_C++/chapter2/lib/libmylogger.a")
add_executable (linklist ${SRC_LIST})

target_link_libraries(linklist mylogger) 
#使用target_link_libraries时，要指定link_directoried,并且，target_link_libraries要放在add_executable后面；
#使用link_libraries,直接指定要链接的库的全路径，要放在add_executable前面
