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
SCENE_DIR			:=		scene/
INIT_DIR			:=		init/
RENDER_DIR			:=		render/
INIT_SOURCE_DIR		:=		$(SOURCE_DIR)$(INIT_DIR)
RENDER_SOURCE_DIR	:=		$(SOURCE_DIR)$(RENDER_DIR)
INIT_OBJ_DIR		:=		$(OBJECT_DIR)$(INIT_DIR)
RENDER_OBJ_DIR		:=		$(OBJECT_DIR)$(RENDER_DIR)

INIT_SOURCE			:=		$(wildcard $(INIT_SOURCE_DIR)*.c)

RENDER_SOURCE		:=		$(wildcard $(RENDER_SOURCE_DIR)*.c) 

SOURCE				:=		\
							$(RENDER_SOURCE) \
							$(INIT_SOURCE) \

OBJECTS				:=		$(SOURCE:$(SOURCE_DIR)%.c=$(OBJECT_DIR)%.o)

LINK				:=		$(COMPILER) $(FLAGS) -o $(NAME) $(OBJECTS) $(LIBFT_A) $(MLX_A) \
							$(LINK_MLX_DIR) $(LINK_MLX) $(LINK_OPENGL_FW) $(LINK_APPKIT_FW) $(ADDSAN)

all:
							echo PLEASE STANDBY...
							make $(NAME)

scene0: all
							./$(NAME) $(SCENE_DIR)scene0.rt

scene1: all
							./$(NAME) $(SCENE_DIR)scene1.rt

scene2: all
							./$(NAME) $(SCENE_DIR)scene2.rt

scene3: all
							./$(NAME) $(SCENE_DIR)scene3.rt

scene4: all
							./$(NAME) $(SCENE_DIR)scene4.rt

$(NAME): $(OBJECT_DIR) $(OBJECTS)
							echo CREATING EXECUTABLE...
							$(LINK)

$(OBJECTS): $(OBJECT_DIR)%.o: $(SOURCE_DIR)%.c
							
							echo 'COMPILING OBJECT ($@)'
							$(COMPILER) $(FLAGS) -o $@ -c $<

$(OBJECT_DIR):
							mkdir -p $(INIT_OBJ_DIR)
							mkdir -p $(RENDER_OBJ_DIR)

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
							echo READY TO MAKE EXECUTABLE...

							
re: libs fclean all

debug:
        @echo "SOURCE: $(SOURCE)"
        @echo "OBJECTS: $(OBJECTS)"


.PHONY: clean fclean libs re
.SILENT:


