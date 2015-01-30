SRCDIR       =  parse
CXXFLAGS	 =  -O2 -g -Wall -fmessage-length=0
SOURCES	    :=  $(shell find $(SRCDIR) -name '*.cpp')
OBJECTS	    :=  $(SOURCES:%.cpp=%.o)
LDFLAGS		 =  
TARGET		 =  lib$(SRCDIR).a

all: $(TARGET)

$(TARGET): $(OBJECTS)
	ar rvs $(TARGET) $(OBJECTS)

%.o: $(SRCDIR)/%.cpp 
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -c -o $@ $<
	
clean:
	rm -f $(OBJECTS) $(TARGET)