INCLUDE = -I/usr/include/
LIBDIR  = -L/usr/X11R6/lib

CC = g++
COMPILERFLAGS = -Wall -O2
CFLAGS = $(COMPILERFLAGS) $(INCLUDE)
LIBRARIES = -lX11 -lXi -lXmu -lglut -lGL -lGLU -lm

EXECNAME = tmp
EXECDIR = bin
SRCDIR = src
INCDIR = include
OBJDIR = obj
MKDIR = mkdir -p $(@D)
OBJS = $(addprefix $(OBJDIR)/, main.o gl_fun.o draw.o rectangle.o square.o quad.o point.o)

TARGET = $(EXECDIR)/$(EXECNAME)
all: $(TARGET)

$(EXECDIR)/$(EXECNAME): $(OBJS)
	$(MKDIR)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBDIR) $(LIBRARIES)

$(OBJDIR)/main.o: $(SRCDIR)/main.cpp $(OBJDIR)/gl_fun.o
	$(CC) $(CFLAGS) -c $< -o $@ $(LIBDIR) $(LIBRARIES)

$(OBJDIR)/gl_fun.o: $(SRCDIR)/gl_fun.cpp $(OBJDIR)/draw.o
	$(CC) $(CFLAGS) -c $< -o $@ $(LIBDIR) $(LIBRARIES)

$(OBJDIR)/draw.o: $(SRCDIR)/draw.cpp $(INCDIR)/draw.hpp
	$(MKDIR)
	$(CC) $(CFLAGS) -c $< -o $@ $(LIBDIR) $(LIBRARIES)

$(OBJDIR)/rectangle.o: $(SRCDIR)/rectangle.cpp $(INCDIR)/rectangle.hpp $(OBJDIR)/quad.o
	$(CC) $(CFLAGS) -c $< -o $@ $(LIBDIR) $(LIBRARIES)

$(OBJDIR)/square.o: $(SRCDIR)/square.cpp $(INCDIR)/square.hpp $(OBJDIR)/quad.o
	$(CC) $(CFLAGS) -c $< -o $@ $(LIBDIR) $(LIBRARIES)

$(OBJDIR)/quad.o: $(SRCDIR)/quad.cpp $(INCDIR)/quad.hpp $(OBJDIR)/point.o
	$(CC) $(CFLAGS) -c $< -o $@ $(LIBDIR) $(LIBRARIES)

$(OBJDIR)/point.o: $(SRCDIR)/point.cpp $(INCDIR)/point.hpp
	$(CC) $(CFLAGS) -c $< -o $@ $(LIBDIR) $(LIBRARIES)

.PHONY: clean
clean:
	rm -rf $(OBJDIR) $(EXECDIR)
