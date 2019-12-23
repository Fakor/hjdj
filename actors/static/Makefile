INCLUDE_DIR=include
CC=g++
CFLAGS=-Wall -std=c++1z -Iinclude

_OBJECTS=easylogging/easylogging++.o $\

_DEPS=Receiver.h $\
      Sender.h $\
      easylogging/easylogging++.h

DEPS=$(patsubst %,$(INCLUDE_DIR)/%,$(_DEPS))

ODIR=obj
OBJECTS=$(patsubst %,$(ODIR)/%,$(_OBJECTS))

TARGET_FOLDER=lib
TARGET=$(TARGET_FOLDER)/libhjdj.a

FOLDERS=$(TARGET_FOLDER) $(ODIR)

$(shell mkdir -p $(FOLDERS))

all: $(TARGET)

$(ODIR)/%.o: src/%.cpp $(DEPS)
	mkdir -p `dirname $@`
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJECTS)
	rm -f $(TARGET)
	ar -r -s $(TARGET) $(OBJECTS)

$(ODIR):
	mkdir -p $(ODIR)

cleanall: clean

clean:
	find $(ODIR) -type f -name "*.o" -delete
	rm -f $(TARGET)
