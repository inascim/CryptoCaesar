open (my $in, "<", "input.txt" ) or die "Vai se fuder :$! ";

    while(<$in>){
        print $_;
    }


close $in or die "$in: $!";
