CXX=g++

CXX_FLAGS=-O3 -Wall -std=c++11 \
	`pythia8-config --cxxflags` \
	`HepMC3-config --cppflags`

LD_FLAGS=`pythia8-config --libs` \
	`HepMC3-config --libs`

main:
	$(CXX) $(CXX_FLAGS) $(LD_FLAGS) -o main main.cc
