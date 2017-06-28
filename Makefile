comp=gcc -std=c99 -Wall

path=bin
obj=	\
	$(path)/List.o

all : check_bin $(path)/libList.a

$(path)/libList.a : $(obj)
	ar rc $(path)/libList.a $(obj)
	ranlib $(path)/libList.a

$(path)/%.o : %.c
	$(comp) -c $< -o $@

check_bin :
	@ if [ ! -d $(path) ]; then mkdir $(path); fi

clean :
	rm -rf $(path)
