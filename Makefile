all: step1 step2 step3 step4

step1:
	make -C step1-sequential

step2:
	make -C step2-parallelized

step3:
	make -C step3-multiserver
	make copy_binary -C step3-multiserver

step4:
	make -C step4-multiserver+parallelized
	make copy_binary -C step4-multiserver+parallelized

clean:
	make clean -C step1-sequential
	make clean -C step2-parallelized
	make clean -C step3-multiserver
	make clean -C step4-multiserver+parallelized
