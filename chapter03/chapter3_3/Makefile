# 设置变量
SRCS = $(wildcard *.cpp)
NODIR_SRCS = $(notdir $(SRCS))
TARGETS = $(basename $(NODIR_SRCS))
FILE_EXISTS = 1
MOVE_FILES =

all:
	$(foreach t, $(TARGETS), \
		$(if $(wildcard $(WORKDIR)/bin/$t), \
		$(), \
		$(if $(wildcard ./$t), $(eval FILE_EXISTS=1), $(eval FILE_EXISTS=0)) ) )

	$(if $(shell [ $(FILE_EXISTS) -eq 0 ] && echo true), \
		$(foreach c, $(NODIR_SRCS), $(CC) $c $(CFLAGS) $(LIBFLAGS) -o $(basename $c);) )

move:
	$(foreach t, $(TARGETS), \
		$(if $(wildcard $(shell pwd)/$t), $(eval MOVE_FILES+=$t)) )

	$(if $(shell [ ! "$(MOVE_FILES)" = "" ] && echo true), \
		$(shell mv $(MOVE_FILES) $(WORKDIR)/bin) )

clean:
	@for target in $(TARGETS); do \
		if [ -e $$target ]; then \
			rm $$target -rf; \
		fi \
	done