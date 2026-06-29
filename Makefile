.PHONY: all clean

PROJECTS = "ASCII Art in C" PasGenCheck

all:
	$(MAKE) -C "ASCII Art in C"
	$(MAKE) -C PasGenCheck

clean:
	$(MAKE) -C "ASCII Art in C" clean
	$(MAKE) -C PasGenCheck clean
