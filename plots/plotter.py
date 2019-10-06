#!/usr/bin/env python3

seed  = str(input())
outputname = seed + '-output.png' 
bestname = '{}-journal-best.dat'.format(seed)
acceptedname = '{}-journal-accepted.dat'.format(seed)
plotname = 'seed: {}'.format(seed)

print('set terminal png enhanced')
print('set output "' + outputname + '"')

print('set title "' + plotname + '"')
print('set xlabel \'accepted number\'')
print('set ylabel \'cost\'')
print('plot "' + acceptedname + '" title \'accepted\' with lines, "' +
bestname + '" title \'best\' with points')
