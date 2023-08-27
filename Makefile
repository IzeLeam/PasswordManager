CC = gcc
CFLAGS = -Wall -Wextra
LDFLAGS = -I include -I "C:/Program Files/OpenSSL/include"
LDLIBS = -L "C:/Program Files/OpenSSL/lib" -lssl -lcrypto

SRCDIR = src
OBJDIR = obj
BINDIR = bin

SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRC))

EXECUTABLE = $(BINDIR)/password_manager

.PHONY: all clean

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ) | $(BINDIR)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) $(LDLIBS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR):
	mkdir $(OBJDIR)

$(BINDIR):
	mkdir $(BINDIR)

clean:
	rmdir /s /q $(OBJDIR) $(BINDIR)
