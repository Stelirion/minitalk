.PHONY:	all clean fclean re fclean_lib fclean_all

# ******** VARIABLES ******** #

# ---- Final Executable --- #

SRV_NAME	=	serveur

CLT_NAME	=	client

LIBFT		=	libft.a

# ---- Directories ---- #

DIR_OBJS	=	.objs/

DIR_SRCS	=	./

DIR_LIBFT	=	libft/

# ---- Files ---- #

HEAD	=	so_long.h

SRV_SRCS	=	srv_main.c

CLT_SRCS	=	clt_main.c

SRV_OBJS	=	${SRV_SRCS:%.c=${DIR_OBJS}%.o}
CLT_OBJS	=	${CLT_SRCS:%.c=${DIR_OBJS}%.o}

INC			=	libft/headers/ft_printf.h libft/headers/get_next_line_bonus.h libft/headers/libft.h

# ---- Compilation ---- #

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

# ---- Commands ---- #

RM		=	rm -rf
MKDIR	=	mkdir -p

# ********* RULES ******** #

all		:	${CLT_NAME} ${SRV_NAME}

# ---- Variables Rules ---- #

${CLT_NAME}	:	${CLT_OBJS} ${addprefix ${DIR_LIBFT}, ${LIBFT}}
			${CC} ${CFLAGS} -o ${CLT_NAME} ${CLT_OBJS} libft/libft.a

$(SRV_NAME)	:	${SRV_OBJS} ${addprefix ${DIR_LIBFT}, ${LIBFT}}
			${CC} ${CFLAGS} -o ${SRV_NAME} ${SRV_OBJS} libft/libft.a

${addprefix ${DIR_LIBFT}, ${LIBFT}}	:
			make ${LIBFT} -C ${DIR_LIBFT}

# ---- Compiled Rules ---- #

${DIR_OBJS}%.o	:	${DIR_SRCS}%.c Makefile $(INC) | ${DIR_OBJS}
					${CC} ${CFLAGS} -o $@ -c $< ${addprefix -I , $(INC)}

${DIR_OBJS}		:
					${MKDIR} ${DIR_OBJS}

# ---- Usual Commands ---- #

clean			:
					${RM} ${DIR_OBJS}
					make clean -C ${DIR_LIBFT}

fclean			:	clean
					${RM} ${CLT_NAME}
					${RM} ${SRV_NAME}
					make fclean -C ${DIR_LIBFT}

re				:	fclean
					${MAKE} all
