# tsp-sa
Approximating the traveling salesman problem using simmulated anneailing. Project for the class "Heuristics for combinatorial optimization" - 2019.

## Build
    make
Clean:
    `make clean`

## Run
#### Bulk run seeds
    main <sequence file> <seeds file>
Note that *sequence file* and *seeds file* need to specify the number of elements they contain and then declare those elements separated by spaces.  
Output will go to standard output.
#### Plot a single seed
    main <sequence file> -p <seed>
Two filenames called ***<seed>-journal-best.dat*** and ***<seed>-journal-accepted.dat***
are going to be written inside folder ***plot/***. To generate a gnuplot script from this files, run (inside ***plot/***):
    `echo "<seed>" | python3 plotter.py > <seed>-script.plt`
Finally, to make and image out of it, run:
    `gnuplot <seed>-script.plt`

