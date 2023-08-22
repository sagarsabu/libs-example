.PHONY: all libs app

all: libs app

libs:
	+make -C libs

app:
	+make -C app
