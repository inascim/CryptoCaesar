package menosmenos;

use strict;
use warnings;

#our %EXPORT_TAGS = ( 'all' => [ qw( ) ] );

use Exporter qw(import);

our @EXPORT_OK = qw( menosmenosLetra menosmenosNum );

	sub menosmenosLetra{
		my ($x)=$_;
#		print $x;

		for (my $j=0; $j<25; $j++){
					++$x;
				}
		return ($x);
	}

	sub menosmenosNum{
		my ($x)=$_;

		for (my $j=0; $j<9; $j++){
					++$x;
				}
	return ($x);
	}

# Preloaded methods go here.

# Autoload methods go after =cut, and are processed by the autosplit program.

1;
