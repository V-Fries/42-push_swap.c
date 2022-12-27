NAME =			push_swap

NAME_DEBUG =	push_swap_debug


H_FILES =\
			sort.h

HEADERS =\
			${addprefix includes/, ${H_FILES}}

INCLUDES =\
			-I ${LIB_PUSH_SWAP_PATH}includes/				\
			-I ${LIB_PUSH_SWAP_PATH}libs/libft/includes/	\
			-I includes


SRCS_DIR = srcs/

SRCS =\
			sort_stack/convert_value_to_index.c	\
			sort_stack/divide_stack.c			\
			sort_stack/operate_on_stack.c		\
			sort_stack/reverse_order.c			\
			sort_stack/should_be_pushed.c		\
			sort_stack/sort_stack.c				\
\
			main.c


TEST_DIR = test/

SRCS_TEST =\
				includes/sort.h.c


DIR_OBJS = 		build/

TEST_OBJS_DIR = ${DIR_OBJS}test/

OBJS =			${addprefix ${DIR_OBJS},${SRCS:.c=.o}}

OBJS_DEBUG =	${addprefix ${DIR_OBJS},${SRCS:.c=_debug.o}}

OBJS_TEST =		${addprefix ${TEST_OBJS_DIR},${SRCS_TEST:.c=.o}}


FLAGS_NO_O3 = 	-Wall -Wextra -Werror

FLAGS =			${FLAGS_NO_O3} -O3

FLAGS_DEBUG	=	${FLAGS_NO_O3} -g3 -fsanitize=address


LIB_PUSH_SWAP_L =		-L${LIB_PUSH_SWAP_PATH} -l_push_swap

LIB_PUSH_SWAP_L_DEBUG =	-L${LIB_PUSH_SWAP_PATH} -l_push_swap_debug

LIB_PUSH_SWAP_A =		${LIB_PUSH_SWAP_PATH}lib_push_swap.a

LIB_PUSH_SWAP_A_DEBUG =	${LIB_PUSH_SWAP_PATH}lib_push_swap_debug.a

LIB_PUSH_SWAP_PATH =	../libs/push_swap_lib/


SHARED_DEPENDENCIES =	Makefile ${HEADERS}

DEFAULT_DEPENDENCIES =	${LIB_PUSH_SWAP_A}

DEBUG_DEPENDENCIES = 	${LIB_PUSH_SWAP_A_DEBUG}


DEBUG_L =	${LIB_PUSH_SWAP_L_DEBUG}

DEFAULT_L =	${LIB_PUSH_SWAP_L}


RMF =	 				rm -f

MKDIR = 				mkdir -p

MAKE_LIB_PUSH_SWAP =	${MAKE} -C ${LIB_PUSH_SWAP_PATH}


all:			${DIR_OBJS}
				${MAKE_LIB_PUSH_SWAP}
				@${MAKE} ${NAME}

$(NAME):		${OBJS}
				${CC} ${FLAGS} ${INCLUDES}	\
					${DEFAULT_L} ${OBJS} -o ${NAME}

${DIR_OBJS}%.o: ${SRCS_DIR}%.c ${SHARED_DEPENDENCIES} ${DEFAULT_DEPENDENCIES}
				${CC} ${FLAGS} ${INCLUDES} -c $< -o $@

debug:			${DIR_OBJS}
				${MAKE_LIB_PUSH_SWAP} debug
				${MAKE} ${NAME_DEBUG}

${NAME_DEBUG}:	${OBJS_DEBUG}
				${CC} ${FLAGS_DEBUG} ${INCLUDES}	\
					${DEBUG_L} ${OBJS_DEBUG} -o ${NAME_DEBUG}

${DIR_OBJS}%_debug.o: ${SRCS_DIR}%.c ${SHARED_DEPENDENCIES} ${DEBUG_DEPENDENCIES}
					cc ${FLAGS_DEBUG} ${INCLUDES} -c $< -o $@

clean:
				${MAKE_LIB_PUSH_SWAP} clean
				${RMF} ${OBJS} ${OBJS_DEBUG} ${OBJS_TEST}

fclean:			clean
				${MAKE_LIB_PUSH_SWAP} fclean
				${RMF} ${NAME} ${NAME_DEBUG}

re:				fclean
				${MAKE} all

re_debug:		fclean
				${MAKE} debug

both:			all debug

test:			${DIR_OBJS}
				${MAKE_LIB_PUSH_SWAP}
				${MAKE} compile_tests

compile_tests:	${OBJS_TEST}
				@echo "Test compiled"

${TEST_OBJS_DIR}%.o: ${TEST_DIR}%.c ${SHARED_DEPENDENCIES} ${DEFAULT_DEPENDENCIES}
				${CC} ${FLAGS} ${INCLUDES} -c $< -o $@

${DIR_OBJS}: Makefile
				@echo ${OBJS} ${OBJS_TEST} | tr ' ' '\n'\
					| sed 's|\(.*\)/.*|\1|'\
					| sed 's/^/${MKDIR} /'\
					| sh -s
				@# Prints all OBJS. 1 per line
					@# Removes the .o file names
					@# Adds mkdir -p at start of each lines
					@# Executes the script (Creates all folders)

.PHONY:			all debug clean fclean re re_debug both test compile_tests
