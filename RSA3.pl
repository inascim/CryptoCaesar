use strict;
use bignum;
use Math::Prime::Util ':all';


sub KeysGen
{
		
	my ($numBits) = @_;

	print "$numBits\n\n\n";
		
	my $p = random_strong_prime(256);
	my $q = random_strong_prime(256);
	
	my $n = $p * $q;
 
	my $phi = ($p - 1) * ($q - 1);

 
	my $e = 257;
 
	my $x = $e ** 1;

	my $d = $x->bmodinv($phi);

	my %Keys = (
		"PublicKeyE" =>	$e,
		"PublicKeyN" => $n,
		"PrivateKeyP"=> $p,
		"PrivateKeyD"=> $d,
		"PrivateKeyQ"=> $q );

	return \%Keys;

}


sub code
{
	my ($hash_ref, $filename) = @_;

	#my $m = (join ( '', map (sprintf ("%03d",ord), split (//,$row)) )) + 1 - 1;

	#my $c = $m->bmodpow($hash_ref->{PublicKeyE},$hash_ref->{PublicKeyN});

	my $filenameCrypt = 'crypto.txt';
	
	open(my $fh, '<:encoding(UTF-8)', $filename)
  		or die "Não foi possível abrir o arquivo '$filename' $!";

	if (-e $filenameCrypt)
	{
        	 unlink $filenameCrypt or warn "Could not unlink $filenameCrypt: $!"; 
	}

	
	while (my $row = <$fh>) {
		chomp $row;
		print "LINHA DO ARQUIVO : $row\n";

			
		my $m = (join ( '', map (sprintf ("%03d",ord), split (//,$row)) )) + 1 - 1;

		$hash_ref = $hash_ref + 0;

		my $c = $m->bmodpow($hash_ref->{PublicKeyE},$hash_ref->{PublicKeyN});
		print "$c\n\n\n";
		
		open my $fileHandle, ">>", "crypto.txt" or die "Can't open 'crypto.txt'\n";
		print $fileHandle "$c\n";
		close $fileHandle;
	}

	
	return ($filenameCrypt);

}

sub decode
{
	my ($hash_ref, $filename) = @_;
	
#	my $M = $c->bmodpow($hash_ref->{PrivateKeyD},$hash_ref->{PublicKeyN});
	
#	my $Me = join ('', map(sprintf("%s",chr), ($M =~ /\d{3}/g))) . "\n";


	
	my $filenameDecrypt = 'decrypto.txt';
	
	open(my $fh, '<', $filename)
  		or die "Não foi possível abrir o arquivo '$filename' $!";

	if (-e $filenameDecrypt)
	{
        	 unlink $filenameDecrypt or warn "Could not unlink $filenameDecrypt: $!"; 
	}

	
	while (my $row = <$fh>) {
		chomp $row;
		print "LINHA DO ARQUIVO : $row\n";
		my $c = $row + 0;	#magica do perl

		$hash_ref = $hash_ref + 0;

		my $M = $c->bmodpow($hash_ref->{PrivateKeyD},$hash_ref->{PublicKeyN});
	
		my $d = join ('', map(sprintf("%s",chr), ($M =~ /\d{3}/g))) . "\n";
		print "$d\n\n\n";
	
		open my $fileHandle, ">>", "decrypto.txt" or die "Can't open 'decrypto.txt'\n";
		print $fileHandle "$d";
		close $fileHandle;
	}

	
	return ($filenameDecrypt);

}

=pad
my $hash_ref = KeysGen(10);

my $filename = 'data.txt';

my $arqC = code($hash_ref, $filename);
my $arqD = decode($hash_ref, $arqC);

print "pronto: arqA: $arqC arqB: $arqD\n\n";
=cut


