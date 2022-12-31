NAME =				push_swap

NAME_DEBUG =		${NAME}_debug

PUSH_SWAP_PATH =	push_swap_/

MAKE_PUSH_SWAP =	make -C ${PUSH_SWAP_PATH}


NAME_CHECKER =			checker

NAME_CHECKER_DEBUG =	${NAME_CHECKER}_debug

CHECKER_PATH =		checker_/

MAKE_CHECKER =		make -C ${CHECKER_PATH}


RUN_INPUT =			"86 41 32 43 46 83 48 64 0 2 80 55 84 56 74 76 61 18 11 39 47 59 50 34 20 70 89 54 19 62 6 75 31 71 38 37 52 82 88 51 4 5 95 17 15 25 63 14 13 81 98 77 66 22 96 24 90 68 8 53 1 94 91 28 45 85 36 93 21 79 10 67 26 97 35 16 99 33 60 57 69 12 29 27 3 87 42 92 65 40 9 23 78 44 72 30 58 73 49 7"


RMF =	 			rm -f


all: ${NAME}

${NAME}:
		${MAKE_PUSH_SWAP}
		cp ${PUSH_SWAP_PATH}${NAME} .

${NAME_DEBUG}:
		${MAKE_PUSH_SWAP} debug
		cp ${PUSH_SWAP_PATH}${NAME_DEBUG} .


${NAME_CHECKER}:
		${MAKE_CHECKER}
		cp ${CHECKER_PATH}${NAME_CHECKER} .

${NAME_CHECKER_DEBUG}:
		${MAKE_CHECKER} debug
		cp ${CHECKER_PATH}${NAME_CHECKER_DEBUG} .

bonus: ${NAME_CHECKER}

clean:
		${MAKE_PUSH_SWAP} clean
		${MAKE_CHECKER} clean

fclean:
		${MAKE_PUSH_SWAP} fclean
		${MAKE_CHECKER} fclean
		${RMF} ${NAME} ${NAME_DEBUG} ${NAME_CHECKER} ${NAME_CHECKER_DEBUG}

re:		fclean
		${MAKE} all

test:
		${MAKE_PUSH_SWAP} test
		${MAKE_CHECKER} test

run:
		${MAKE} ${NAME}
		${MAKE} ${NAME_CHECKER}
		./${NAME} ${RUN_INPUT} | ./${NAME_CHECKER} ${RUN_INPUT} > run.log
		@cat run.log

run_debug:
		${MAKE} ${NAME_DEBUG}
		${MAKE} ${NAME_CHECKER_DEBUG}
		./${NAME_DEBUG} ${RUN_INPUT} | ./${NAME_CHECKER_DEBUG} ${RUN_INPUT} > run.log
		@cat run.log

r_push_swap:
		${MAKE} ${NAME}
		./${NAME} ${RUN_INPUT} > run.log
		@cat run.log


.PHONY:	all clean fclean re test run run_debug r_push_swap ${NAME} ${NAME_DEBUG}	\
		${NAME_CHECKER} ${NAME_CHECKER_DEBUG}
