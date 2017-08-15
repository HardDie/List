ifndef V
	QUIET_CC       = @echo ' ' CC '     ' $@;
	QUIET_AR       = @echo ' ' AR '     ' $@;
	QUIET_RAN      = @echo ' ' RAN '    ' $@;
	QUIET_BUILT_IN = @echo ' ' BUILTIN '' $@;
	QUIET_CLEAN    = @echo ' ' CLEAN '  ' $<;
endif

CC = cc
CFLAGS = -std=c99
RM = rm -f
AR = ar

path=bin
obj= \
	$(path)/List.o

all : check_bin $(path)/libList.a

$(path)/libList.a : $(obj)
	$(QUIET_AR)$(AR) rc $(path)/libList.a $(obj)
	$(QUIET_RAN)ranlib $(path)/libList.a

$(path)/%.o : %.c
	$(QUIET_CC)$(CC) $(CFLAGS) -c $< -o $@

check_bin :
	@ if [ ! -d $(path) ]; then mkdir $(path); fi

clean : $(path)
	$(QUIET_CLEAN)$(RM) -r $(path)
