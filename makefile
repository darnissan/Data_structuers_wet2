GPP=g++
PROJ_FILES_PATH=.
TESTS_DIR=./UnitTests
O_FILES_DIR=$(TESTS_DIR)/OFiles
EXEC=WorldCupUnitTester
TESTS_INCLUDED_FILE=worldcup23a2.h $(TESTS_DIR)/catch.hpp
OBJS=$(O_FILES_DIR)/UnitTests.o $(O_FILES_DIR)/Team.o $(O_FILES_DIR)/Player.o $(O_FILES_DIR)/TeamAndAbilities.o $(O_FILES_DIR)/worldcup23a2.o # UPDATE HERE ALL THE O FILES YOU CREATED BELOW
DEBUG_FLAG= -g # can add -g
COMP_FLAG=--std=c++11 -Wall -Werror -pedantic-errors $(DEBUG_FLAG)

$(EXEC) : $(OBJS)
	$(GPP) $(COMP_FLAG) $(OBJS) -o $@

$(O_FILES_DIR)/UnitTests.o : $(TESTS_DIR)/UnitTests.cpp
	@mkdir -p $(O_FILES_DIR)
	$(GPP) -c $(COMP_FLAG) $(TESTS_DIR)/UnitTests.cpp -o $@

 # UPDATE FROM HERE



$(O_FILES_DIR)/Team.o : Team.cpp Team.h Player.h ReversedTree.h
	@mkdir -p $(O_FILES_DIR)
	$(GPP) -c $(COMP_FLAG) Team.cpp -o $@

$(O_FILES_DIR)/Player.o : Player.cpp Player.h ReversedTree.h
	@mkdir -p $(O_FILES_DIR)
	$(GPP) -c $(COMP_FLAG) Player.cpp -o $@

$(O_FILES_DIR)/TeamAndAbilities.o : TeamAndAbilities.cpp TeamAndAbilities.h RankTree.h
	@mkdir -p $(O_FILES_DIR)
	$(GPP) -c $(COMP_FLAG) TeamAndAbilities.cpp -o $@


$(O_FILES_DIR)/worldcup23a2.o : worldcup23a2.cpp worldcup23a2.h wet2util.h AvlTree.h Team.h Player.h TeamAndAbilities.cpp TeamAndAbilities.h HashTable.h RankTree.h  BiDirectionList.h DisjointSet.h  ReversedTree.h
	@mkdir -p $(O_FILES_DIR)
	$(GPP) -c $(COMP_FLAG) worldcup23a2.cpp -o $@
	
 # UNTIL HERE
	

.PHONY: clean
clean:
	rm -f $(OBJS) $(EXEC)