STATIC_PATH=static

INCLUDE_DIR_STATIC=$(STATIC_PATH)/include
CC=g++
CFLAGS=-Wall -std=c++1z -I$(INCLUDE_DIR_STATIC)

_OBJECTS_STATIC=easylogging/easylogging++.o $\

_DEPS_STATIC=Receiver.h $\
      Sender.h $\
      easylogging/easylogging++.h

DEPS_STATIC=$(patsubst %,$(INCLUDE_DIR_STATIC)/%,$(_DEPS_STATIC))

ODIR=obj
OBJECTS_STATIC=$(patsubst %,$(ODIR)/%,$(_OBJECTS_STATIC))

TARGET_FOLDER=lib
TARGET=$(TARGET_FOLDER)/libhjdj.a

FOLDERS=$(TARGET_FOLDER) $(ODIR)

$(shell mkdir -p $(FOLDERS))

all: $(TARGET)

$(ODIR)/%.o: $(STATIC_PATH)/src/%.cpp $(DEPS_STATIC)
	mkdir -p `dirname $@`
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJECTS_STATIC)
	rm -f $(TARGET)
	ar -r -s $(TARGET) $(OBJECTS_STATIC)

$(ODIR):
	mkdir -p $(ODIR)

cleanall: clean

clean:
	find $(ODIR) -type f -name "*.o" -delete
	rm -f $(TARGET)
