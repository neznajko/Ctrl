NAME = Ctrl
SORS = ${NAME}.java
FLGS = -g
LDIR = lib
GOAL = ${LDIR}/${NAME}.class

.PHONY: clean run

${GOAL}: ${SORS}
	javac -d ${LDIR} ${FLGS} $<

clean:
	${RM} ${wildcard */*.class}

run:
	@java -cp ${LDIR} ${NAME} ${ARGS}
