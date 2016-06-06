comp=gcc -std=c99 -Wall

lib=-lList
path=bin
pathlib=lib

obj=	\
	$(path)/main.o

libobj=	\
	$(path)/List.o

all : $(pathlib)/libList.a $(path)/main

$(path)/main : $(obj) $(pathlib)/libList.a
	$(comp) $(obj) -o $(path)/main -L$(pathlib) $(lib)

$(pathlib)/libList.a : $(libobj)
	ar rc $(pathlib)/libList.a $(libobj)
	ranlib $(pathlib)/libList.a

$(path)/%.o : %.c
	$(comp) -c $< -o $@

clean :
	rm -rf $(path)/* $(pathlib)/*
