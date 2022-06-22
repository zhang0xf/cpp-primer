# 设置变量
SRCS = $(wildcard *.cpp)
NODIR_SRCS = $(notdir $(SRCS))
TARGETS = $(basename $(NODIR_SRCS))

.PHONY:all clean

all:
	@# 注释:for关键字不能使用函数,如:basename
	$(foreach src, $(NODIR_SRCS),\
		$(CC) $(src) $(CFLAGS) $(LIBFLAGS) -o $(basename $(src)); \
	)
	@mv $(TARGETS) $(WORKDIR)/bin

clean:
	@for target in $(TARGETS); do \
		if [ -e $$target ]; then \
			rm $$target -rf; \
		fi \
	done