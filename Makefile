build:
	$(MAKE) -C ./mySimpleComputer
	$(MAKE) -C ./console build
run: build
	./console/pr01.out

clean:
	$(MAKE) -C ./mySimpleComputer clean
	$(MAKE) -C ./console clean