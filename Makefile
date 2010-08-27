# Makefile for jsgmd

EXEC = jsgmd24 jsgmd54 jsgmd80 jsgmd110 jsgmd224 jsgmd198
DOC = doc/jsgmd.pdf
SCRIPT = batch.sh data.sh log.sh plotlog.sh run.sh summary-all.sh summary.sh monitor.sh

CFLAGS += -Wall -fnested-functions

ifdef DEBUG
CFLAGS += -DDEBUG -g --no-inline
SINGLETHREAD = yes
else
CFLAGS += -O2
endif

ifdef SINGLETHREAD
CFLAGS += -DSINGLETHREAD
else
CFLAGS += -pthread
endif


.PHONY: all doc clean dist

all: $(EXEC)

jsgmd%:: jsgmd.c
	$(CC) $(CFLAGS) -lm -o $@ $^ $(shell ./jsgmd-config $*)

doc: $(DOC)
.SUFFIXES:
.SUFFIXES: .tex .pdf
.tex.pdf:
	cd $(<D); latexmk -pdf $(<F)


dist: all doc
	zip -r tmp/jsgmd.zip  Makefile jsgmd.c $(SCRIPT) $(EXEC) $(DOC)


clean:
	rm -f $(EXEC)
distclean: clean
	latexmk -C -pdf $(DOC:%.pdf=%.tex)

