for(i=1; i<N; i++)
{
	Temp = A[i];
	j = i-1;
	while(Temp<A[j] && j>=0)
	{
		A[j+1] = A[j];
		j = j-1;
	}
	A[j+1] = Temp;
}
