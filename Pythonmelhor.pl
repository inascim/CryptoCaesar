use warnings;

use strict;


sub code{
    my ($mensagem, $senha, $tamanho) = @_;
    my @charsMensagem = split("", $mensagem);
    my @charsSenha = split("", $senha);
    my $contador=0;

    foreach (@charsMensagem){

        #Expandir depois esse regex para incuir outros caracteres
        if (/[a-zA-Z]/){
            for (my $i='A',my $i==@charsSenha[$contador % $tamanho],my $i++){
                ++$_;
            }
        $contador++;
        }
    }

    return (@charsMensagem);
}

my $c= "abacaxi";
my $v= "senha";
my $lenght= 5;
print code($c,$v, $lenght), "\n";
