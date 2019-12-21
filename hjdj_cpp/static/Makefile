INCLUDE_DIR=include
CC=g++
CFLAGS=-Wall -std=c++1z -Iinclude


ODIR=obj
_OBJECTS=Receiver.o $\
	 Sender.o
OBJECTS=$(patsubst %,$(ODIR)/%,$(_OBJECTS))

TARGET_FOLDER=lib
TARGET=$(TARGET_FOLDER)/libhjdj.a

FOLDERS=$(TARGET_FOLDER) $(ODIR)

all: $(TARGET)

$(ODIR)/%.o: src/%.cpp paths
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJECTS) paths
	rm -f $(TARGET)
	ar -r -s $(TARGET) $(OBJECTS)

paths:
	mkdir -p $(ODIR)
	mkdir -p $(TARGET_FOLDER)

cleanall: clean

clean:
	rm -f $(ODIR)/*.o $(TARGET)
