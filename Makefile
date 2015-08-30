CC=gcc
CFLAGS=-Wall -Wextra -g -O3
LDFLAGS=
SRCFILES=$(wildcard *.c)
OBJFILES=$(SRCFILES:.c=.o)
DEPFILES=$(SRCFILES:.c=.d)
TARGET=rand_test
.PHONY: all clean

all: $(TARGET)

-include $(DEPFILES)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) $(OBJFILES) -o $(TARGET) $(LDFLAGS)

%.o: %.cc Makefile
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

clean:
	-@rm -f $(TARGET) $(OBJFILES) $(DEPFILES)

#  gprof main gmon.out > prof_output
profile: $(OBJFILES)
	 $(CC) $(CFLAGS) -pg $(OBJFILES) -o $(TARGET) $(LDFLAGS)

print-%: ; @echo $*=$($*)
