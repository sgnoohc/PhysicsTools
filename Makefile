all:
	g++ -g -O2 -Wall -fPIC -Wshadow -Woverloaded-virtual -pthread -std=c++11 -Wno-deprecated-declarations -m64 -I/cvmfs/cms.cern.ch/slc6_amd64_gcc530/cms/cmssw/CMSSW_8_0_6/external/slc6_amd64_gcc530/bin/../../../../../../lcg/root/6.06.00-ikhhed3/include -o Particle.so -shared Particle.cc

clean:
	rm -f Particle.so test_C.* test_C_*
