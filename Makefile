NAME =				push_swap

NAME_DEBUG =		${NAME}_debug

PUSH_SWAP_PATH =	push_swap_/

MAKE_PUSH_SWAP =	make -C ${PUSH_SWAP_PATH}

RMF =	 			rm -f

all: ${NAME}

${NAME}:
		${MAKE_PUSH_SWAP}
		cp ${PUSH_SWAP_PATH}${NAME} .

debug:
		${MAKE_PUSH_SWAP}
		cp ${PUSH_SWAP_PATH}${NAME_DEBUG} .

clean:
		${MAKE_PUSH_SWAP} clean

fclean:
		${MAKE_PUSH_SWAP} fclean
		${RMF} ${NAME} ${NAME_DEBUG}

re:		fclean
		${MAKE} all
