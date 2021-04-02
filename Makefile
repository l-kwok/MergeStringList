SANFLAGS += -fsanitize=address
CXXFLAGS += -Wall -g -std=c++2a -pedantic $(SANFLAGS)
LDFLAGS += $(SANFLAGS)
main:	main.o
	$(CXX) -o $@ $^ $(LDFLAGS)
.phony: clean
clean:
	$(RM) main *.o