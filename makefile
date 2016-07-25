
CC='g++'
CCFLAGS=$(shell perl -MExtUtils::Embed -e ccopts)
LD='g++'
LDFLAGS=$(shell perl -MExtUtils::Embed -e ldopts)
CRYPTOCESAROBJS= CryptoCesar.o arquivo.o dirtools.o mensagem.o dicionario.o
EXECS= CryptoCesar

.c.o:
	$(CC) $(CCFLAGS) -c $<


all: $(EXECS)

CryptoCesar: $(CRYPTOCESAROBJS)
	$(LD) -o $@ $(CRYPTOCESAROBJS) $(LDFLAGS) -Wall

