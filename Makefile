CFLAGS := -Wall -Werror -g

BINS := swapcontext_self swapcontext_other
all: $(BINS)

swapcontext_self: swapcontext_self.o
swapcontext_other: swapcontext_other.o

swapcontext_self.o: swapcontext_self.c
	$(CC) -c -o $@ $^ $(CFLAGS) -DSWAP_SAME_CONTEXT

swapcontext_other.o: swapcontext_self.c
	$(CC) -c -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o $~ $(BINS)
