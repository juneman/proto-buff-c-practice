.PHONY: all clean


#-------------------------
CC=gcc
CFLAGS= -lprotobuf-c

#------------------
TARGET=player

#----------------
all: $(TARGET)

premake:
	protoc-c -I=. --c_out=. player.proto	

OBJECTS=player.pb-c.o player.o

$(filter %.o,$(OBJECTS)): %.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

player.pb-c.c: player.proto
	protoc-c -I=. --c_out=. $^

$(TARGET): player.pb-c.o player.o
	gcc $(CFLAGS)  $^  -o $@

clean:
	rm -f *.o $(TARGET) *.pb-c.* 
