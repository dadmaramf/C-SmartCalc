CFLAGS = -c -Wall -Werror -Wextra
LDFLAGS = -std=c11 -Wall -Werror -Wextra
SOURCE = $(wildcard s21_*.c)
OBJECTS = $(patsubst %.c, %.o, ${SOURCE})
UNAME_S := $(shell uname -s)
APP = build/view.app
NEW_TEST_SRC=$(wildcard tests/*.c)

ifeq ($(UNAME_S),Linux)
  	OPEN_CMD = xdg-open
	ADD_LIB = -lcheck -lsubunit -lm -lrt -lpthread -D_GNU_SOURCE
endif
ifeq ($(UNAME_S),Darwin)
	OPEN_CMD = open
	ADD_LIB = -lcheck
endif

all: install

s21_calculator.a:
	@gcc $(CFLAGS) $(SOURCE) 
	@ar rcs $@ $(OBJECTS)
	rm -rf *.o
	ranlib s21_calculator.a

test: s21_calculator.a
	@gcc $(LDFLAGS) ${NEW_TEST_SRC}  s21_calculator.a -o test $(ADD_LIB)
	./test


	
install: 
	@mkdir build
	cd build/ && qmake  ../view/view.pro && make
	@mkdir $(HOME)/Desktop/calc/
	@cp -rf $(APP) $(HOME)/Desktop/calc/
	make clean

uninstall:
	@rm -rf $(HOME)/Desktop/calc/


leaks:
	CK_FORK=no leaks --atExit -- ./test

clean:
	-rm -rf build*
	-rm -rf *.o && rm -rf *.gcno
	-rm -rf *.a && rm -rf *.gcda
	-rm -rf *.info && rm -rf *.gcov
	-rm -rf ./gcov_report
	-rm -fr report
	-rm -fr test
	-rm -rf *.txt

style:
	clang-format -style=Google -i *.c *.h */*.c */*.h
	cppcheck --enable=all --suppress=missingIncludeSystem ${SOURCE} ${NEW_TEST_SRC}
	
dvi: 
	  open ../README_RUS.md
	  
dist:
	@mkdir -p ../dist
	@cp -R $(HOME)/Desktop/calc/view.app ../dist
	@cp ../README_RUS.md ../dist && cp ../README.md ../dist
	@cd ../dist && tar cvzf  SmartCalc_v1.0.tgz *
	@cd ../dist && rm -rf view.app README.md README_RUS.md

gcov_report:${SOURCE}
	@gcc --coverage ${SOURCE} ${NEW_TEST_SRC} -o test $(ADD_LIB)
	./test
	@lcov -t "stest" -o s21_test.info -c -d .
	@genhtml -o report s21_test.info
	$(OPEN_CMD) ./report/index.html

.PHONY:	s21_calculator.a test prov valgrind
