build:
	$(MAKE) -C ./mySimpleComputer
	$(MAKE) -C ./myTerm
	$(MAKE) -C ./myBigChars
	$(MAKE) -C ./console build
	

run: build
	./console/console.out

clean:
	$(MAKE) -C ./mySimpleComputer clean
	$(MAKE) -C ./myTerm clean
	$(MAKE) -C ./myBigChars clean
	$(MAKE) -C ./console clean