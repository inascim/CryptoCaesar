
CC='gcc'
CCFLAGS=$(shell perl -MExtUtils::Embed -e ccopts)
LD=$(shell perl -V::ld:)
LDFLAGS=$(shell perl -MExtUtils::Embed -e ldopts)
CRYPTOCESAROBJS= CryptoCesar.o arquivo.o dirtools.o mensagem.o
EXECS= CryptoCesar

.c.o:
	$(CC) $(CCFLAGS) -c $<


all: $(EXECS)

CryptoCesar: $(CRYPTOCESAROBJS)
	$(LD) -o $@ $(CRYPTOCESAROBJS) $(LDFLAGS) -Wall

