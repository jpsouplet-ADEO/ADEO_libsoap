bin_PROGRAMS=xsd2c

INCLUDES=$(LIBXML_CFLAGS)
x_LDFLAG=$(LIBXML_LIBS)

xsd2c_SOURCES=tr.o Enumeration.o util.o obj.o formatter.o xsd2c.o main.o
xsd2c_LDFLAGS=$(x_LDFLAG)


# repertoires de l'application
RACINE=/home2/lm/bertrand/soaptest
OBJ=$(RACINE)/obj
BIN=$(RACINE)/bin
SRC=$(RACINE)/sources

CONFIG_BIN_SOAP=/home2/lm/bertrand/lib/bin/csoap-config

#LIBS=`$(CONFIG_BIN_SOAP) --libs`
#CFLAGS=`$(CONFIG_BIN_SOAP) --cflags`

SRC_LIB=/home2/lm/bertrand/lib/lib

LIBS=-Kthread -L/home2/lm/bertrand/lib/lib $(SRC_LIB)/libnanohttp.so $(SRC_LIB)/libcsoap.so $(SRC_LIB)/libxml2.so -lm -lsocket -lnsl  
CFLAGS=-I/home2/lm/bertrand/lib/include/libcsoap-1.1 -I/home2/lm/bertrand/lib/include/nanohttp-1.1 -I/home2/lm/bertrand/lib/include/libxml2


DEBUG=yes
CC=cc

EXEC=$(bin_PROGRAMS)

all: $(EXEC)


xsd2c: $(xsd2c_SOURCES)
	$(CC) -g -o xsd2c $(xsd2c_SOURCES)  $(LIBS)
	
soaptest.o:$(xsd2c_SOURCES)
	cd $(OBJ) ;	$(CC) -c $(SRC)/soaptest.c $(CFLAGS)


tr.o:tr.c 
	$(CC) -c tr.c $(CFLAGS)
	
Enumeration.o:Enumeration.c 
	$(CC) -c Enumeration.c $(CFLAGS)
	
util.o:util.c 
	$(CC) -c util.c $(CFLAGS)
	
obj.o:obj.c 
	$(CC) -c obj.c $(CFLAGS)
	
formatter.o:formatter.c
	$(CC) -c formatter.c $(CFLAGS)
	
xsd2c.o:xsd2c.c
	$(CC) -c xsd2c.c $(CFLAGS)
	
main.o:main.c
	$(CC) -c main.c $(CFLAGS)
	
clean:
	rm -rf *.o 
	
cleanall:clean
	rm -rf $(EXEC) 
