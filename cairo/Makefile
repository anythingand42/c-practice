PROGS=cairo-demo cairo-spline cairo-knockout

# I'd like to put a bunch of compiler-specific warning flags here, but
# I don't know a good way to choose the right flags based on the
# compiler in use.
#
# So, for now, if you want more warnings, set them in CFLAGS before
# calling make. For example, for gcc:
#
# CFLAGS="-Wall -Wpointer-arith -Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations -Wnested-externs -fno-strict-aliasing" make

MYCFLAGS=`pkg-config --cflags cairo`
MYLDFLAGS=`pkg-config --libs cairo x11`

all: $(PROGS)

%.o: %.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) ${MYCFLAGS} $< -o $@

%: %.c
	$(CC) $^ -o $@ $(CFLAGS) $(CPPFLAGS) ${MYCFLAGS} ${MYLDFLAGS}

clean:
	rm -f $(PROGS) *.o


