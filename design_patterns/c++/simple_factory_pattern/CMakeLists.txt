cmake_minimum_required(VERSION 2.6)
project (SIMPLEFACTORYPATTERN)
#set (SRC_LIST )

#允许gdb调试
set(CMAKE_BUILD_TYPE "RELEASE")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")


#添加C++11支持及其他选项
set(CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS} -g -ftest-coverage -fprofile-arcs -Wno-deprecated")
#set(CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS -g -ftest-coverage -fprofile-arcs"})


#添加dict子目录
#add_subdirectory(dict) 


#当前目录下所有源文件赋给DIR_SRCS
AUX_SOURCE_DIRECTORY(. DIR_SRCS) 


## for lib   
#file(GLOB_RECURSE include_HEADES "./*.h")
#file(GLOB_RECURSE test_src "./*.[ch]pp")
#add_library(test_python SHARED ${include_HEADES}
# ${test_src}
#   )
#target_link_libraries(test libface_identify.so)
#生成可执行文件
add_executable(simplefactorypattern ${DIR_SRCS}) 


#添加C++11编译选项,但是只有CMAKE 3.1支持
#target_compile_features(test PRIVATE cxx_range_for)


#添加链接库
#target_link_libraries(test xxx)
#target_link_libraries(test xxx)
#include_directories (../lib)
#link_directories("/home/baiheng222/study/practice/datastruct/The_Classic_Algorithm_Fundamental_of_C_C++/chapter2/lib/")
#link_libraries("/home/baiheng222/study/practice/datastruct/The_Classic_Algorithm_Fundamental_of_C_C++/chapter2/lib/libmylogger.a")

#target_link_libraries(linklist mylogger)
#使用target_link_libraries时，要指定link_directoried,并且，target_link_libraries要放在add_executable后面；
#使用link_libraries,直接指定要链接的库的全路径，要放在add_executable前面

