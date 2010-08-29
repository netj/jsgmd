# Makefile for jsgmd

EXEC = jsgmd-16 jsgmd-24 jsgmd-30 jsgmd-54 jsgmd-80 jsgmd-96 jsgmd-110 jsgmd-198 jsgmd-224
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

jsgmd-%: jsgmd.c
	$(CC) $(CFLAGS) -lm -o $@ $^ $(shell ./jsgmd-config $*)


doc: $(DOC)
.SUFFIXES:
.SUFFIXES: .tex .pdf
.tex.pdf:
	latexmk -cd -pdf $<


dist: all doc
	zip -r tmp/jsgmd.zip  Makefile jsgmd.c $(SCRIPT) $(EXEC) $(DOC)


clean:
	rm -f $(EXEC)
distclean: clean
	latexmk -CA -cd -pdf $(DOC:%.pdf=%.tex)

