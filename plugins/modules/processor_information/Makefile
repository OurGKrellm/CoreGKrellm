##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile of the source file
##

ROOT	=			.

SRC_DIR	=			.

CXX		=		g++

NAME	=			../processor_module.so

BUILD	=			$(ROOT)/build

SRC		=		$(SRC_DIR)/entrypoint.cpp \
				$(SRC_DIR)/ProcessorInformation.cpp


CXXFLAGS=			-g -I $(ROOT) -I ../../../inc $(WARN) -std=gnu++17 -fPIC

LDFLAGS	=			-L -lstdc++fs -shared

LIB 	?=			1

TEST	?=			0

DEB 	?=      	0

G		=			-g -D DEBUG

V		?=			@

OBJS	=			$(patsubst $(SRC_DIR)/%.cpp, $(BUILD)/%.o, $(SRC))

#COLOR

GREEN	=			\e[1;32m

WHITE	=			\e[0m

ORANGE	=			\e[1;33m

RED 	=			\e[1;35m

BLUE	=			\e[1;34m

debug:				CXXFLAGS += $(G)

all:				$(NAME)

$(NAME):			$(OBJS)
				$(V)printf "$(GREEN)Compile sources.$(WHITE)\n"
				$(V)$(CXX) -o $(NAME) $(OBJS) $(LDFLAGS)
				$(V)printf "$(GREEN)Linking obj and Libraries.$(WHITE)\n"

debug: fclean echo_d $(NAME)

$(BUILD)/$(NAME):	$(OBJS)
					$(V)printf "$(GREEN)Compile sources.$(WHITE)\n"
					$(V)$(CXX) -o $(BUILD)/$(NAME) $(OBJS) $(LDFLAGS)
					$(V)printf "$(GREEN)Linking obj and Libraries.$(WHITE)\n"

$(BUILD)/%.o:		$(SRC_DIR)/%.cpp
					$(V)mkdir -p $(dir $@)
					$(V)printf "$(BLUE)Compiling [$(GREEN)$(notdir $<)$(BLUE) -> $(RED)$(notdir $@)$(BLUE)]\n$(WHITE)"
					$(V)$(CXX) -o $@ -c $< $(CXXFLAGS) $(LDFLAGS)

clean:
					$(V)rm -rf $(OBJS)
					$(V)printf "$(ORANGE)Removing object files.$(WHITE)\n"

fclean: clean
					$(V)rm -f $(BUILD)/$(NAME)
					$(V)rm -f $(ROOT)/$(NAME)
					$(V)printf "$(ORANGE)Removing binary file.$(WHITE)\n"

re:	fclean
					$(V)make --no-print-directory all

echo_build:
					$(V)printf "$(GREEN)Begin of the build !\n$(ORANGE)Warnings : \n$(WHITE)"

echo_d:
					$(V)printf "$(RED)DEBUG MODE initialized.$(WHITE)\n";

.PHONY: clean fclean debug all re echo_debug buildrepo
