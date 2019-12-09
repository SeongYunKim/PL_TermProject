default:
	flex main.l
	bison -dv main.y
	gcc list.c lex.yy.c main.tab.c -o PL_TermProject
