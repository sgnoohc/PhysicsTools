include Makefile.arch

#
# stuff to make
#
SOURCES=$(wildcard *.cc)
OBJECTS=$(SOURCES:.cc=.o)
LIB=PhysicsTools.so

#
# how to make it
#

$(LIB): $(OBJECTS)
	$(LD) $(LDFLAGS) $(SOFLAGS) $(OBJECTS) $(ROOTLIBS) -lTMVA -lEG -lGenVector -lXMLIO -lMLP -lTreePlayer -o $@

%.o:	%.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

#
# target to build
# likelihood id library
#

all: $(LIB)
clean:
	rm -f *.o \
	rm -f *.d \
	rm -f *.so \

testclean:
	rm -f test_C.* test_C_*
