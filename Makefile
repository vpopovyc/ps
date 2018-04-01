# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/01 15:31:54 by vpopovyc          #+#    #+#              #
#    Updated: 2018/04/01 15:31:55 by vpopovyc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC = ps

SRCFILENAME := ParticleSystem.cpp CLManager.cpp GLManager.cpp SDLManager.cpp \
				main.cpp

SRC = $(addprefix src/, $(SRCFILENAME))

OBJ = $(SRC:.cpp=.o)

CC = clang++

CCFLAGS = -Wall -Wextra -Werror

PSINC = -Iincludes

FRAMEWORKS = -framework OpenGL -framework OpenCL -framework SDL2

FRMPATH = -F /Library/Frameworks

# -----------------------------------------------------------
# Libraries

# libGLEW

LIBGLEWBIN = libglew/src/lib/libGLEW.a

LIBGLEWINC = libglew/src/include

LIBGLEW = libglew/src/lib

# -----------------------------------------------------------
# Compiler rules

LIBS = -lGLEW

LIBSDIR = -L$(LIBGLEW)

LIBSINC = -I$(LIBGLEWINC)

# -----------------------------------------------------------

all: $(EXEC)

$(EXEC): $(LIBGLEWBIN) $(OBJ)
	$(CC) $(CCFLAGS) $(FRMPATH) $(FRAMEWORKS) $(LIBSDIR) $(LIBS) $(OBJ) -o $(EXEC)

$(LIBGLEWBIN): glew.all

%.o:%.cpp
	$(CC) $(CCFLAGS) $(PSINC) $(LIBSINC) $(FRMPATH) -o $@ -c $<

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(EXEC)

re: fclean all

glew.all:
	@echo  "\x1b[32mlibglew   compiles...\x1b[0m"
	@make -C libglew/src glew.lib.static

glew.clean:
	@make -C libglew/src distclean


.phony: all clean fclean re glew.all glew.clean
