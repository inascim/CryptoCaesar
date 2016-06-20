#Trabalho de Linguagens de programação - 2016/1
# Eduardo Naslausky
# Igor Nascimento
#Professor: Miguel

use warnings;
use strict;

#use File::Basename qw(dirname);
#use Cwd  qw(abs_path);
#use lib dirname(dirname abs_path $0) . '\CryptoCaesar\lib';


use menosmenos qw( menosmenosLetra menosmenosNum );


sub code{
    my ($mensagem, $senha, $tamanho) = @_;
    my @charsMensagem = split("", $mensagem);
    my $lowerSenha= lc($senha);
    my @charsSenha = split("", $lowerSenha);
    my $contador=0;
    foreach (@charsMensagem){
        my $i='a';
        if (/[a-zA-Z0-9]/){
            while($i ne @charsSenha[$contador % $tamanho]){
                ++$_;
                ++$i;
            }
            my @letra = split("",$_);
            $_= $letra[-1];
            $contador++;
            #print $_,"\n";
        }
    }
    return (@charsMensagem);
}


sub decode{
    my ($mensagem, $senha, $tamanho) = @_;
    my @charsMensagem = split("", $mensagem);
    my $lowerSenha= lc($senha);
    my @charsSenha = split("", $lowerSenha);
    my $contador=0;
    foreach (@charsMensagem){
        my $i='a';
        if (/[a-zA-Z]/){
            while($i ne @charsSenha[$contador % $tamanho]){
                #for (my $j=0; $j<25; $j++){#HACK PARA FAZER DECREMENTO, JA QUE PERL NÃO CONSEGUE DECREMENTAR
                #    ++$_;
                #}
                $_=menosmenosLetra($_);
                ++$i;
            }
            my @letra = split("",$_);
            $_= $letra[-1];
            $contador++;
            #print $_,"\n";
        }
		elsif(/[0-9]/){
            while($i ne @charsSenha[$contador % $tamanho]){
                #for (my $j=0; $j<9; $j++){#HACK PARA FAZER DECREMENTO, JA QUE PERL NÃO CONSEGUE DECREMENTAR
                #    ++$_;
                #}
                $_=menosmenosNum($_);
                ++$i;
            }
            my @letra = split("",$_);
            $_= $letra[-1];
            $contador++;
		}
    }
    return (@charsMensagem);
}
#my @alfabeto=('a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z');
#sfnjapm =  code (abacaxi,senha,3);
##Eduardo asa 3

##Fevbsep234

my $m= "Fzgvewtw Tixl 38";
my $s= "Miguel";
my $lenght= 6;
#print code($m,$s, $lenght), "\n";
print decode($m,$s, $lenght), "\n";
