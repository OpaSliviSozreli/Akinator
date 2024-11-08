CXX = g++
SOURCES = main.cpp tree_func.cpp log_file_func.cpp
EXECUTABLE_FILE = akinator
CFLAGS = -b
WARNINGS = -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal \
		   -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs \
		   -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe \
		   -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body \
		   -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op \
		   -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual \
		   -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing \
		   -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla \
		   -D_DEBUG -D_EJUDGE_CLIENT_SIDE

all: akinator

akinator: main.o tree_func.o log_file_func.o
	$(CXX) $(SOURCES) -o $(EXECUTABLE_FILE) $(WARNINGS)

main.o: main.cpp
	$(CXX) main.cpp -c

tree_func.o: tree_func.cpp
	$(CXX) tree_func.cpp -c

log_file_func.o: log_file_func.cpp
	$(CXX) log_file_func.cpp -c