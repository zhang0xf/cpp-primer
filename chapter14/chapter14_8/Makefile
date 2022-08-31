CUR_DIRS = $(shell pwd)
MAIN_SRCS = $(wildcard *_main.cpp)
NODIR_MAIN_SRCS = $(notdir $(MAIN_SRCS))
SRCS = $(shell find $(CUR_DIRS) -mindepth 1 -maxdepth 1 -type f -name "*.cpp" | grep -v "_main.cpp")
NODIR_SRCS = $(notdir $(SRCS))
TARGETS = $(basename $(NODIR_MAIN_SRCS))

# ifeq:用于控制make在Makefile看到的内容,不能用于make执行时！

all:
	@#echo $(NODIR_MAIN_SRCS)
	@#echo $(NODIR_SRCS)
	$(foreach s, $(NODIR_MAIN_SRCS), \
		 $(CC) $s $(NODIR_SRCS) $(CFLAGS) $(LIBS) -o $(WORKDIR)/bin/$(basename $s); )

clean:
	$(foreach t, $(TARGETS), \
		$(if $(wildcard $(CUR_DIRS)/$t), $(shell rm $t -rf;)) )
