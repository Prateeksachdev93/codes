t=int(raw_input())
#		Number of n-step closed paths on hexagonal lattice.
walk=[1, 0, 6, 12, 90, 360, 2040, 10080, 54810, 290640, 1588356, 8676360, 47977776, 266378112, 1488801600]
while t>0:
	n=int(raw_input())
	print walk[n];
	t=t-1