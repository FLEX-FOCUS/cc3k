CXX = g++
CXXFLAGS = -Wall -MMD 
EXEC = cc3k
OBJECTS = main.o Display.o Character.o Player.o Game.o Level.o First.o YoooWoody.o Jasper.o Dragon.o Drow.o Dwarf.o Elf.o Enemy.o Fifth.o Fourth.o Goblin.o Gold.o Halfling.o Human.o Item.o Merchant.o Orc.o Potion.o Second.o Shade.o Third.o Troll.o Vampire.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -lncurses -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
