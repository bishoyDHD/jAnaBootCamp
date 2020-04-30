ROOTCFLAGS = $(shell root-config --cflags)
CXXFLAGS   = -fPIC

all: obj testmap libA.so

obj:
	@if [ ! -d obj ]; then mkdir obj; fi

testmap: obj/testmap.o obj/A.o obj/ADict.o
	@echo "Linking $@"
	@g++ $(CXXFLAGS) $^ $(ROOTCFLAGS) -o $@ `root-config --libs`

obj/testmap.o: src/testmap.cxx
	@echo "Compiling $@"
	@g++ -c $(CXXFLAGS) $< $(ROOTCFLAGS) -o $@

libA.so: obj/A.o obj/ADict.o
	@echo "Compiling $@"
	@g++ -shared  $^ -o $@

obj/A.o: src/A.cxx src/A.h
	@echo "Compiling $@"
	@g++ -c $(CXXFLAGS) $< $(ROOTCFLAGS) -o $@

obj/ADict.o: ADict.cxx ADict.h
	@echo "Compiling $@.."
	@g++ -c $(CXXFLAGS) $< $(ROOTCFLAGS) -o $@

ADict.cxx: src/A.h src/ALinkDef.h
	@echo "Generating dictionary $@..."
	@rootcint  -f $@ -c $^

clean:
	@rm -fv obj/*.o testmap ADict.h ADict.cxx libA.so testmap.root
	@find . -name "*~" -exec rm -fv {} \;

backup:
	@tar zcf testmap.tar.gz Makefile src
