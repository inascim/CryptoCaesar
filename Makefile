CC='g++'
CCFLAGS=$(shell perl -MExtUtils::Embed -e ccopts)

LD='g++'
LDFLAGS=$(shell perl -MExtUtils::Embed -e ldopts)


CRYPTORSAOBJS= CryptoRSA.o arquivo.o dirtools.o perlxsi.o mensagem.o dicionario.o

EXECS= CryptoRSA

.c.o:
	$(CC) $(CCFLAGS) -c $<

all: $(EXECS)

CryptoRSA: $(CRYPTORSAOBJS)
	$(LD) -o $@ $(CRYPTORSAOBJS) -Wall $(LDFLAGS)



clean :    
	rm -f *.o $(ALL) 


