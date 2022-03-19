## +++ DEFAULT MAKE OUTPUT +++ :
## Set defaut 'make' rule to run if no argument is given
.PHONY: default
default: all ;

all: d1 d2 d3 d5

clean: d1-clean d2-clean d3-clean d5-clean

d1:
	make -C ./Day-01/cpp

d2:
	make -C ./Day-02

d3:
	make -C ./Day-03

d5:
	make -C ./Day-05

# run make clean for each day
d1-clean:
	make -C ./Day-01/cpp clean

d2-clean:
	make -C ./Day-02 clean

d3-clean:
	make -C ./Day-03 clean

d5-clean:
	make -C ./Day-05 clean
