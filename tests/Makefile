CXX       := g++
CXX_FLAGS := -std=c++14 -O2 -I..
SOURCES   := strbin.cc
TARGET    := tests

all: $(SOURCES)
	@echo "Compiling '$(SOURCES)' to '$(TARGET)'...";
	@$(CXX) $(CXX_FLAGS) $^ -o $(TARGET);

clean:
	@echo "Cleaning...";
	@rm $(TARGET);
