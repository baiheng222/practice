1、所有的目录编译都采用cmake来生成makefile并编译
2、所有的目录中的源码都可以单独编译，编译时需要在目录中新建一个目录，在这个新建的目录中执行cmake
比如：需要编译linklist中的源码，在linklist目录中执行：
mkdir build
cd build
cmake ../
make
3、顶层目录中的CMakeLists.txt可以构建编译所有的子目录
