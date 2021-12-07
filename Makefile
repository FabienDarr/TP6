# Regles
all : tp6-7 exe clean 

#Declaration des variables
USER = darrigrand
HEAD = $(wildcard *.h)
SRC = $(wildcard $(srcdir)*.c)
OBJ = $(subst $(srcdir), $(bindir), $(SRC:.c=.o))
PROG = tp6-7


# Commandes
CC = gcc -Wall -Werror
RM = rm -f $(OBJ)
CP = cp -r $(srcdir)*.c $(savedir)
REST = cp -r $(savedir)*.c $(srcdir)
LFLAGS = -lm


#Declaration des chemins
srcdir = ./src/
bindir = ./bin/
docdir = ./doc/
savedir = ./save/

#Compilation dans .o en un executable
$(PROG) : $(OBJ)
	$(CC) $(OBJ) $(LFLAGS) -o ./bin/$(PROG)

#Compile tous les fichiers .c de ./src/ en .o dans ./bin/
./bin/%.o : ./src/%.c
	$(CC) -c $^ -o $@

#Appele la fonction restore
.PHONY : restore

#Renvoie les fichier de ./save/ dans ./src/
restore :
	$(REST)

#Appele la fonction save
.PHONY : save

#Sauvegarde les fichier de ./src/ dans ./save/
save :
	$(CP)

#Appelle la fonction pour effacer
.PHONY : clean

#Efface les .o
clean :
	$(RM)
#Execute le programme
exe :
	./bin/$(PROG)
