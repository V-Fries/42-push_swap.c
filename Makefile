NAME =				push_swap

NAME_DEBUG =		${NAME}_debug

PUSH_SWAP_PATH =	push_swap_/

MAKE_PUSH_SWAP =	make -C ${PUSH_SWAP_PATH}


NAME_CHECKER =			checker

NAME_CHECKER_DEBUG =	${NAME_CHECKER}_debug

CHECKER_PATH =		checker_/

MAKE_CHECKER =		make -C ${CHECKER_PATH}


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


.PHONY:	all clean fclean re test
