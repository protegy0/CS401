# Define the compiler and flags
CXX = g++
CXXFLAGS = -Wall 

# Define the source directories
SRCDIR = src
INCDIR = include

# Define the object and executable directories
OBJDIR = obj
BINDIR = bin

# Get the list of source files
SOURCES = $(wildcard $(SRCDIR)/*.cpp)

# Create a list of object files
OBJECTS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SOURCES))

# Define the executable name
TARGET = main

# Default rule: build the executable
all: $(BINDIR)/$(TARGET)

# Compile object files
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@

# Link object files to create the executable
$(BINDIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(BINDIR)
	$(CXX) $(OBJECTS) -o $(BINDIR)/$(TARGET)

# Clean rule: remove object files and the executable
clean:
	rm -rf $(OBJDIR) $(BINDIR)

run: ${BINDIR}/${TARGET}
	./${BINDIR}/${TARGET}

.PHONY: all clean