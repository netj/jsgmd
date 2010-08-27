EXEC = jsgmd24 jsgmd54 jsgmd80 jsgmd110 jsgmd224 jsgmd198
DOC = doc/jsgmd.pdf
SCRIPT = batch.sh data.sh log.sh plotlog.sh run.sh summary-all.sh summary.sh monitor.sh

ifdef DEBUG
CFLAGS_ += -DDEBUG -g --no-inline
SINGLETHREAD = yes
else
CFLAGS_ += -O2
endif

ifdef SINGLETHREAD
CFLAGS_ += -DSINGLETHREAD
else
CFLAGS_ += -pthread
endif

CC = gcc $(CFLAGS_) $(CFLAGS) -lm -o

all: $(EXEC)

jsgmd24: jsgmd.c
	$(CC) $@ $< -DA=2 -DB=3  -DT=60
jsgmd54: jsgmd.c
	$(CC) $@ $< -DA=3 -DB=5  -DT=300
jsgmd80: jsgmd.c
	$(CC) $@ $< -DA=3 -DB=6  -DT=900
jsgmd110: jsgmd.c
	$(CC) $@ $< -DA=3 -DB=7  -DT=1800
jsgmd224: jsgmd.c
	$(CC) $@ $< -DA=3 -DB=10 -DT=7200
jsgmd198: jsgmd.c
	$(CC) $@ $< -DA=1 -DB=9  -DT=7200

clean:
	rm -f $(EXEC) $(DOC)
	latexmk -c -pdf $(DOC:%.pdf=%.tex)

doc: $(DOC)
.SUFFIXES:
.SUFFIXES: .tex .pdf
.tex.pdf:
	cd $(<D); latexmk -pdf $(<F)

dist: all $(DOC)
	zip -r tmp/jsgmd.zip  Makefile jsgmd.c $(SCRIPT) $(EXEC) $(DOC)

