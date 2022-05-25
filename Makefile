default: all


all:
	make -C original all

coremark:
	make -C coremark all

clean:
	make -C original clean
	make -C coremark clean
