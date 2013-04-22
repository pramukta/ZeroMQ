MATHDIR = /Applications/Mathematica.app
MATHLINKSDIR = ${MATHDIR}/SystemFiles/Links
MLINKDIR = ${MATHLINKSDIR}/MathLink/DeveloperKit
MATHINCDIR = ${MATHDIR}/SystemFIles/IncludeFiles/C
SYS = MacOSX
CADDSDIR = ${MLINKDIR}/CompilerAdditions

MPREP = ${CADDSDIR}/mprep
CC = /usr/bin/cc
LD = /usr/bin/ld

INCDIRS = -I${CADDSDIR} -I/opt/local/include
LIBDIRS = -L${CADDSDIR} -L/opt/local/lib -F${CADDSDIR}

LDFLAGS = -lc -lzmq -framework Foundation -lMLi3 -lstdc++
EXTRAFLAGS = -macosx_version_min 10.6
objects = connector.o zmq_wrapper.o

all: connector

connector: connector.tm.o ${objects}
	${LD} -o $@ ${EXTRAFLAGS} ${LIBDIRS} ${LDFLAGS} connector.tm.o ${objects} /usr/lib/crt1.o
connector.o: connector.c
	${CC} -c ${INCDIRS} $<
connector.tm.o: connector.tm.c
	${CC} -c ${INCDIRS} $<
connector.tm.c: connector.tm
	${MPREP} $< -o $@
zmq_%.o: zmq_%.c
	${CC} -c ${INCDIRS} $<
clean:
	rm *.o *.tm.c connector