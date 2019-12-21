INCLUDE_DIR=include
CC=g++
CFLAGS=-Wall -std=c++1z -Iinclude

_OBJECTS=Receiver.o $\
	 Sender.o

_DEPS=Receiver.h $\
      Sender.h $\

DEPS=$(patsubst %,$(INCLUDE_DIR)/%,$(_DEPS))

ODIR=obj
OBJECTS=$(patsubst %,$(ODIR)/%,$(_OBJECTS))

TARGET_FOLDER=lib
TARGET=$(TARGET_FOLDER)/libhjdj.a

FOLDERS=$(TARGET_FOLDER) $(ODIR)

$(shell mkdir -p $(FOLDERS))

all: $(TARGET)

$(ODIR)/%.o: src/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJECTS)
	rm -f $(TARGET)
	ar -r -s $(TARGET) $(OBJECTS)

$(ODIR):
	mkdir -p $(ODIR)

cleanall: clean

clean:
	rm -f $(ODIR)/*.o $(TARGET)
