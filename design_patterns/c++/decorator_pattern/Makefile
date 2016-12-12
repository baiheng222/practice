#include makeinclude


CXX                 =g++
CC                  =gcc
AR                  =ar
RANLIB              =ranlib
TARGET              =x86
CXXFLAGS            =-Wall  -fsigned-char -O2 -c


#UICOMPILE = -I$(PREFIX)/include
#UILINK =-L$(FL_LIB_DIR) 

EXENAME := builder_pattern
SRCS := $(wildcard *.cpp)
OBJS := $(patsubst %.cpp, %.o, $(SRCS))
DEPS := $(patsubst %.cpp, %.d, $(SRCS))

all:$(EXENAME)

$(EXENAME):$(DEPS) $(OBJS)
	@echo Linking and building $@ ... 
	@$(CXX) -o $(EXENAME) $(OBJS)
	@echo All jobs done.

%.d:%.cpp
	@echo Making dependency of $@ ...
	@$(CXX) -M $(CXXFLAGS) $< > $@
	@$(CXX) -M $(CXXFLAGS) $< | sed s/\\.o/.d/ >> $@

%.o:%.cpp
	@echo Compiling $@ ...
	@$(CXX) $(CXXFLAGS) $<
clean:
	@echo Deleting tmp file ...
	@-rm core* $(EXENAME) $(DEPS) $(OBJS) *~

depend:$(DEPS)
	@echo Dependencies are now up-to-date.

install:
	strip $(EXENAME)
	cp -f $(EXENAME) /tmp

-include $(DEPS)
