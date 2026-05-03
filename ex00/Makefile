# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/03 11:15:51 by jkovacev          #+#    #+#              #
#    Updated: 2026/05/03 13:19:54 by jkovacev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = clap_trap

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp \
	ClapTrap.hpp \
	ClapTrap.cpp

OBJDIR = objects
OBJS = $(SRCS:%.cpp=$(OBJDIR)/%.o)

DEPS = ClapTrap.hpp

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: %.cpp $(DEPS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re