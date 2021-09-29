# This is the default target, which will be built when 
# you invoke make
.PHONY: all
all: conways

# This rule tells make how to build conways from main.cpp
conways: main.cpp
	g++ -O2 -std=c++17 -stdlib=libc++ -o conways *.cpp

# This rule tells make to copy hello to the binaries subdirectory,
# creating it if necessary
.PHONY: install
install:
	mkdir -p binaries
	cp -p conways binaries

# This rule tells make to delete conways and conways.o
.PHONY: clean 
clean:
	rm -f conways