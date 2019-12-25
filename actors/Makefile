STATIC_PATH=static

INCLUDE_DIR_STATIC=$(STATIC_PATH)/include
CC=g++
CFLAGS=-Wall -std=c++1z -I$(INCLUDE_DIR_STATIC)

_OBJECTS_STATIC=easylogging/easylogging++.o $\

_DEPS_STATIC=Receiver.h $\
	     Sender.h $\
	     easylogging/easylogging++.h $\
	     hjdj_includes.h

DEPS_STATIC=$(patsubst %,$(INCLUDE_DIR_STATIC)/%,$(_DEPS_STATIC))

ODIR=obj
OBJECTS_STATIC=$(patsubst %,$(ODIR)/%,$(_OBJECTS_STATIC))

HJDJ=hjdj

LIB_FOLDER=lib
LIB=$(LIB_FOLDER)/lib$(HJDJ).a


BIN_DIR=bin

TARGETS_FOLDER=targets

TARGETS_DIR=$(foreach goal,$(MAKECMDGOALS),$(shell find $(TARGETS_FOLDER) -type f -name $(goal).cpp))
$(info $(TARGETS_DIR))
_TARGETS=$(subst $(TARGETS_FOLDER),$(BIN_DIR),$(TARGETS_DIR))
TARGETS=$(subst .cpp,,$(_TARGETS))

FOLDERS=$(LIB_FOLDER) $(ODIR) $(BIN_DIR)

$(shell mkdir -p $(FOLDERS))

all: $(LIB)

$(ODIR)/%.o: $(STATIC_PATH)/src/%.cpp $(DEPS_STATIC)
	mkdir -p `dirname $@`
	$(CC) -c -o $@ $< $(CFLAGS)

$(LIB): $(OBJECTS_STATIC)
	rm -f $(LIB)
	ar -r -s $(LIB) $(OBJECTS_STATIC)

$(ODIR):
	mkdir -p $(ODIR)

%: $(TARGETS_FOLDER)/%.cpp $(LIB)
	$(CC) $^ -o $(BIN_DIR)/$@ $(CFLAGS) -L$(LIB_FOLDER) -l$(HJDJ)

cleanall: clean

clean:
	find $(ODIR) -type f -name "*.o" -delete
	rm -f $(LIB)
	rm -f $(BIN_DIR)/*
