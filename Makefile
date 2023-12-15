NAME				:=		miniRT

COMPILER			:=		gcc
FLAGS				:=		-Wextra -Werror -Wall

ADDSAN				:=		-g -fsanitize=address

LIBFT_DIR			:=		libft/
LIBFT_A				:=		$(LIBFT_DIR)libft.a

MLX_DIR				:=		minilibx/
MLX_A				:=		$(MLX_DIR)libmlx.a

LINK_MLX			:=		-lmlx
LINK_MLX_DIR		:=		-Lminilibx

LINK_OPENGL_FW		:=		-framework OpenGL
LINK_APPKIT_FW		:=		-framework AppKit

OBJECT_DIR			:=		objects/
SOURCE_DIR			:=		source/

SOURCE				:=		\
							$(SOURCE_DIR)main.c \

OBJECTS				:=		$(SOURCE:$(SOURCE_DIR)%.c=$(OBJECT_DIR)%.o)

LINK				:=		$(COMPILER) $(FLAGS) -o $(NAME) $(OBJECTS) $(LIBFT_A) $(MLX_A) \
							$(LINK_MLX_DIR) $(LINK_MLX) $(LINK_OPENGL_FW) $(LINK_APPKIT_FW) $(ADDSAN)

all: $(NAME)

$(NAME): $(OBJECT_DIR) $(OBJECTS)
							echo CREATING EXECUTABLE...
							$(LINK)

$(OBJECTS): $(OBJECT_DIR)%.o: $(SOURCE_DIR)%.c
							echo PLEASE STANDBY...
							echo COMPILING OBJECTS...
							$(COMPILER) $(FLAGS) -o $@ -c $<

$(OBJECT_DIR):
							mkdir -p $(OBJECT_DIR)

clean:
							rm -rf $(OBJECT_DIR)
							rm -rf $(NAME).dSYM

fclean: clean
							rm -f $(NAME)

libs:
							echo RECOMPILING LIBRARIES FOR ARCHITECTURE CHANGE...
							make re -C $(LIBFT_DIR)
							make clean -C $(LIBFT_DIR)
							make re -C $(MLX_DIR)
							make clean -C $(MLX_DIR)
							echo READY TO MAKE EXECUTABLE...

							
re: libs fclean all


.PHONY: clean fclean arch_change re
.SILENT:


