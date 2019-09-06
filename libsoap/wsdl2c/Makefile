bin_PROGRAMS=wsdl2c

INCLUDES=$(LIBXML_CFLAGS) -I$(top_srcdir)
wsdl2cl_LDFLAG=$(LIBXML_LIBS)

xsd2c_root= $(top_srcdir)/xsd2c

xsd2c_objs=../xsd2c/util.o \
../xsd2c/formatter.o \
../xsd2c/obj.o \
../xsd2c/xsd2c.o \
../xsd2c/tr.o \
../xsd2c/Enumeration.o

wsdl2c_SOURCES=CallVar.o CallFunc.o CallList.o codewriter.o wsdl2c.o
wsdl2c_LDFLAGS=$(wsdl2cl_LDFLAG) $(xsd2c_objs)


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
CFLAGS=-I/home2/lm/bertrand/lib/include/libcsoap-1.1 -I.. -I/home2/lm/bertrand/lib/include/nanohttp-1.1 -I/home2/lm/bertrand/lib/include/libxml2


DEBUG=yes
CC=cc

EXEC=$(bin_PROGRAMS)

all: $(EXEC)


wsdl2c: $(wsdl2c_SOURCES)
	$(CC) -g -o wsdl2c $(wsdl2c_SOURCES) $(xsd2c_objs) $(LIBS)
	
CallVar.o:CallVar.c
	$(CC) -c CallVar.c $(CFLAGS)
CallFunc.o:CallFunc.c
	$(CC) -c CallFunc.c $(CFLAGS)
CallList.o:CallList.c
	$(CC) -c CallList.c $(CFLAGS)
codewriter.o:codewriter.c
	$(CC) -c codewriter.c $(CFLAGS)
wsdl2c.o:wsdl2c.c
	$(CC) -c wsdl2c.c $(CFLAGS)

clean:
	rm -rf *.o 
	
cleanall:clean
	rm -rf $(EXEC) 
