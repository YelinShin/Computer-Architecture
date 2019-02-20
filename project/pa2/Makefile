PROGRAMS = count

CC = gcc
CFLAGS = -Wall

%: %.c %.h
	$(CC) $(CFLAGS) -o $@ $<

.PHONY: clean

all: $(PROGRAMS)

clean:
	@rm -f *.o $(PROGRAMS)
