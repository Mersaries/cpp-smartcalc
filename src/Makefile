CXX = g++
CXX_FLAGS = -std=c++17
EFLAGS = -Wall -Werror -Wextra
TFLAGS = -lgtest -lgtest_main
MFLAGS = -fsanitize=address
DEBUG = -g
SRC_FILES = sources/Model.cc
TEST_FILES = tests/test_model.cc

.PHONY:
	all install uninstall dvi dist tests clean gcov_report valgrind build check_style fix_style

all: clean tests

build: clean
	cmake -B build -S . && cmake --build build

install: build
	mkdir ~/Desktop/SmartCalc_v2.0
	cp ./build/s21_smartcalc ~/Desktop/SmartCalc_v2.0/s21_smartcalc
	cp ./README.html ~/Desktop/SmartCalc_v2.0/README.html
	make clean

uninstall:
	rm -rf ~/Desktop/SmartCalc_v2.0

dvi:
	open README.html

dist:
	mkdir SmartCalc_v2.0
	mkdir SmartCalc_v2.0/src
	cp -r headers -r sources -r design -r tests Makefile README.html CMakeLists.txt SmartCalc_v2.0/src
	tar -cvzf SmartCalc_v2.0.tar SmartCalc_v2.0/
	mv SmartCalc_v2.0.tar ~/Desktop/SmartCalc_v2.0.tar
	rm -rf SmartCalc_v2.0


tests: clean
	${CXX} ${CXX_FLAGS} ${EFLAGS} ${DEBUG} ${SRC_FILES} ${TEST_FILES} -o test ${MFLAGS} ${TFLAGS}
	./test

clean:
	rm -rf *.a *.o test *.css coverage*.html gcov_report *.gcno *.gcda .clang-format build SmartCalc_v2.0

gcov_report: clean
	$(CXX) $(EFLAGS) ${SRC_FILES} --coverage -g -O0 $(TEST_FILES) -o gcov_report $(TFLAGS)
	./gcov_report
	gcovr
	gcovr --filter sources/ --exclude-throw-branches --html-details coverage.html
	open coverage.html

valgrind: clean
	${CXX} ${CXX_FLAGS} ${EFLAGS} ${DEBUG} ${SRC_FILES} ${TEST_FILES} -o test ${MFLAGS} ${TFLAGS}
	valgrind --leak-check=full -s test

check_style:
	cp ../materials/linters/.clang-format .
	clang-format -n tests/*.cc headers/*.h *.h *.cc sources/*.cc sources/*.h

fix_style:
	cp ../materials/linters/.clang-format .
	clang-format -i tests/*.cc headers/*.h *.h *.cc sources/*.cc sources/*.h